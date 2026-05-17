# Podprojekt lib.

# Więcej informacji o podprojektach oraz poszczególnych elementach tego pliku
# znajdziesz w przykładzie 8.

# W wyniku kompilacji tego projektu ma powstać biblioteka dynamiczna.


###############################################################################
# Identyfikator podprojektu
###############################################################################

project(p11lib)


###############################################################################
# Cel podprojektu
###############################################################################

# Poniższa instrukcja tworzy zmienną sources zawierającą listę wszystkich plików,
# których ścieżka pasuje do wzorca src/lib_f/*.cpp (czyli plików z rozszerniem .cpp
# znajdujących się w folderze src/lib_f i jego podfolderach) lub pasujących do wzorca
# src/lib_g/*.cpp# (czyli plików z rozszerniem .cpp znajdujących się w folderze
# src/lib_g i jego podfolderach).
file(GLOB_RECURSE sources src/lib_f/*.cpp src/lib_g/*.cpp)
# Tak naprawdę wystarczyło użyć polecenia
#   file(GLOB_RECURSE sources src/*.cpp)
# ponieważ foldery lib_f i lib_g znajdują się w folderze src, chcieliśmy jednak
# pokazać, że można użyć kilku wzorców. Poza tym, dzięki zastosowaniu dwóch wzorców,
# mamy pewność, że w zmiennej sources znajdą się tylko pliki z tych dwóch folderów,
# a nie z innych potencjalnych folderów, które mogłyby się znaleźć w folderze src
# w przyszłości.

# Zastąpienie file(GLOB_RECURSE ...) przez file(GLOB ...) spowodowałoby, że zmienna
# sources zawierałaby tylko pliki z folderów src/lib_f i src/lib_g, ale nie
# z ich podfolderów.

# Tworzymy cel - bibliotekę dynamiczną na podstawie plików źródłowych określonych
# w zmiennej sources.
add_library(${PROJECT_NAME} SHARED ${sources})
# Cel ten odpowiada bibliotece dynamicznej - patrz przykład 4.


###############################################################################
# NIEOBOWIĄZKOWE: Alias celu
###############################################################################

add_library(p11::lib ALIAS ${PROJECT_NAME})


###############################################################################
# Pozostałe elementy
###############################################################################

# Folder zawierający pliki nagłówkowe.
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/inc
)

# Standard języka C++.
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)