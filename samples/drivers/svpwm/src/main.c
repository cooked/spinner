/**
 * Copyright 2022 Stefano Cottafavi <stefano.cottafavi@gmail.com>.
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>

#include "svm.h"

const struct device *svpwm;
svm_t svm;

void main(void) {

	svpwm = DEVICE_DT_GET(DT_NODELABEL(svpwm));

	//svpwm_start(svpwm);

	while(1) {
		
		k_msleep(100);

	}
}
