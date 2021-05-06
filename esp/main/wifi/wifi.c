/*
 * wifi.c
 *
 *  Created on: 4 de mai. de 2021
 *      Author: Alexandre Magalhães
 */


#include "wifi.h"

#define ESP_WIFI_SSID 	"Magalhaes"
#define ESP_WIFI_PASS 	"magal2020"

WIFI_STATUS wifiStatus;
static const char *TAG = "wifi: ";


/*
 * Seta o status da conexão WiFi
*/
void setWifiStatus(bool status) {
	wifiStatus.status = status;
}

/*
 * Informa o status da conexão WiFi
*/
bool getWifiStatus(void) {
	return wifiStatus.status;
}


/*
 * Função de callback responsável por receber as notificações do wifi durante o processo de conexão com a rede ethernet
*/
esp_err_t event_handler(void *ctx, system_event_t *event) {
    switch(event->event_id) {

    	// WiFi configurado com sucessp
		case SYSTEM_EVENT_STA_START:
			// WiFi desconectado
			setWifiStatus(false);
			// Inicializa a conexão com o roteador WiFi
			esp_wifi_connect();
			break;

		// Conexão com o roteador estabelecida
		case SYSTEM_EVENT_STA_GOT_IP:
			// WiFi conectado
			setWifiStatus(true);
			// Imprime o endereço IP do ESP32
			ESP_LOGI(TAG, "got ip:%s", ip4addr_ntoa(&event->event_info.got_ip.ip_info.ip));
			break;

		// Quando houver falha de conexão WiFi
		case SYSTEM_EVENT_STA_DISCONNECTED:
			// WiFi desconectado
			setWifiStatus(false);
			// Inicializa a conexão com o roteador WiFi
			esp_wifi_connect();

			break;

		default:
			break;
    }

    return ESP_OK;
}

/*
 * Configura a pilha WiFi no modo Station (STA)
*/
void wifi_init_sta(void) {
    tcpip_adapter_init();

    ESP_ERROR_CHECK(esp_event_loop_init(event_handler, NULL) );

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    wifi_config_t wifi_config = {
        .sta = {
            .ssid = ESP_WIFI_SSID,
            .password = ESP_WIFI_PASS
        },
    };

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA) );
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config) );
    ESP_ERROR_CHECK(esp_wifi_start() );

    ESP_LOGI(TAG, "wifi_init_sta ok.");
    ESP_LOGI(TAG, "Connect to ap SSID:%s password:%s", ESP_WIFI_SSID, ESP_WIFI_PASS);
}

/*
 * Inicializa o modo WiFi do ESP32
*/
void inicializaWifi(void) {

	// WiFi desconectado
	setWifiStatus(false);
	// Inicializa a configuração do WiFi
	wifi_init_sta();
}
