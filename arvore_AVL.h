#ifndef ARVOREAVL_H
#define ARVOREAVL_H

/**
 * @struct node_AVL
 * @brief Estrutura de um nó da árvore AVL.
 *
 * Campos:
 * - info: valor armazenado no nó.
 * - height: altura do nó.
 * - left: ponteiro para o filho à esquerda.
 * - right: ponteiro para o filho à direita.
 */
typedef struct node_AVL {
    int dado;
    int altura;
    struct node_AVL *esq;
    struct node_AVL *dir;
} node_AVL;

/**
 * @brief Cria um novo nó com o valor informado.
 *
 * @param x Valor a ser armazenado no nó.
 * @return Ponteiro para o novo nó criado.
 */
node_AVL* criar_no(int x);

/**
 * @brief Retorna a altura de um nó.
 *
 * @param no Ponteiro para o nó.
 * @return Altura do nó. Se for NULL, retorna 0.
 */
int altura(node_AVL *no);

/**
 * @brief Calcula o fator de balanceamento de um nó.
 *
 * @param no Ponteiro para o nó.
 * @return Diferença entre altura da subárvore direita e esquerda.
 */
int fator_balanceamento(node_AVL *no);

/**
 * @brief Atualiza a altura de um nó com base nas alturas dos filhos.
 *
 * @param no Ponteiro para o nó.
 */
void atualizar_altura(node_AVL *no);

/**
 * @brief Realiza uma rotação simples para a direita.
 *
 * @param y Nó desbalanceado.
 * @return Novo nó raiz após a rotação.
 */
node_AVL* rotacao_direita(node_AVL *y);

/**
 * @brief Realiza uma rotação simples para a esquerda.
 *
 * @param x Nó desbalanceado.
 * @return Novo nó raiz após a rotação.
 */
node_AVL* rotacao_esquerda(node_AVL *x);

/**
 * @brief Rebalanceia a árvore no nó fornecido.
 *
 * @param no Nó que pode estar desbalanceado.
 * @return Novo nó raiz após o rebalanceamento.
 */
node_AVL* rebalancear(node_AVL *no);

/**
 * @brief Insere um valor na árvore AVL.
 *
 * @param raiz Raiz da árvore.
 * @param x Valor a ser inserido.
 * @return Nova raiz da árvore após inserção e rebalanceamento.
 */
node_AVL* inserir(node_AVL *raiz, int x);

/**
 * @brief Remove um valor da árvore AVL.
 *
 * @param raiz Raiz da árvore.
 * @param x Valor a ser removido.
 * @return Nova raiz da árvore após a remoção e rebalanceamento.
 */
node_AVL* remover(node_AVL *raiz, int x);

/**
 * @brief Exibe os elementos da árvore em ordem (in-order).
 *
 * @param raiz Raiz da árvore.
 */
void em_ordem(node_AVL *raiz);

/**
 * @brief Libera toda a memória alocada para a árvore.
 *
 * @param raiz Raiz da árvore.
 */
void liberar_AVL(node_AVL *raiz);

#endif // ARVOREAVL_H
