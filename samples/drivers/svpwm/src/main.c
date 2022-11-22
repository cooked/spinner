/**
 * Copyright 2022 Stefano Cottafavi <stefano.cottafavi@gmail.com>.
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#include "svm.h"
#include "svpwm.h"

#define SLEEP_TIME_MS   1000
#define LED0_NODE DT_ALIAS(led0)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);


const struct device *svpwm;
svm_t svm;

void main(void) {

	svpwm = DEVICE_DT_GET(DT_NODELABEL(svpwm));

	int ret;

	if (!device_is_ready(led.port)) {
		return;
	}

	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return;
	}

	
	svpwm_start(svpwm);
	svpwm_set_phase_voltages(svpwm, 0.5f, 0.5f);

	while(1) {
		
		ret = gpio_pin_toggle_dt(&led);
		if (ret < 0) {
			return;
		}

		k_msleep(SLEEP_TIME_MS);
	}
}
