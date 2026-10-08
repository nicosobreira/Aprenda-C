#include <stdbool.h>
#include <stdio.h>

int leia_int(void);
int leia_int_entre(int min, int max);

double leia_double(void);
double leia_double_positivo(void);

int main(void)
{
    const int primeira_opcao = 1;
    const int ultima_opcao = 3;

    double saldo = 1000.0;

    printf("--- OPÇÕES ---\n");
    printf("1. Ver Saldo\n");
    printf("2. Depositar\n");
    printf("3. Sair\n");
    printf("\n");

    bool caixa_esta_ligado = true;
    while (caixa_esta_ligado)
    {
        int opcao = leia_int_entre(primeira_opcao, ultima_opcao);

        if (opcao == 1)
        {
            printf("Seu saldo é de R$ %.2f\n", saldo);
        }
        else if (opcao == 2)
        {
            printf("\n");
            printf("Deseja depositar quanto? [Digite 0 para sair]\n");

            double deposito = leia_double_positivo();

            saldo += deposito;
        }
        else if (opcao == 3)
        {
            caixa_esta_ligado = false;
        }

        printf("\n");
    }

    printf("Até mais!\n");

    return 0;
}

int leia_int(void)
{
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
        else
        {
            leitura_valida = true;
        }
    } while (!leitura_valida);

    return numero;
}

int leia_int_entre(int min, int max)
{
    int numero;

    bool leitura_valida = false;
    do
    {
        numero = leia_int();

        if (numero < min)
        {
            printf("Digite um número maior ou igual a %d!\n", min);
        }
        else if (numero > max)
        {
            printf("Digite um número menor ou igual a %d!\n", max);
        }
        else
        {
            leitura_valida = true;
        }

    } while (!leitura_valida);

    return numero;
}

double leia_double(void)
{
    double numero;

    bool leitura_valida = false;
    do
    {
        printf("> ");

        int r = scanf("%lf", &numero);
        if (r != 1)
        {
            while (getchar() != '\n')
            {
            }

            printf("Digite um número inteiro!\n");
        }
        else
        {
            leitura_valida = true;
        }
    } while (!leitura_valida);

    return numero;
}

double leia_double_positivo(void)
{
    double numero;

    bool leitura_valida = false;
    do
    {
        numero = leia_double();

        if (numero < 0)
        {
            printf("Digite um número positivo!\n");
        }
        else
        {
            leitura_valida = true;
        }
    } while (!leitura_valida);

    return numero;
}
