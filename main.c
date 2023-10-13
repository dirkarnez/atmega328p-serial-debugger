#include <avr/io.h>

void usart_init()
{
	UCSR0B = (1<<TXEN0) | (1<<RXEN0);
	UCSR0C = (1<<UCSZ00) | (1<<UCSZ01);
	UBRR0L = 0xCF; 
}

void usart_send(unsigned char ch)
{
	while(!(UCSR0A &(1<<UDRE0)));
	UDR0 = ch;
}

void usart_read(unsigned char* ptr_ch)
{
	while(!(UCSR0A & (1<<RXC0)));
	*ptr_ch = UDR0;
}

void welcome_mess()
{
  unsigned char welcome[32] = "2.5\n";
	unsigned int loc = 0;
	for ( ; welcome[loc]!='\0' ; loc++)
		usart_send(welcome[loc]);
}

int main(void)
{
    usart_init();
    while (1) 
    {
      	welcome_mess();	
    }
}
