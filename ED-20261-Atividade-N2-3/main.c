#include <stdio.h>
#include "interface.h"

int main()
{
    int opcao;

    do
    {
        exibirMenu();
        scanf("%d", &opcao);
        executarOpcao(opcao);
    } while (opcao != 0);

    return 0;
}