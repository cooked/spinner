# Copyright (c) 2021 Teslabs Engineering S.L.
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_SPINNER_CLOOP)
  # Add *.h to global include paths
  zephyr_include_directories(src)

  zephyr_library()
  zephyr_library_sources(src/cloop.c)
  zephyr_library_sources_ifdef(CONFIG_SPINNER_CLOOP_SHELL src/cloop_shell.c)
endif()

