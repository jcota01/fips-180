set(sources ${sources}
    src/word.cpp
    src/pad.cpp
)

add_library(FIPS-180-LIB SHARED 
    ${sources}
)

target_include_directories(FIPS-180-LIB PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)