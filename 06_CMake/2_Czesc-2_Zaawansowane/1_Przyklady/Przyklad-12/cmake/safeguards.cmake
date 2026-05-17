# Źródło:
# https://github.com/bast/cmake-example/blob/master/cmake/safeguards.cmake

# Copyright (c) 2014-2018 by Radovan Bast.
# All rights reserved.

# Licencja:
# BSD 3-Clause "New" or "Revised" License
# https://github.com/bast/cmake-example/blob/master/LICENSE


# cmake -S <sdir> -B <bdir>
# Żądamy aby <sdir> i <bdir> były różnymi folderami.
if(${PROJECT_SOURCE_DIR} STREQUAL ${PROJECT_BINARY_DIR})
    message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there.")
endif()

# Jeśli użytkownik nie określił build type, ustawiamy go na "Release".

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

string(TOLOWER "${CMAKE_BUILD_TYPE}" cmake_build_type_tolower)
string(TOUPPER "${CMAKE_BUILD_TYPE}" cmake_build_type_toupper)

# Sprawdzamy, czy build type jest jednym z dozwolonych.

if(NOT cmake_build_type_tolower STREQUAL "debug" AND
   NOT cmake_build_type_tolower STREQUAL "release" AND
   NOT cmake_build_type_tolower STREQUAL "minsizerel" AND
   NOT cmake_build_type_tolower STREQUAL "relwithdebinfo")
    message(FATAL_ERROR "Unknown build type \"${CMAKE_BUILD_TYPE}\". Allowed values are Debug, Release, RelWithDebInfo, and MinSizeRel (case-insensitive).")
endif()