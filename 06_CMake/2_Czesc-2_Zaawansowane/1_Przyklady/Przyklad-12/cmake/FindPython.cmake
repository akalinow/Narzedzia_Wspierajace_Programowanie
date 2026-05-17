# Zaadaptowano z:
# https://github.com/bast/cmake-example/blob/master/cmake/FindGit.cmake

# Copyright (c) 2014-2018 by Radovan Bast.
# All rights reserved.

# Licencja:
# BSD 3-Clause "New" or "Revised" License
# https://github.com/bast/cmake-example/blob/master/LICENSE

find_program(
    PYTHON_EXECUTABLE
    NAMES python3
    DOC "Python interpreter"
    )
mark_as_advanced(PYTHON_EXECUTABLE)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Python DEFAULT_MSG PYTHON_EXECUTABLE)