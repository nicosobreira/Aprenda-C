#include <stdbool.h>
#include <stdio.h>

char leia_char(void);

int main(void)
{
    printf("Primeiro caracter.\n");
    char a = leia_char();

    printf("Segundo caracter.\n");
    char b = leia_char();

    printf("O primeiro vale %c\n", a);
    printf("O segundo vale %c\n", b);

    return 0;
}

char leia_char(void)
{
    char caracter;

    bool leitura_valida = false;

    do
    {
        printf("> ");
        int r = scanf("%c ", &caracter);
        if (r != 1)
        {
            while (getchar() != '\n')
            {
            }
            printf("Digite um caracter válido!");
        }
        else
        {
            leitura_valida = true;
        }
    } while (!leitura_valida);

    return caracter;
}
