#include <stdio.h>
#include <stdlib.h>
#include "lista_com_vetor.h"

/**
 * @brief Inicializa a lista tornando seu tamanho zero.
 *
 * @param lista ponteiro para a estrutura que será inicializada.
 */
void inicializar_vetor(ListaV *lista){
    lista->tam=0;
    lista->capacidade=20;
    lista->itens = malloc(lista->capacidade * sizeof(int));
}
/**
 * @brief Insere um valor no final da lista, se houver espaço.
 *
 * @param lista Ponteiro para a estrutura do tipo Lista onde o valor será adicionado.
 * @param valor Valor inteiro que será adicionado.
 */
void inserir_vetor(ListaV *lista, int valor){
    if(lista->tam == lista->capacidade ){
        lista->capacidade *=2;
        int *novo = realloc(lista->itens,lista->capacidade * sizeof(int));
        if(novo == NULL){
            printf("Erro ao alocar memória");
            free(lista->itens);
            exit(EXIT_FAILURE);
        }
        lista->itens = novo;
    }
    lista->itens[lista->tam++] = valor;
}
/**
 * @brief Exclui o primeiro valor indicado no parâmetro.
 *
 * @param lista Ponteiro para a lista onde o valor será excluido.
 * @param valor Valor inteiro que será excluido.
 */
void excluir(ListaV *lista,int valor){
    for(int i=0;i<lista->tam;i++){
        if(lista->itens[i] == valor){
            for(int j = i;j<lista->tam-1;j++){
                lista->itens[j] = lista->itens[j+1];
            }
            lista->tam--;
            printf("Valor excluido com sucesso\n");
            return;
        }
    }
    printf("Valor não encontrado\n");
}
/**
 * @brief Busca um valor na lista.
 *
 * @param lista Ponteiro da lista onde será buscado.
 * @param valor Valor inteiro que será buscado.
 * @return true se o valor existir na lista; senão false.
 */
bool buscar_vetor(ListaV *lista,int valor){
    for(int i=0;i<lista->tam;i++){
        if(lista->itens[i]==valor){
            return true;
        }
    }
    return false;
}
/**
 * @brief Libera o array alocado e muda os campos da lista para um padrão.
 *
 * @param lista Ponteiro da lista que será liberada.
 */
void libera_lista_vetor(ListaV *lista){
    free(lista->itens);
    lista->itens = NULL;
    lista->tam = 0;
    lista->capacidade = 0;
}
/**
 * @brief Exibe todos os elementos da lista.
 *
 * @param lista Ponteiro da lista que será exibida.
 */
void exibirLista(ListaV *lista){
    for(int i = 0;i<lista->tam;i++){
        printf("%2d ",lista->itens[i]);
    }printf("\n");
}

