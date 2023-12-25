#include <stdint.h>
#include"Driver.h"

void delayMS(int delay);

int main(void)
{
	USART1_begin(9600);

	while (1)
	{
		USART1_print("ON \r");

		delayMS(3000);

		USART1_print("OFF\r");
		delayMS(3000);
	}
}


void delayMS(int delay)
{
	int i;
	for (; delay > 0; delay--)
		for (i = 0; i <= 3195; i++)
			;
}

