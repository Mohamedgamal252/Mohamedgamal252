/*
 * project2.c
 *
 * Created: 9/6/2023 1:58:20 PM
 * Author : m
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "std_macros.h"
#include "Sys.h"
ISR(INT2_vect){
	if(Curr_state==OFF){
		Curr_state = ON;
		desired_temp = EEPROM_read(0x0000);
	}
	else if (Curr_state==ON || Curr_state==SETTING){
		Curr_state = OFF;
	}
}
ISR(TIMER1_COMPA_vect){
	temp_measure_f = 1;
}
ISR(TIMER0_COMP_vect){
	if ((Curr_state==SETTING) || (Curr_state==ON)){
		setting_counter++;
		if(setting_counter % 4 == 0){
			toggle_f ^= 1;
		}
		if (setting_counter > 20){
			
			
			Curr_state = ON;
		}
	}
}

int main(void)
{
   sys_init();
    while (1) 
    {
    switch (Curr_state){
	    case ON:{
		    ON_state();
		    break;
	    }
	    case OFF:{
		    OFF_state();
		    break;
	    }
	    case SETTING:{
		    SET_state();
		    break;
	    }
    }
    }
    }