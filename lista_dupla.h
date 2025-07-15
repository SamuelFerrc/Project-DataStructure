#ifndef LISTADUPLA_H
#define LISTADUPLA_H

#define TAM_NOME 100

/**
 * @struct ListaD
 * @brief Estrutura que representa um nó de uma lista duplamente encadeada.
 *
 * Campos:
 * - nome: string que armazena o nome do contato
 * - numero: número inteiro associado ao contato
 * - prox: ponteiro para o próximo nó da lista
 * - ant: ponteiro para o nó anterior da lista
 */
typedef struct lista {
    char nome[TAM_NOME];
    int numero;
    struct lista* prox;
    struct lista* ant;
} ListaD;

/**
 * @brief Insere um novo nó no início da lista.
 *
 * @param nome Nome a ser armazenado no novo nó.
 * @param numero Número inteiro a ser armazenado.
 * @param no Ponteiro para o primeiro nó atual da lista.
 * @return Ponteiro para o novo primeiro nó da lista.
 */
ListaD* insere_comeco(char* nome, int numero, ListaD* no);

/**
 * @brief Insere um novo nó no final da lista.
 *
 * @param nome Nome a ser armazenado no novo nó.
 * @param numero Número inteiro a ser armazenado.
 * @param no Ponteiro para o primeiro nó atual da lista.
 * @return Ponteiro para o primeiro nó da lista (inicial).
 */
ListaD* insere_final(char* nome, int numero, ListaD* no);

/**
 * @brief Procura um nó da lista que contenha o nome indicado.
 *
 * @param nome Nome a ser buscado.
 * @param no Ponteiro para o primeiro nó da lista.
 * @return Ponteiro para o nó encontrado, ou NULL se não existir.
 */
ListaD* procura_por_nome(char* nome, ListaD* no);

/**
 * @brief Remove o primeiro nó encontrado com o nome indicado.
 *
 * @param nome Nome do nó a ser removido.
 * @param no Ponteiro para o primeiro nó da lista.
 * @return Ponteiro para o primeiro nó da lista após a remoção.
 */
ListaD* remove_por_nome(char* nome, ListaD* no);

/**
 * @brief Libera todos os nós da lista, desalocando memória.
 *
 * @param no Ponteiro para o primeiro nó da lista.
 */
void libera_lista_dupla(ListaD* no);

/**
 * @brief Exibe todos os nós da lista com seus respectivos dados.
 *
 * @param no Ponteiro para o primeiro nó da lista.
 */
void mostra_lista(ListaD* no);

#endif // LISTADUPLA_H
