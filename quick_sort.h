#ifndef QUICKSORT_H
#define QUICKSORT_H

/**
 * @brief Inverte os tipoes usando ponteiros
 * 
 * @param a Ponteiro para o primeiro inteiro.
 * @param b Ponteiro para o segundo inteiro.
 */
void trocar(int *a,int *b);

/**
 * @brief Particiona o array e faz a ordenação em torno do pivô v[fim].
 * 
 * @param v Array que será particionado.
 * @param ini Valor inteiro que indica o indíce que começa esse vetor.
 * @param fim Valor inteiro que indica o indíce que termina esse vetor.
 * @return o indíce onde encontra-se o meio desse vetor.
 */
int particiona(int v[],int ini,int fim);

/**
 * @brief Ordena os valores em ordem crescente.
 * 
 * @param v Array onde estão os valores a serem ordenados.
 * @param ini Valor inteiro que indica o indíce que começa esse vetor.
 * @param fim Valor inteiro que indica o indíce que termina esse vetor.
 */
void quicksort(int v[],int ini,int fim);

#endif