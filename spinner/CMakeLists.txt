#-------------------------------------------------------------------------------
# Spinner
#
# Copyright (c) 2021 Teslabs Engineering S.L.
# SPDX-License-Identifier: Apache-2.0
list(APPEND ZEPHYR_EXTRA_MODULES
    # drivers
	${CMAKE_CURRENT_SOURCE_DIR}/../drivers/currsmp
    ${CMAKE_CURRENT_SOURCE_DIR}/../drivers/feedback
    ${CMAKE_CURRENT_SOURCE_DIR}/../drivers/svpwm
    # libraries
	${CMAKE_CURRENT_SOURCE_DIR}/../lib/control
	${CMAKE_CURRENT_SOURCE_DIR}/../lib/svm
	${CMAKE_CURRENT_SOURCE_DIR}/../lib/utils
)

# But this works! And it keeps the current merging of existing config files
# intact! Hurray!!!
#list(APPEND OVERLAY_CONFIG
#	$ENV{BASE_DIR}/drivers_and_libraries/backend/backend.conf
#	$ENV{BASE_DIR}/drivers_and_libraries/lpwan/nbiot/nbiot.conf
#	$ENV{BASE_DIR}/drivers_and_libraries/sensors/mlx90393/mlx90393.conf
#)

list(APPEND BOARD_ROOT 
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

cmake_minimum_required(VERSION 3.13.1)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(spinner LANGUAGES C VERSION 1.0.0)


#-------------------------------------------------------------------------------
# Options
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

zephyr_include_directories(../include)

#-------------------------------------------------------------------------------
# Application

target_sources(app PRIVATE 
    src/main.c
)
