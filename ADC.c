/*
 * ADC.c
 *
 * Created: 9/6/2023 2:24:52 PM
 *  Author: m
 */ 

#include "ADC.h"
#include <util/delay.h>

void ADC_init(){
	
	 set_bit(ADMUX,REFS0);
	 clr_bit(ADMUX,MUX0);
	 clr_bit(ADMUX,MUX1);
	 clr_bit(ADMUX,MUX2);
	 clr_bit(ADMUX,MUX3);
	 clr_bit(ADMUX,MUX4);
	 clr_bit(ADMUX,ADLAR);
	
	 ADCSRA |=(1<<ADEN);
	 ADCSRA |=(1<<ADPS0);
	
}

uint16_t ADC_read(){
	
	uint16_t data = 0;
	ADCSRA |=(1<<ADSC);
	
	while(read_bit(ADCSRA,ADIF)==0) 
	{    
	}
	_delay_us(10);
	
	data = ADCL;
	data |= (ADCH<<8);
	return data;
}