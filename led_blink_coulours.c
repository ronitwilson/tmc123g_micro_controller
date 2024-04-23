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

*/


 #define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
 #define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))

 void delay(unsigned int counter) {
		while (counter >  0){
			counter = counter -1;
		}
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

//    GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock GPIO Port F
//    GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0

    *RCGCGPIO = 0x20U;
    *GPIOFEN = 0x0EU;
    *GPIOFDIR = 0x0EU;
    *GPIOFDATA = 0x04U;

     while(1)
    {
			*GPIOFDATA = 0x02U;
			delay(10000000);
			*GPIOFDATA = 0x04U;
			delay(10000000);
			*GPIOFDATA = 0x08U;
			delay(10000000);
//       *GPIOFDATA = 0x02U;
    }
}
