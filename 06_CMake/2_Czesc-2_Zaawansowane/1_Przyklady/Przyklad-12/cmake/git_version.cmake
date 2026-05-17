# Zaadaptowano z:
# https://github.com/bast/cmake-example/blob/master/cmake/git_revision.cmake

# Copyright (c) 2014-2018 by Radovan Bast.
# All rights reserved.

# Licencja:
# BSD 3-Clause "New" or "Revised" License
# https://github.com/bast/cmake-example/blob/master/LICENSE

find_package(Git)

if(GIT_FOUND)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} --version
        OUTPUT_VARIABLE GIT_VERSION
        ERROR_QUIET
        )
    if(NOT ${GIT_VERSION} STREQUAL "")
        string(STRIP ${GIT_VERSION} GIT_VERSION)
    endif()
    message(STATUS "Wersja Git: ${GIT_VERSION}")
else()
    set(GIT_VERSION "unknown")
endif()