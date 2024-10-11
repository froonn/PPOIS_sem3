Все файлы исходного кода библиотеки находятся в директории `real_matrix`.

Библиотека компилируется как SHARED.

# компиляция

Для успешной компиляции библиотеки необходимо установить google test

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
doxygen Doxyfile
```
# использование с помощью CMake

Для использования библиотеки в вашем проекте необходимо добавить следующие строки в `CMakeLists.txt`:

```cmake
add_subdirectory(real_matrix)
include_directories(real_matrix/include)

add_executable(<your_executable_name> <your_source_files.cc>)

target_link_libraries(<your_executable_name> real_matrix)
```

Замените `<your_executable_name>` на имя вашего исполняемого файла, а `<your_source_files.cc>` на ваши исходные файлы.
