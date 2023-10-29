#include "stm32f10x.h"                  // Device header
#include "Serial.h"
#include "Upper_Computer.h"
#include <stdarg.h>

/******С��ģʽ�����ֽ���ǰ***/
/*********���ݲ��************/
#define BYTE0(dwTemp)       (*(char *)(&dwTemp))	 
#define BYTE1(dwTemp)       (*((char *)(&dwTemp) + 1))	 
#define BYTE2(dwTemp)       (*((char *)(&dwTemp) + 2))
#define BYTE3(dwTemp)       (*((char *)(&dwTemp) + 3))

uint8_t BUFF[100];//�洢����


/**
  * @brief          ������λ����ʼ��
  * @param[in]    	
  * @retval         none
  */
void Ano_Init(void)
{
	Serial_Init();
	
}

/**
  * @brief          ������λ����������
  * @param[in]      �����ݵ�����
  * @retval         none
  */

//void sent_data(int A,int B,int C)
//{
//	int i;
//	uint8_t sumcheck = 0;
//	uint8_t addcheck = 0;
//	uint8_t _cnt=0;
//	BUFF[_cnt++]=FRAME_HEADER;//֡ͷ
//	BUFF[_cnt++]=GENERAL_OUTPUT_ADDR;
//	BUFF[_cnt++]=0XF1;//����ʽ֡��0xF1-0xFA
//	BUFF[_cnt++]=0x0C ;// ���ݳ���
//	BUFF[_cnt++]=BYTE0(A);
//	BUFF[_cnt++]=BYTE1(A);
//	BUFF[_cnt++]=BYTE2(A);
//	BUFF[_cnt++]=BYTE3(A);
//	BUFF[_cnt++]=BYTE0(B);
//	BUFF[_cnt++]=BYTE1(B);
//	BUFF[_cnt++]=BYTE2(B);
//	BUFF[_cnt++]=BYTE3(B);	
//	BUFF[_cnt++]=BYTE0(C);
//	BUFF[_cnt++]=BYTE1(C);
//	BUFF[_cnt++]=BYTE2(C);
//	BUFF[_cnt++]=BYTE3(C);

//	for(i=0;i<BUFF[3]+4;i++) 
//	{
//		sumcheck+=BUFF[i];
//		addcheck+=sumcheck;
//	}
//	BUFF[_cnt++]=sumcheck;	
//	BUFF[_cnt++]=addcheck;	
//	
//	Serial_SendArray(BUFF,_cnt);
//}
void sent_data(uint8_t len, ...)
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
	
	Serial_SendArray(BUFF,_cnt);
}


