# Narzędzia wspierające programowanie
## Temat: CMake

### Ćwiczenie 1.

Napisz plik `CMakeLists.txt` dla projektu z folderu `App_Example`. W wyniku budowania projektu powinny powstać:

* biblioteka statyczna **lib1** – na podstawie kodu z podfolderu `lib1`,
* biblioteka dynamiczna **lib2** – na podstawie kodu z podfolderu `lib2`,
* plik wykonywalny **app** – na podstawie kodu z podfolderu `app`.

Upewnij się, że proces budowania projektu przebiega poprawnie.

### Ćwiczenie 2.

Napisz plik `CMakeLists.txt` dla projektu z folderu `MathTools` (znajduje się on w głównym folderze repozytorium, a więc poza folderem `06_CMake`). W wyniku budowania projektu powinny powstać:

* biblioteka statyczna **funkcja** – na podstawie pliku `Funkcja.C`,
* biblioteka dynamiczna **wymierna** – na podstawie plików `Wielomian.C` i `Wymierna.C`,
* biblioteka dynamiczna **gauss** – na podstawie plików `Gauss.C` i `IntGauss.C`,
* plik wykonywalny **MathTools** – na podstawie pliku `MathTools.C`.

Upewnij się, że proces budowania projektu przebiega poprawnie.

*Wskazówka*. Projekt ma zewnętrzną zależność – bibliotekę GSL. Zajrzyj do [dokumentacji modułu FindGSL](https://cmake.org/cmake/help/latest/module/FindGSL.html), w szczególności do sekcji [Examples](https://cmake.org/cmake/help/latest/module/FindGSL.html#examples), żeby dowiedzieć się, jak sobie z tym poradzić.