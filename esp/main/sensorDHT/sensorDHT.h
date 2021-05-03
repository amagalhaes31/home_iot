/*
 * sensorDHT.h
 *
 *  Created on: 3 de mai. de 2021
 *      Author: Alexandre Magalhães
 */

#ifndef MAIN_SENSORDHT_SENSORDHT_H_
#define MAIN_SENSORDHT_SENSORDHT_H_

typedef struct {
    int16_t umidade;
    int16_t temperatura;
} DHT_MEDIDAS;

DHT_MEDIDAS getDHTMedidas (void);
void leituraSensorDHT (void *pvParameters);
void inicializaSensorDHT (void);

#endif /* MAIN_SENSORDHT_SENSORDHT_H_ */
