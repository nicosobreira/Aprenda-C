<p align="center">
  <a href="../modulos/variaveis.md">← Variáveis</a>
  &nbsp;|&nbsp;
  <a href="../modulos/condicionais.md">Condicionais →</a>
</p>

---

# Exercícios: Variáveis

Para fazer esses exercícios, sugiro **reduzir o uso de IA**. Em caso de dúvida, procure primeiro por **sites**, **vídeos** e **tutorias** para te ajudar, use a IA como a última saída.

> Teste suas soluções com **outros valores de entrada**, não só com o do enunciado.

## Entrada e Saída

Como ainda não sabemos como pedir dados para os usuários enquanto o programa está em execução, vamos utilizar um padrão de **entrada** e **saída** para os exercícios.

Os exercícios vão **dar as entradas** e pedir para você criar uma solução entre o comentário `// Saída:` e o `return 0;`.

### Exemplo

> Enunciado.

Exiba a soma de dois números inteiros `a` e `b`.

> O que o exercício vai dar.

```c
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

```c
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

### Comentários

Repare que, no parágrafo anterior, eu falei em um "comentário `// Saída:`". Mas o que isso quer dizer? Se `Saída` não é uma variável, nem uma função, por que o compilador não reclama dele?

A resposta é que aquela linha é um **comentário**: um texto que existe apenas para quem **lê** o código, não para o computador. O compilador simplesmente **ignora** tudo o que está dentro de um comentário, como se ele nem estivesse ali.

Em C, existem duas formas de escrever comentários:

```c
// Isso é um comentário de uma linha só.

/*
Isso é um comentário
que pode ocupar
várias linhas.
*/
```

Comentários servem para explicar o **porquê** de alguma parte do código, ou para deixar anotações para você mesmo (ou para quem for ler seu código depois). Teste o código a seguir, depois **apague** a linha do comentário e rode de novo - você vai ver que nada muda na execução:

```c
#include <stdio.h>

int main(void)
{
    // Essa linha só existe para explicar o próximo printf, o compilador a ignora.
    printf("Olá, Mundo!\n");

    return 0;
}
```

Agora, faça o oposto: pegue uma linha de código de verdade, como o `printf`, e coloque ela dentro de `/* */` ou depois de `//`:

```c
#include <stdio.h>

int main(void)
{
    /* printf("Olá, Mundo!\n"); */
    // printf("Isso é um comentário!\n");

    return 0;
}
```

Rode o programa de novo. Percebeu que ambos os `printf` não é mais executado? Isso porque, para o compilador, aquela linha deixou de existir. Esse é um uso bem comum de comentários no dia a dia: **desativar temporariamente** um trecho de código, sem precisar apagá-lo — útil quando você está testando algo.

Voltando aos exercícios: é exatamente esse **comentário de uma linha** (`//`) que vamos usar para marcar onde fica a **entrada** e a **saída** de cada exercício.

## Prevendo a Saída

Leia o código a seguir e, **antes de compilar**, anote o que você acha que cada `printf` vai imprimir:

``` c
#include <stdio.h>

int main(void)
{
    printf("1) %d\n", 7 / 2 * 2);
    printf("2) %f\n", 7 / 2 * 2.0);
    printf("3) %f\n", 7 / 2.0 * 2);
    printf("4) %d\n", -7 / 2);
    printf("5) %d\n", -7 % 2);

    int a = 2 + 3 * 4 % 5 - 1;
    printf("6) %d\n", a);

    double media = (3 + 4) / 2;
    printf("7) %.1f\n", media);

    int inteiro = 9.99;
    printf("8) %d\n", inteiro);

    char letra = 'A' + 2;
    printf("9) %c %d\n", letra, letra);

    int x = 17;
    x = x / 5 * 5 + x % 5;
    printf("10) %d\n", x);

    return 0;
}
```

Depois, compile, rode e compare com as suas previsões. Tente entender o por quê da suas previsões esterem erradas.

<details>
<summary>Dica 1: Tipos</summary>

- O **tipo** do resultado depende dos **tipos dos números** da operação, e a conta é feita **da esquerda para a direita**.

</details>

<details>
<summary>Dica 2: Divisao</summary>

- Lembre-se de que a divisão de inteiros é **truncada**. Teste a relação `dividendo = quociente * divisor + resto` com os valores `-7` e `2`.

</details>

<details>
<summary>Dica 3: Char e Módulo</summary>

- Lembre-se de que o `char` é um número e de que o módulo (`%`) tem a mesma prioridade da multiplicação e da divisão.

</details>


<details>
<summary>Clique aqui para ver a resposta</summary>

```
1) 6
2) 6.000000
3) 7.000000
4) -3
5) -1
6) 3
7) 3.0
8) 9
9) C 67
10) 17
```

1. `7 / 2` é uma divisão entre inteiros, então vale `3` (truncado). Depois, `3 * 2` vale `6`.
2. A conta continua da esquerda para a direita: `7 / 2` ainda é inteira e vale `3`. Só depois o `3` é multiplicado por `2.0`, resultando em `6.0`. O `.0` chegou **tarde demais** para salvar a divisão.
3. Agora `7 / 2.0` já é uma divisão **real**, vale `3.5`, e `3.5 * 2` vale `7.0`.
4. A divisão de inteiros é truncada **em direção ao zero**: `-3.5` vira `-3`, e não `-4`.
5. O resto precisa manter a relação `dividendo = quociente * divisor + resto`: `-7 = (-3) * 2 + (-1)`. Em C, o sinal do resto é o **mesmo sinal do dividendo**.
6. Como `*` e `%` têm a mesma prioridade, são feitos da esquerda para a direita: `3 * 4` vale `12`, `12 % 5` vale `2`, depois `2 + 2 - 1` vale `3`.
7. `(3 + 4) / 2` é uma divisão entre inteiros (`7 / 2`), que vale `3`. Só depois o `3` é convertido para `double`, e não o contrário. Declarar a variável como `double` **não** muda a divisão.
8. Ao guardar um `double` em um `int`, a parte depois da vírgula é **descartada** (truncada, não arredondada). Por isso o resultado é `9`, e não `10`.
9. `'A'` vale `65`, então `'A' + 2` vale `67`. O `%c` mostra esse valor como letra (`C`), e o `%d`, como número.
10. Isso é a relação `dividendo = quociente * divisor + resto` escrita em C: `17 / 5` vale `3`, `3 * 5` vale `15`, `17 % 5` vale `2` e `15 + 2` vale `17`. O valor de `x` não mudou.

</details>

## Troca de Valores

Crie um programa que **troque** os valores das variáveis `a` e `b`. Exiba os valores **antes** e **depois** da troca.

``` c
#include <stdio.h>

int main(void)
{
    // Entrada:

    int a = 3;
    int b = 8;

    // Saída:

    return 0;
}
```

### Exemplo

```
Antes:  a = 3 e b = 8
Depois: a = 8 e b = 3
```

Antes de olhar a dica, tente o jeito mais "óbvio": `a = b;` seguido de `b = a;`. Qual é o resultado? Por quê?

<details>
<summary>Precisa de uma dica? Clique aqui.</summary>

Quando fazemos `a = b;`, o valor antigo de `a` é **perdido**.

</details>

<details>
<summary>Clique aqui para ver a resposta</summary>

O jeito "óbvio" não funciona: depois de `a = b;`, o valor `3` some e as duas variáveis passam a valer `8`. Ao executar `b = a;`, copiamos o `8` para `b`, que já valia `8`.

A solução é guardar o valor antigo de `a` em uma **variável auxiliar** antes de sobrescrevê-lo:

``` c
#include <stdio.h>

int main(void)
{
    // Entrada:

    int a = 3;
    int b = 8;

    // Saída:

    printf("Antes:  a = %d e b = %d\n", a, b);

    int auxiliar = a;
    a = b;
    b = auxiliar;

    printf("Depois: a = %d e b = %d\n", a, b);

    return 0;
}
```

</details>

## Segundos em Horas, Minutos e Segundos

Crie um programa que receba uma quantidade de segundos e a converta para horas, minutos e segundos.

Não use valores mágicos: `60` e `3600` devem ser constantes com nomes claros.

``` c
#include <stdio.h>

int main(void)
{
    // Entrada:

    int total_segundos = 3725;

    // Saída:

    return 0;
}
```

### Exemplos

Para `3725`:

```
1h 2min 5s
```

Para `59`:

```
0h 0min 59s
```

Para `7200`:

```
2h 0min 0s
```

<details>
<summary>Precisa de uma dica? Clique aqui.</summary>

Primeiro descubra **quantas horas completas** cabem em `total_segundos` (qual operação ignora o que sobra?). Depois, pergunte-se: **o que sobrou**? (qual operação dá esse resto?).

</details>

<details>
<summary>Clique aqui para ver a resposta</summary>

``` c
#include <stdio.h>

int main(void)
{
    // Entrada:

    int total_segundos = 3725;

    // Saída:

    const int segundos_por_minuto = 60;
    const int segundos_por_hora = 3600;

    int horas = total_segundos / segundos_por_hora;
    int resto = total_segundos % segundos_por_hora;

    int minutos = resto / segundos_por_minuto;
    int segundos = resto % segundos_por_minuto;

    printf("%dh %dmin %ds\n", horas, minutos, segundos);

    return 0;
}
```

Usamos a **divisão truncada** para contar quantas unidades completas cabem, e o **módulo** para saber o que sobrou. Para `3725`:

1. `3725 / 3600` vale `1` hora, e `3725 % 3600` sobra `125` segundos.
2. `125 / 60` vale `2` minutos, e `125 % 60` sobra `5` segundos.

Aqui, o truncamento da divisão de inteiros, que parecia um problema, é **exatamente o que queremos**.

</details>

## Maiúscula e Minúscula

Crie um programa que converta a letra minúscula `minuscula` para maiúscula, **sem usar** nenhuma função da Biblioteca Padrão.

``` c
#include <stdio.h>

int main(void)
{
    // Entrada:

    char minuscula = 'g';

    // Saída:

    return 0;
}
```

### Exemplo

```
A maiúscula de g é G.
```

Faça em **duas etapas**:

1. Imprima o `'g'` e o `'G'` como **números** (`%d`). Qual é a diferença entre eles? Teste com outro par de letras, como `'a'` e `'A'`. A diferença é a mesma?
2. Use essa diferença para fazer a conversão. **Não use um valor mágico**: crie uma constante com um nome claro e calcule o valor dela a partir de **dois caracteres** (lembre-se de que o `char` é um número).

<details>
<summary>Precisa de uma dica? Clique aqui.</summary>

Como o `char` é só um número, você pode **somar** e **subtrair** caracteres como qualquer outro inteiro. Por exemplo, `'A' + 2` vale `67`, que é o código de `'C'`.

</details>

<details>
<summary>Clique aqui para ver a resposta</summary>

Para a primeira parte, podemos ver o valor decimal da letra `g` e `G` da seguinte forma:

``` c
printf("%c vale %d\n", 'g', 'G');
printf("%c vale %d\n", 'G', 'G');
```

```
g vale 103
G vale 71
```

A diferença é `103 - 71`, ou seja, `32`; note que ela é a mesma para qualquer par de letras, porque na Tabela ASCII o alfabeto minúsculo está na mesma ordem do maiúsculo, só **deslocado**.

Escrever `32` direto no código seria um valor mágico. Em vez disso, calculamos a diferença com os próprios caracteres:

``` c
#include <stdio.h>

int main(void)
{
    // Entrada:

    char minuscula = 'g';

    // Saída:

    const int diferenca = 'a' - 'A';

    char maiuscula = minuscula - diferenca;

    printf("A maiúscula de %c é %c.\n", minuscula, maiuscula);

    return 0;
}
```

O código agora se explica sozinho: a diferença entre uma minúscula e uma maiúscula é a distância entre `'a'` e `'A'`.

</details>

---

<p align="center">
  <a href="../modulos/variaveis.md">← Variáveis</a>
  &nbsp;|&nbsp;
  <a href="../modulos/condicionais.md">Condicionais →</a>
</p>
