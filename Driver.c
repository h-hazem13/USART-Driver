#include <stdint.h>
#include "Driver.h"

void USART1_begin(uint32_t baudRate) {
    // Enable GPIOA and USART1 clock
    RCC_AHB1ENR |= 0x01;     // Enable GPIOA clock
    RCC_APB2ENR |= (1<<4); // Enable USART1 clock

    // Configure PA9 (USART1 TX)  PA10 (USART1 RX) as alternate function
    GPIOA_MODER |= (1<<19); // Set mode to alternate function
    GPIOA_MODER |= (1<<21);// Set mode to alternate function

    // Set alternate function to AF7 (USART1)
    GPIOA_AFRH |= (7 << 4);
	GPIOA_AFRH |= (7 << 8);   
    
    // Configure USART1
    USART1_CR1 |= 0x00002000; // Enable USART
    // Enable USART1 RX and TX
    USART1_CR1 |= (1<<2);   // Rx Enable
	USART1_CR1 |= (1<<3);   // Tx Enable
	USART1_CR1 |= (1<<13);  // USART Enable

    USART1_CR2 &=0x00000000; //Stop Bit to 1
    USART1_CR3 &=0x00000000; //Full Duplex Mode
    USART1_BRR = 16000000 / baudRate;
}

int USART1_available() {
    // Check if the received data buffer is not empty
    return (USART1_SR & 0x00000020) != 0;
}

char USART1_read() {
    // Wait until RX buffer is not empty 
    while (!(USART1_SR & 0x00000020)) {}
    return USART1_DR & 0xFF;
}

void USART1_readBytes(char* buffer, uint32_t len) {
    for (uint32_t i = 0; i < len; ++i) {
        buffer[i] = USART1_read();
    }
}

void USART1_write(char data) {
    // Wait until TX buffer is empty
    while (!(USART1_SR & 0x00000080)) {}
    USART1_DR = data;
}

void USART1_writeBytes(const char* buffer, uint32_t len) {
    for (uint32_t i = 0; i < len; ++i) {
        USART1_write(buffer[i]);
    }
}

void USART1_print( char *text)
{
	while(*text) USART1_write(*text++);

}

void USART1_println(const char* str) {
    USART1_print(str);
    USART1_write('\0'); // Null-terminate the string
}