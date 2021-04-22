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
	uint8_t leds;
	uint8_t lamps;
	bool switch_0: 1;
	bool switch_1: 1;
}GPIO_STATUS;

void inicializaGPIO(void);
void saidasGPIO(void *pvParameter);
uint8_t getLedStatus(void);
uint8_t getLampStatus(void);

#endif /* MAIN_GPIO_CONFIGGPIO_H_ */
