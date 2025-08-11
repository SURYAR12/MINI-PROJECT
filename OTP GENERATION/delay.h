#include<LPC21XX.H>

void delay(int sec)

{
   T0PR=15000000-1;
   T0TCR=0x01;
   while(T0TC<sec);
   T0TCR=0x03;
   T0TCR=0x00;
}
void delay_ms(int sec)
{
   T0PR=1500-1;
   T0TCR=0x01;
   while(T0TC<sec);
   T0TCR=0x03;
   T0TCR=0x00;
}

 void delay_micro(int sec)
{
  T0PR=1500-1;
  T0TCR=0x01;
  while(T0TC<sec);
  T0TCR=0x03;
  T0TCR=0x00;
}
