/*
 * wifi.h
 *
 *  Created on: 4 de mai. de 2021
 *      Author: Alexandre Magalhães
 */

#ifndef MAIN_WIFI_WIFI_H_
#define MAIN_WIFI_WIFI_H_

#include <stdio.h>
#include <errno.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "esp_system.h"
#include "esp_log.h"
#include "lwip/err.h"
#include "lwip/sys.h"
#include "lwip/sockets.h"

typedef struct {
	bool status;
} WIFI_STATUS;

void setWifiStatus (bool status);
bool getWifiStatus (void);
esp_err_t event_handler(void *ctx, system_event_t *event);
void wifi_init_sta(void);
void inicializaWifi(void);

#endif /* MAIN_WIFI_WIFI_H_ */
