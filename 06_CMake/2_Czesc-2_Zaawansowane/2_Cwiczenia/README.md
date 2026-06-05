# Narzędzia wspierające programowanie
## Temat: CMake

### Część 2. Zagadnienia zaawansowane
### Ćwiczenia

---

### Ćwiczenie 3.

W folderze `App_Shapes` znajdziesz kod źródłowy prostego projektu w języku C++. Umieść w nim, w odpowiednich miejscach struktury folderów, pliki `CMakeLists.txt` w taki sposób, by projekt poprawnie budował się za pomocą CMake.

W wyniku budowania projektu powinny powstać:
* biblioteka dynamiczna **shapes** – na podstawie kodu źródłowego zawartego w podfolderze `shapes`,
* biblioteka statyczna **printer** – na podstawie kodu źródłowego zawartego w podfolderze `printer`,
* plik wykonywalny **geometry** – na podstawie kodu źródłowego zawartego w podfolderze `app`.

Stworzone przez Ciebie pliki powinny definiować następujące własności projektu:
* identyfikator projektu: *geometry*,
* wersja projektu: 1.3,
* język projektu: C++, standard języka: C++20.

### Ćwiczenie 4.
*Wymagane wcześniejsze wykonanie ćwiczenia 3.*

Zmodyfikuj odpowiednie pliki `CMakeLists.txt` utworzone w ramach ćwiczenia 3. oraz, w razie potrzeby, kod źródłowy projektu z folderu `App_Shapes` tak, aby wartości przekazywane funkcji `Print` w funkcji `main` (w obu jej wywołaniach) nie były określone w kodzie źródłowym, a w nadrzędnym pliku `CMakeLists.txt`.

### Ćwiczenie 5.
*Wymagane wcześniejsze wykonanie ćwiczenia 4.*

Zmodyfikuj odpowiednie pliki `CMakeLists.txt` utworzone w ramach ćwiczenia 4. oraz, w razie potrzeby, kod źródłowy projektu z folderu `App_Shapes` tak, aby wartości przekazywane funkcji `Print` w funkcji `main` (w obu jej wywołaniach) mogły być określane przez użytkownika w wierszu poleceń w czasie budowania projektu.

### Ćwiczenie podsumowujące

W folderze `MathTools` (znajduje się on w głównym folderze repozytorium, a więc poza folderem `06_CMake`) znajdziesz kod źródłowy prostego projektu w języku C++.

1. Przyjrzyj się kodowi źródłowemu projektu. Spróbuj zrozumieć zależności pomiędzy jego elementami.

2. Zastanów się, w jaki sposób optymalnie wykorzystać różne funkcjonalności CMake, które pojawiły się na ćwiczeniach (tworzenie bibliotek, podział na podprojekty, dynamiczne generowanie plików, interakcja z użytkownikiem, globbing, moduły), w procesie budowania tego projektu.

3. Umieść w odpowiednich miejscach struktury folderów projektu pliki `CMakeLists.txt` w taki sposób, by projekt poprawnie budował się za pomocą CMake.

*Wskazówka*. Projekt ma zewnętrzną zależność – bibliotekę GSL. Zajrzyj do [dokumentacji modułu FindGSL](https://cmake.org/cmake/help/latest/module/FindGSL.html), w szczególności do sekcji [Examples](https://cmake.org/cmake/help/latest/module/FindGSL.html#examples), żeby dowiedzieć się, jak sobie z tym poradzić.