# Estruturas de Repetições: Exercícios

Fazer e verificar as respostas do exercícios 1 e 2 primeiro, depois fazer o exercício 3.

## Exercícios

### 1. Contador de Pares

Crie um programa que:

1. Leia um inteiro **positivo** chamado `numero` do usuário; e
2. Imprima **todos os números pares** entre 0 e `numero` (incluindo o `numero`, caso ele seja par).

#### Exemplo

> Digite um número inteiro positivo: 9
> 0
> 2
> 4
> 6
> 8


#### Incremento

Vimos na seção passada que poderiamos usar o `++` para incrementar uma variável em um.
Mas também podemos usar da seguinte sintaxe:

``` c
int numero = 10;

numero += 1;
```

Note que é possível **trocar o 1 por outro número**, como o 2, por exemplo.

<details>
<summary>Clique aqui para ver a resposta</summary>

#### Usando o while

``` c
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int numero;

    printf("Digite um número inteiro: ");
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

Note que é mais comum o uso de **nomes menores** para as variáveis declaradas em loops. Prefere-se nomes como: `i`, `j` e `k`.

``` c
for (int i = 0; i <= numero; i += 2)
{
    printf("%d\n", i);
}
```

</details>

### 2. Jogo da Adivinhação

- Explicar o uso do `rand`

```
Tente adivinhar o número: A
Entrada inválida! Digite apenas números.
Tente adivinhar o número: 10
Muito baixo!
Tente adivinhar o número: 50
Muito alto!
Tente adivinhar o número: 42
Você acertou!
```

<details>
<summary>Clique aqui para ver a resposta</summary>

resp

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

- Como o código vai ficar gigante, talvez introduzir o tema para o próximo módulo de Funções.
