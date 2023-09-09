#ifndef _UPPER_COMPUTER_H
#define _UPPER_COMPUTER_H



//目标地址宏定义
#define FRAME_HEADER 		  0XAA   //<帧头
#define GENERAL_OUTPUT_ADDR	  0XFF   //<广播型输出





void Ano_Init(void);

//void sent_data(int A,int B,int C);
void sent_data(uint8_t len, ...);





#endif

