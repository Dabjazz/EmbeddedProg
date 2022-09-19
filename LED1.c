#include<lpc21xx.h>
						  void delay(unsigned int a);
int main(){


IODIR1=(0XFF<<17);	//Config the direction of port P0.0


	while(1){
	IOSET1=(0xFF<<17);		//Set port pin to High
	delay(100);
	IOCLR1=(0xFF<<17);		//clear port pin

	delay(100);
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