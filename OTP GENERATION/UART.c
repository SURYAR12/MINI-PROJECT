// gsm program

#include<lpc21xx.h>
#include <stdlib.h>
#include <stdio.h> 
#include"uart_tx.h"
#include"delay.h"
void generate_otp(void);
unsigned char l=0;
char otp_str[10];
int main()
{
  
  uart0_config();
  uart0_str("AT\r\n");
  delay(1000);
  uart0_str("AT+CMGF=1\r\n");
  delay(1000);
  if(l==0)
  uart0_str("AT+CMGFS=\"+918508485099\"\r\n");
  else
  uart0_str("AT+CMGS=\"+917010011768\"\r\n");
  delay(1000);
  uart0_str("hi");
  delay(1000);

      generate_otp();   // make new OTP
      uart0_str("Your OTP is: ");
      uart0_str(otp_str);  // send OTP
      uart0_tx(0x1A);

  delay(1000);
  while(1); 
  
}
void generate_otp(void) {
    int otp = (rand() % 900000) + 100000; 
    sprintf(otp_str, "%d", otp);           // convert to string
}
