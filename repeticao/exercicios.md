# Estruturas de Repetições: Exercícios

Para fazer esses exercícios, sugiro **reduzir o uso de IA**. Em caso de dúvida, procure primeiro por **sites**, **vídeos** e **tutorias** para te ajudar, use a IA como a última saída.

## Formato da entrada

Nesses exercícios vamos usar uma formatação diferente para pedir dados do usuário. Primeiro vou mostrar como ela é, depois como implementa-la:

> Esse bloco indica como a entrada e saída do programa deve funcionar.
```
Digite um número de 1 a 10.
> 5

Você digitou 5.

```

Usamos do `>` seguido de um espaço para indicar **as entradas do nosso programa**.
Caso o usuário digite algo inválido, a saída deve ficar dessa forma:

```
Digite um número de 1 a 10.
> texto
Digite um número inteiro!
> 0
Digite um número maior ou igual a 1!
> 11
Digite um número menor ou igual a 10!
> 5

Você digitou 5.

```

Em C fica assim:

``` c
const int min = 1;
const int max = 10;

printf("Digite um número de 1 a 10.\n");

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
    else if (numero < min)
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

printf("\n");

printf("Você digitou 5.\n");
```

## Exercícios

### 1. Contador de Pares

Crie um programa que:

1. Leia um inteiro **positivo** chamado `numero` do usuário.
2. Imprima **todos os números pares** entre 0 e `numero` (incluindo o `numero`, caso ele seja par).

#### Exemplo

Sem erros na entrada:

```
Descubra quais são os inteiros pares entre 0 e algum número da sua escolha!
> 9

0
2
4
6
8

```

Com erros:

```
Descubra quais são os inteiros pares entre 0 e algum número da sua escolha!
> texto
Digite um número inteiro!
> -1
Digite um número maior ou igual a 0!
> 2

0
2

```

#### Incremento

Vimos na seção passada que poderíamos usar o `++` para incrementar uma variável em 1.
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
    printf("Descubra quais são os inteiros pares entre 0 e algum número da sua escolha!\n");

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
        else if (numero < 0)
        {
            printf("Digite um número maior ou igual a %d!\n", 0);
        }
        else
        {
            leitura_valida = true;
        }
    } while (!leitura_valida);

    printf("\n");

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
2. Peça para o usuário tentar adivinhar qual é esse número.

Cada tentativa deve ser **contada** em uma variável chamada `jogadas`. Em caso de **erro de digitação** a variável `jogadas` **não deve ser incrementada**.

Separe a lógica em **dois** `do while`, um **externo** e outro **interior**, de modo que o interior apenas valide a entrada, sem nenhuma comparação com a variável `aleatorio`.

#### Exemplo

Sem erros na entrada:

```
Um número inteiro entre 1 e 100 foi gerado.
Tente adivinhar o número.
> 50

O número é menor.
> 20

O número é maior.
> 22

Você acertou! Foram 3 jogada(s)!

```

Com erros:

```
Um número inteiro entre 1 e 100 foi gerado.
Tente adivinhar o número.
> texto
Digite um número inteiro!
> 0
Digite um número maior ou igual a 1!
> 101
Digite um número menor ou igual a 100!
> 5

O número é menor.
> 2

Você acertou! Foram 2 jogada(s)!

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

O motivo disso está em como os computadores geram números aleatórios. Os computadores, por serem máquinas lógicas e determinísticas, não conseguem gerar números **verdadeiramente aleatórios**, mas sim usam de fórmulas matemáticas complexas onde o número atual depende do anterior, a fim de gerar números **pseudoaleatórios**. Sendo assim, é necessário um **ponto de partida** para que essas fórmulas comecem. Esse ponto é chamado de ***seed***.
A função `rand` já vem com uma *seed* padrão, por isso temos que mudá-la **dentro da nossa função main**. Mudamos a *seed* com outra função também declarada em `stdlib.h`, chamada `srand`.

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

De forma mais genêrica, podemos limitar um número aletório entre dois inteiros `min` e `max` dessa forma:

``` c
const int min = 5;
const int max = 10;

int aleatorio = min + rand() % (max - min + 1);
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

    int aleatorio = min + rand() % (max - min + 1);

    printf("Um número inteiro entre %d e %d foi gerado.\n", min, max);
    printf("Tente adivinhar o número.\n");

    int jogadas = 0;

    int tentativa;
    do
    {
        bool leitura_valida = false;
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
            }
            else if (tentativa < min)
            {
                printf("Digite um número maior ou igual a %d!\n", min);
            }
            else if (tentativa > max)
            {
                printf("Digite um número menor ou igual a %d!\n", max);
            }
            else
            {
                leitura_valida = true;
            }
        } while (!leitura_valida);

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
```

</details>

### 3. Menu de Caixa Eletrônico

Por último, crie um programa que **simule um caixa eletrônico**.

Primeiro, será um exibido um **menu**, explicando o uso do caixa. Ele vai contar com essas opções:

1. Ver o saldo atual;
2. Depositar dinheiro; e
3. Sair do caixa.

O usuário deve **começar** o programa com **R$ 1000.00** na conta.

#### Exemplos

Sem erros na entrada:

```
--- OPÇÕES ---
1. Ver Saldo
2. Depositar
3. Sair

> 1
Seu saldo é de R$ 1000.00

> 2

Deseja depositar quanto? [Digite 0 para sair]
> 10.25

> 1
Seu saldo é de R$ 1010.25

> 3
Até mais!

```

Com erros:

```
--- OPÇÕES ---
1. Ver Saldo
2. Depositar
3. Sair

> texto
Digite um número inteiro!
> 0
Opção inválida. Digite um número de 1 a 3!
> 4
Opção inválida. Digite um número de 1 a 3!
> 2

Deseja depositar quanto? [Digite 0 para sair]
> -10
Digite um número positivo!
> texto
Digite um número real!
> 0

> 3
Até mais!

```

<details>
<summary>Clique aqui para ver a resposta</summary>

> Não se esqueça de importar os *headers* caso necessário!

Vamos criar duas variáveis constantes que vão nos dizer a primeira opção e a última.

``` c
const int primeira_opcao = 1;
const int ultima_opcao = 3;
```

Em seguida, declaramos a variável `saldo` com o valor de R$ 1000.0 e mostramos as opções disponíveis.

``` c
double saldo = 1000.0;

printf("--- OPÇÕES ---\n");
printf("1. Ver Saldo\n");
printf("2. Depositar\n");
printf("3. Sair\n");
printf("\n");
```

Para sair do caixa, o usuário deve digitar o número `3`, caso contrário o caixa deve continuar ligado. Implementamos essa lógica com um *while loop* junto a uma variável booleana chamada `caixa_esta_ligado`, com o valor `true`.

``` c
bool caixa_esta_ligado = true;
while (caixa_esta_ligado)
{
    // Continuação ...
}
```

Agora, pedimos por um valor de 1 a 3, ou seja, de `primeira_opcao` até `ultima_opcao`, dentro do *while loop*.

``` c
    int opcao;

    bool leitura_valida = false;
    do
    {
        printf("> ");

        int r = scanf("%d", &opcao);
        if (r != 1)
        {
            while (getchar() != '\n')
            {
            }

            printf("Digite um número inteiro!\n");
        }
        else if (opcao < primeira_opcao)
        {
            printf("Digite um número maior ou igual a %d!\n", primeira_opcao);
        }
        else if (opcao > ultima_opcao)
        {
            printf("Digite um número menor ou igual a %d!\n", ultima_opcao);
        }
        else
        {
            leitura_valida = true;
        }
    } while (!leitura_valida);
```

Por enquanto, vamos criar uma série de `if` e `else if` para cada opção que não fazem nada - com exeção da opção `3`, que muda a variável `caixa_esta_ligado` para `false`, desligando o caixa:

``` c
    if (opcao == 1)
    {
        // ...
    }
    else if (opcao == 2)
    {
        // ...
    }
    else if (opcao == 3)
    {
        caixa_esta_ligado = false;
    }

    printf("\n"); // Quebra linha visual
```

Implementar a opção `1` é fácil, é só exibir o saldo atual:

``` c
        printf("Seu saldo é de R$ %.2f\n", saldo);
```

Para a opção `2` temos que (1) ler um valor `double` do usuário e (2) somar esse valor a variável `saldo`. Fazemos isso no código a seguir:

``` c
        printf("\n"); // Quebra linha visual
        printf("Deseja depositar quanto? [Digite 0 para sair]\n");

        double deposito;

        bool leitura_valida = false;
        do
        {
            printf("> ");

            int r = scanf("%lf", &deposito);
            if (r != 1)
            {
                while (getchar() != '\n')
                {
                }

                printf("Digite um número real!\n");
            }
            else if (deposito < 0)
            {
                printf("Digite um número positivo!\n");
            }
            else
            {
                leitura_valida = true;
            }
        } while (!leitura_valida);

        saldo += deposito;
```

Ao final exibimos uma mensagem de despedida e retornamos `0`:

``` c
printf("Até mais!\n");

return 0;
```

O código final, com tudo junto, está abaixo

<details>
<summary>Clique aqui para ver o código final</summary>

``` c
#include <stdbool.h>
#include <stdio.h>

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
        int opcao;

        bool leitura_valida = false;
        do
        {
            printf("> ");

            int r = scanf("%d", &opcao);
            if (r != 1)
            {
                while (getchar() != '\n')
                {
                }

                printf("Digite um número inteiro!\n");
            }
            else if (opcao < primeira_opcao)
            {
                printf("Digite um número maior ou igual a %d!\n", primeira_opcao);
            }
            else if (opcao > ultima_opcao)
            {
                printf("Digite um número menor ou igual a %d!\n", ultima_opcao);
            }
            else
            {
                leitura_valida = true;
            }
        } while (!leitura_valida);

        if (opcao == 1)
        {
            printf("Seu saldo é de R$ %.2f\n", saldo);
        }
        else if (opcao == 2)
        {
            printf("\n");
            printf("Deseja depositar quanto? [Digite 0 para sair]\n");

            double deposito;

            bool leitura_valida = false;
            do
            {
                printf("> ");

                int r = scanf("%lf", &deposito);
                if (r != 1)
                {
                    while (getchar() != '\n')
                    {
                    }

                    printf("Digite um número real!\n");
                }
                else if (deposito < 0)
                {
                    printf("Digite um número positivo!\n");
                }
                else
                {
                    leitura_valida = true;
                }
            } while (!leitura_valida);

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
```

</details>

</details>

## Reflexões

Em todos os exercícios, nos pedimos para o usuário digitar algum valor com restrições; como um inteiro no intervalo de 1 a 100 ou um inteiro maior que 0.
Perceba que o código praticamente **não muda** de exercício para exercício. A lógica é a mesma, a única diferença é a mensagem que informa ao usuário o que ele deve digitar.

A medida que o programa cresce, temos que ficar copiando e colando o **mesmo código**, o que torna o código difícil de entender - como no exercício 3.

No próximo capítulo veremos as **funções**, que vão nos permitir reutilizar as lógicas de leitura em diversos lugares, eliminando o copia e cola.

<!-- Na hora de falar sobre modularizade, explicar o que acontece se adicionarmos uma nova feature ao Exercício 3. Vamos adicionar uma opção que **saca dinheiro**. Exmplicar por que mesmo que as lógicas de **depositar** e **sacar** sejam **parecidas** hoje, isso por mudar, por que elas são fundalmentalmente diferentes. -->
