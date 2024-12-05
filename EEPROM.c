/*
 * EEPROM.c
 *
 * Created: 9/6/2023 4:42:17 PM
 *  Author: m
 */ 
#include "EEPROM.h"

unsigned char EEPROM_read(const unsigned short addr){
	
	EEARL = (char)addr;
	EEARH = (char)(addr>>8);
	
	set_bit(EECR,EERE);
	return EEDR;
}
void EEPROM_write(const unsigned short addr, unsigned char data){
	unsigned char INT_EN=0;
	
	EEARL = (char)addr;
	EEARH = (char)(addr>>8);
	EEDR = data;
	set_bit(EECR,EEMWE);
	set_bit(EECR,EEWE);
	while(((EECR&(1<<EEWE))>>EEWE)==1);
	
	
	if (INT_EN==1)
	{
		set_bit(SREG,7);
	}
	
}