#ifndef ANO_H
#define ANO_H


//目标地址宏定义
#define FRAME_HEADER 		  0XAA   //<帧头
#define GENERAL_OUTPUT_ADDR	  0XFF   //<广播型输出


//串口与延时函数初始化
void Ano_Init(void);

/**
  * @brief          匿名上位机发送数据
  * @param[in]      被传递的数据，需均为int，首个参数为长度
  * @retval         none
  */
void Ano_Send(uint8_t len, ...);

#endif


