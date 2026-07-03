#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    printf("Digite um número inteiro.\n");

    int numero;
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
            continue;
        }

        if (numero < 0)
        {
            printf("Digite um número maior ou igual a %d!\n", 0);
            continue;
        }

        break;
    } while (true);

    printf("\n");

    int contador = 0;
    while (contador <= numero)
    {
        printf("%d\n", contador);

        contador += 2;
    }

    return 0;
}
