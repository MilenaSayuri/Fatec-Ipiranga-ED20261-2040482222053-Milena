#include <stdio.h>
#include "interface.h"
#include "recursao.h"

void exibirMenu()
{
    printf("\n============ Conversor e Calculadora Cientifica (CUCC) ============\n");
    printf("1. Converter Decimal para Binario\n");
    printf("2. Calcular Potencia\n");
    printf("3. Somar Digitos\n");
    printf("0. Sair\n");
    printf("\n");
    printf("Escolha uma opcao: ");
}

void executarOpcao(int opcao)
{
    int numero, base, exp, resultado;

    switch (opcao)
    {
    case 1:
        printf("Digite um numero decimal inteiro: ");
        scanf("%d", &numero);
        printf("Resultado em Binario: ");
        if (numero < 0)
            numero = -numero;
        decToBin(numero);
        printf("\n");
        break;

    case 2:
        printf("Digite a base: ");
        scanf("%d", &base);
        printf("Digite o expoente (maior ou igual a zero): ");
        scanf("%d", &exp);

        if (exp < 0)
            printf("Erro: O expoente deve ser >= 0.\n");
        else
            resultado = potencia(base, exp);
        printf("Resultado da potencia: %d\n", resultado);
        break;

    case 3:
        printf("Digite um numero inteiro: ");
        scanf("%d", &numero);
        if (numero < 0)
        {
            numero = -numero;
        }
        resultado = somaDigitos(numero);
        printf("A soma dos digitos e: %d\n", resultado);
        break;

    case 0:
        printf("Encerrando...\n");
        break;

    default:
        printf("Opcao invalida! Tente novamente.\n");
    }
}