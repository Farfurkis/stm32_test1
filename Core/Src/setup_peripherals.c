#include "setup_peripherals.h"
#include "engine-control.h"

DEVICES devices;

DEVICES setup_engine(TIM_HandleTypeDef *controlling_timer, const uint8_t controlling_channel) {
	devices.engine = configure_engine(controlling_timer, controlling_channel);
	return devices;
}

DEVICES setup_battery() {
	// Not implemented yet
	return devices;
}

DEVICES setup_display() {
	// Not implemented yet
	return devices;
}
