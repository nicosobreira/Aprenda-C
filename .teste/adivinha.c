#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));

    const int min = 1;
    const int max = 100;

    int aleatorio = min + rand() % max;
    printf("[debug] aleatorio = %d\n", aleatorio);
    printf("Um número inteiro entre %d e %d foi gerado.\n", min, max);

    printf("Tente adivinhar o número.\n");

    int jogadas = 0;
    int tentativa;
    do
    {
        printf("> ");

        int r = scanf("%d", &tentativa);
        if (r != 1)
        {
            while (getchar() != '\n')
            {
            }

            printf("Digite um número inteiro!\n");
            continue;
        }

        if (tentativa < min)
        {
            printf("Digite um número maior do que %d!\n", min);
            continue;
        }

        if (tentativa > max)
        {
            printf("Digite um número menor do que %d!\n", max);
            continue;
        }

        jogadas++;

        if (tentativa > aleatorio)
        {
            printf("O número é menor.\n");
        }
        else if (tentativa < aleatorio)
        {
            printf("O número é maior.\n");
        }
        else
        {
            printf("Você acertou! Foram %d jogada(s)!\n", jogadas);
            break;
        }
    } while (true);

    return 0;
}
