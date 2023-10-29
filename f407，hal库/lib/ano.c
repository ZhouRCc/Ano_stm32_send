/**
  ****************************(C) COPYRIGHT ZhouCc****************************
  * @file       can_receive.c/h
  * @brief      This is the program used by the anonymous host computer on the STM32F4
  *             ����������λ����stm32f4�ϵ�ʹ�ó���
  * @note       ���������λ�����ղ����������������reset
  * @history
  *  Version    Date            Author          Modification
  *  V1.0       2023.4.30       ZhouCc          ���
  *  V1.5		2023.10.6		ZhouCc			���Ӷ�keil AC6�������ļ��ݼ���cpp�ļ���
  @verbatim
  ==============================================================================

  ==============================================================================
  @endverbatim
  ****************************(C) COPYRIGHT ZhouCc****************************
  */

#include "main.h"
#include "ano.h"
#include "usart.h"
#include "bsp_delay.h"
#include <stdarg.h>
//�˺궨�壬ʹ�ô���1ʱ���˴���Ϊ1��ʹ�ô���6ʱ��Ϊ6
#define WHICH_UART 1


/******С��ģʽ�����ֽ���ǰ***/
/*********���ݲ��************/
#define BYTE0(dwTemp)       (uint8_t)(dwTemp & 0xFF) 	 
#define BYTE1(dwTemp)       (uint8_t)((dwTemp & 0xFF00)>>8)	 
#define BYTE2(dwTemp)       (uint8_t)((dwTemp & 0xFF0000)>>16)
#define BYTE3(dwTemp)       (uint8_t)((dwTemp & 0xFF0000)>>24)

uint8_t BUFF[100];//�洢����

/**
  * @brief          ������λ����ʼ��
  * @param[in]    	none
  * @retval         none
  */
void Ano_Init(void)
{
	delay_init();
	//enable receive interrupt and idle interrupt
	//ʹ�ܽ����жϺͿ����ж�
	__HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE);  //receive interrupt
	__HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);  //idle interrupt
	__HAL_UART_ENABLE_IT(&huart6, UART_IT_RXNE);  //receive interrupt
	__HAL_UART_ENABLE_IT(&huart6, UART_IT_IDLE);  //idle interrupt
}

/**
  * @brief          ������λ����������
  * @param[in]      �����ݵ����ݣ����Ϊint���׸�����Ϊ����
  * @retval         none
  */

void Ano_Send(uint8_t len, ...)
{
	int i;
	int intbuf;
	uint8_t sumcheck = 0;
	uint8_t addcheck = 0;
	uint8_t _cnt=0;
	
	va_list args;

	va_start(args,len);

	BUFF[_cnt++]=FRAME_HEADER;//֡ͷ
	BUFF[_cnt++]=GENERAL_OUTPUT_ADDR;
	BUFF[_cnt++]=0xF1;//����ʽ֡��0xF1-0xFA
	BUFF[_cnt++]=4 * len;// ���ݳ���

	while(len --)
	{
		intbuf=va_arg(args,int);
		BUFF[_cnt ++] = BYTE0(intbuf);
		BUFF[_cnt ++] = BYTE1(intbuf);
		BUFF[_cnt ++] = BYTE2(intbuf);
		BUFF[_cnt ++] = BYTE3(intbuf);
	}

	va_end(args);

	for(i=0;i<BUFF[3]+4;i++) 
	{
		sumcheck+=BUFF[i];
		addcheck+=sumcheck;
	}
	BUFF[_cnt++]=sumcheck;	
	BUFF[_cnt++]=addcheck;	
#if WHICH_UART == 1
	
	HAL_UART_Transmit(&huart1,BUFF,_cnt,0xFFF);
#elif WHICH_UART == 6
	HAL_UART_Transmit(&huart6,BUFF,_cnt,0xFFF);
#else
	#error WHICH_UART must be define 1 or 6
#endif
}


//�жϻص�����
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	
}


