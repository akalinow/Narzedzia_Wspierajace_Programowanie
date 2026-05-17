# Przykład 11. Globbing.

# Dotychczas w naszych przykładach zawsze ręcznie wymienialiśmy wszystkie pliki źródłowe
# potrzebne do kompilacji danego celu. CMake oferuje jednak mechanizm, który pozwala na
# automatyczne wyszukiwanie plików źródłowych w katalogu. Nazywa się on globbingiem
# i jest realizowany za pomocą polecenia file(GLOB ...). W tym przykładzie pokażemy,
# jak z niego korzystać.

###############################################################################

# Niniejszy projekt ma dwa cele. W wyniku jego kompilacji mają powstać:
# biblioteka lib oraz aplikacja (plik wykonywalny) app. # Podzielimy zatem
# projekt na dwa podprojekty - każdy będzie odpowiadał jednemu z celów.

# To jest główny plik CMakeLists.txt całego projektu, opisuje zatem własności
# projektu oraz wylicza podprojekty.


cmake_minimum_required(VERSION 3.15)

###############################################################################
# Ogólne właśności projektu
###############################################################################

project(p11
    VERSION 1.0
    DESCRIPTION "Przykład 11."
    LANGUAGES CXX)


###############################################################################
# Podprojekty
###############################################################################

# Patrz: Przykład 8.

add_subdirectory(lib)    # Biblioteka lib.
add_subdirectory(app)    # Aplikacja app.