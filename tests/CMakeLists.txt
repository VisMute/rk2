cmake_minimum_required(VERSION 3.10)
project(G26Tests)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем тестовые исходные файлы
set(TEST_SOURCE_FILES
    t.cpp
)

# Создаем исполняемый файл для тестов
add_executable(G26Tests ${TEST_SOURCE_FILES})

# Линкуем тесты с библиотекой и Google Test
target_link_libraries(G26Tests PRIVATE G26Lib gtest gtest_main)

# Включаем тестирование
enable_testing()