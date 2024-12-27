find_package(Catch2 3 REQUIRED)

# Add the test executable
add_executable(test_fips_180 test_fips_180.cpp)

# Link the library to the test executable
target_link_libraries(test_fips_180 PRIVATE FIPS-180-LIB)
target_link_libraries(test_fips_180 PRIVATE Catch2::Catch2WithMain)

# Add the test
add_test(NAME TestFips180 COMMAND test_fips_180)
