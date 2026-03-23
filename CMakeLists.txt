cmake_minimum_required(VERSION 3.10)

project(Hcow)

set(CMAKE_C_STANDARD 99)

# Pega todos os arquivos .c
file(GLOB SRC_FILES "lib/modules/*.c")

# Cria biblioteca estática
add_library(hcow STATIC ${SRC_FILES})

# Inclui headers
target_include_directories(hcow PUBLIC lib)
