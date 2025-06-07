# Podprojekt lib3.

# W wyniku kompilacji tego projektu ma powstać biblioteka szczególnego typu.
# Kod żródłowy biblioteki składa się wyłącznie z plików nagłówkowych, nie ma
# w nim żadnych plików z "właściwym" kodem (np. plików z rozszerzeniem .cpp).
# Tworząc cel odpowiadający takiej bibliotece należy użyć słowa kluczowego
# INTERFACE. W czasie budowania projektu biblioteka taka nie powstawnie jako
# "osobny byt", będzie przez CMake traktowana po prostu jako zbiór dodatkowych
# plików nagłówkowych.



###############################################################################
# Identyfikator podprojektu
###############################################################################

# Podprojekt - tak, jak "zwykły" projekt CMake - posiada identyfikator.
# Identyfikator ten nie musi być zgodny z nazwą folderu, w którym znajduje
# się podprojekt.

# Nadajemy temu podprojektowi identyfikator p7lib3.

project (p7lib3)


###############################################################################
# Cel podprojektu
###############################################################################

# Tworzymy cel - bibliotekę INTERFACE. Nadajemy mu identyfikator taki sam,
# jak identyfikator podprojektu, czyli p7lib3. W tym celu, zamiast przepisywać
# nazwę podprojektu, użyjemy tworzonej automatycznie zmiennej PROJECT_NAME.
# Warto stosować tę zmienną w takich sytuacjach - dzięki temu unikniemy
# na przykład literówki przy przepisywaniu identyfikatora podprojektu.
add_library(${PROJECT_NAME} INTERFACE)
# Cel ten odpowiada bibliotece zbudowanej wyłącznie z plików nagłówkowych,
# dlatego nie wymieniamy tu plików źródłowych.

# Podkreślamy: wyrażenie ${PROJECT_NAME} ma wartość p7lib3, ponieważ w linii
# 23. wywołaliśmy polecenie project właśnie z argumentem p7lib3.


###############################################################################
# NIEOBOWIĄZKOWE: Alias celu
###############################################################################

# Alias to po prostu alternatywny identyfikator celu. Dzięki jego utworzeniu
# wszędzie tam, gdzie powinniśmy posłużyć się identyfikatorem celu, możemy
# zamiast niego użyć aliasu. Obie "nazwy" celu, właściwy identyfikator oraz
# alias, bedą przez CMake traktowane tak samo.

# Poniższe polecenie utworzy alias p7::lib3 dla celu o identyfikatorze
# p7lib3 (przechowywanym w zmiennej PROJECT_NAME - wyjaśnienie wyżej).
add_library(p7::lib3 ALIAS ${PROJECT_NAME})

# Po co tworzyć aliasy? Nie jest to konieczne, jednak może pomóc nam zapanować
# nad projektem. Wygodnie jest odwoływać się do celu podprojektu zgodnie
# z konwencją
#    nazwa_glownego_projektu::nazwa_podprojektu
# W naszym przypadku główny projekt nazywa się p7, natomiast podprojekt -
# lib3, stąd alias celu to p7::lib3.


###############################################################################
# Pozostałe elementy
###############################################################################

# Dalsza część pliku CMakeLists.txt podprojektu zawiera standardowe elementy,
# omówione w poprzednich przykładach.

# Zwrócimy tylko uwagę na to, że wykorzystujemy poniżej dwie zmienne tworzone
# automatycznie przez CMake:
# - PROJECT_NAME - nazwa podprojektu; tu: p7lib3 - jest to zarazem nazwa celu;
#      zmienna ta została omówiona powyżej,
# - PROJECT_SOURCE_DIR - folder źródłowy podprojektu, czyli folder zawierający
#      plik CMakeList.txt podprojektu (a więc niniejszy plik); tu:
#         (główny folder projektu)/lib3
#      patrz przykład 2.

# W tej części również używamy słowa kluczowego INTERFACE.

# Folder zawierający pliki nagłówkowe.
target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${PROJECT_SOURCE_DIR}/inc
)

# Standard języka C++.
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)