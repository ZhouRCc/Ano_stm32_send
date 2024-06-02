/**
  ****************************(C) COPYRIGHT ZhouCc****************************
  * @file       can_receive.c/h
  * @brief      This is the program used by the anonymous host computer on the STM32F4
  *             这是匿名上位机在stm32f4上的使用程序
  * @note       如果发现上位机接收不到数，请多摁几下reset
  * @history
  *  Version    Date            Author          Modification
  *  V1.0       2023.4.30       ZhouCc          完成
  *  V1.5		2023.10.6		ZhouCc			增加对keil AC6编译器的兼容
  @verbatim
  ==============================================================================

  ==============================================================================
  @endverbatim
  ****************************(C) COPYRIGHT ZhouCc****************************
  */
#ifndef ANO_H
#define ANO_H
//增加对cpp的兼容
#ifdef __cplusplus
extern "C"{
#endif
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
#ifdef __cplusplus
}
#endif

#endif


