/*
 * Timer.c
 *
 * Created: 9/6/2023 5:08:12 PM
 *  Author: m
 */ 
 #include "Timer.h"
 
 void timer1_init(){
	
	set_bit(TCCR1B,WGM12);
	OCR1AH = 0b00000000;
	OCR1AL = 0b01100010;
	set_bit(TCCR1B,CS10);
	clr_bit(TCCR1B,CS11);
	set_bit(TCCR1B,CS12);
	sei();

}



void timer0_init(){
	
	
	set_bit(TCCR0,WGM01);
	OCR0 = 250;
	set_bit(TCCR0,CS00);
	set_bit(TCCR0,CS02);
	sei();
	set_bit(TIMSK,OCIE0);
	
}



void timer1_INT_disable(){
	
	clr_bit(TIMSK,OCIE1A);
	
}



void timer1_INT_enable(){
	set_bit(TIMSK,OCIE1A);
}