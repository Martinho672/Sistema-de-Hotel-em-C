cmake_minimum_required(VERSION 3.14)
project(Definitivo C)

set(CMAKE_C_STANDARD 99)

add_executable(Definitivo main.c Hospede.h Operacaohospede.h Operacaohospede.c Helper.h Codigos.h Codigos.c OperacaoCodigo.h OperacaoCodigo.c)