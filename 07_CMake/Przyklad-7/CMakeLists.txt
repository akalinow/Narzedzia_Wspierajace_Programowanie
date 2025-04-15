# Przykład 7. Podprojekty.

# Przykład ten omawia podział projektu na podprojekty.


cmake_minimum_required(VERSION 3.15)

project(p7
    VERSION 1.0
    DESCRIPTION "Przykład 7."
    LANGUAGES CXX)

###############################################################################

# Dołączamy kolejne podprojekty
add_subdirectory(lib1)
add_subdirectory(lib2)
add_subdirectory(app)
# Dokumentacja:
#   https://cmake.org/cmake/help/latest/command/add_subdirectory.html