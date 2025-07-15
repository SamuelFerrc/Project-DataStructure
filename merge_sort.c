#include "merge_sort.h"

void mesclar(int vetor[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int esquerda[n1], direita[n2];

    for (int i = 0; i < n1; i++) {
        esquerda[i] = vetor[inicio + i];
    }

    for (int i = 0; i < n2; i++) {
        direita[i] = vetor[meio + 1 + i];
    }

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        if (esquerda[i] <= direita[j]) {
            vetor[k++] = esquerda[i++];
        } else {
            vetor[k++] = direita[j++];
        }
    }

    while (i < n1) {
        vetor[k++] = esquerda[i++];
    }

    while (j < n2) {
        vetor[k++] = direita[j++];
    }
}

void merge_sort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio + 1, fim);

        mesclar(vetor, inicio, meio, fim);
    }
}
