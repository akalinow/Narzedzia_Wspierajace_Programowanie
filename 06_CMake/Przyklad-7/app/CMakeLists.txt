# Podprojekt app.

# W wyniku kompilacji tego projektu ma powstać aplikacja
# wykorzystująca biblioteki lib1, lib2 i lib3.


###############################################################################
# Identyfikator podprojektu
###############################################################################

# Podprojekt - tak, jak "zwykły" projekt CMake - posiada identyfikator.
# Identyfikator ten nie musi być zgodny z nazwą folderu, w którym znajduje
# się podprojekt.

# Nadajemy temu podprojektowi identyfikator p7app.

project(p7app)


###############################################################################
# Cel podprojektu
###############################################################################

# Tworzymy cel - plik wykonywalny. Nadajemy mu identyfikator taki sam,
# jak identyfikator podprojektu, czyli p7app. W tym celu, zamiast przepisywać
# nazwę podprojektu, użyjemy tworzonej automatycznie zmiennej PROJECT_NAME.
# Warto stosować tę zmienną w takich sytuacjach - dzięki temu unikniemy
# na przykład literówki przy przepisywaniu identyfikatora podprojektu.
add_executable(${PROJECT_NAME}
    main.cpp
)
# Cel ten odpowiada plikowi wykonywalemu - patrz przykład 1.

# Podkreślamy: wyrażenie ${PROJECT_NAME} ma wartość p7app, ponieważ w linii
# 17. wywołaliśmy polecenie project właśnie z argumentem p7app.


###############################################################################
# Pozostałe elementy
###############################################################################

# Dalsza część pliku CMakeLists.txt podprojektu zawiera standardowe elementy,
# omówione w poprzednich przykładach.

# Zwrócimy tylko uwagę na to, że wykorzystujemy poniżej tworzoną automatycznie
# przez CMake zmienną PROJECT_NAME, przechowującą nazwę podprojektu; tu: p7app
# - jest to zarazem nazwa celu. Zmienna ta została omówiona powyżej.

# Dołączamy wszystkie trzy biblioteki: lib1, lib2 i lib3 do pliku
# wykonywalnego p7app. Możemy tu posłużyć się identyfikatorami odpowiednich
# celów lub ich aliasami, o ile je utworzyliśmy. Szczegóły znajdziemy w plikach
# CMakeLists.txt podprojektów bibliotek - z zawartych w nich komentarzy dowiemy
# się, skąd się wzięły zapisy p7::lib1 etc.
target_link_libraries(${PROJECT_NAME}
    p7::lib1
    p7::lib2
    p7::lib3
)
# Polecenie target_link_libraries zostało wprowadzone w przykładach 3. i 4.

# Standard języka C++.
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

# Nie ma potrzeby wywoływania instrukcji
#     target_include_directories
# Dzięki zastosowaniu słów kluczowych PUBLIC oraz INTERFACE
# w poleceniu target_include_directories w plikach CMakeLists.txt
# poszczególnych bibliotek, samo dołącznie tych bibliotek dołączy
# również odpowiednie pliki nagłówkowe.