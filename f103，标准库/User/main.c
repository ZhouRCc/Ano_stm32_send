#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Upper_Computer.h"

uint8_t RxData;

int main(void)
{
	uint32_t i;
	uint32_t b;
	uint32_t c = 1;
	
	Ano_Init();

	
	while (1)
	{
		for(i=0;i < 100;i++)
		{
			b = i * 2;
			sent_data(3,i,b,c);
			Delay_ms(10);
		}
		for(;i > 0;i--)
		{
			b = i * 2;
			sent_data(3,i,b,c);
			Delay_ms(10);
		}
	}
}
