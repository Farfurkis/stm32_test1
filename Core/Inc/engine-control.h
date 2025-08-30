/*
 * Engine control interface
 */

#ifndef INC_ENGINE_CONTROL_H_
#define INC_ENGINE_CONTROL_H_
#include <stdint.h>

#include "main.h"

#define MAX_DRIVE_SPEED 100
#define MIN_DRIVE_SPEED 0

typedef struct {
    TIM_HandleTypeDef *timer;
    uint8_t channel;
    uint8_t drive_speed;
} PWM_ENGINE;

PWM_ENGINE configure_engine(TIM_HandleTypeDef *controlling_timer, uint8_t controlling_channel);

/**
 * Start engine at preconfigured speed, run for specified period of time, stop
 * @param engine
 * @param period_milliseconds
 */
void run_timed(const PWM_ENGINE *engine, uint16_t period_milliseconds);

/**
 *
 * @param speed Desired engine speed
 */
void set_speed(PWM_ENGINE *engine, uint8_t speed);

/**
 * Stop all engine operations immediately. Disable possible operations until explicit lock removal
 * by operations_enable() execution.
 */
void emergency_stop(PWM_ENGINE *engine);

/**
 * Enables operations with engine, generally for two cases:
 * 1. After it's initialization completion
 * 2. Restore after emergency stop
 */
void operations_enable();

#endif /* INC_ENGINE_CONTROL_H_ */
