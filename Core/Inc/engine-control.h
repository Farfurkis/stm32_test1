/*
 * Engine control interface
 */

#ifndef INC_ENGINE_CONTROL_H_
#define INC_ENGINE_CONTROL_H_
#include <stdbool.h>
#include <stdint.h>

#include "main.h"

// TODO: introduce STOP_DRIVE_SPEED as MIN_DRIVE_SPEED physically means that it is minimal operation speed but not 0.
#define MAX_DRIVE_SPEED 100
#define MIN_DRIVE_SPEED 0

typedef struct {
    TIM_HandleTypeDef *timer; // Timer responsible for cotrolling engine's duty cycles
    uint8_t channel;     // Timer channel
    uint8_t drive_speed; // Speed at which engine should work, in range from MIN_DRIVE_SPEED to MAX_DRIVE_SPEED
    uint16_t periodsToRun; // How many interrupting timer periods engine should run before stop
    bool locked;         // false if engine is ready to starts
} PWM_ENGINE;

PWM_ENGINE engine_configure(TIM_HandleTypeDef *controlling_timer, uint8_t controlling_channel);

/**
 * Start engine at preconfigured speed, run for specified period of time, stop
 * @param engine
 * @param periods
 */
void engine_run_timed(PWM_ENGINE *engine, uint16_t periods);

/**
 * Stop engine, function works in other manner than emergency_stop:
 * engine doesn't locked after stopping and it's speed remains unchanged.
 * @param engine
 */
void engine_stop(const PWM_ENGINE *engine);

/**
 *
 * @param speed Desired engine speed
 */
void engine_set_speed(PWM_ENGINE *engine, uint8_t speed);

/**
 * Stop all engine operations immediately. Disable possible operations until explicit lock removal
 * by operations_enable() execution.
 */
void engine_emergency_stop(PWM_ENGINE *engine);

/**
 * Enables operations with engine, generally for two cases:
 * 1. After it's initialization completion
 * 2. Restore after emergency stop
 */
void operations_enable();

#endif /* INC_ENGINE_CONTROL_H_ */
