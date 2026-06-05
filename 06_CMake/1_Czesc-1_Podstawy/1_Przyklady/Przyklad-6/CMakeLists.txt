# Przykład 6. Zależności zewnętrzne.

# W tym przykładzie dodamy do projektu zewnętrzną zależność - biblioteki Boost.


cmake_minimum_required(VERSION 3.15)

project(p6
    VERSION 1.0
    DESCRIPTION "Przykład 6."
    LANGUAGES CXX)

###############################################################################

# Dołączamy biblioteki filesystem i system z pakietu Boost.
find_package(Boost 1.46.1 REQUIRED COMPONENTS filesystem system)

if(Boost_FOUND)
    message("Biblioteki Boost dołączone!")
else()
    message(FATAL_ERROR "Nie można odnaleźć bibliotek Boost!")
endif()

###############################################################################

add_executable(p6e
    main.cpp
)

# Dołączamy biblioteki Boost do celu p6e.
target_link_libraries(p6e
    PRIVATE
        Boost::filesystem
)