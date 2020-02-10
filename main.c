/*
 * UART_Driver.c
 *
 * Created: 2/8/2020 5:41:05 PM
 * Author : Khaled Magdy
 */ 
#include "gpio.h"
#include "interrupt.h"
#include "timers.h"
#include "UART.h"
#include "softwareDelay.h"
#include "UART_cfg.h"
#include "led.h"

static volatile uint8_t UART_RX_Data = 0x00;

// Transmitter Test Code

int main(void)
{
	UART_cfg uart1_cfg;
	
	uart1_cfg.baudrate =	   9600;
	uart1_cfg.dataBits =	   UART_Bits_8;
	uart1_cfg.mode =		   UART_TX;
	uart1_cfg.parity =		   No_Parity;
	uart1_cfg.sampleEdge =     RisingEdg;
	uart1_cfg.stopBits =	   StopBits_1;
	uart1_cfg.uartSync =	   UART_Async;
	uart1_cfg.uartInterrupts = UART_No_Interrupts;
	
    UART_Init(&uart1_cfg);
	uint8_t counter=0;
	while (1) 
    {
	    UART_Write_String("OMG PLZzzz! Report My Noob Team XD\r\n");
	    UART_Write_String("Report Jungle Plz! 0 gank, Enemy jg ganked 9999 times\r\n");	
		//UART_Write(counter++);
		//UART_Write('A');
		softwareDelayMs(3500);
    }
}

//===============================================
// Receiver Test Code
/*
int main(void)
{
	UART_cfg uart1_cfg;
	uart1_cfg.baudrate =	   9600;
	uart1_cfg.dataBits =	   UART_Bits_8;
	uart1_cfg.mode =		   UART_RX;
	uart1_cfg.parity =		   No_Parity;
	uart1_cfg.sampleEdge =     RisingEdg;
	uart1_cfg.stopBits =	   StopBits_1;
	uart1_cfg.uartSync =	   UART_Async;
	uart1_cfg.uartInterrupts = OnRx;
	
	UART_Init(&uart1_cfg);
	Led_Init(LED_2);
	//gpioPortDirection(GPIOB, OUTPUT);
	//gpioPortWrite(GPIOB, 0xFF);
	while (1)
	{
		// Do Nothing! Stay IDLE ....
		softwareDelayMs(250);
		//UART_RX_Data = UDR;
		//gpioPortWrite(GPIOB, UART_RX_Data);
	}
}
ISR(USART_RXC_vect)
{
	// Read UART Data Received Buffer
	UART_RX_Data = UDR;
	Led_Toggle(LED_2);
	// Update PORTB (For Display)
	//gpioPortWrite(GPIOB, UART_RX_Data);
}
*/