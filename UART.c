/*
 * UART.c
 *
 * Created: 2/8/2020 5:44:07 PM
 *  Author: Khaled Magdy
 */ 

#include "UART.h"


void UART_Init(UART_cfg* uart_cfg)
{
	UCSRC = 0x00;
	UCSRB = 0x00;
	
	// Set The UART Baud Rate
	UBRRL = ((F_cpu/(16*uart_cfg->baudrate)) - 1);
	UBRRH = ((F_cpu/(16*uart_cfg->baudrate)) - 1)>>8;
	
	// Set The UART Mode OF Operation
	CLEAR_BIT(UCSRB, 2);
	UCSRB |= (uart_cfg->mode | uart_cfg->uartInterrupts);
	//UCSRC |= 0x80;
	// Set The UART Synchronization
	UCSRC |= (uart_cfg->uartSync | uart_cfg->sampleEdge | uart_cfg->dataBits | uart_cfg->parity | uart_cfg->stopBits);
	// Set The UART Data Sampling Edge
	// Set The UART Data Bits
	// Set The UART Parity Option
	// Set The UART Stop Bits
	// Set The UART Interrupt Mode
	SREG  |= (0x80);
}

void UART_Write(uint8_t data)
{
	// Wait For Empty Transmit Budder
	while(!(UCSRA & (1<<5)));
	// Write The Data To The Buffer & Send!
	UDR = data;
}

void UART_Write_String(uint8_t* str)
{
	uint16_t i=0;
	while(str[i] != '\0')
		UART_Write(str[i++]);
}
