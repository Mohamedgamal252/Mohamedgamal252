/*
 * Cool_Heat_Elements.c
 *
 * Created: 9/6/2023 4:39:30 PM
 *  Author: m
 */ 
#include "std_macros.h"
#include "Cool_Heat_Elements.h"

void heat_init(void){
	set_bit(HEAT_PORT_DIR,HEAT_PIN);
}

void cool_init(void){
	set_bit(COOL_PORT_DIR,COOL_PIN);
}

void heat_start(void){
	set_bit(HEAT_PORT,HEAT_PIN);
}

void cool_start(void){
	set_bit(COOL_PORT,COOL_PIN);
}
void heat_stop(void){
	clr_bit(HEAT_PORT,HEAT_PIN);
}

void cool_stop(void){
	clr_bit(COOL_PORT,COOL_PIN);
}
