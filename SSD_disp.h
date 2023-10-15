/*
 * SSD_disp.h
 *
 * Created: 9/6/2023 5:00:16 PM
 *  Author: m
 */ 


#ifndef SSD_DISP_H_
#define SSD_DISP_H_

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "std_macros.h"



#define DISP1 1
#define DISP2 2

#define SSD_ENABLE_PORT_DIR DDRB
#define SSD_ENABLE_PORT PORTB
#define SSD1_ENABLE_PIN 6
#define SSD2_ENABLE_PIN 7
#define SSD_DATA PORTD
#define SSD_PORT_DIR DDRD


void SSD_init(void);
void SSD_send(uint16_t N);
void SSD_enable(uint8_t disp);
void SSD_disable(void);
void SSD_turn_off(void);
void SSD_write(uint16_t N);



#endif /* SSD_DISP_H_ */