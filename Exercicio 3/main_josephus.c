#include <stdio.h>
#include "circulo.h"

int main() {
    int quantidade, passo;
    printf("Digite o número de participantes: ");
    scanf("%d", &quantidade);

    printf("Digite o número para a contagem: ");
    scanf("%d", &passo);

    Elemento *participanteInicial = montarCirculo(quantidade);
    executarJosephus(&participanteInicial, passo);

    printf("O último participante é: %d\n", participanteInicial->identificador);
    free(participanteInicial); // Limpa o último elemento restante
    return 0;
}
