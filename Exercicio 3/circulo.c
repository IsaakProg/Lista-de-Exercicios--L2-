#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"

Elemento *inicializarElemento(int identificador) {
    Elemento *novoElemento = (Elemento*) malloc(sizeof(Elemento));
    novoElemento->identificador = identificador;
    novoElemento->seguinte = novoElemento;
    return novoElemento;
}

Elemento *montarCirculo(int quantidade) {
    if (quantidade == 0) return NULL;
    
    Elemento *primeiro = inicializarElemento(1);
    Elemento *atual = primeiro;

    for (int i = 2; i <= quantidade; i++) {
        atual->seguinte = inicializarElemento(i);
        atual = atual->seguinte;
    }
    atual->seguinte = primeiro; // Fecha o círculo
    return primeiro;
}

void executarJosephus(Elemento **referencia, int passo) {
    Elemento *atual = *referencia, *anterior = NULL;

    while (atual != atual->seguinte) {
        for (int cont = 1; cont < passo; ++cont) {
            anterior = atual;
            atual = atual->seguinte;
        }
        anterior->seguinte = atual->seguinte;
        if (atual == *referencia) *referencia = anterior->seguinte;
        free(atual);
        atual = anterior->seguinte;
    }
}


#endif // CIRCULO_H

