# Estruturas de Repetições: Exercícios

Para fazer esses exercícios, sugiro **reduzir o uso da IA**. Em caso de dúvida, procure primeiro por **sites**, **vídeos** e **tutorias** para te ajudar, use a IA como a última saída.

## Exercícios

### 1. Contador de Pares

Crie um programa que:

1. Leia um inteiro **positivo** chamado `numero` do usuário.
2. Imprima **todos os números pares** entre 0 e `numero` (incluindo o `numero`, caso ele seja par).

#### Exemplo

```
Digite um número inteiro positivo: 9
0
2
4
6
8
```

```
Digite um número inteiro positivo: -2
Digite um inteiro positivo: texto
Digite um inteiro: 2
0
2
```

#### Incremento

Vimos na seção passada que poderíamos usar o `++` para incrementar uma variável em um.
Mas também podemos usar da seguinte sintaxe:

``` c
int numero = 10;

numero += 1;
```

Note que é possível **trocar o 1 por outro número**, como o 2, por exemplo.

#### Resposta

<details>
<summary>Clique aqui para ver a resposta</summary>

#### Usando o while

``` c
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    printf("Digite um número inteiro: ");

    int numero;
    do
    {
        int r = scanf("%d", &numero);
        if (r != 1)
        {
            while (getchar() != '\n')
            {
            }

            printf("Digite um inteiro: ");
            continue;
        }

        if (numero < 0)
        {
            printf("Digite um inteiro positivo: ");
            continue;
        }

        break;
    } while (true);

    int contador = 0;
    while (contador <= numero)
    {
        printf("%d\n", contador);

        contador += 2;
    }

    return 0;
}
```

#### Usando o for

Aqui, vou apenas trocar o `while` pelo `for`, mas você deve colocar a leitura da entrada do usuário.

``` c
for (int contador = 0; contador <= numero; contador += 2)
{
    printf("%d\n", contador);
}
```

Variáveis que são incrementadas, chamadas de **contadores**, normalmente possuem **nomes menores** quando o contexto permite.
É mais comum o uso de nomes como: `i`, `j` e `k`.

``` c
for (int i = 0; i <= numero; i += 2)
{
    printf("%d\n", i);
}
```

</details>

### 2. Jogo da Adivinhação

Crie um programa que:

1. Gere um número aleatório de 1 até 100 chamado `aleatorio`.
2. Peça para o usuário tentar acertar.

Cada tentativa deve ser **contada** em uma variável chamada `jogadas`. Em caso de **erro de digitação** a variável `jogadas` **não deve ser incrementada**.

#### Exemplo

```
Um número inteiro entre 1 e 100 foi gerado.
Tente adivinhar o número.
> texto
Digite um número inteiro!
> 0
Digite um número maior do que 1!
> 101
Digite um número menor do que 100!
> 50
O número é maior.
> 75
O número é menor.
> 70
Você acertou! Foram 3 jogada(s)!
```

#### Gerando números aleatórios

Para gerar um número aleatório em C, usamos a função `rand`, declarada no *header* `stdlib.h`, que gera um valor inteiro não negativo.

``` c
#include <stdio.h>   // Para o printf
#include <stdlib.h>  // Para o rand

int main(void)
{
    int aleatorio = rand();

    printf("O número aleatório é: %d\n", aleatorio);

    return 0;
}
```

Rode esse programa várias vezes e perceberá duas coisas:

1. Os números **não são aleatórios**; e
2. Eles são **grandes**.

O motivo disso está em como os computadores geram números aleatórios. Os computadores, por serem máquinas lógicas e determinísticas, não conseguem gerar números **verdadeiramente aleatórios**, mas sim usam de fórmulas matemáticas complexas onde o número atual depende do anterior, a fim de gerar números **pseudoaleatórios**. Sendo assim, é necessário um **ponto de partida** para que essas fórmulas comecem. Esse ponto é chamado de **seed**.
A função `rand` já vem com uma **seed padrão**, por isso temos que mudá-la **dentro da nossa função main**. Fazemos isso com outra função também declarada em `stdlib.h`, chamada `srand`.

``` c
#include <stdio.h>   // Para o printf
#include <stdlib.h>  // Para o rand e srand

int main(void)
{
    srand(50);

    int aleatorio = rand();

    printf("O número aleatório é: %d\n", aleatorio);

    return 0;
}
```

Conseguimos mudar a **seed**, mas se rodarmos o programa mais de uma vez o mesmo valor aparece. Assim como a seed padrão da função `rand`, o nosso novo valor continua sendo **constante**. Para resolvermos esse problema vamos utilizar do **tempo atual** em segundos, a partir da função `time`, declarada no *header* `time.h`.

``` c
#include <stdio.h>   // Para o printf
#include <stdlib.h>  // Para o rand e srand
#include <time.h>    // Para o time

int main(void)
{
    srand(time(NULL));

    int aleatorio = rand();

    printf("O número aleatório é: %d\n", aleatorio);

    return 0;
}
```

Veremos o que é esse `NULL` em [Memória I](./memoria/README.md), por ora veja ele como algo que indica à função `time` que queremos que o tempo atual seja **retornado** como um inteiro.

#### Limitando o valor entre 1 e 100

Agora que temos números imprevisíveis, precisamos resolver o problema de serem muito grandes. Para limitar o número entre 1 e 100, usamos o operador de **resto da divisão matemática** (`%`).

Se dividirmos qualquer número por 100, o resto dessa divisão sempre será algo entre 0 e 99. Somando 1 a esse resultado, garantimos que o número gerado estará exatamente entre 1 e 100:

``` c
int aleatorio = 1 + rand() % 100
```

#### Resposta

<details>
<summary>Clique aqui para ver a resposta</summary>

``` c
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
```

</details>

### 3. Menu de Caixa Eletrônico

O programa deve ler a escolha do usuário. Se ele digitar algo inválido (uma letra, um número negativo, ou um número fora das opções 1, 2 e 3), o programa deve avisar o erro, limpar o buffer (se necessário) e mostrar o menu novamente.

- Se escolher 1, imprima o saldo atual.
- Se escolher 2, peça o valor do depósito, e some o valor ao saldo.
- Se escolher 3, o programa deve encerrar.

```
--- MENU ---
1. Ver Saldo
2. Depositar
3. Sair

Escolha uma opção: X
Opção inválida. Digite um número de 1 a 3.
Escolha uma opção: 5
Opção inválida. Digite um número de 1 a 3.
Escolha uma opção: 1
Seu saldo é R$ 1000.00.
--- MENU ---
... (menu repete até usuário digitar 3)
```

<details>
<summary>Clique aqui para ver a resposta</summary>

resp

</details>

## Reflexões

- Falar por que as resoluções estão ruim (nenhuma modularização, múltiplas responsabilidades da função main) e introduzir o próximo capítulo sobre funções, que resolvem esses problemas.
- O **control flow** está péssimo.
