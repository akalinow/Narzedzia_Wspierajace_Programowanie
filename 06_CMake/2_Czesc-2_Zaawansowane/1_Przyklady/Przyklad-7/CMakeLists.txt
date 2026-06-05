# Przykład 7. Flagi kompilatora.

# Przykład ten omawia sposoby określania flag kompilatora.


cmake_minimum_required(VERSION 3.15)

project(p7
    VERSION 1.0
    DESCRIPTION "Przykład 7."
    LANGUAGES CXX)

###############################################################################

# Sposób I - niezalecany. Domyślne flagi kompilatora.
# Ustawiamy flagę FLAG1 dla wszystkich celów w projekcie.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DFLAG1" CACHE STRING "Set C++ Compiler Flags" FORCE)

###############################################################################

add_executable(p7e
    main.cpp
)

# Sposób II - zalecany. Flaga kompilatora dla konkretnego celu.
# Ustawiamy flagę FLAG3 dla celu p7e.
target_compile_definitions(p7e 
    PRIVATE
        FLAG3
)
