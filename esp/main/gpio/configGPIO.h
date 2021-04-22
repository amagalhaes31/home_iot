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
	bool ledOn: 1;
	bool dhtStatus: 1;
	uint8_t lamp;
	bool switch_0: 1;
	bool switch_1: 1;
}GPIO_STATUS;

void inicializaGPIO(void);
void leds (void *pvParameter);
bool getLedEthernet(void);
bool getDhtStatus(void);
uint8_t getLampStatus(void);

#endif /* MAIN_GPIO_CONFIGGPIO_H_ */
