#ifndef _UPPER_COMPUTER_H
#define _UPPER_COMPUTER_H



//Ŀ���ַ�궨��
#define FRAME_HEADER 		  0XAA   //<֡ͷ
#define GENERAL_OUTPUT_ADDR	  0XFF   //<�㲥�����





void Ano_Init(void);

//void sent_data(int A,int B,int C);
void sent_data(uint8_t len, ...);





#endif

