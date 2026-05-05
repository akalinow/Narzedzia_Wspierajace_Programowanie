# Przykład 12. Moduły.

# W tym przykładzie nauczymy się tworzyć moduły CMake, czyli skrypty,
#które definiują funkcje i makra, które można wykorzystać w innych
# skryptach CMake. Moduły są bardzo przydatne do organizowania kodu
# CMake i ponownego wykorzystywania go w różnych projektach.


cmake_minimum_required(VERSION 3.15)

project(p12
    VERSION 1.0
    DESCRIPTION "Przykład 12."
    LANGUAGES CXX
)


###############################################################################
# Komunikaty dla użytkownika
###############################################################################

message(STATUS "Projekt: ${PROJECT_NAME}")
message(STATUS "Wersja: ${PROJECT_VERSION}")
message(STATUS "Opis: ${PROJECT_DESCRIPTION}")

message(STATUS "Standard C++: ${CMAKE_CXX_STANDARD}")
message(STATUS "System: ${CMAKE_SYSTEM_NAME}")

###############################################################################
# Używamy modułów
###############################################################################

include(cmake/safeguards.cmake)

include(cmake/git_version.cmake)
include(cmake/python_version.cmake)


###############################################################################
# Dynamiczne generowanie plików nagłówkowych
###############################################################################

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/config.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/inc/config.h
    @ONLY
)


###############################################################################
# Cel. Plik wykonywalny
###############################################################################

add_executable(p12e
    src/main.cpp
)

target_include_directories(p12e PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/inc
)

target_compile_features(p12e PRIVATE cxx_std_20)