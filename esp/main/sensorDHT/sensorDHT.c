/*
 * sensorDHT.c
 *
 *  Created on: 3 de mai. de 2021
 *      Author: Alexandre Magalhães
 */

#include <stdio.h>
#include "freertos/FreeRTOSConfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sensorDHT.h"
#include "dht.h"
#include "../hardwareDefinitions.h"
#include "../debug.h"


static const dht_sensor_type_t sensor_type = DHT_TYPE_DHT11;
DHT_MEDIDAS dhtMedida;


DHT_MEDIDAS getDHTMedidas (void) {
	return dhtMedida;
}

void leituraSensorDHT (void *pvParameters) {

    gpio_set_pull_mode(SENSOR_DHT, GPIO_PULLUP_ONLY);

    while (1)
    {
        if (dht_read_data(sensor_type, SENSOR_DHT, &dhtMedida.umidade, &dhtMedida.temperatura) == ESP_OK) {
        	if (DEBUG_DHT)
        		printf("Umidade: %d%% Temperatura: %dC\n", dhtMedida.umidade / 10, dhtMedida.temperatura / 10);
        }
        else {
        	if (DEBUG_DHT)
        		printf("Falha na leitura do sensor DHT11 \n");
        }

        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }

}

void inicializaSensorDHT (void) {

	xTaskCreate(leituraSensorDHT, "leituraSensorDHT", configMINIMAL_STACK_SIZE * 3, NULL, 2, NULL);
}

