#include<lpc21xx.h>
/*void uart0_str(unsigned char *);
void uart0_tx(unsigned char);
void uart0_config(void); */

void uart0_config(void)
{
   PINSEL0=0X05;
   U0LCR=0X83;
   U0DLL=97;
   U0DLM=0;
   U0LCR=0X03;
}
void uart0_tx(unsigned char rxbyte)
{
  while(((U0LSR>>5)&1)==0);
  U0THR=rxbyte;
}
void uart0_str(unsigned char *s)
{

  while(*s)
  uart0_tx(*s++); 
}
