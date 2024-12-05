/*
 * LED.c
 *
 * Created: 9/6/2023 4:58:46 PM
 *  Author: m
 */ 
#include "LED.h"

 void led_init(void){
	 
	 set_bit(LED_PORT_DIR,LED_PIN);
	 clr_bit(LED_PORT,LED_PIN);

 }
 void led_on(void){
	 set_bit(LED_PORT,LED_PIN);
 }

 void led_off(void){
	 clr_bit(LED_PORT,LED_PIN);
 }