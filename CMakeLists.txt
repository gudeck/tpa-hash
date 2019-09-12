cmake_minimum_required(VERSION 3.14)
project(tpa_hash C)

set(CMAKE_C_STANDARD 11)

add_executable(tpa_hash src/main.c src/headers/main.h src/hash.c src/headers/hash.h src/cliente.c src/headers/cliente.h src/hashAberto.c src/headers/hashAberto.h src/hashFechado.c src/headers/hashFechado.h)