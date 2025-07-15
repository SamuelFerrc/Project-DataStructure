#include <stdio.h>
#include <stdlib.h>
#include "arvore_AVL.h"

/**
 * @brief Retorna o maior entre dois valores inteiros.
 */
int max(int a, int b) {
    return (a > b) ? a : b;
}
/**
 * @brief Retorna o menor valor do nó
 */
node_AVL* menor_no(node_AVL *no) {
    node_AVL *atual = no;
    while (atual->esq != NULL)
        atual = atual->esq;
    return atual;
}


/**
 * @brief Cria um novo nó com o valor informado.
 *
 * @param x Valor a ser armazenado no nó.
 * @return Ponteiro para o novo nó criado.
 */
node_AVL* criar_no(int x) {
    node_AVL* no = (node_AVL*)malloc(sizeof(node_AVL));
    no->dado = x;
    no->altura = 1;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

/**
 * @brief Retorna a altura de um nó.
 *
 * @param no Ponteiro para o nó.
 * @return Altura do nó. Se for NULL, retorna 0.
 */
int altura(node_AVL *no) {
    if (no == NULL)
        return 0;
    return no->altura;
}

/**
 * @brief Calcula o fator de balanceamento de um nó.
 *
 * @param no Ponteiro para o nó.
 * @return Diferença entre altura da subárvore direita e esquerda.
 */
int fator_balanceamento(node_AVL *no) {
    if (no == NULL)
        return 0;
    return altura(no->dir) - altura(no->esq);
}

/**
 * @brief Atualiza a altura de um nó com base nas alturas dos filhos.
 *
 * @param no Ponteiro para o nó.
 */
void atualizar_altura(node_AVL *no) {
    if (no != NULL)
        no->altura = 1 + max(altura(no->esq), altura(no->dir));
}

/**
 * @brief Realiza uma rotação simples para a direita.
 *
 * @param y Nó desbalanceado.
 * @return Novo nó raiz após a rotação.
 */
node_AVL* rotacao_direita(node_AVL *y) {
    node_AVL *x = y->esq;
    node_AVL *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    atualizar_altura(y);
    atualizar_altura(x);

    return x;
}

/**
 * @brief Realiza uma rotação simples para a esquerda.
 *
 * @param x Nó desbalanceado.
 * @return Novo nó raiz após a rotação.
 */
node_AVL* rotacao_esquerda(node_AVL *x) {
    node_AVL *y = x->dir;
    node_AVL *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    atualizar_altura(x);
    atualizar_altura(y);

    return y;
}

/**
 * @brief Rebalanceia a árvore no nó fornecido.
 *
 * @param no Nó que pode estar desbalanceado.
 * @return Novo nó raiz após o rebalanceamento.
 */
node_AVL* rebalancear(node_AVL *no) {
    atualizar_altura(no);
    int fb = fator_balanceamento(no);

    if (fb > 1) {
        if (fator_balanceamento(no->dir) < 0)
            no->dir = rotacao_direita(no->dir);
        return rotacao_esquerda(no);
    }

    if (fb < -1) {
        if (fator_balanceamento(no->esq) > 0)
            no->esq = rotacao_esquerda(no->esq);
        return rotacao_direita(no);
    }

    return no;
}

/**
 * @brief Insere um valor na árvore AVL.
 *
 * @param raiz Raiz da árvore.
 * @param x Valor a ser inserido.
 * @return Nova raiz da árvore após inserção e rebalanceamento.
 */
node_AVL* inserir(node_AVL *raiz, int x) {
    if (raiz == NULL)
        return criar_no(x);

    if (x < raiz->dado)
        raiz->esq = inserir(raiz->esq, x);
    else if (x > raiz->dado)
        raiz->dir = inserir(raiz->dir, x);
    else
        return raiz;

    return rebalancear(raiz);
}

/**
 * @brief Remove um valor da árvore AVL.
 *
 * @param raiz Raiz da árvore.
 * @param x Valor a ser removido.
 * @return Nova raiz da árvore após a remoção e rebalanceamento.
 */
node_AVL* remover(node_AVL *raiz, int x) {
    if (raiz == NULL)
        return NULL;

    if (x < raiz->dado) {
        raiz->esq = remover(raiz->esq, x);
    } else if (x > raiz->dado) {
        raiz->dir = remover(raiz->dir, x);
    } else {
        if (raiz->esq == NULL || raiz->dir == NULL) {
            node_AVL *temp = raiz->esq ? raiz->esq : raiz->dir;
            free(raiz);
            return temp;
        } else {
            node_AVL *temp = menor_no(raiz->dir);
            raiz->dado = temp->dado;
            raiz->dir = remover(raiz->dir, temp->dado);
        }
    }

    return rebalancear(raiz);
}

/**
 * @brief Exibe os elementos da árvore em ordem (in-order).
 *
 * @param raiz Raiz da árvore.
 */
void em_ordem(node_AVL *raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esq);
        printf("%d ", raiz->dado);
        em_ordem(raiz->dir);
    }
}

/**
 * @brief Libera toda a memória alocada para a árvore.
 *
 * @param raiz Raiz da árvore.
 */
void liberar_AVL(node_AVL *raiz) {
    if (raiz != NULL) {
        liberar_AVL(raiz->esq);
        liberar_AVL(raiz->dir);
        free(raiz);
    }
}
