# Przykład 10. Interakcja z użytkownikiem.

# W tym przykładzie nauczymy się pozyskiwać informacje od użytkownika, pozwalając
# mu na przypisywanie wartości zmiennym.

# Jednym ze sposobów jest oczywiście umieszczenie definicji tych zmiennych (polecenie
# set()) w pliku CMakeLists.txt, w pobliżu jego początku, i zachęcenie użytkownika
# do ręcznej edycji tego pliku, bywa to jednak mało wygodne i może prowadzić do błędów
# (np. przypadkowe usunięcie lub zmiana innych linii w pliku CMakeLists.txt).

# Poznamy tu inne sposoby, pozwalające użytkownikowi na przypisywanie wartości zmiennym
# bez konieczności edycji pliku CMakeLists.txt. Będzie on mógł to zrobić bezpośrednio
# z wiersza poleceń, dodając przełączniki
#   -Dnazwa_zmiennej="Wartość zmiennej"
# (zwróć uwagę na duże D, brak spacji po D i znak równości), na przykład
#   cmake -Dvar1="Wartość zmiennej var1" -Dvar2="Wartość zmiennej var2" ..

cmake_minimum_required(VERSION 3.15)

project(p10
    VERSION 1.0
    DESCRIPTION "Przykład 10."
    LANGUAGES CXX)


###############################################################################
# Zmienne definiowane przez użytkownika
###############################################################################

# Zadeklarujemy teraz zmienne, którym użytkownik będzie mógł przypisywać
# wartości wywołując cmake z odpowiednimi przełącznikami.


# Sposób I. option() - wartość ON lub OFF #####################################
# Składnia: option(NAZWA_ZMIENNEJ "Opis" DOMYŚLNA_WARTOŚĆ)

option(ENABLE_FEATURE_X "Włącza funkcjonalność X" OFF)

# Użycie: 
#   cmake -DENABLE_FEATURE_X=ON  <...>
#   cmake -DENABLE_FEATURE_X=OFF <...>

option(ENABLE_FEATURE_Y "Włącza funkcjonalność Y" ON)

# Użycie: 
#   cmake -DENABLE_FEATURE_Y=ON  <...>
#   cmake -DENABLE_FEATURE_Y=OFF <...>

# Dokumentacja:
#   https://cmake.org/cmake/help/latest/command/option.html


# Sposób II. set(...CACHE...) - dowolna wartość ###############################
# Składnia: set(NAZWA_ZMIENNEJ "WartośćDomyślna" CACHE TYP "Opis")

set(VAR_1 "VAR_1 - wartość domyślna" CACHE STRING "Zmienna VAR_1")

# Użycie:
#   cmake -DVAR_1="Wartość zmiennej VAR_1" <...>

set(VAR_2 "VAR_2 - wartość domyślna" CACHE STRING "Zmienna VAR_2")

# Użycie:
#   cmake -DVAR_2="Wartość zmiennej VAR_2" <...>

# Dokumentacja:
#   https://cmake.org/cmake/help/latest/command/set.html


###############################################################################
# Cel. Plik wykonywalny
###############################################################################

# Dodajemy cel - plik wykonywalny p10e.
add_executable(p10e
    src/main.cpp
)

target_compile_features(p10e PRIVATE cxx_std_20)


###############################################################################
# Wykorzystnie zmiennych w kodzie źródłowym
###############################################################################

# Zajmiemy się teraz udostępnieniem wartości tych zmiennych w kodzie źródłowym.
# Możemy to zrobić na (co najmniej) dwa sposoby.


# Sposób I. target_compile_definitions() ######################################

# Przykład: zmienna ENABLE_FEATURE_X (ON/OFF)
if(ENABLE_FEATURE_X)
    target_compile_definitions(p10e PRIVATE ENABLE_FEATURE_X)
endif()
# target_compile_definitions() utworzy w kodzie źródłowym makro ENABLE_FEATURE_X
# - możemy więc używać konstrukcji
#   #ifdef ENABLE_FEATURE_X
#       // kod, który ma być kompilowany tylko wtedy, gdy ENABLE_FEATURE_X=ON
#   #endif
# Zajrzyj do pliku src/main.cpp, by zobaczyć przykład użycia tego makra.

# Przykład: zmienna VAR_1 (dowolna wartość)
target_compile_definitions(p10e PRIVATE VAR_1="${VAR_1}")
# target_compile_definitions() utworzy w kodzie źródłowym makro VAR_1, które będzie
# zawierać wartość zmiennej VAR_1 (przekazaną przez użytkownika lub domyślną)
# - możemy więc użyć na przykład konstrukcji
#   std::cout << VAR_1 << std::endl;
# Zajrzyj do pliku src/main.cpp, by zobaczyć przykład użycia tego makra.

# Dokumentacja:
#   https://cmake.org/cmake/help/latest/command/target_compile_definitions.html


# Sposób II. configure_file() - dynamiczne generowanie plików #################

# Wykorzystamy narzędzie znane z przykładu 9., czyli dynamiczne generowanie plików
# nagłówkowych za pomocą polecenia configure_file(). Możemy - podobnie, jak
# w przykładzie 9. - przypisać wartości zmiennych CMake do zmiennych w kodzie źródłowym
# C++, często jednak wygodnie jest posłużyć się preprocesorem i jego markami.
# Tak też postąpimy.

# W przypadku zmiennych typu ON/OFF mamy do dyspozycji specjalną dyrektywę preprocesora
# #cmakedefine, która automatycznie wygeneruje właściwą dyrektywę #define, jeśli
# wartość odpowiedniej zmiennej to ON - przykład jej użycia znajdziesz w pliku
# inc/config.h.in.

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/config.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/inc/config.h
    @ONLY
)

# Dodajemy folder z wygenerowanymi plikami nagłówkowymi do ścieżek przeszukiwanych
# przez kompilator.
target_include_directories(p10e PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/inc
)