cmake_minimum_required(VERSION 3.14)
project(PalindromeChecker)

set(CMAKE_CXX_STANDARD 17)


if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/googletest/CMakeLists.txt)
    add_subdirectory(googletest)
else()

    find_package(GTest REQUIRED)
endif()


add_library(palindrome_lib 
    src/palindrome.cpp
)


target_include_directories(palindrome_lib 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)


add_executable(palindrome_tests 
    tests/test_palindrome.cpp
)


if(TARGET gtest)
    target_link_libraries(palindrome_tests 
        palindrome_lib 
        gtest 
        gtest_main
    )
else()
    target_link_libraries(palindrome_tests 
        palindrome_lib 
        GTest::GTest 
        GTest::Main
    )
endif()


target_include_directories(palindrome_tests 
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)


enable_testing()
add_test(NAME PalindromeTests COMMAND palindrome_tests)