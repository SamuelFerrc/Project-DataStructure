cmake_minimum_required(VERSION 3.29)
project(ED_Projeto C)

set(CMAKE_C_STANDARD 11)

include_directories(Project-DataStructure/Bibliotecas)

add_executable(ED_Projeto
    Project-DataStructure/Bibliotecas/arvore.c
    Project-DataStructure/Bibliotecas/arvore.h
    Project-DataStructure/Bibliotecas/fila_de_prioridade.c
    Project-DataStructure/Bibliotecas/fila_de_prioridade.h
    Project-DataStructure/Bibliotecas/lista_com_vetor.c
    Project-DataStructure/Bibliotecas/lista_com_vetor.h
    Project-DataStructure/Bibliotecas/listadupla.c
    Project-DataStructure/Bibliotecas/listadupla.h
    Project-DataStructure/Bibliotecas/mergesort.c
    Project-DataStructure/Bibliotecas/mergesort.h
    Project-DataStructure/Bibliotecas/quicksort.c
    Project-DataStructure/Bibliotecas/quicksort.h
    Project-DataStructure/main.c)
