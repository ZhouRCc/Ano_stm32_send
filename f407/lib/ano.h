#ifndef ANO_H
#define ANO_H


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

#endif


