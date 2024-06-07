cmake_minimum_required(VERSION 3.10)

project(G26)

# Добавляем основные файлы проекта
add_library(G26Lib SHARED
    G26_CRTP_1)

add_executable(G26Project
    Main.cpp
)

target_link_libraries(G26Project PRIVATE G26Lib)

# Добавляем Google Test с использованием FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Добавляем тестируемый исполняемый файл
add_executable(G26Tests
    tests/t.cpp
)

# Линкуем библиотеки Google Test
target_link_libraries(G26Tests
    PRIVATE
    gtest
    gtest_main
)

enable_testing()
add_test(NAME G26Tests COMMAND G26Tests)
