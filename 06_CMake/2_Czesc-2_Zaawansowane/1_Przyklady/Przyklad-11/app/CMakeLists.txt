# Podprojekt app.

# Więcej informacji o podprojektach oraz poszczególnych elementach tego pliku
# znajdziesz w przykładzie 8.

# W wyniku kompilacji tego projektu ma powstać aplikacja wykorzystująca
# bibliotekę lib.


###############################################################################
# Identyfikator podprojektu
###############################################################################

project(p11app)


###############################################################################
# Cel podprojektu
###############################################################################

# Poniższa instrukcja tworzy zmienną sources zawierającą listę wszystkich plików,
# których ścieżka pasuje do wzorca src/*.cpp (czyli plików z rozszerniem .cpp
# znajdujących się w folderze src i jego podfolderach).
file(GLOB_RECURSE sources
    src/*.cpp
)

# Zastąpienie file(GLOB_RECURSE ...) przez file(GLOB ...) spowodowałoby, że zmienna
# sources zawierałaby tylko pliki z folderu src, ale nie w jego podfolderach
# (wprawdzie folder ten nie ma podfolderów, ale to tylko przykład).

add_executable(${PROJECT_NAME} ${sources})
# Cel ten odpowiada plikowi wykonywalemu - patrz przykład 1.


###############################################################################
# Pozostałe elementy
###############################################################################

# Dołączamy bibliotekę lib.
target_link_libraries(${PROJECT_NAME}
    p11::lib
)

# Standard języka C++.
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)