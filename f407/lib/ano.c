#include "main.h"
#include "ano.h"
#include "usart.h"
#include "bsp_delay.h"
#include <stdarg.h>
//�˺궨�壬ʹ�ô���1ʱ���˴���Ϊ1��ʹ�ô���6ʱ��Ϊ6
#define WHICH_UART 1


/******С��ģʽ�����ֽ���ǰ***/
/*********���ݲ��************/
#define BYTE0(dwTemp)       (*(char *)(&dwTemp))	 
#define BYTE1(dwTemp)       (*((char *)(&dwTemp) + 1))	 
#define BYTE2(dwTemp)       (*((char *)(&dwTemp) + 2))
#define BYTE3(dwTemp)       (*((char *)(&dwTemp) + 3))

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


