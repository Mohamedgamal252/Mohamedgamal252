/*
 * SSD_disp.c
 *
 * Created: 9/6/2023 5:00:31 PM
 *  Author: m
 */ 
#include "SSD_disp.h"

uint8_t Nums[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void SSD_init(void){
	
	
	SSD_PORT_DIR = 0xFF;
	set_bit(SSD_ENABLE_PORT_DIR,SSD1_ENABLE_PIN);
	set_bit(SSD_ENABLE_PORT_DIR,SSD2_ENABLE_PIN);
	
	
	SSD_disable();
	
}

void SSD_send(uint16_t N){
	SSD_DATA = Nums[N];
}
void SSD_enable(uint8_t disp){
	if(disp == 1){
		set_bit(SSD_ENABLE_PORT,SSD1_ENABLE_PIN);
		clr_bit(SSD_ENABLE_PORT,SSD2_ENABLE_PIN);
	}
	else if (disp == 2){
		set_bit(SSD_ENABLE_PORT,SSD2_ENABLE_PIN);
		clr_bit(SSD_ENABLE_PORT,SSD1_ENABLE_PIN);
	}
}
void SSD_disable(void){
	clr_bit(SSD_ENABLE_PORT,SSD1_ENABLE_PIN);
	clr_bit(SSD_ENABLE_PORT,SSD2_ENABLE_PIN);
}
void SSD_turn_off(void){
	SSD_DATA = 0x00;
}
void SSD_write(uint16_t N){
	uint8_t units;
	uint8_t tens;
	
	units = N % 10;
	tens = (int) N / 10;
	
	SSD_enable(DISP1);
	SSD_send(units);
	_delay_ms(5);
	
	SSD_enable(DISP2);
	SSD_send(tens);
	_delay_ms(5);
}