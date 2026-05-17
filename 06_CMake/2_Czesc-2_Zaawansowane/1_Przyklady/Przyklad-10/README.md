### Wywołanie

```bash
cmake -DENABLE_FEATURE_X=<ON lub OFF> -DENABLE_FEATURE_Y=<ON lub OFF> -DVAR_1="Wartość zmiennej VAR_1" -DVAR_2="Wartość zmiennej VAR_2" -S <sdir> -B <bdir>
```

Na przykład, jeśli folder roboczy to folder, w którym znajdują się pliki źródłowe, możemy napisać

```bash
cmake -DENABLE_FEATURE_X=ON -DENABLE_FEATURE_Y=OFF -DVAR_1="A B C" -DVAR_2="P Q R" -S. -B build
```

Pominięcie którejś ze zmiennych (czyli któregoś z przełączników `-D...`) spowoduje użycie wartości domyślnej, określonej w pliku `CMakeListst.txt`.

### Uwaga

W przypadku wystąpienia problemów, przed każdym wywołaniem CMake warto usunąć folder `<bdir>` (w powyższym przykładzie: `build`). Alternatywnie, w pliku `CMakeListst.txt` możemy dodać `FORCE` do polecenia `set()`, tzn.
```bash
set(VAR_1 "VAR_1 - wartość domyślna" CACHE STRING "Zmienna VAR_1" FORCE)
```