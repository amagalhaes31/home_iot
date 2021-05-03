/*
 * hardwareDefinitions.h
 *
 *  Created on: 3 de mai. de 2021
 *      Author: Alexandre Magalhães
 */

#ifndef MAIN_HARDWAREDEFINITIONS_H_
#define MAIN_HARDWAREDEFINITIONS_H_

// Definições do hardware
#define LED_ETH 	GPIO_NUM_2
#define LED_DHT 	GPIO_NUM_15
#define LED_SENSOR	GPIO_NUM_16
#define LAMP_0 		GPIO_NUM_17
#define LAMP_1 		GPIO_NUM_18
#define LAMP_2 		GPIO_NUM_19

#define SWITCH_0	GPIO_NUM_34
#define SWITCH_1	GPIO_NUM_36
#define SWITCH_2	GPIO_NUM_39
#define SENSOR_DHT	GPIO_NUM_27
#define SENSOR_0	GPIO_NUM_26
#define SENSOR_1	GPIO_NUM_32

#define GPIO_OUTPUT_PIN_SEL ((1ULL<<LED_ETH)|(1ULL<<LED_DHT)|(1ULL<<LED_SENSOR)|(1ULL<<LAMP_0)|(1ULL<<LAMP_1)|(1ULL<<LAMP_2))
#define GPIO_INPUT_PIN_SEL  ((1ULL<<SWITCH_0)|(1ULL<<SWITCH_1)|(1ULL<<SWITCH_2)|(1ULL<<SENSOR_0)|(1ULL<<SENSOR_1))

#endif /* MAIN_HARDWAREDEFINITIONS_H_ */
