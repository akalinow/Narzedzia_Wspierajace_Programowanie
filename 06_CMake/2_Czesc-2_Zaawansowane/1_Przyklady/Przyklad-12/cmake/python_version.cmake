# Zaadaptowano z:
# https://github.com/bast/cmake-example/blob/master/cmake/git_revision.cmake

# Copyright (c) 2014-2018 by Radovan Bast.
# All rights reserved.

# Licencja:
# BSD 3-Clause "New" or "Revised" License
# https://github.com/bast/cmake-example/blob/master/LICENSE

find_package(Python)

if(PYTHON_FOUND)
    execute_process(
        COMMAND ${PYTHON_EXECUTABLE} --version
        OUTPUT_VARIABLE PYTHON_VERSION
        ERROR_QUIET
        )
    if(NOT ${PYTHON_VERSION} STREQUAL "")
        string(STRIP ${PYTHON_VERSION} PYTHON_VERSION)
    endif()
    message(STATUS "Wersja Python: ${PYTHON_VERSION}")
else()
    set(PYTHON_VERSION "unknown")
endif()