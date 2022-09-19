#include <lpc21xx.h>
						  void delay(unsigned int a);
int main(){

			unsigned int x,y;
IODIR1=(0x1<<17);	//Config the direction of port P0.0


	while(1){
	
	for( x=17,y=25;x<25&&y>17;x++,y--){
	IOSET1=(0x1<<x)|(0x1<<y);		//Set port pin to High
	delay(100);
	IOCLR1=(0x1<<x)|(0x1<<y);		//clear port pin

	delay(100);
	} 		
	
	for( x=25,y=17;x>17&&y<25;x--,y++){
	IOSET1=(0x1<<x)|(0x1<<y);		//Set port pin to High
	delay(100);
	IOCLR1=(0x1<<x)|(0x1<<y);		//clear port pin

	delay(100);
	} 					   }


return 0;
}


void delay(unsigned int a){
unsigned int i,j;
	for(i=0;i<a;i++){
	for(j=0;j<6000;j++){
	
	}
	}
}