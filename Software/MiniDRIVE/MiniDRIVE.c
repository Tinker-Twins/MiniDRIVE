///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                            MiniDRIVE Program                                                                                      //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
/* AUTHORS:	Chinmay Vilas Samak
			Tanmay Vilas Samak

*/
#define F_CPU 1000000UL // Macros defining the processor frequency to 1 Mhz
						// UL means Unsigned Long data type | Unsigned Long is used since 1000000 lies outside the range of integer data type (which on AVR is -32768 to +32768)

#define BAUDRATE 4800 							// Macros defining the baud rate for serial communication (UART)
#define UBRR_Value ((F_CPU/(BAUDRATE*16UL))-1)	// Macros defining Baudrate value to be stored in USART Baud Rate Register (UBRR)


#include<avr/io.h> 		// Header file with AVR device-specific IO definitions
#include<util/delay.h> 	// Header file with convenience functions for busy-wait delay loops

void UART_Initialize() 		// Function to initialize serial communication (UART)
{
	UBRRL=UBRR_Value;		// Load lower 8-bits of Baudrate value into lower byte of UBRR (UBRRL)
	UBRRH=(UBRR_Value>>8);	// Load upper 8-bits of Baudrate value into higher byte of UBRR (UBRRH)
	UCSRB|=(1<<RXEN);		// Enable the Receiver by making the RXEN (receiver enable) bit of the USART Control and Status Register B (UCSRB) high
}

unsigned int UART_Receive() 		// Function to receive serial data stream using serial communication (UART)
{
	while((UCSRA & (1<<RXC))==0);	// Wait while data is being received by checking the RXC (USART receive complete) flag in the USART Control and Status Register A (UCSRA)
									// When data is received in the RX Buffer, the RXC flag is set (high)
	return(UDR);					// Return the received 8-bit data packet i.e. data packet stored in the USART Data Register (UDR)
}

void main()								// Main function
{
	unsigned char dataPacket;		// Declaring a variable to hold received data packet
	
	DDRB=0b11111111;				// Set Port B as output port (PB7-PB0)
	UART_Initialize();				// Initializing serial communication (UART)
	_delay_ms(50);					// Time delay for stable communication
	
	while(1)
	{
		dataPacket=UART_Receive();	// Assign the declared variable to the received data packet
		
		if(dataPacket=='w')			// If received data (ASCII character) is "w"
		PORTB=0b00001010;			// Go forward
		
		else if(dataPacket=='s')	// If received data (ASCII character) is "s"
		PORTB=0b00000101;			// Go backward
		
		else if(dataPacket=='a')	// If received data (ASCII character) is "a"
		PORTB=0b00000110;			// Turn left
		
		else if(dataPacket=='d')	// If received data (ASCII character) is "d"
		PORTB=0b00001001;			// Turn right
		
		else						// If any other data (ASCII character) is received (for example "x")
		PORTB=0b00000000;			// Stop
	}
}