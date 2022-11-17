# Copyright (c) 2021 Teslabs Engineering S.L.
# SPDX-License-Identifier: Apache-2.0

# Add *.h to global include paths
zephyr_include_directories(src)

zephyr_library()
zephyr_library_sources_ifdef(CONFIG_SPINNER_SVPWM_STM32 src/svpwm_stm32.c)

