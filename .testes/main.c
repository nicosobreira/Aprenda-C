#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    double nota = 5.0;
    double frequencia = 10.0;

    if (nota < 6.0 && frequencia < 9.0)
    {
        printf("Você reprovou...\n");
    }
    else
    {
        printf("Você passou!\n");
    }

    return 0;
}
