project(p7app)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
    p7::lib1
    p7::lib2
)

# Nie ma potrzeby wywoływania instrukcji
#     target_include_directories
# Dzięki zastosowaniu słów kluczowych PUBLIC oraz INTERFACE
# w poleceniu target_include_directories w plikach CMakeLists.txt
# poszczególnych bibliotek, samo dołącznie tych bibliotek dołączy
# również odpowiednie pliki nagłówkowe.