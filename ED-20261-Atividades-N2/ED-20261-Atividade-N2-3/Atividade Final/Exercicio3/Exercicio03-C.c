// RA: 2040482222053 - Milena Sayuri Hayakawa

#include <stdio.h>
// Parte C — Profundidade da recursão

/*
 * TABELA DE COMPLEXIDADE:
 * n | Movimentos (contado) | 2^n - 1 (esperado)
 * 1 | 1                    | 2^1 - 1 = 1
 * 2 | 3                    | 2^2 - 1 = 3
 * 3 | 7                    | 2^3 - 1 = 7
 * 4 | 15                   | 2^4 - 1 = 15
 * 5 | 31                   | 2^5 - 1 = 31
 * 6 | 63                   | 2^6 - 1 = 63
 */

int contador_movimentos = 0;

void imprimirEspacos(int nivel)
{
    for (int i = 0; i < nivel * 2; i++)
        printf(" ");
}

void hanoi(int n, char origem, char destino, char auxiliar, int nivel)
{
    if (n == 1)
    { // Caso base
        contador_movimentos++;
        imprimirEspacos(nivel);
        printf("[Nivel %d] Move disco 1 de %c para %c\n", nivel, origem, destino);
        return;
    }

    // Antes de descer para n-1 discos menores na primeira chamada
    hanoi(n - 1, origem, auxiliar, destino, nivel + 1);

    contador_movimentos++;
    imprimirEspacos(nivel);
    printf("[Nivel %d] Move disco %d de %c para %c\n", nivel, n, origem, destino);

    // Depois de mover o disco maior, transfere os n-1 discos para o destino
    hanoi(n - 1, auxiliar, destino, origem, nivel + 1);
}

int main()
{
    int testes[] = {1, 3, 4};
    int qtd_testes = sizeof(testes) / sizeof(*testes);

    for (int i = 0; i < qtd_testes; i++)
    {
        int n = testes[i];
        contador_movimentos = 0;

        printf("\n--- Parte C: Teste com n = %d ---\n", n);
        hanoi(n, 'A', 'C', 'B', 0);
        printf("Total de movimentos realizados: %d\n", contador_movimentos);
    }

    return 0;
}