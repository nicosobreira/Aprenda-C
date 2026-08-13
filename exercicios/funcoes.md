# Funções: Exercícios

Ao testar os programas, você não precisa ficar digitando os valores das funções `leia` toda vez no terminal, mas pode **comentar** a linha com o `leia` e colocar um valor de teste abaixo. Exemplo:

``` c
// int idade = leia_int();
int idade = 18;
```

Depois é só remover a linha de teste e tirar o comentário.

## Refatoração dos exercícios passados

Agora que você já conhece as funções, primeiro refatore o exercício [Contador de Pares](./repeticao.md#contador-de-pares) e depois [Jogo da Adivinhação](./repeticao.md#jogo-da-adivinhação), usando as funções `leia`. Caso seja necessário, crie as suas próprias funções.

<details>
<summary>Resposta do Contador de Pares</summary>

``` c
#include <stdbool.h>
#include <stdio.h>

int leia_int(void);
int leia_int_positivo(void);

int main(void)
{
    printf("Descubra quais são os inteiros pares entre 0 e algum número da sua escolha!\n");

    int numero = leia_int_positivo();

    printf("\n");

    for (int i = 0; i <= numero; i += 2)
    {
        printf("%d\n", i);
    }

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

int leia_int_positivo(void)
{
    int numero;

    bool leitura_valida = false;
    do
    {
        numero = leia_int();

        if (numero < 0)
        {
            printf("Digite um número maior ou igual a %d!\n", 0);
        }
        else
        {
            leitura_valida = true;
        }
    } while(!leitura_valida);

    return numero;
}
```

</details>

<details>
<summary>Resposta do Jogo da Adivinhação</summary>

``` c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int leia_int(void);
int leia_int_entre(int min, int max);

int main(void)
{
    srand(time(NULL));

    const int min = 1;
    const int max = 100;

    int aleatorio = min + rand() % (max - min + 1);

    printf("Um número inteiro entre %d e %d foi gerado.\n", min, max);
    printf("Tente adivinhar o número.\n");

    int jogadas = 0;

    int tentativa;
    do
    {
        tentativa = leia_int_entre(min, max);

        printf("\n");

        if (tentativa > aleatorio)
        {
            printf("O número é menor.\n");
        }
        else if (tentativa < aleatorio)
        {
            printf("O número é maior.\n");
        }

        jogadas += 1;
    } while (tentativa != aleatorio);

    printf("Você acertou! Foram %d jogada(s)!\n", jogadas);

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
    do {
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
    } while(!leitura_valida);

    return numero;
}
```

</details>

## Leitura de `char`

- Buscar algum exercício que peça para criar uma nova função chamada `leia_char`, ou melhor ainda, uma `leia_char_entre` que vai precisar que o leitor separe em funções separadas. Ou ainda, pedir para criar uma função `leia_char_letra` (algo do tipo).

<details>
<summary>Clique aqui para ver a resposta</summary>

```c
```

</details>

## É triângulo?

Faça as seguintes alterações no exercício [Triângulo](./exercicios/condicional.md#triângulo):

1. Troque o padrão de entrada e saída que tínhamos adotado (usando comentários) por funções do tipo `leia`.
2. Crie **duas novas funções**, uma que vai **apenas verificar** se esses lados formam um triângulo e outra que imprime a *classificação* do triângulo - **assumindo** que os lados formam um triângulo.

<details>
<summary>Clique aqui para ver a resposta</summary>

```c
```

</details>
