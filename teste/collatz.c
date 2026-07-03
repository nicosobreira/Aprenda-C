#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    printf("Digite um número inteiro positivo.\n");
    int numero;
    bool leitura_valida = false;
    do
    {
        printf("> ");

        int r = scanf("%d", &numero);
        if (r != 1)
        {
            while (getchar() != '\n')
            {
            }

            printf("Digite um número inteiro!\n");
        }
        else if (numero <= 0)
        {
            printf("Digite um número maior que %d!\n", 0);
        }
        else
        {
            leitura_valida = true;
        }
    } while (!leitura_valida);

    printf("\n");

    int passos = 0;
    while (numero != 1)
    {
        if (numero % 2 == 0)
        {
            numero = numero / 2;
        }
        else
        {
            numero = numero * 3 + 1;
        }

        printf("%d ", numero);
        passos++;
    }

    printf("\n");

    return 0;
}
