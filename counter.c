#include <lpc21xx.h>
 void delay(unsigned int a);
 void delay(unsigned int a){
unsigned int i,j;
	for(i=0;i<a;i++){
	for(j=0;j<6000;j++){
	
	}
	}
}


int main(){
unsigned int x,y;
	   IODIR1=(0XFF<<17);
	
		  while(1){
		  for(x=17;x<25;x++){
		  	IOSET1=(0xff<<x);
		  	delay(500);
			IOCLR1=(0xff<<x);
		  }
		  
		  
		  }




return 0;
}