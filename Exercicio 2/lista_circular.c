// lista_circular.c
#include "lista_circular.h"
#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info;
    struct lista *prox;
};

// Inicializa uma lista vazia
Lista* inicializa(void) {
    return NULL;
}

// Insere um elemento na lista
Lista* insere(Lista* l, int v) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if (novo == NULL) {
        exit(1);
    }
    novo->info = v;
    if (l == NULL) {
        novo->prox = novo; // Faz o novo nó apontar para si mesmo
    } else {
        novo->prox = l->prox;
        l->prox = novo;
    }
    return novo; // Retorna o novo nó como o "inicial"
}

// Função para imprimir os elementos da lista
void imprime(Lista* l) {
    Lista* p = l;
    if (p) {
        do {
            printf("%d ", p->info);
            p = p->prox;
        } while (p != l);
        printf("\n");
    }
}

// Função para buscar um elemento na lista
Lista* busca(Lista* l, int v) {
    Lista* p = l;
    if (p) {
        do {
            if (p->info == v)
                return p;
            p = p->prox;
        } while (p != l);
    }
    return NULL; // Não encontrado
}

// Função para retirar um elemento da lista
Lista* retira(Lista* l, int v) {
    // Implementação da função retira para lista circular
    // ...
}

// Função para liberar a lista da memória
void libera(Lista* l) {
    // Implementação da função libera para lista circular
    // ...
}
