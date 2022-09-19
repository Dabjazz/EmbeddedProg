#include <lpc21xx.h>
											  void delay(unsigned int a);
int main(){

			unsigned int x,y;
IODIR1|=(0xff<<11);	//Config the direction of port P0.0
IODIR1&=~(1<<25)
IODIR0|=(1<<11)

	
	
	while(1){
	if(IOPIN1&(1<<25)){
	IOSET0=(1<<11);		//Set port pin to High
	delay(100);
	IOCLR0=(1<<11);		//clear port pin

	delay(100);		  }
	} 
		 


return 0;
}


void delay(unsigned int a){
unsigned int i,j;
	for(i=0;i<a;i++){
	for(j=0;j<6000;j++){
	
	}
	}
}