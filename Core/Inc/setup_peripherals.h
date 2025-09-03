/*
 * Peripheral initialization logic
 */

#ifndef INC_SETUP_PEIRHEPALS_H_
#define INC_SETUP_PERIPHERALS_H_
#include "engine-control.h"

typedef struct {
    PWM_ENGINE engine1;
    PWM_ENGINE engine2;
} DEVICES;

DEVICES* setup_engine1(TIM_HandleTypeDef *controlling_timer, uint8_t controlling_channel);
DEVICES* setup_engine2(TIM_HandleTypeDef *controlling_timer, uint8_t controlling_channel);
DEVICES* setup_battery();
DEVICES* setup_display();
DEVICES* setup_start_button();
DEVICES* setup_emergency_stop_button();

#endif /* INC_SETUP_PEIRHEPALS_H_ */
