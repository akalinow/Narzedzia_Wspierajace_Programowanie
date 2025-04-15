# Przykład 3. Biblioteka statyczna.

# W tym przykładzie część programu zostanie wydzielona w postaci biblioteki
# statycznej, której użyjemy później do utworzenia właściwego pliku wykonywalnego.


cmake_minimum_required(VERSION 3.15)

project(p3
    VERSION 1.0
    DESCRIPTION "Przykład 3."
    LANGUAGES CXX)


###############################################################################
# Cel 1. Biblioteka statyczna
###############################################################################

# Tworzymy cel - bibliotekę statyczną. Nadajemy mu identyfikator p3lib.
add_library(p3lib STATIC
    src/class_a.cpp
    src/class_b.cpp
)
# Dokumentacja:
#   https://cmake.org/cmake/help/latest/command/add_library.html

# Określamy folder, który zawiera pliki nagłówkowe dla celu p3lib.
target_include_directories(p3lib
    PUBLIC
        ${PROJECT_SOURCE_DIR}/inc
)

target_compile_features(p3lib PRIVATE cxx_std_20)


###############################################################################
# Cel 2. Plik wykonywalny
###############################################################################

# Dodajemy cel - plik wykonywalny p3e.
add_executable(p3e
    src/main.cpp
)

# Dołączamy bibliotekę p3lib do pliku wykonywalnego p3e.
target_link_libraries(p3e
    PRIVATE 
        p3lib
)

target_compile_features(p3e PRIVATE cxx_std_20)
