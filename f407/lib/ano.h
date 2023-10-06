/**
  ****************************(C) COPYRIGHT ZhouCc****************************
  * @file       can_receive.c/h
  * @brief      This is the program used by the anonymous host computer on the STM32F4
  *             ����������λ����stm32f4�ϵ�ʹ�ó���
  * @note       ���������λ�����ղ����������������reset
  * @history
  *  Version    Date            Author          Modification
  *  V1.0       2023.4.30       ZhouCc          ���
  *  V1.5		2023.10.6		ZhouCc			���Ӷ�keil AC6�������ļ���
  @verbatim
  ==============================================================================

  ==============================================================================
  @endverbatim
  ****************************(C) COPYRIGHT ZhouCc****************************
  */
#ifndef ANO_H
#define ANO_H
//���Ӷ�cpp�ļ���
#ifdef __cplusplus
extern "C"{
#endif
//Ŀ���ַ�궨��
#define FRAME_HEADER 		  0XAA   //<֡ͷ
#define GENERAL_OUTPUT_ADDR	  0XFF   //<�㲥�����


//��������ʱ������ʼ��
void Ano_Init(void);

/**
  * @brief          ������λ����������
  * @param[in]      �����ݵ����ݣ����Ϊint���׸�����Ϊ����
  * @retval         none
  */
void Ano_Send(uint8_t len, ...);
#ifdef __cplusplus
}
#endif

#endif


