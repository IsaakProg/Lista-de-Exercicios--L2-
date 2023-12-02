#include <stdio.h>
#include <stdlib.h>

typedef struct noArvore {
    int chave;
    int balanceamento;
    struct noArvore *ramoEsq;
    struct noArvore *ramoDir;
} NoArvore;

NoArvore* criaArvoreVazia(void) {
    return NULL;
}

NoArvore* novoNo(int valor, NoArvore* esquerda, NoArvore* direita) {
    NoArvore* no = (NoArvore*)malloc(sizeof(NoArvore));
    no->chave = valor;
    no->balanceamento = 0; // Inicializa o fator de balanceamento como 0
    no->ramoEsq = esquerda;
    no->ramoDir = direita;
    return no;
}

int arvoreEstaVazia(NoArvore* arvore) {
    return arvore == NULL;
}

NoArvore* buscaNo(NoArvore* arvore, int valor) {
    if (arvoreEstaVazia(arvore))
        return NULL;
    if (valor < arvore->chave)
        return buscaNo(arvore->ramoEsq, valor);
    else if (valor > arvore->chave)
        return buscaNo(arvore->ramoDir, valor);
    return arvore;
}

NoArvore* liberaArvore(NoArvore* arvore) {
    if (!arvoreEstaVazia(arvore)) {
        liberaArvore(arvore->ramoEsq);
        liberaArvore(arvore->ramoDir);
        free(arvore);
    }
    return NULL;
}

NoArvore* insereNo(NoArvore* arvore, int valor) {
    if (arvoreEstaVazia(arvore))
        return novoNo(valor, NULL, NULL);
    else if (valor < arvore->chave)
        arvore->ramoEsq = insereNo(arvore->ramoEsq, valor);
    else
        arvore->ramoDir = insereNo(arvore->ramoDir, valor);
    return arvore;
}

void exibeEmOrdem(NoArvore* arvore) {
    if (!arvoreEstaVazia(arvore)) {
        exibeEmOrdem(arvore->ramoEsq);
        printf("%d ", arvore->chave);
        exibeEmOrdem(arvore->ramoDir);
    }
}

int main(void) {
    NoArvore* raiz = criaArvoreVazia();
    int total, valor;
    scanf("%d", &total);
    for (int i = 0; i < total; i++) {
        scanf("%d", &valor);
        raiz = insereNo(raiz, valor);
    }
    exibeEmOrdem(raiz);
    printf("\n");
    raiz = liberaArvore(raiz);
    return 0;
}
