#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#define TAM_MAX 100

/**
 * @struct fila_prioridade_t
 * @brief Estrutura que representa uma fila de prioridade (heap máximo).
 *
 * Campos:
 * - dados: array que armazena os elementos do heap
 * - tamanho: quantidade atual de elementos no heap
 */
typedef struct {
 int dados[TAM_MAX];
 int tamanho;
} fila_prioridade_t;

/**
 * @brief Reorganiza o heap de cima para baixo para manter a propriedade de heap.
 *
 * @param fila Ponteiro para o heap que será ajustado.
 * @param i Índice a partir do qual o ajuste será feito.
 */
void desce_heap(fila_prioridade_t *fila, int i);

/**
 * @brief Reorganiza o heap de baixo para cima para manter a propriedade de heap.
 *
 * @param fila Ponteiro para o heap que será ajustado.
 * @param i Índice do elemento inserido que será ajustado.
 */
void sobe_heap(fila_prioridade_t *fila, int i);

/**
 * @brief Constrói um heap máximo a partir de um vetor já carregado na estrutura.
 *
 * @param fila Ponteiro para a fila de prioridade a ser construída.
 * @return Ponteiro para a estrutura fila_prioridade_t já ajustada.
 */
fila_prioridade_t *construir_heap(fila_prioridade_t *fila);

/**
 * @brief Insere um novo valor no heap, mantendo a propriedade de heap.
 *
 * @param fila Ponteiro para o heap onde o valor será inserido.
 * @param valor Valor inteiro que será inserido.
 */
void inserir_valor(fila_prioridade_t *fila, int valor);

/**
 * @brief Remove e retorna o maior valor do heap (a raiz).
 *
 * @param fila Ponteiro para o heap de onde o valor será removido.
 * @return Valor máximo removido do heap.
 */
int remover_maximo(fila_prioridade_t *fila);

#endif // FILA_PRIORIDADE_H
