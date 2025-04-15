project (p7lib2)

# Tworzymy cel - bibliotekę statyczną i nadajemy jej alias p7::lib2.
add_library(${PROJECT_NAME} INTERFACE)
add_library(p7::lib2 ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${PROJECT_SOURCE_DIR}/inc
)