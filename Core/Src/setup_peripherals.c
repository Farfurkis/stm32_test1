#include "setup_peripherals.h"
#include "engine-control.h"

static DEVICES devices;

DEVICES* setup_engine1(TIM_HandleTypeDef *controlling_timer, const uint8_t controlling_channel) {
	devices.engine1 = engine_configure(controlling_timer, controlling_channel);
	return &devices;
}

DEVICES* setup_engine2(TIM_HandleTypeDef *controlling_timer, const uint8_t controlling_channel) {
	devices.engine2 = engine_configure(controlling_timer, controlling_channel);
	return &devices;
}

DEVICES* setup_battery() {
	// Not implemented yet
	return &devices;
}

DEVICES* setup_display() {
	// Not implemented yet
	return &devices;
}
