#include <stdio.h>
#include <stdlib.h>

#include "lista_com_vetor.h"
#include "lista_dupla.h"
#include "fila_de_prioridade.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "arvore_AVL.h"

// Função de teste: Lista com vetor
void testar_lista_vetor() {
    ListaV lista;
    inicializar_vetor(&lista);

    int op, valor;
    do {
        printf("\n--- LISTA COM VETOR ---\n");
        printf("1 - Inserir\n2 - Excluir\n3 - Buscar\n4 - Exibir\n0 - Sair\nEscolha: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Valor: ");
                scanf("%d", &valor);
                inserir_vetor(&lista, valor);
                break;
            case 2:
                printf("Valor a excluir: ");
                scanf("%d", &valor);
                excluir(&lista, valor);
                break;
            case 3:
                printf("Valor a buscar: ");
                scanf("%d", &valor);
                printf(buscar_vetor(&lista, valor) ? "Encontrado\n" : "Nao encontrado\n");
                break;
            case 4:
                exibirLista(&lista);
                break;
        }
    } while (op != 0);

    libera_lista_vetor(&lista);
}

// Função de teste: Lista duplamente encadeada
void testar_lista_dupla() {
    ListaD *lista = NULL;
    int op, numero;
    char nome[100];

    do {
        printf("\n--- LISTA DUPLA ---\n");
        printf("1 - Inserir Inicio\n2 - Inserir Final\n3 - Remover por Nome\n4 - Exibir\n0 - Sair\nEscolha: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Nome: ");
                scanf(" %[^\n]", nome);
                printf("Número: ");
                scanf("%d", &numero);
                lista = insere_comeco(nome, numero, lista);
                break;
            case 2:
                printf("Nome: ");
                scanf(" %[^\n]", nome);
                printf("Número: ");
                scanf("%d", &numero);
                lista = insere_final(nome, numero, lista);
                break;
            case 3:
                printf("Nome a remover: ");
                scanf(" %[^\n]", nome);
                lista = remove_por_nome(nome, lista);
                break;
            case 4:
                mostra_lista(lista);
                break;
        }
    } while (op != 0);

    libera_lista_dupla(lista);
}

// Função de teste: Fila de prioridade
void testar_fila_prioridade() {
    fila_prioridade_t fila = {.tamanho = 0};
    int op, valor;

    do {
        printf("\n--- FILA DE PRIORIDADE ---\n");
        printf("1 - Inserir\n2 - Remover máximo\n3 - Exibir heap\n0 - Sair\nEscolha: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Valor: ");
                scanf("%d", &valor);
                inserir_valor(&fila, valor);
                break;
            case 2:
                printf("Máximo removido: %d\n", remover_maximo(&fila));
                break;
            case 3:
                printf("Heap: ");
                for (int i = 0; i < fila.tamanho; i++) {
                    printf("%d ", fila.dados[i]);
                }
                printf("\n");
                break;
        }
    } while (op != 0);
}

// Função de teste: Arvore AVL
void testar_arvore_AVL() {
    node_AVL *raiz = NULL;
    int op, valor;

    do {
        printf("\n--- ARVORE AVL ---\n");
        printf("1 - Inserir\n2 - Remover\n3 - Exibir em ordem\n0 - Sair\nEscolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Valor a inserir: ");
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
            break;
            case 2:
                printf("Valor a remover: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;
            case 3:
                printf("Em ordem: ");
            em_ordem(raiz);
            printf("\n");
            break;
        }
    } while (op != 0);

    liberar_AVL(raiz);
}

// Função de teste: Ordenações
void testar_ordenacoes() {
    int v[100], n, op;

    printf("\nTamanho do vetor: ");
    scanf("%d", &n);
    printf("Digite os %d elementos:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    printf("Escolha a ordenacao: 1 - MergeSort | 2 - QuickSort: ");
    scanf("%d", &op);

    if (op == 1) {
        merge_sort(v, 0, n - 1);
    } else {
        quicksort(v, 0, n - 1);
    }

    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int op;
    do {
        printf("\n====== MENU PRINCIPAL ======\n");
        printf("1 - Testar Lista com Vetor\n");
        printf("2 - Testar Lista Dupla\n");
        printf("3 - Testar Fila de Prioridade\n");
        printf("4 - Testar Ordenacoes (Merge/Quick)\n");
        printf("5 - Testar Arvore AVL\n");
        printf("0 - Sair\nEscolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1: testar_lista_vetor(); break;
            case 2: testar_lista_dupla(); break;
            case 3: testar_fila_prioridade(); break;
            case 4: testar_ordenacoes(); break;
            case 5: testar_arvore_AVL(); break;
        }
    } while (op != 0);

    return 0;
}
