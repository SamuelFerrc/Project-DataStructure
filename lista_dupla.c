#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_dupla.h"

/**
 * @brief Insere um novo nó no início da lista.
 *
 * @param nome Nome a ser armazenado no novo nó.
 * @param numero Número inteiro a ser armazenado.
 * @param no Ponteiro para o primeiro nó atual da lista.
 * @return Ponteiro para o novo primeiro nó da lista.
 */
ListaD* insere_comeco(char* nome, int numero, ListaD* no){
    ListaD* novo_no = (ListaD*)malloc(sizeof(ListaD));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória");
        exit(1);
    }
    strcpy(novo_no->nome, nome);
    novo_no->numero = numero;
    novo_no->prox = no;
    novo_no->ant = NULL;

    if (no != NULL) {
        no->ant = novo_no;
    }

    return novo_no;
}

/**
 * @brief Insere um novo nó no final da lista.
 *
 * @param nome Nome a ser armazenado no novo nó.
 * @param numero Número inteiro a ser armazenado.
 * @param no Ponteiro para o primeiro nó atual da lista.
 * @return Ponteiro para o primeiro nó da lista (inicial).
 */
ListaD* insere_final(char* nome, int numero, ListaD* no){
    if (no == NULL) {
        return insere_comeco(nome, numero, no);
    }
    ListaD* aux_no = no;
    ListaD* novo_no = (ListaD*)malloc(sizeof(ListaD));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória");
        exit(1);
    }
    strcpy(novo_no->nome, nome);
    novo_no->numero = numero;
    novo_no->prox = NULL;

    while (aux_no->prox != NULL){
        aux_no = aux_no->prox;
    }
    aux_no->prox = novo_no;
    novo_no->ant = aux_no;
    return no;
}

/**
 * @brief Procura um nó da lista que contenha o nome indicado.
 *
 * @param nome Nome a ser buscado.
 * @param no Ponteiro para o primeiro nó da lista.
 * @return Ponteiro para o nó encontrado, ou NULL se não existir.
 */
ListaD* procura_por_nome(char* nome, ListaD* no){
    if (no == NULL){
        return NULL;
    }
    while (no != NULL){
        if (strcmp(no->nome, nome) == 0){
            return no;
        }
        no = no->prox;
    }
    return NULL;
}

/**
 * @brief Remove o primeiro nó encontrado com o nome indicado.
 *
 * @param nome Nome do nó a ser removido.
 * @param no Ponteiro para o primeiro nó da lista.
 * @return Ponteiro para o primeiro nó da lista após a remoção.
 */
ListaD* remove_por_nome(char* nome, ListaD* no){
    ListaD* escolhido = procura_por_nome(nome, no);
    if (escolhido == NULL){
        return no;
    }
    if (escolhido == no){
        ListaD* prox_no = no->prox;
        free(escolhido);
        if (prox_no != NULL) {
            prox_no->ant = NULL;
        }
        return prox_no;
    }
    else{
        if (escolhido->ant != NULL) {
            escolhido->ant->prox = escolhido->prox;
        }
        if (escolhido->prox != NULL){
            escolhido->prox->ant = escolhido->ant;
        }
        free(escolhido);
        return no;
    }
}

/**
 * @brief Libera todos os nós da lista, desalocando memória.
 *
 * @param no Ponteiro para o primeiro nó da lista.
 */
void libera_lista_dupla(ListaD *no){
    while (no != NULL){
        ListaD* temp = no;
        no = no->prox;
        free(temp);
    }
}

/**
 * @brief Exibe todos os nós da lista com seus respectivos dados.
 *
 * @param no Ponteiro para o primeiro nó da lista.
 */
void mostra_lista(ListaD* no){
    if (no == NULL){
        printf("LISTA VAZIA\n");
        return;
    }
    while (no != NULL){
        printf("NOME: %s\n", no->nome);
        printf("NUMERO: %d\n\n", no->numero);
        no = no->prox;
    }
}
