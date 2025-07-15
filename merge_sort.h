#ifndef MERGESORT_H
#define MERGESORT_H

/**
 * @brief Combina duas subpartes ordenadas de um vetor em uma única sequência ordenada.
 *
 * @param arr Vetor de inteiros a ser processado.
 * @param inicio Índice inicial da primeira subparte.
 * @param meio Índice final da primeira subparte (meio do vetor).
 * @param fim Índice final da segunda subparte.
 */
void mesclar(int arr[], int inicio, int meio, int fim);

/**
 * @brief Ordena um vetor de inteiros utilizando o algoritmo Merge Sort.
 *
 * @param arr Vetor de inteiros a ser ordenado.
 * @param inicio Índice inicial do vetor a ser ordenado.
 * @param fim Índice final do vetor a ser ordenado.
 */
void merge_sort(int arr[], int inicio, int fim);

#endif // MERGESORT_H
