
#include <stdint.h>
#include "Driver.h"

void delayMS(int delay);
void USART1_readBytes(char* buffer, uint32_t len);
int main (void)
{
	USART1_begin(9600);
	GPIOA_MODER|= (1<<10);    // PA5 pin is output
	char stri[]={'\0'};

	while(1)
	{

		USART1_readBytes(stri,4);


		if(!strcmp(stri,"ON \r"))
		{	USART1_print("LED is ON\r\n");
			GPIOA_ODR |= (1<<5); // led is turn ON



		}
		else if(!strcmp(stri,"OFF\r"))
		{
			USART1_print("LED is OFF\r\n");
			GPIOA_ODR &= ~(1<<5); // led is turn OFF

		}
	}
}
