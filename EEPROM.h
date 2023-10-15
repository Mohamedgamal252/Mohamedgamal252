/*
 * EEPROM.h
 *
 * Created: 9/6/2023 4:42:04 PM
 *  Author: m
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include <avr/io.h>
#include "std_macros.h"

void EEPROM_write(const unsigned short addr, unsigned char data);
unsigned char EEPROM_read(const unsigned short addr);



#endif 