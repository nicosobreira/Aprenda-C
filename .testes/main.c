#include <stdio.h>

int main(void)
{
    const int total = 7;
    double temperaturas[total] = {20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0};

    double soma = 0;
    for (int i = 0; i < total; i = i + 1)
    {
        soma += temperaturas[i];
    }
    double media = soma / total;

    printf("A média de temperatura é %f°C\n", media);

    return 0;
}
