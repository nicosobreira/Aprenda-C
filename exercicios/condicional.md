# Condicionais: Exercícios

Como ainda não sabemos como pedir dados para os usuários enquanto o programa está em execução, vamos utilizar um padrão de **entrada** e **saída** para os exercícios.

Os exercícios vão **dar as entradas** e pedir para você criar uma solução entre o comentário `// Saída:` e o `return 0;`.

## Exemplo

> Enunciado.

Exiba a soma de dois números inteiros `a` e `b`.

> O que o exercício vai dar.

``` c
int main(void)
{
    // Entrada:

    int a = 0;
    int b = 0;

    // Saída:

    return 0;
}
```

> A resposta do exercício.

<details>
<summary>Clique aqui para ver a resposta</summary>

``` c
int main(void)
{
    // Entrada:

    int a = 0;
    int b = 0;

    // Saída:

    int resultado = a + b;

    printf("%d + %d = %d\n", a, b, resultado);

    return 0;
}
```

</details>

## Comentários

Repare que, no parágrafo anterior, eu falei em um "comentário `// Saída:`". Mas o que isso quer dizer? Se `Saída` não é uma variável, nem uma função, por que o compilador não reclama dele?

A resposta é que aquela linha é um **comentário**: um texto que existe apenas para quem **lê** o código, não para o computador. O compilador simplesmente **ignora** tudo o que está dentro de um comentário, como se ele nem estivesse ali.

Em C, existem duas formas de escrever comentários:

``` c
// Isso é um comentário de uma linha só.

/*
Isso é um comentário
que pode ocupar
várias linhas.
*/
```

Comentários servem para explicar o **porquê** de alguma parte do código, ou para deixar anotações para você mesmo (ou para quem for ler seu código depois). Teste o código a seguir, depois **apague** a linha do comentário e rode de novo - você vai ver que nada muda na execução:

``` c
#include <stdio.h>

int main(void)
{
    // Essa linha só existe para explicar o próximo printf, o compilador a ignora.
    printf("Olá, Mundo!\n");

    return 0;
}
```

Agora, faça o oposto: pegue uma linha de código de verdade, como o `printf`, e coloque ela dentro de `/* */`:

``` c
#include <stdio.h>

int main(void)
{
    /* printf("Olá, Mundo!\n"); */

    return 0;
}
```

Rode o programa de novo. Percebeu que o `printf` não é mais executado? Isso porque, para o compilador, aquela linha deixou de existir. Esse é um uso bem comum de comentários no dia a dia: **desativar temporariamente** um trecho de código, sem precisar apagá-lo — útil quando você está testando ou depurando algo.

> Mais para frente, em [Funções](../funcoes/README.md), veremos um tipo especial de comentário usado para documentar o que uma função faz.

Voltando aos exercícios: é exatamente esse **comentário de uma linha** (`//`) que vamos usar para marcar onde fica a **entrada** e a **saída** de cada exercício.

## 1. Classificador de Idade

Crie um programa que receba a idade de uma pessoa como entrada e classifique a categoria correspondente, como saída, de acordo com as regras a seguir:

- **Infantil**: Menor que 12 anos.
- **Juvenil**: De 12 a 17 anos.
- **Adulto**: De 18 a 59 anos.
- **Idoso**: De 60 anos ou mais.

``` c
int main(void)
{
    // Entrada:

    int idade = 0;

    // Saída:

    return 0;
}
```

<details>
<summary>Precisa de uma dica? Clique aqui.</summary>

Lembre-se de que as verificações vão **alterando as faixas de possíveis valores**. Releia o capítulo [else if](../condicional/README.md#else-if) se preciso.

</details>

<details>
<summary>Clique aqui para ver a resposta</summary>

``` c
#include <stdio.h>

int main(void)
{
    // Entrada:

    int idade = 27;

    // Saída:

    if (idade < 0)
    {
        printf("Idade inválida!\n");
    }
    else if (idade < 12)
    {
        printf("Infantil.\n");
    }
    else if (idade <= 17)
    {
        printf("Juvenil.\n");
    }
    else if (idade <= 59)
    {
        printf("Adulto.\n");
    }
    else
    {
        printf("Idoso.\n");
    }

    return 0;
}
```

</details>

## 2. Aprovação Escolar

Crie um programa que receba quatro notas de um aluno, calcule a **média ponderada** das notas, seguindo os seguintes pesos:

| Nota | Peso |
| :-:  | :-   |
| 1    | 4    |
| 2    | 2    |
| 3    | 2    |
| 4    | 1    |

Mostre essa média e depois informe se esse aluno:

1. Passou, caso a média seja maior ou igual a 6.
2. Reprovou, caso a média seja menor ou igual a 4.
3. Está de recuperação, caso a média esteja entre 4 e 6.

> Pulei a definição da função `main`, mas você deve colocar.

``` c
// Entrada:

double nota1 = 0.0;
double nota2 = 0.0;
double nota3 = 0.0;
double nota4 = 0.0;

// Saída:

return 0;
```

<details>
<summary>Clique aqui para ver a resposta</summary>

> Não se esqueça de colocar `#include <stdio.h>` para usar a função `printf`!

``` c
int main(void)
{
    // Entrada:

    double nota1 = 0.0;
    double nota2 = 0.0;
    double nota3 = 0.0;
    double nota4 = 0.0;

    // Saída:

    const double media_aprovado = 6.0;
    const double media_reprovado = 4.0;

    const double peso1 = 4;
    const double peso2 = 2;
    const double peso3 = 2;
    const double peso4 = 1;

    double pesos = peso1 + peso2 + peso3 + peso4;

    double media = (nota1 * peso1 + nota2 * peso2 + nota3 * peso3 + nota4 * peso4) / pesos;

    printf("A média do aluno foi: %.2f\n", media);

    if (media >= media_aprovado)
    {
        printf("Aprovado.\n");
    }
    else if (media <= media_reprovado)
    {
        printf("Reprovado.\n");
    }
    else
    {
        printf("Recuperação.\n");
    }

    return 0;
}
```

</details>

## 3. Triângulo

Crie um programa que verifique se três retas formam um triângulo, seguindo a seguinte regra: **para todo lado do triângulo, a soma de dois lados deve ser maior que o terceiro**. As retas são valores inteiros.

Caso as retas **não formem** um triângulo, mostre uma mensagem de erro e retorne `-1` da função `main`.

Caso as retas **formem** um triângulo, classifique-o seguindo essas regras:

- Se todos os lados são iguais, então o triângulo é equilátero.
- Se pelo menos dois dos lados são iguais, então ele é isósceles.
- Senão, ele é escaleno.

> Não se esqueça de criar a função `main`!

``` c
// Entrada

int a = 0;
int b = 0;
int c = 0;
```

<details>
<summary>Clique aqui para ver a resposta</summary>

> Coloque o código dentro da função `main`, não se esqueça do `return 0;` ao final.

```c
// Saída

if (a + b > c && a + c > b && b + c > a)
{
    printf("Forma um triângulo.\n");
}
else
{
    printf("Não forma um triângulo.\n");
    return -1;
}

if (a == b && b == c)
{
    printf("É um triângulo Equilátero!\n");
}
else if (a == b || a == c || b == c)
{
    printf("É um triângulo Isósceles!\n");
}
else
{
    printf("É um triângulo Escaleno!\n");
}
```

</details>
