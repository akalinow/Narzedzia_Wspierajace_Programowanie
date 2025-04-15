# Przykład 4. Biblioteka dynamiczna.

# W tym przykładzie część programu zostanie wydzielona w postaci biblioteki
# dynamicznej, której użyjemy później do utworzenia właściwego pliku wykonywalnego.


cmake_minimum_required(VERSION 3.15)

project(p4
    VERSION 1.0
    DESCRIPTION "Przykład 4."
    LANGUAGES CXX)


###############################################################################
# Cel 1. Biblioteka dynamiczna
###############################################################################

# Tworzymy cel - bibliotekę dynamiczną. Nadajemy mu identyfikator p4lib.
add_library(p4lib SHARED
    src/class_a.cpp
    src/class_b.cpp
)
# Dokumentacja:
#   https://cmake.org/cmake/help/latest/command/add_library.html

# Określamy folder, który zawiera pliki nagłówkowe dla celu p4lib.
target_include_directories(p4lib
    PUBLIC
        ${PROJECT_SOURCE_DIR}/inc
)

target_compile_features(p4lib PRIVATE cxx_std_20)


###############################################################################
# Cel 2. Plik wykonywalny
###############################################################################

# Dodajemy cel - plik wykonywalny p4e.
add_executable(p4e
    src/main.cpp
)

# Dołączamy bibliotekę p3lib do pliku wykonywalnego p4e.
target_link_libraries(p4e
    PRIVATE 
        p4lib
)

target_compile_features(p4e PRIVATE cxx_std_20)