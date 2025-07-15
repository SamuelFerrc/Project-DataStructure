#include <stdio.h>
#include "quick_sort.h"

/**
 * @brief Inverte os tipoes usando ponteiros
 * 
 * @param a Ponteiro para o primeiro inteiro.
 * @param b Ponteiro para o segundo inteiro.
 */
void trocar(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Particiona o array e faz a ordenação em torno do pivô v[fim].
 * 
 * @param v Array que será particionado.
 * @param ini Valor inteiro que indica o indíce que começa esse vetor.
 * @param fim Valor inteiro que indica o indíce que termina esse vetor.
 * @return o indíce onde encontra-se o meio desse vetor.
 */
int particiona(int v[],int ini,int fim){
    int pivo = v[fim];
    int i = ini-1;
    for(int j = ini;j<fim;j++){
        if(v[j] < pivo){
            i++;
            trocar(&v[i],&v[j]);
        }
    }
    trocar(&v[i+1],&v[fim]);
    return i+1; 
}
/**
 * @brief Ordena os valores em ordem crescente.
 * 
 * @param v Array onde estão os valores a serem ordenados.
 * @param ini Valor inteiro que indica o indíce que começa esse vetor.
 * @param fim Valor inteiro que indica o indíce que termina esse vetor.
 */
void quicksort(int v[],int ini,int fim){
    int pivo;
    if(ini < fim){
        pivo  = particiona(v,ini,fim);
        quicksort(v,ini,pivo-1);
        quicksort(v,pivo+1,fim);
    }
}
