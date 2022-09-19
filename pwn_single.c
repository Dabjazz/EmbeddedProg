#include "lcd_fun.c"
#include <lpc21xx.h>
void PWM4_Single_Edge(void);
void pwm_config(void);
int main()
{
	lcd_config();
	pwm_config();

	while(1){

		PWM4_Single_Edge();
	}
	
	return 0;
}

void pwm_config(void){
	/*configure P0.8-->PWM4*/

PINSEL0|=(1<<17);
PINSEL0&=~(1<<16);

PWMPR=14;
PWMMR0=10000 ; //T=10MS
PWMLER=(1<<0);    //ENABLE MR0 VALUE

PWMMCR=(1<<1); //CONFIGURE MR0 IN REP MODE
PWMPCR|=(1<<4);//CONFIGURE PWN4 AS A single edge
PWMPCR|=(1<<12);//ENABLE PWNM4  Op
PWMTCR=(1<<0)|(1<<3);
}

void PWM4_Single_Edge(void){
	//25% Duty cycle
PWMMR3=1500;
PWMMR4=4000;
PWMLER=(1<<3)|(1<<4);
delay(1000);
	//50% Duty cycle
PWMMR3=1500;
PWMMR4=6500;
PWMLER=(1<<3)|(1<<4);
delay(1000);

	//75% Duty cycle
PWMMR3=1500;
PWMMR4=9500;
PWMLER=(1<<3)|(1<<4);
delay(1000);
    //95% Duty cycle
PWMMR4=9500;
PWMLER=(1<<3)|(1<<4);
delay(1000);
}