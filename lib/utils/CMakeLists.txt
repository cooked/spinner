# Copyright (c) 2021 Teslabs Engineering S.L.
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_SPINNER_UTILS_STM32)
  # Add *.h to global include paths
  zephyr_include_directories(src)

  zephyr_library()
  zephyr_library_sources(src/stm32_tim.c src/stm32_adc.c)
endif()
