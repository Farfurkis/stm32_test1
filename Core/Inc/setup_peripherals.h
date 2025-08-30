/*
 * Peripheral initialization logic
 */

#ifndef INC_SETUP_PEIRHEPALS_H_
#define INC_SETUP_PERIPHERALS_H_
#include "engine-control.h"

typedef struct {
    PWM_ENGINE engine;
} DEVICES;

DEVICES* setup_engine(TIM_HandleTypeDef *controlling_timer, uint8_t controlling_channel);
DEVICES* setup_battery();
DEVICES* setup_display();


#endif /* INC_SETUP_PEIRHEPALS_H_ */
