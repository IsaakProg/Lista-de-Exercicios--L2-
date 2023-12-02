#ifndef CIRCULO_H
#define CIRCULO_H

typedef struct Elemento {
    int identificador;
    struct Elemento *seguinte;
} Elemento;

Elemento *inicializarElemento(int identificador);
Elemento *montarCirculo(int quantidade);
void executarJosephus(Elemento **referencia, int passo);

#endif
