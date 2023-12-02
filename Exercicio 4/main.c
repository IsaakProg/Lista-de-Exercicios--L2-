#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE 1000

typedef struct {
    int contador;
    int dados[CAPACIDADE];
} ControlePilha;

void ConfiguraPilha(ControlePilha* controle) { controle->contador = -1; }

int VerificaPilhaVazia(ControlePilha* controle) { return controle->contador == -1; }

int VerificaPilhaCheia(ControlePilha* controle) { return controle->contador == CAPACIDADE - 1; }

int AdicionarElemento(ControlePilha* controle, int elemento) {
    if (VerificaPilhaCheia(controle)) {
        printf("Aviso: Capacidade máxima da pilha atingida.\n");
        return 0;
    }
    controle->dados[++controle->contador] = elemento;
    return elemento;
}

int RemoverElemento(ControlePilha* controle) {
    if (VerificaPilhaVazia(controle)) {
        printf("Aviso: Não há elementos para remover.\n");
        return -1;
    }
    return controle->dados[controle->contador--];
}

int main() {
    ControlePilha pilha;
    ConfiguraPilha(&pilha);
    
    printf("--INSERINDO NA PILHA--\n");
    printf("Inserido: %d\n", AdicionarElemento(&pilha, 10));
    printf("Inserido: %d\n", AdicionarElemento(&pilha, 20));
    printf("Inserido: %d\n", AdicionarElemento(&pilha, 30));
    
    printf("--REMOVENDO DA PILHA--\n");
    printf("Removido: %d\n", RemoverElemento(&pilha));
    printf("Removido: %d\n", RemoverElemento(&pilha));
    printf("Removido: %d\n", RemoverElemento(&pilha));
    
    printf("--ESTADO FINAL DA PILHA--\n");
    if (VerificaPilhaVazia(&pilha)) {
        printf("A pilha está agora vazia.\n");
    } else {
        printf("Ainda há elementos na pilha.\n");
    }
    
    return 0;
}
