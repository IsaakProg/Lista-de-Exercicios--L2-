#include <stdio.h>
#include <string.h>

#define MAX_PARTICIPANTES 100
#define TAM_LETRA 5

typedef struct {
    int topo;
    char elementos[MAX_PARTICIPANTES][TAM_LETRA];
} Pilha;

void push(Pilha *p, const char *valor) {
    if (p->topo < MAX_PARTICIPANTES - 1) {
        strcpy(p->elementos[p->topo], valor);
        p->topo++;
    }
}

void pop(Pilha *p, char *valor) {
    if (p->topo > 0) {
        p->topo--;
        strcpy(valor, p->elementos[p->topo]);
    }
}

int main() {
    int n, ans;
    char c, aux[TAM_LETRA], aux2[TAM_LETRA], topoElem[TAM_LETRA];
    Pilha painel;

    while (scanf("%d", &n) != EOF) {
        painel.topo = 0;
        ans = 0;
        push(&painel, "FACE");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                scanf(" %c", &c);
                aux[j] = c;
            }
            aux[4] = '\0';

            for (int j = 0; j < 4; j++) {
                aux2[j] = aux[3 - j];
            }
            aux2[4] = '\0';

            if (painel.topo > 0) {
                pop(&painel, topoElem);
                if (strcmp(topoElem, aux2) == 0) {
                    ans++;
                    if (painel.topo == 0) {
                        push(&painel, "FACE");
                    }
                } else {
                    push(&painel, topoElem);
                    push(&painel, aux);
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
