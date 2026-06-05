# Zaadaptowano z:
# https://github.com/bast/cmake-example/blob/master/cmake/safeguards.cmake

# Copyright (c) 2014-2018 by Radovan Bast.
# All rights reserved.

# Licencja:
# BSD 3-Clause "New" or "Revised" License
# https://github.com/bast/cmake-example/blob/master/LICENSE


# cmake -S <sdir> -B <bdir>
# Żądamy, aby <sdir> i <bdir> były różnymi folderami.
if(${PROJECT_SOURCE_DIR} STREQUAL ${PROJECT_BINARY_DIR})
    message(FATAL_ERROR "Nie można budować projektu w folderze źródłowym. Proszę użyć innego folderu dla plików wynikowych.")
endif()