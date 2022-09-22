
unsigned int MSG[20];

// p0.23-RD2, p0.24-TD2, P0.25-RD1, P10-TD1

void can_config(void){
	PINSEL1|=(1<<14)|(1<<16)|(1<<18);
	PINSEL1&=~((1<<15)|(1<<17)|(1<<19));

	//BRP[9:0]=2+1,TSEG1[19:16]=15+1,TSEG[22:20]=3+1
	C2MOD=(1<<0);		//Disable CAN
	C2BTR=(2<<0)|(15<<16)|(3<<20);
	C2MOD=0; //Enable CAn

	C1MOD=(1<<0);		//Disable CAN
	C1BTR=(2<<0)|(15<<16)|(3<<20);
	C1MOD=0; //Enable CAn
}

void can_tx(unsigned int d)		//CAN2 as a Tx
{
	while(!(C2GSR&(1<<2)));//Check TBR is empty or not
	C2TID1=0x456;//Load Msg ID value
	C2TFI1=(1<<18);//Load Frame info DLC[19:16]=0100,RTR=0,IDE=0
	C2TDA1=d;//Load the DATA
	C2CMR=(1<<0)|(1<<5);//Enable queued Tx, Select TB1
	while(!(C2GSR&(1<<3)));//Check Data Transmitted or not
}


unsigned int can_rx(void)		//CAN 1 as receiver
{
	while((C1GSR&(1<<0)));//Check RBR HAS RECEIVED DATA OR NOT
	MSG[0]=C1RID;//Load id from id reg to a variable
	MSG[1]=C1RDA;//load data from data reg to a variable
	C1CMR=(1<<2);//release the buffer
	return MSG[1];
}