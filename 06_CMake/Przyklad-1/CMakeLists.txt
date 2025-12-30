# Przykład 1. Podstawy.

# Przykład ten zawiera minimalny zestaw elementów, które muszą się znaleźć
# w każdym projekcie CMake (oraz jeden dodatkowy, ale pożyteczny).


###############################################################################
# Definicja projektu
###############################################################################

# Ustawiamy minimalną wersję CMake, która może być użyta do zbudowania projektu.
cmake_minimum_required(VERSION 3.15)
# Można tu użyć następujących poleceń:
#
#   cmake_minimum_required(VERSION 3.15)
#       - oznacza to, że minimalna wymagana wersja CMake to 3.15,
#
#   cmake_minimum_required(VERSION 3.15...4.0)
#       - oznacza to, że minimalna wymagana wersja CMake to 3.15,
#         ale projekt był też testowany z nowszymi wersjami CMake,
#         aż do 4.0.
#
# Dokumentacja:
#   https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html


# Definiujemy projekt.
project(p1
    VERSION 1.0
    DESCRIPTION "Przykład 1."
    LANGUAGES CXX)
# p1 to identyfikator projektu. Jego podanie jest obowiązkowe.
#
# Kolejne argumenty nie są wymagane, jednak warto je dodać:
#
#   VERSION
#       - wersja projektu; jej podanie pozwoli nam uniknąć chaosu, który mógłby
#         powstać w miarę tworzenia nowych wersji,
#
#   DESCRIPTION
#       - krótki, czytelny dla człowieka opis projektu,
#
#   LANGUAGES
#       - lista języków programowania używanych w ramach projektu; na przykład
#         CXX oznacza C++; pełna lista dopuszczalnych wartości jest dostępna
#         w dokumentacji.
#
# Dokumentacja:
#   https://cmake.org/cmake/help/latest/command/project.html


###############################################################################
# Cele projektu
###############################################################################

# Z każdym projektem związane są tzw. cele, czyli pliki wykonywalne i biblioteki,
# które mają powstać w czasie budowania projektu - to one mają być zasadniczym
# owocem naszej pracy programistycznej.
#
# W tym przykładzie projekt jest wyjątkowo prosty - ma tylko jeden cel, którym
# jest plik wykonywalny.

# Dodajemy cel - plik wykonywalny hello.
add_executable(hello main.cpp)
# Polecenie to ma zasadniczo dwa argumenty:
#
#   - nazwa pliku wykonywalnego:
#     w tym przykładzie: hello - w systemie Windows powstanie plik hello.exe,
#     w systemach macOS i Linux - plik hello,
#
#   - lista plików z kodem źródłowym, które należy skompilować w celu utworzenia
#     tego pliku wykonywalnego.
#
# Dokumentacja:
#   https://cmake.org/cmake/help/latest/command/add_executable.html

# NIEOBOWIĄZKOWE: ustalamy standard języka C++.
target_compile_features(hello PRIVATE cxx_std_20)
# Instrukcja ta oznacza, że pliki źródłowe, które mają być kompilowane w ramach
# budowania celu hello, będą kompilowane przy założeniu, że kod źródłowy jest
# zgodny ze standardem C++ 20.
#
# Nazwa instrukcji zaczyna się od "target_", co oznacza, że dotyczy ona tylko
# konkretnego celu - jego nazwa jest pierwszym argumentem polecenia (tu: hello).
# Trzeci argument określa standard języka - listę możliwych wartości można
# znaleźć w dokumentacji. Argument drugi, PRIVATE, nie odgrywa tu znaczenia.
#
# Dokumentacja:
#   https://cmake.org/cmake/help/latest/command/target_compile_features.html
#
# Przykład: dopuszczalne wartości określające standard języka C++:
#   https://cmake.org/cmake/help/latest/prop_gbl/CMAKE_CXX_KNOWN_FEATURES.html