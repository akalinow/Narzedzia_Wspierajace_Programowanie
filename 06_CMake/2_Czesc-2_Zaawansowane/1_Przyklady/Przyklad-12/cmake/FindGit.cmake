# Źródło:
# https://github.com/bast/cmake-example/blob/master/cmake/FindGit.cmake

# Copyright (c) 2014-2018 by Radovan Bast.
# All rights reserved.

# Licencja:
# BSD 3-Clause "New" or "Revised" License
# https://github.com/bast/cmake-example/blob/master/LICENSE

find_program(
    GIT_EXECUTABLE
    NAMES git
    DOC "git command line client"
    )
mark_as_advanced(GIT_EXECUTABLE)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Git DEFAULT_MSG GIT_EXECUTABLE)