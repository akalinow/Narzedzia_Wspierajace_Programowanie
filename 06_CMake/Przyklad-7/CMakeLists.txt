# Przykład 7. Podprojekty.

# Przykład ten omawia podział projektu na podprojekty.

# Gdy projekt staje się coraz bardziej skomplikowany, trudniej jest nad nim
# zapanować. Rozwiązaniem może być podział projektu na podprojekty.

# Każdy podprojekt posiada swój własny plik CMakeLists.txt, określający
# zasady jego budowania (w standardowy sposób - patrz poprzednie przykłady).
# Istnieje ponadto "nadrzędny" plik CMakeLists.txt, który określa własności
# projektu (nazwa, wersja etc.) oraz zawiera listę podprojektów. Plik ten
# zwykle znajduje się w nadrzędnym folderze projektu.

###############################################################################

# Niniejszy projekt jest ma aż cztery cele. W wyniku jego kompilacji mają powstać
# trzy biblioteki: lib1, lib2 i lib3 oraz aplikacja (plik wykonywalny) app.
# Podzielimy zatem projekt na cztery podprojekty - każdy będzie odpowiadał
# jednemu z celów.

# To jest główny plik CMakeLists.txt całego projektu, opisuje zatem własności
# projektu oraz wylicza podprojekty.


cmake_minimum_required(VERSION 3.15)

###############################################################################
# Ogólne właśności projektu
###############################################################################

project(p7
    VERSION 1.0
    DESCRIPTION "Przykład 7."
    LANGUAGES CXX)

# Szczegóły: przykład 1.


###############################################################################
# Podprojekty
###############################################################################

# W celu określania podprojektów należy posłużyć się poleceniem add_subdirectory.
# Jako argument tego polecenia podajemy ścieżkę folderu, w którym znajduje się
# plik CMakeLists.txt podprojektu (a nie na przykład identyfikator podprojektu).
# Ścieżka ta może być zarówno względna, jak i bezwzględna.

# Każdy z czterech podprojektów w tym przykładzie znajduje się w podfolderze
# głównego folderu projektu, zatem najwygodniej jest zastosować ścieżki
# względne, podając po prostu nazwę podfolderu.

add_subdirectory(lib1)   # Biblioteka lib1.
add_subdirectory(lib2)   # Biblioteka lib2.
add_subdirectory(lib3)   # Biblioteka lib3.
add_subdirectory(app)    # Aplikacja app.
# Dokumentacja:
#   https://cmake.org/cmake/help/latest/command/add_subdirectory.html