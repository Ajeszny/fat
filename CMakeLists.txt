#
# DANTE :: System Automatycznych Testów Jednostkowych oraz Akceptacyjnych
# Tomasz Jaworski, 2018-2020
#
# Plik wygenerowany automatycznie
# Znacznik czasowy: 2024-01-21 14:46:45.923346
#

cmake_minimum_required(VERSION 3.17)
project(project1 C)

# Przyjmij standard C11
set(CMAKE_C_STANDARD 11)

# Ustaw opcje kompilatora (z raportu Dante)
add_compile_options(
      "-Wno-parentheses"
      "-xc"
      "-Werror=vla"
      "-Wall"
      "-Wno-error=parentheses"
      "-fmax-errors=5"
      "-Wno-error=unused-parameter"
      "-D_GNU_SOURCE"
      "-pedantic"
      "-Wextra"
      "-std=c11"
      "-Wno-error=implicit-fallthrough"
      "-fdiagnostics-color"
      "-DINSIDE_DANTE"
      "-Werror"
      "-D_ANSI_OUTPUT"
      "-ggdb3"

)

# Ustaw opcje konsolidatora (z raportu Dante)
add_link_options(
        "-Wl,-wrap,main"
        "-Wl,-cref"
        "-Wl,-Map=main.map"
        "-ggdb3"
)

# Utwórz target 'project1' i dodaj do niego pliki źródlowe:
add_executable(project1
        "ajesznutils.c"
        "file_reader.c"
        "main.c"
        "unit_helper_v2.c"
        "unit_test_v2.c"
        "rdebug.c"
)

# Dołącz niezbędne biblioteki
target_link_libraries(project1
        "m"
)