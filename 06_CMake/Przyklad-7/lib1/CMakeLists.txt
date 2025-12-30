# Podprojekt lib1.

# W wyniku kompilacji tego projektu ma powstać biblioteka statyczna.


###############################################################################
# Identyfikator podprojektu
###############################################################################

# Podprojekt - tak, jak "zwykły" projekt CMake - posiada identyfikator.
# Identyfikator ten nie musi być zgodny z nazwą folderu, w którym znajduje
# się podprojekt.

# Nadajemy temu podprojektowi identyfikator p7lib1.

project(p7lib1)


###############################################################################
# Cel podprojektu
###############################################################################

# Tworzymy cel - bibliotekę statyczną. Nadajemy mu identyfikator taki sam,
# jak identyfikator podprojektu, czyli p7lib1. W tym celu, zamiast przepisywać
# nazwę podprojektu, użyjemy tworzonej automatycznie zmiennej PROJECT_NAME.
# Warto stosować tę zmienną w takich sytuacjach - dzięki temu unikniemy
# na przykład literówki przy przepisywaniu identyfikatora podprojektu.
add_library(${PROJECT_NAME} STATIC
    src/lib1.cpp
)
# Cel ten odpowiada bibliotece statycznej - patrz przykład 3.

# Podkreślamy: wyrażenie ${PROJECT_NAME} ma wartość p7lib1, ponieważ w linii
# 16. wywołaliśmy polecenie project właśnie z argumentem p7lib1.


###############################################################################
# NIEOBOWIĄZKOWE: Alias celu
###############################################################################

# Alias to po prostu alternatywny identyfikator celu. Dzięki jego utworzeniu
# wszędzie tam, gdzie powinniśmy posłużyć się identyfikatorem celu, możemy
# zamiast niego użyć aliasu. Obie "nazwy" celu, właściwy identyfikator oraz
# alias, bedą przez CMake traktowane tak samo.

# Poniższe polecenie utworzy alias p7::lib1 dla celu o identyfikatorze
# p7lib1 (przechowywanym w zmiennej PROJECT_NAME - wyjaśnienie wyżej).
add_library(p7::lib1 ALIAS ${PROJECT_NAME})

# Po co tworzyć aliasy? Nie jest to konieczne, jednak może pomóc nam zapanować
# nad projektem. Wygodnie jest odwoływać się do celu podprojektu zgodnie
# z konwencją
#    nazwa_glownego_projektu::nazwa_podprojektu
# W naszym przypadku główny projekt nazywa się p7, natomiast podprojekt -
# lib1, stąd alias celu to p7::lib1.


###############################################################################
# Pozostałe elementy
###############################################################################

# Dalsza część pliku CMakeLists.txt podprojektu zawiera standardowe elementy,
# omówione w poprzednich przykładach.

# Zwrócimy tylko uwagę na to, że wykorzystujemy poniżej dwie zmienne tworzone
# automatycznie przez CMake:
# - PROJECT_NAME - nazwa podprojektu; tu: p7lib1 - jest to zarazem nazwa celu;
#      zmienna ta została omówiona powyżej,
# - PROJECT_SOURCE_DIR - folder źródłowy podprojektu, czyli folder zawierający
#      plik CMakeList.txt podprojektu (a więc niniejszy plik); tu:
#         (główny folder projektu)/lib1
#      patrz przykład 2.

# Folder zawierający pliki nagłówkowe.
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/inc
)

# Standard języka C++.
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)