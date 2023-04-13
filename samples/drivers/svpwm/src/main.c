/**
 * Copyright 2022 Stefano Cottafavi <stefano.cottafavi@gmail.com>.
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#include "svm.h"
#include "svpwm.h"

#define SLEEP_TIME_MS   10
#define LED0_NODE DT_ALIAS(led0)
#define SW00_NODE DT_ALIAS(sw0)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec btn = GPIO_DT_SPEC_GET(SW00_NODE, gpios);

const struct device *svpwm;
svm_t svm;

static uint8_t lut[1000] = {
	50,53,56,59,62,65,68,71,74,77,
	79,82,84,86,89,90,92,94,95,96,
	98,98,99,100,100,100,100,100,99,98,
	98,96,95,94,92,90,89,86,84,82,
	79,77,74,71,68,65,62,59,56,53,
	50,47,44,41,38,35,32,29,26,23,
	21,18,16,14,11,10,8,6,5,4,
	2,2,1,0,0,0,0,0,1,2,
	2,4,5,6,8,10,11,14,16,18,
	21,23,26,29,32,35,38,41,44,47,
};

void main(void) {

	svpwm = DEVICE_DT_GET(DT_NODELABEL(svpwm));

	int ret;
	uint8_t ilut= 0;

	if (!device_is_ready(led.port)) {
		return;
	}

	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return;
	}

	
	svpwm_start(svpwm);

	while(1) {

		if(ilut==100)
			ilut=0;
		else
			ilut++;

		svpwm_set_phase_voltages(svpwm, 0.f, lut[ilut]/100.0f);

		ret = gpio_pin_toggle_dt(&led);
		if (ret < 0) {
			return;
		}

		k_msleep(SLEEP_TIME_MS);
	}
}
