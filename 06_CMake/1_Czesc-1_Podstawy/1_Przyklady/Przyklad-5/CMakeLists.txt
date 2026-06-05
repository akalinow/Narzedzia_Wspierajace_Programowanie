# Przykład 5. Biblioteka INTERFACE (tylko pliki nagłówkowe).

# W tym przykładzie część programu zostanie wydzielona w postaci biblioteki
# szczególnego typu, określanej w CMake słowem kluczowym INTERFACE.
# Kod żródłowy biblioteki składa się wyłącznie z plików nagłówkowych, nie ma
# w nim żadnych plików z "właściwym" kodem (np. plików z rozszerzeniem .cpp).
# Tworząc cel odpowiadający takiej bibliotece należy użyć właśnie słowa kluczowego
# INTERFACE. W czasie budowania projektu biblioteka taka nie powstawnie jako
# osobny byt, będzie przez CMake traktowana po prostu jako zbiór dodatkowych
# plików nagłówkowych.


cmake_minimum_required(VERSION 3.15)

project(p5
    VERSION 1.0
    DESCRIPTION "Przykład 5."
    LANGUAGES CXX)


###############################################################################
# Cel 1. Biblioteka INTERFACE
###############################################################################

# Tworzymy cel - bibliotekę INTERFACE. Nadajemy mu identyfikator p5lib.
add_library(p5lib INTERFACE)
# Cel ten odpowiada bibliotece zbudowanej wyłącznie z plików nagłówkowych,
# dlatego nie wymieniamy tu plików źródłowych.

# Dokumentacja:
#   https://cmake.org/cmake/help/latest/command/add_library.html

# Określamy folder, który zawiera pliki nagłówkowe dla celu p5lib.
target_include_directories(p5lib
    INTERFACE
        ${PROJECT_SOURCE_DIR}/inc
)

target_compile_features(p5lib INTERFACE cxx_std_20)


###############################################################################
# Cel 2. Plik wykonywalny
###############################################################################

# Dodajemy cel - plik wykonywalny p5e.
add_executable(p5e
    src/main.cpp
)

# Dołączamy bibliotekę p5lib do pliku wykonywalnego p5e.
target_link_libraries(p5e
    PRIVATE 
        p5lib
)

target_compile_features(p5e PRIVATE cxx_std_20)