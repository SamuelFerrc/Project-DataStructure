cmake_minimum_required(VERSION 3.29)
project(ED_Projeto C)

set(CMAKE_C_STANDARD 11)

include_directories(Project-DataStructure/Bibliotecas)

add_executable(ED_Projeto
    Project-DataStructure/Bibliotecas/arvore_AVL.c
    Project-DataStructure/Bibliotecas/arvore_AVL.h
    Project-DataStructure/Bibliotecas/fila_de_prioridade.c
    Project-DataStructure/Bibliotecas/fila_de_prioridade.h
    Project-DataStructure/Bibliotecas/lista_com_vetor.c
    Project-DataStructure/Bibliotecas/lista_com_vetor.h
    Project-DataStructure/Bibliotecas/lista_dupla.c
    Project-DataStructure/Bibliotecas/lista_dupla.h
    Project-DataStructure/Bibliotecas/merge_sort.c
    Project-DataStructure/Bibliotecas/merge_sort.h
    Project-DataStructure/Bibliotecas/quick_sort.c
    Project-DataStructure/Bibliotecas/quick_sort.h
    Project-DataStructure/main.c)
