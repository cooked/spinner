# Copyright 2022 Stefano Cottafavi <stefano.cottafavi@gmail.com>.
# SPDX-License-Identifier: Apache-2.0

list(APPEND ZEPHYR_EXTRA_MODULES
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../drivers/svpwm
	${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/svm
	${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/utils
)

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(svpwm LANGUAGES C VERSION 1.0.0)

target_sources(app PRIVATE 
    src/main.c
    src/svm_shell.c
)
