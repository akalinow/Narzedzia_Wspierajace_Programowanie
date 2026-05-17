# Przykład 2. Projekt ze strukturą folderów.

# Dobrą praktyką jest tworzenie odpowiedniej struktury folderów projektu,
# np. w przypadku języka C++ umieszczanie plików nagłówkowych w jednym
# folderze (np. inc), natomiast plików z właściwym kodem w drugim (np. src).


cmake_minimum_required(VERSION 3.15)

project(p2
    VERSION 1.0
    DESCRIPTION "Przykład 2."
    LANGUAGES CXX)

###############################################################################

# Dodajemy cel - plik wykonywalny p2e.
add_executable(p2e
    ${PROJECT_SOURCE_DIR}/src/class_a.cpp
    ${PROJECT_SOURCE_DIR}/src/class_b.cpp
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)
# Wykorzystaliśmy zmienną PROJECT_SOURCE_DIR, tworzoną automatycznie przez CMake,
# zawierającą ścieżkę do nadrzędnego folderu naszego projektu.
#
# Użycie zmiennej PROJECT_SOURCE_DIR nie jest tu koniecznie, zamiast
#   ${PROJECT_SOURCE_DIR}/src/nazwa_pliku.cpp
# moglibyśmy napisać po prostu
#   src/nazwa_pliku.cpp

target_compile_features(p2e PRIVATE cxx_std_20)

# Określamy folder, który zawiera pliki nagłówkowe.
target_include_directories(p2e
    PRIVATE
        ${PROJECT_SOURCE_DIR}/inc
)
# Na przykład w przypadku kompilatora g++ będzie to skutkowało dodaniem
# przy jego wywołaniu argumentu -I z określoną tu ścieżką:
#   g++ -I./inc ...
#
# Dokumentacja:
#   https://cmake.org/cmake/help/latest/command/target_include_directories.html