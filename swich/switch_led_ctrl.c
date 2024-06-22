/*
excersites in https://users.ece.utexas.edu/~valvano/Volume1/E-Book/C8_SwitchLED.htm
gpio data reg A 0x40004000 
GPIO PA5 -> 0x40004000 + 80 (which comes from setting 5 bit form [9:2] discribed in page 654
gpio clock register 0x400FE000 offset 608 set 01
GPIO A enable -> 0x40004000 ox51c -> set 20
GPIO A dir -> 0x40004000 offset 0x400 -> set ~20
*/

#define GPIO_PORTA_BIT_5 (*((volatile unsigned long *)0x40004080))
#define GPIO_CLOCK (*((volatile unsigned long *)0x400FE608))
#define GPIO_A_DIR (*((volatile unsigned long *)0x40004400))
#define GPIO_A_ENABLE (*((volatile unsigned long *)0x4000451c))

int main() {
	GPIO_CLOCK |= 0x00000001;
	volatile unsigned long delay;
	delay = GPIO_CLOCK;
	GPIO_A_DIR &= ~0x20;
	GPIO_A_ENABLE |= 0x20;
	
	while(1) {
		unsigned int currentdata;
		currentdata = GPIO_PORTA_BIT_5;
	}		
	
	
}
