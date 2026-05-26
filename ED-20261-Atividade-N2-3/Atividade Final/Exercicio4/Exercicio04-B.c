// RA: 2040482222053 - Milena Sayuri Hayakawa

#include <stdio.h>

// Exercício 04 — Busca Binária Recursiva e Potenciação Rápida
//  Parte B: Potenciação Rápida

long long potenciaRapida(long long base, int exp, int *chamadas)
{
    (*chamadas)++;

    //                              CASO BASE:
    // Qualquer base elevada a 0 resulta em 1, interrompendo a descida na pilha de recursao
    if (exp == 0)
        return 1;

    //                          CASOS RECURSIVO:
    // Se o expoente for par, usamos a propriedade: b^exp = (b^(exp/2))^2, cortando o tamanho do problema pela metade a cada chamada
    if (exp % 2 == 0)
    {
        long long metade = potenciaRapida(base, exp / 2, chamadas);
        return metade * metade;
    }

    else
        return base * potenciaRapida(base, exp - 1, chamadas);
}

int main()
{
    int chamadas;
    long long resultado;

    printf("--- Potenciacao Rapida O(log n) ---\n");

    chamadas = 0;
    resultado = potenciaRapida(2, 10, &chamadas);
    printf("2^10 = %-15lld | Chamadas recursivas: %d\n", resultado, chamadas);

    chamadas = 0;
    resultado = potenciaRapida(3, 7, &chamadas);
    printf("3^7  = %-15lld | Chamadas recursivas: %d\n", resultado, chamadas);

    chamadas = 0;
    resultado = potenciaRapida(5, 0, &chamadas);
    printf("5^0  = %-15lld | Chamadas recursivas: %d\n", resultado, chamadas);

    chamadas = 0;
    resultado = potenciaRapida(7, 12, &chamadas);
    printf("7^12 = %-15lld | Chamadas recursivas: %d\n", resultado, chamadas);

    /*
                      --- COMPARACAO COM A ABORDAGEM INGENUA ---
      Abordagem ingenua: b^n = b * b^(n-1)
      Na abordagem ingenua, o numero de chamadas recursivas escala de forma linear (O(n)) com o valor do expoente
      Para calcular 7^12, o programa precisaria de 13 chamadas na pilha (contando o caso base)

      Abordagem rapida:
      Já nessa abordagem como dividimos o expoente por 2 nos casos pares, a profundidade da recursao cai bastante para O(log n).

        Comparacao:
        2^10:  Abordagem ingenua = 11 chamadas | Rapida = 6 chamadas
        3^7:   Abordagem ingenua = 8 chamadas  | Rapida = 6 chamadas
        7^12:  Abordagem ingenua = 13 chamadas | Rapida = 6 chamadas

        Essa reducao salva uso critico de memoria na pilha de execucao, evitando Stack Overflow e acelera o processamento.
   */

    return 0;
}