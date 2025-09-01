#include "engine-control.h"

#include "stm32l1xx_hal_tim.h"

PWM_ENGINE engine_configure(TIM_HandleTypeDef *controlling_timer, const uint8_t controlling_channel) {
    PWM_ENGINE engine;
    engine.channel = controlling_channel;
    engine.drive_speed = MIN_DRIVE_SPEED;
    engine.timer = controlling_timer;
    return engine;
}

void engine_run_timed(PWM_ENGINE *engine, const uint16_t periods) {
    if (engine->drive_speed > MIN_DRIVE_SPEED && engine->drive_speed <= MAX_DRIVE_SPEED) {
        // frequency = 32MHz, prescaler = 32
        // so we have duty_values range from 0 to 1000
        uint32_t duty_value = engine->drive_speed-1;
        __HAL_TIM_SET_COMPARE(engine->timer, engine->channel, duty_value);
        engine->periodsToRun = periods;
    }
}

void engine_stop(const PWM_ENGINE *engine) {
    __HAL_TIM_SET_COMPARE(engine->timer, engine->channel, 0);
}

void engine_set_speed(PWM_ENGINE *engine, uint8_t speed) {
    if (speed > MAX_DRIVE_SPEED) {
        speed = MAX_DRIVE_SPEED;
    } else if (speed < MIN_DRIVE_SPEED) {
        speed = MIN_DRIVE_SPEED;
    }
    engine->drive_speed = speed;
}

void engine_emergency_stop(PWM_ENGINE *engine) {
    engine->drive_speed = MIN_DRIVE_SPEED;
    __HAL_TIM_SET_COMPARE(engine->timer, engine->channel, 0);
    // TODO: consider to set engine onto break mode for a while, maybe it'll stop faster. If it is reasonable, of course.
}

void operations_enable() {

}