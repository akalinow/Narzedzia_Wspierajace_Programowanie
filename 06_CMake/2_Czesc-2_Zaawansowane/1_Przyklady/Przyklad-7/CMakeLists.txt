# Przykład 7. Biblioteka INTERFACE (tylko pliki nagłówkowe).

# W tym przykładzie część programu zostanie wydzielona w postaci biblioteki
# szczególnego typu, określanej w CMake słowem kluczowym INTERFACE.
# Kod żródłowy biblioteki składa się wyłącznie z plików nagłówkowych, nie ma
# w nim żadnych plików z "właściwym" kodem (np. plików z rozszerzeniem .cpp).
# Tworząc cel odpowiadający takiej bibliotece należy użyć właśnie słowa kluczowego
# INTERFACE. W czasie budowania projektu biblioteka taka nie powstawnie jako
# osobny byt, będzie przez CMake traktowana po prostu jako zbiór dodatkowych
# plików nagłówkowych.


cmake_minimum_required(VERSION 3.15)

project(p7
    VERSION 1.0
    DESCRIPTION "Przykład 7."
    LANGUAGES CXX)


###############################################################################
# Cel 1. Biblioteka INTERFACE
###############################################################################

# Tworzymy cel - bibliotekę INTERFACE. Nadajemy mu identyfikator p7lib.
add_library(p7lib INTERFACE)
# Cel ten odpowiada bibliotece zbudowanej wyłącznie z plików nagłówkowych,
# dlatego nie wymieniamy tu plików źródłowych.

# Dokumentacja:
#   https://cmake.org/cmake/help/latest/command/add_library.html

# Określamy folder, który zawiera pliki nagłówkowe dla celu p7lib.
target_include_directories(p7lib
    INTERFACE
        ${PROJECT_SOURCE_DIR}/inc
)

target_compile_features(p7lib INTERFACE cxx_std_20)


###############################################################################
# Cel 2. Plik wykonywalny
###############################################################################

# Dodajemy cel - plik wykonywalny p7e.
add_executable(p7e
    src/main.cpp
)

# Dołączamy bibliotekę p7lib do pliku wykonywalnego p7e.
target_link_libraries(p7e
    PRIVATE 
        p7lib
)

target_compile_features(p7e PRIVATE cxx_std_20)