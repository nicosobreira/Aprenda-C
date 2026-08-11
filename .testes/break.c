#include <stdbool.h> // Para `true` e `false`
#include <stdio.h>   // Para `printf` e `scanf`

double leia_double_entre(double min, double max, const char *mensagem);

int main(void)
{
    const double min = 0.0;
    const double max = 10.0;

    double nota = leia_double_entre(min, max, "Digite uma nota.");

    printf("\n");
    printf("A nota foi de %g.\n", nota);

    return 0;
}

double leia_double_entre(double min, double max, const char *mensagem)
{
    if (mensagem == NULL)
    {
        printf("Digite uma número real.");
    }
    else
    {
        printf("%s\n", mensagem);
    }

    double numero;

    bool leitura_valida = false;
    do
    {
        printf(" > ");
        int r = scanf("%lf", &numero); // O `scanf` retorna o número de conversões bem sucedidas.

        if (r != 1)
        {
            int c;
            while ((c = getchar() != '\n') && c != EOF)
            {
            }

            printf("Digite um número real!\n");
        }
        else if (numero < min)
        {
            printf("Digite um número maior que %g!\n", min);
        }
        else if (numero > max)
        {
            printf("Digite um número menor que %g!\n", max);
        }
        else
        {
            leitura_valida = true;
        }
    } while (!leitura_valida);

    return numero;
}
