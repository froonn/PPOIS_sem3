Все файлы исходного кода библиотеки находятся в директории `real_matrix`.

# компиляция

Для успешной компиляции программы необходимо установить библиотеку [`UnitTest++`](https://github.com/unittest-cpp/unittest-cpp)

Компиляция производится с помощью утилиты `сmake`:

```bash
mkdir build
cd build
cmake ..
make
```

# запуск тестов

Запуск тестов производится с помощью утилиты `ctest` из директории `build`:

```bash
ctest
```

# cборка документации

Сборка документации производится с помощью утилиты `doxygen`:

```bash
doxygen -g
doxygen Doxyfile
```
# использование с помощью CMake

Для использования библиотеки в вашем проекте необходимо добавить следующие строки в `CMakeLists.txt`:

```cmake
include_directories(real_matrix/include)
link_directories(real_matrix/build)

add_executable(your_executable_name your_source_files.cpp)

target_link_libraries(your_executable_name real_matrix)
```

Замените `your_executable_name` на имя вашего исполняемого файла, а `your_source_files.cpp` на ваши исходные файлы.


