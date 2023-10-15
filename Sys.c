/*
 * Sys.c
 *
 * Created: 9/6/2023 5:04:26 PM
 *  Author: m
 */ 
#include "Sys.h"

void sys_init(void){
	
	ADC_init();
	Buttons_init();
	cool_init();
	heat_init();
	led_init();
	SSD_init();
	timer0_init();
	timer1_init();
	timer1_INT_enable();
	
	
	Curr_state = OFF;
	
	
	if(EEPROM_read(0x0000) != 0xFF){
		desired_temp = EEPROM_read(0x0000);
	}
	else{
		desired_temp = INIT_DESIRED_TEMP;
	}
	
	temp_arr_init();
	
	
	EEPROM_write(0x0000,(uint8_t) desired_temp);	
	
}



void OFF_state(void){
		SSD_turn_off();
		led_off();
		heat_stop();
		cool_stop();
		go_to_sleep();
}



void ON_state(void){
	
	
		
	if (temp_measure_f == 1){
		actual_temp = (ADC_read()*0.5);
		add_new_temp(temp_arr , actual_temp);
		avg_temp = calc_avg_temp(temp_arr);	
		temp_measure_f = 0;
	}
	
	SSD_write(actual_temp);
	
	
	change_temp();
	 
	
	
	if(UP_pressed()==PRESSED || DOWN_pressed()==PRESSED){

		SSD_disable();
		setting_counter = 0;
		Curr_state = SETTING;
			
	}
}


void SET_state(void){
	heat_stop();
	cool_stop();
	led_off();
	
	
	if(toggle_f == 1){
		SSD_write(desired_temp);
	}
	else{
		SSD_turn_off();
	}
	
	
	
	if((UP_pressed() == PRESSED) && (desired_temp < MAX_TEMP)){
		desired_temp = desired_temp + 5;
		setting_counter = 0;
		SSD_write(desired_temp);
	}
	else if ((DOWN_pressed() == PRESSED) && (desired_temp > MIN_TEMP)){
		desired_temp = desired_temp - 5;
		setting_counter = 0;
		SSD_write(desired_temp);
	}
	
	EEPROM_write(0x0000,desired_temp);
	
}


void change_temp(void){
	if( (desired_temp < avg_temp + MARGIN_TEMP) && (desired_temp > avg_temp - MARGIN_TEMP) ){
		
		heat_stop();
		cool_stop();
		led_off();
	}
	else if(desired_temp < avg_temp + MARGIN_TEMP){
		
		
		heat_stop();
		cool_start();
		led_on();
	}
	else if (desired_temp > avg_temp - MARGIN_TEMP){
	
		
		heat_start();
		cool_stop();
		if (toggle_f == 1)
		{
			led_on();
		}
		else {
			led_off();
		}
	}
}



void temp_arr_init(void){
	uint16_t first_temp = ADC_read()*0.5;
	
	for (uint8_t i = 0; i<NUM_OF_TEMP_MEASURES; i++){
		temp_arr[i]= first_temp;
	}
	
	avg_temp = calc_avg_temp(temp_arr);
	arr_counter = 0;
}


void add_new_temp(uint16_t * arr , uint16_t new_val){
	arr[arr_counter] = new_val;
	arr_counter ++;
	
	if (arr_counter == 10){
		arr_counter = 0;
	}
}



uint16_t calc_avg_temp(uint16_t * arr){
	uint16_t sum = 0;
	uint16_t avg;
	
	for(uint8_t i=0; i<NUM_OF_TEMP_MEASURES; i++){
		sum = sum + arr[i];
	}
	avg = (uint16_t) sum / NUM_OF_TEMP_MEASURES;
	return avg;
}



void go_to_sleep(void){
	
	MCUCR&=~(1<<SM0);
	MCUCR&=~(1<<SM1);
	MCUCR&=~(1<<SM2);
	
	MCUCR|=(1<<SE);

}