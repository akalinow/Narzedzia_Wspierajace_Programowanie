# Przykład 9. Dynamiczne generowanie plików.

# CMake umożliwia dynamiczne generowanie plików projektu na podstawie szablonów.
# Służy do tego polecenie configure_file(). Pliki szablonów mają rozszerzenie .in.

# Mechanizm ten pozwala wpływać na kod źródłowy na etapie budowania projektu.
# Możemy dzięki niemu na przykład określać wartości wybranych zmiennych nie
# bezpośrednio w kodzie źródłowym ani w danych wejściowych, ale w pliku CMakeLists.txt.

# W tym przykładzie zdefiniujemy w pliku CMakeLists.txt kilka zmiennych, a następnie
# wygenerujemy dwa pliki nagłówkowe zawierające wartości tych zmiennych oraz dodatkowo
# kilku zmiennych tworzonych automatycznie przez CMake. Wartośći te wykorzystamy
# w kodzie aplikacji.


cmake_minimum_required(VERSION 3.15)

project(p9
    VERSION 1.0
    DESCRIPTION "Przykład 9."
    LANGUAGES CXX)


###############################################################################
# Zmienne
###############################################################################

# Zmienna var1
set(var1 "Wartość zmiennej var1!")

# Zmienna var2
set(var2 "Wartość zmiennej var2")

# Zmienna p9_VERSION

# Tworząc zmienne, możemy użyć wartości już istniejących zmiennych, posługując
# się składnią ${NAZWA_ISTNIEJACEJ_ZMIENNEJ}. W tym przykładzie przypiszemy do
# zmiennej p9_VERSION wartość zmiennej PROJECT_VERSION, która jest automatycznie
# definiowana przez CMake i ma wartość określoną w poleceniu project() (w tym przypadku
# 1.0). Dzięki temu, jeśli zmienimy wersję projektu w poleceniu project(), zmienna
# p9_VERSION zostanie automatycznie zaktualizowana, co ułatwia zarządzanie
# wersjami w projekcie. Wykorzystamy też własną zmienną pomocniczą p9_BUILD.

set(p9_BUILD "1348912")

set(p9_VERSION "${PROJECT_VERSION}.build${p9_BUILD}")
# Oczekiwana wartość zmiennej p9_VERSION to "1.0.build1348912".

# Dokumentacja:
#   https://cmake.org/cmake/help/latest/command/set.html


###############################################################################
# Dynamiczne generowanie plików
###############################################################################

# Wygenerujemy pliki nagłówkowe cf_a.h i cf_b.h na podstawie szablonów cf_a.h.in
# i cf_b.h.in. Pliki te są tworzone automatycznie przez CMake, dlatego umieszczamy
# je w folderze docelowym, czyli ${CMAKE_CURRENT_BINARY_DIR}, a nie w folderze
# źródłowym, czyli ${CMAKE_CURRENT_SOURCE_DIR}, który powinien zawierać wyłącznie
# pliki tworzone przez programistę.

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/cf_a.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/inc/cf_a.h
)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/cf_b.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/inc/cf_b.h
    @ONLY
)
# Dodanie @ONLY nie jest konieczne, powoduje jednak, że CMake będzie szukać tylko
# zmiennych w formacie @NAZWA_ZMIENNEJ@, a nie w formacie ${NAZWA_ZMIENNEJ}
# (bez @ONLY CMake będzie szukać obu formatów). W przypadku tego przykładu
# nie ma to znaczenia, ale w bardziej rozbudowanych projektach może być przydatne,
# ponieważ pozwala uniknąć przypadkowej zamiany ciągów tekstowych, które mają
# postać ${NAZWA_ZMIENNEJ}, ale są używane w innym kontekście i nie chemy ich zamieniać.

# Dokumentacja:
#   https://cmake.org/cmake/help/latest/command/configure_file.html


###############################################################################
# Cel. Plik wykonywalny
###############################################################################

# Dodajemy cel - plik wykonywalny p9e.
add_executable(p9e
    src/main.cpp
)

# Dodajemy folder z wygenerowanymi plikami nagłówkowymi do ścieżek przeszukiwanych
# przez kompilator.
target_include_directories(p9e PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/inc
)

target_compile_features(p9e PRIVATE cxx_std_20)