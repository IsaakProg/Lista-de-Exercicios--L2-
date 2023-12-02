// lista_circular.h
#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

typedef struct lista Lista;

Lista* inicializa(void);
Lista* insere(Lista* l, int v);
void imprime(Lista* l);
Lista* busca(Lista* l, int v);
Lista* retira(Lista* l, int v);
void libera(Lista* l);

#endif
