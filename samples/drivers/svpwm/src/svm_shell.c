/**
 * Copyright 2022 Stefano Cottafavi <stefano.cottafavi@gmail.com>.
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdlib.h>

#include <zephyr/shell/shell.h>

#include "svpwm.h"

extern const struct device *svpwm;

static int cmd_svpwm_start(const struct shell *shell, size_t argc, char **argv)
{
	ARG_UNUSED(shell);
	ARG_UNUSED(argc);
	ARG_UNUSED(argv);

	svpwm_start(svpwm);

	return 0;
}

static int cmd_svpwm_stop(const struct shell *shell, size_t argc, char **argv)
{
	ARG_UNUSED(shell);
	ARG_UNUSED(argc);
	ARG_UNUSED(argv);

	svpwm_stop(svpwm);

	return 0;
}

static int cmd_svpwm_set(const struct shell *shell, size_t argc, char **argv)
{
	if (argc != 2) {
		shell_help(shell);
		return -EINVAL;
	}

	/* NOTE: i_d = 0, assuming PMSM */
	//cloop_set_ref(0.0f, strtof(argv[1], NULL));
	int v_alpha = 1;
	int v_beta = 0;
	svpwm_set_phase_voltages(svpwm, v_alpha, v_beta);

	return 0;
}

SHELL_STATIC_SUBCMD_SET_CREATE(
	sub_svpwm,
	SHELL_CMD(start, NULL, "Start SV-PWM", cmd_svpwm_start),
	SHELL_CMD(stop, NULL, "Stop SV-PWM", cmd_svpwm_stop),
	SHELL_CMD(set, NULL, "Set SV-PWM value", cmd_svpwm_set),
	SHELL_SUBCMD_SET_END);

SHELL_CMD_REGISTER(svpwm, &sub_svpwm, "SV-PWM Control", NULL);
