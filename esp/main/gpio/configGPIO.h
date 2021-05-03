/*
 * configGPIO.h
 *
 *  Created on: 13 de abr. de 2021
 *      Author: Alexandre Magalhães
 */

#ifndef MAIN_GPIO_CONFIGGPIO_H_
#define MAIN_GPIO_CONFIGGPIO_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct {
	uint8_t switch0 : 1;
	uint8_t switch1 : 1;
	uint8_t switch2 : 1;
	uint8_t sensor0 : 1;
	uint8_t sensor1 : 1;
}GPIO_INPUTS;

typedef struct {
	uint8_t leds;
	uint8_t lamps;
	GPIO_INPUTS gpioInputs;
}GPIO_STATUS;


uint8_t getLedStatus(void);
uint8_t getLampStatus(void);
void setInputsStatus(GPIO_INPUTS inputs);
GPIO_INPUTS getInputsStatus(void);
void inicializaGPIO(void);
void saidasGPIO(void *pvParameter);
void entradasGPIO(void *pvParameter);

#endif /* MAIN_GPIO_CONFIGGPIO_H_ */
