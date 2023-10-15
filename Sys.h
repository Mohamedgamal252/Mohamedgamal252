/*
 * Sys.h
 *
 * Created: 9/6/2023 5:04:07 PM
 *  Author: m
 */ 


#ifndef SYS_H_
#define SYS_H_

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Sys_Config.h"
#include "std_macros.h"
#include "ADC.h"
#include "Buttons.h"
#include "Cool_Heat_Elements.h"
#include "LED.h"
#include "SSD_disp.h"
#include "Timer.h"
#include "EEPROM.h"

#define OFF 0
#define ON 1
#define SETTING 2



void sys_init(void);
void ON_state(void);
void OFF_state(void);
void SET_state(void);

void change_temp(void);
void add_new_temp(uint16_t * arr , uint16_t new_val);
uint16_t calc_avg_temp(uint16_t * arr);
void temp_arr_init(void);
void go_to_sleep(void);


uint8_t Curr_state;
uint16_t temp_arr[NUM_OF_TEMP_MEASURES];
uint16_t desired_temp;
uint16_t actual_temp;
uint16_t avg_temp;

uint8_t temp_measure_f;
uint8_t temp_measure_counter;
uint8_t setting_counter;

uint16_t toggle_f;
uint8_t arr_counter;



#endif /* SYS_H_ */