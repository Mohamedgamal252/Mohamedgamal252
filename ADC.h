/*
 * ADC.h
 *
 * Created: 9/6/2023 2:25:05 PM
 *  Author: m
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include "std_macros.h"

void ADC_init(void);
uint16_t ADC_read(void);

#endif /* ADC_H_ */