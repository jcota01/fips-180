find_package(Catch2 3 REQUIRED)

set(TEST_SOURCES
    word/test_word.cpp
    word/test_word_operations.cpp
    word/test_word_shift.cpp
    block/test_block.cpp
    pad/test_pad.cpp
)

foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_link_libraries(${TEST_NAME} PRIVATE FIPS-180-LIB Catch2::Catch2WithMain)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()