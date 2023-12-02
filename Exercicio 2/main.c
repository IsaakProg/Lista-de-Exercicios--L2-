// main.c
#include "lista_circular.h"
#include <stdio.h>

int main() {
    Lista* l = inicializa();
    
    // 1. Inserção de 10 elementos
    for (int i = 1; i <= 10; i++) {
        l = insere(l, i * 10); // Insere múltiplos de 10
    }
    
    // 2. Impressão de todos elementos
    printf("Lista após inserções: ");
    imprime(l);
    
    // 3. Busca de 1 elemento presente na lista
    int valorBusca = 50;
    Lista* encontrado = busca(l, valorBusca);
    if (encontrado) {
        printf("Elemento %d encontrado na lista.\n", valorBusca);
    } else {
        printf("Elemento %d não encontrado na lista.\n", valorBusca);
    }
    
    // 4. Busca de 1 elemento não presente na lista
    valorBusca = 55;
    encontrado = busca(l, valorBusca);
    if (encontrado) {
        printf("Elemento %d encontrado na lista.\n", valorBusca);
    } else {
        printf("Elemento %d não encontrado na lista.\n", valorBusca);
    }
    
    // 5. Impressão de todos elementos
    printf("Lista após buscas: ");
    imprime(l);
    
    // 6. Retirar 2 elementos
    l = retira(l, 20); // Supõe-se que a função retira já está corretamente implementada.
    l = retira(l, 30);
    
    // Impressão de todos elementos após retiradas
    printf("Lista após retiradas: ");
    imprime(l);
    
    // Liberação de todos os elementos da lista
    libera(l); // Supõe-se que a função libera já está corretamente implementada.
    
    // 7. Impressão de todos elementos, deve estar vazia
    printf("Lista após liberação: ");
    imprime(l);
    
    // 8. Liberação de todos elementos da memória, se necessário
    l = NULL;

    return 0;
}

