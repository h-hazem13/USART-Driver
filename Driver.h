#include <stdint.h>
// RCC registers
#define RCC_BASE    0x40023800
#define RCC_AHB1ENR (*(volatile uint32_t *)(RCC_BASE + 0x30))
#define RCC_APB2ENR (*(volatile uint32_t *)(RCC_BASE + 0x44))
// USART1 registers
#define USART1_BASE 0x40011000
#define USART1_SR   (*(volatile uint32_t *)(USART1_BASE + 0x00))
#define USART1_DR   (*(volatile uint32_t *)(USART1_BASE + 0x04))
#define USART1_BRR  (*(volatile uint32_t *)(USART1_BASE + 0x08))
#define USART1_CR1  (*(volatile uint32_t *)(USART1_BASE + 0x0C))
#define USART1_CR2  (*(volatile uint32_t *)(USART1_BASE + 0x10))
#define USART1_CR3  (*(volatile uint32_t *)(USART1_BASE + 0x14))

// GPIOA registers
#define GPIOA_BASE  0x40020000
#define GPIOA_MODER (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_ODR   (*(volatile uint32_t *)(GPIOA_BASE + 0x14))
#define GPIOA_AFRH  (*(volatile uint32_t *)(GPIOA_BASE + 0x24)) // Added definition for GPIOA_AFRL

//usart function
void USART1_begin(uint32_t baudRate);
int USART1_available();
char USART1_read();
void USART1_readBytes(char* buffer, uint32_t len) ;
void USART1_Write(char data);
void USART1_Text_write(const char* buffer, uint32_t len);
void USART1_print( char *text);
void USART1_println(const char* str);
void delayMS(int delay);