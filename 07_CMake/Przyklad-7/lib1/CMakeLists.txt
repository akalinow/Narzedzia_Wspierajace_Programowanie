project (p7lib1)

# Tworzymy cel - bibliotekę statyczną i nadajemy jej alias p7::lib1.
add_library(${PROJECT_NAME} src/lib1.cpp)
add_library(p7::lib1 ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/inc
)