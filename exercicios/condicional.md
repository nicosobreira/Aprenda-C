# Condicionais: Exercícios

* Explicar o padrão de Entrada e Saída nos exercícios a seguir.

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

## 1. Classificador de Idade

Crie um programa que:

1. Receba a idade de uma pessoa como entrada.
2. Classifique e imprima a categoria correspondente, como saída, de acordo com as regras a seguir:
    - **Infantil**: Menor que 12 anos.
    - **Juvenil**: De 12 a 17 anos.
    - **Adulto**: De 18 a 59 anos.
    - **Idoso**: De 60 anos ou mais.

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

## 2. Aprovação Escolar

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

    const double nota_aprovado = 7.0;
    const double nota_reprovado = 5.0;

    const double peso1 = 4;
    const double peso2 = 2;
    const double peso3 = 3;
    const double peso4 = 1;

    double pesos = peso1 + peso2 + peso3 + peso4;

    double media = (nota1 * peso1 + nota2 * peso2 + nota3 + peso3 + nota4 + peso4) / pesos;

    printf("A média do aluno foi: %.2f\n", media);

    if (media >= nota_aprovado)
    {
        printf("Aprovado.\n");
    }
    else if (media <= nota_reprovado)
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

## 3. Triângulo

> Coloque o código dentro da função `main`, não se esqueça do `return 0;` ao final.

```c
// Entrada

int a = 0;
int b = 0;
int c = 0;

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
