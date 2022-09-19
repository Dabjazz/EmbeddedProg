/*toggle LED P1.17 for every 5 sec
using timer0,MR0*/
#include <lpc21xx.h>
#include "lcd_fun.c"
void timer_config(void);
void toggle(unsigned int t );
unsigned int val;
int main()
{
	/* code */
	val=0;
	IODIR1|=(0XFF<<17);
	lcd_config();
	timer_config();

	while(1){
		//aCTION PART 1
		if(T0IR&(1<<0)){
			toggle(17);
			//toggle(18);
			T0IR=(1<<0);//Clear  int MR0 flag
		}
		//aCTION PART 2
		if(T0IR&(1<<1)){
			//toggle(17);
			toggle(18);
			T0IR=(1<<1);//Clear  int MR1 flag
		} 
	}
		if(T0IR&(1<<2)){
			//toggle(17);
			toggle(19);
			T0IR=(1<<2);//Clear  int MR2 flag
		}
		if(T0IR&(1<<3)){
			//toggle(17);
			//toggle(19);
			lcd_num(val);
			val++;
			T0IR=(1<<3);//Clear  int MR2 flag
		} 
	

	return 0;
}

void timer_config(void){
T0PR=14;
T0MR0=5000000;
T0MCR= (1<<0)|(1<<3)|(1<<9)|(1<<6)|(1<<10);  //MRO IN REP AND INT MODE
T0TCR=(1<<1); //clear counter
T0TCR=(1<<0); //enable Timer
T0MR1=100000000;
T0MR2=150000000;
T0MR3=200000000;
}
void toggle(unsigned int t ){
IOSET1=(1<<t);
delay(500);
IOCLR1=(1<<t);
delay(500);
}