/*
https://www.youtube.com/watch?v=tof-Vv5ehSs&t=336s&ab_channel=SMtrainingacademy
R = PF 1
    B = PF2
    G = PR3

    enable port F clock
    digitlize the portf pins
    direction for portf
    data to portf


    gpio data reg f -> 0x4002 5000  0x000
    gpio direc reg f -> 0x4002 5000 0x0400 (pg 663) -> 4002 5400
    gpio digital enable reg f -> 0x4002 5000 51C (pg  682) 4002 551c
    gpio clock -> 0x400F E000 608 (pg 340)   -> 0x400F E608

    gpio data pin access
    0x4002 5000 + [9:2] bits set(3FC) -> 0x4002 53FC
		
		switch is in portf0 and portf4
		
		meaning portf0 and   portf4 should be input
		
		direction reg = same since input is zero
		
		read input and then use to glow let
		
		default red
		pf0 blue
		pf1 green
		
		set digital enable- ox1F
		set  pull up - ox11
		

*/


#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define  GPIO_PUR_R             (*((volatile unsigned long *)0x40025510))
#define GPIO_DATA_REG_R 				(*((volatile unsigned long *)0x400253FCU))

 void delayfn(unsigned int counter) {
		while (counter >  0){
			counter = counter -1;
		}
 }
 
 void setDataPortF(unsigned int value) {
			unsigned int currentdata;
			currentdata = GPIO_DATA_REG_R;
			currentdata	= currentdata & 0xF1U;
			GPIO_DATA_REG_R = currentdata | value;
 }
 
int main()
{	
    unsigned int *RCGCGPIO;
    RCGCGPIO = (unsigned int *)0x400FE608U;

    unsigned int *GPIOFEN;
    GPIOFEN = (unsigned int *)0x4002551CU;

    unsigned int *GPIOFDIR;
    GPIOFDIR = (unsigned int *)0x40025400U;

    unsigned int *GPIOFDATA;
    GPIOFDATA = (unsigned int *) 0x400253FCU;


		unsigned int delay;
	
    *RCGCGPIO = 0x20U;
	
		delay = *RCGCGPIO;
	
		GPIO_PORTF_LOCK_R = 0x4C4F434BU;   // 2) unlock GPIO Port F
    GPIO_PORTF_CR_R = 0x1FU;           // allow changes to PF4-0
    *GPIOFEN = 0x01F;
    *GPIOFDIR = 0x0EU;
		GPIO_PUR_R = 0x11U;
//    *GPIOFDATA = 0x02U;
		setDataPortF(0x02U);
		
		unsigned int switches;
		

     while(1)
    {
/*			*GPIOFDATA = 0x02U;
			delayfn(10000000);
			*GPIOFDATA = 0x04U;
			delayfn(10000000);
			*GPIOFDATA = 0x08U;
			delayfn(10000000);
//       *GPIOFDATA = 0x02U;*/
		switches = GPIO_DATA_REG_R;
		switches = switches & 0x11U;
		if((switches & 0x01U)){
			setDataPortF(0x04U);
			delayfn(10000);
    }
		else if((switches & 0x10U)){
			setDataPortF(0x08U);
			delayfn(10000);
    }
		else {
			setDataPortF(0x02U);
		}
	}
		
}
