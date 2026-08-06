# Funções

Já estamos usando diversas funções, como o `main`, `printf` e `scanf`, e até criamos algumas próprias, como a `entrar_na_festa` e `print_divisao`, lá no capítulo de [Condicionais](../condicional/README.md). Agora, vamos entender a sintaxe e, principalmente, **por que** elas são tão importantes.

## Declarando uma função

Vamos usar como base o exemplo da **entrada da festa** que vimos em [Negação](../condicional/README.md#negacao). Aqui está a função `entrar_na_festa`, caso tenha esquecido:

``` c
#include <stdio.h>
#include <stdbool.h>

void entrar_na_festa(bool tem_convite)
{
    if (!tem_convite)
    {
        printf("Você não tem convite! Rala!\n");
        return;
    }

    printf("Seja bem-vindo!\n");
    printf("Pode escolher uma mesa aqui.\n");
    printf("O banheiro fica a direita.\n");
    printf("Tenha uma boa noite!\n");
}
```

A linha `void entrar_na_festa(bool tem_convite)` é chamada de **assinatura** da função `entrar_na_festa`. A assinatura é separada em partes: primeiro vem o **tipo de retorno**, depois o **nome** da função, por último - entre parênteses - ficam os **parâmetros**.

Após a assinatura, entre as chaves (`{}`), fica a **declaração** da função - tudo aquilo que será executado ao usarmos a função. Essa parte também é chamada de **corpo** da função.

Para usarmos a função, devemos **chama-la** em outra função. Por exemplo, podemos **chamar** a função `entrar_na_festa` dentro da função `main` da seguinte forma:

``` c
int main(void)
{
    entrar_na_festa(true);

    return 0;
}
```

Colocamos o nome da função seguido por parênteses que contém os valores que vamos passar.

Na sequência, veremos cada parte da função com mais detalhes.

## Tipo de Retorno

O primeiro termo do exemplo é o `void`. Esse tipo tem diversos usos na linguagem C, o que nos interessa é quando ele indica o **tipo de retorno** da função. Nesse caso, ele mostra que **nenhum valor será retornado** da função.

Note o uso do `return;` na função `entrar_na_festa`, não existe **nenhum valor** entre o `return` e `;`.
Agora, na função `main` mais básica, escrevemos:

``` c
int main(void)
{
    return 0;
}
```

Existe um `0` após o `return`, que é um valor do tipo `int` - como indicado pela assinatura da função.

É importante saber que quando o `void` vem antes de um asterisco (`*`), ou seja, `void *`, seu significado muda. Veremos esse significado em um outro módulo.

<!-- TODO: Preciso falar qual capítulo o `void *` será apresentado -->

## Nomes das funções

Os nomes das funções seguem as mesmas regras de nomenclatura que **todos os outros** identificadores na linguagem C. Veja [Regras de Nomenclatura](../variaveis/variaveis-1.md#regras-de-nomenclatura) caso tenha esquecido.

## Parâmetros

Os parâmetros são **variáveis** que passamos para as funções quando chamamos elas. Veja a função `print_divisao`, que vimos em [Negação](../condicional/README.md#negacao):

``` c
void print_divisao(double numero, double divisor)
{
    if (divisor == 0.0)
    {
        printf("ERRO, a divisão por zero é inválida!\n");
        return;
    }

    printf("O resultado é: %f\n", numero / divisor);
}
```

As variáveis `numero` e `divisor`, declaradas na assinatura da função, são os parâmetros da função. Quando chamamos a função, falamos que estamos passando argumentos para a função. Veja:

``` c
int main(void)
{
    print_divisao(20.0, 2.0);

    return 0;
}
```

Nesse caso, os valores `20.0` e `2.0` são os argumentos. Se passarmos alguma variável como argumento, falamos que **seus valores são os argumentos**. Por exemplo:

``` c
int main(void)
{
    double total_da_conta = 20.0;
    double pessoas = 2.0;

    print_divisao(total_da_conta, pessoas);

    return 0;
}
```

Aqui, passamos como argumentos os valores da variáveis `total_da_conta` e `pessoas`, que no caso são `20.0` e `2.0`. Na linguagem C, os argumentos são **copiados** para os parâmetros. Veja o que acontece se alterarmos a variável `divisor` e exibir o seu valor antes e depois de chamarmos a função `print_divisao`:

``` c
void print_divisao(double numero, double divisor)
{
    if (divisor == 0.0)
    {
        printf("ERRO, a divisão por zero é inválida!\n");
        return;
    }

    divisor += 2; // ALTERAÇÃO

    printf("O divisor em print_divisao é: %f\n", divisor);
    printf("O resultado é: %f\n", numero / divisor);
}

int main(void)
{
    double total_da_conta = 20.0;
    double pessoas = 2.0;

    print_divisao(total_da_conta, pessoas);

    printf("Fora da função, o divisor é: %f\n", pessoas);

    return 0;
}
```

A variável `divisor` dentro da função passa a valer `4.0`, depois de `divisor += 2;`, com isso o resultado da divisão é `5.0` (`20.0 / 4.0`). Depois da função, exibimos o argumento `pessoas` que passamos para o parâmetro `divisor`, que no caso é `2.0` - que foi inalterado.

Veremos em um outro módulo como usar parâmetros que **mudam** os argumentos.

### Escopos

Os escopos delimitam a região em nosso código que uma variável fica disponível.

Por exemplo, no programa a seguir, a variável `numero` foi criada no **escopo global**, e portanto, fica disponível tanto para a função `main` quanto para qualquer outra função declarada no mesmo arquivo.

``` c
#include <stdio.h>

int numero = 0;

int main()
{
    printf("Numero: %d\n", numero);

    return 0;
}
```

Agora, vamos declarar outra função, chamada `retorna_numero`, que retorna uma **copia** do valor armazenado na variável **global** `numero` e recebe nenhum argumento:

``` c
#include <stdio.h>

int numero = 0;

int retorna_numero()
{
    return numero;
}

int main()
{
    printf("Numero de retorna_numero: %d\n", retorna_numero());

    return 0;
}
```

Agora vamos adicionar outra variável chamada `numero`, só que dentro da função `main`, e ver como o programa vai se comportar:

``` c
#include <stdio.h>

int numero = 0;

int retorna_numero()
{
    return numero;
}

int main()
{
    int numero = 7;
    printf("Numero de main: %d\n", numero);

    printf("Numero de retorna_numero: %d\n", retorna_numero());

    return 0;
}
```

Quando declaramos `int numero = 7;` dentro da função `main`, estamos criando uma **variável local** que também se chama `numero`, mas armazena `7`. Desse modo, nosso programa possui uma variável global e outra local, ambas com o nome de `numero`, mas como o compilador sabe quando teve usar cada uma?

Isso se deve a uma regra da linguagem C: **a variável do escopo mais interno sempre tem preferência sobre a do escopo mais externo**. O escopo pode ser definido em cima do arquivo, para variáveis globais, ou dentro do corpo das funções, entre **chaves**, para variáveis locais.

Quando declaramos `int numero = 7;` dentro de `main`, o compilador passa a usar essa variável local no primeiro `printf`. Contudo, no segundo `printf`, usamos o valor de uma função, nesse caso a `retorna_numero`. Olhe bem para a definição de `retorna_numero`, você percebe alguma declaração de uma variável chamada `numero`? Como não estamos declarando nenhuma variável, o compilador usará a variável do escopo global.
Exclua a linha que declara a **variável global** `numero` e verá que o compilador vai exibir um erro dentro da função `retorna_numero`, falando que não existe nenhuma variável `numero`.

O próximo exemplo mostra o que acontece quando declaramos duas variáveis com o mesmo nome no mesmo escopo:

``` c
#include <stdio.h>

int main()
{
    int numero = 7;
    printf("Primeira definição: %d\n", numero);

    int numero = 2;
    printf("Segunda definição: %d\n", numero);

    return 0;
}
```

Esse código não irá compilar devido a uma regra da linguagem C: é permitido a declaração de variáveis com o mesmo nome, contanto que as variáveis fiquem em **escopos diferentes**. Como ambas as variáveis `numero` fazem parte do escopo da função `main`, elas violam a regra.

Tente remover o `int` quando a variável `numero` recebe 2, ou seja, em `int numero = 2;`. Agora, o programa irá compilar e mostrará dois valores distintos.

#### Boas Práticas

É recomendado, mas não obrigatório, adicionar o prefixo `g_` para suas variáveis globais. Isso deixa muito claro quais variáveis são globais e quais são locais.

No exemplo a seguir, deixamos claro que estamos incrementando a variável global `g_numero` por 1:

``` c
#include <stdio.h>

int g_numero = 0;

int main()
{
    int numero = 7;

    g_numero = g_numero + 1;

    printf("Numero local: %d\n", numero);

    printf("Numero global: %d\n", g_numero);

    return 0;
}
```

## Declaração e Definição

Até agora, sempre declaramos nossas funções **antes** da `main`. Mas o que acontece se quisermos colocá-las **depois**? Vamos ver o que acontece com uma versão **reduzida** da função `entrar_na_festa`:

``` c
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    entrar_na_festa(true);

    return 0;
}

void entrar_na_festa(bool tem_convite)
{
    if (!tem_convite)
    {
        printf("Você não tem convite! Rala!\n");
        return;
    }

    printf("Seja bem-vindo!\n");
}
```

Recebemos esse erro ao compilarmos nosso programa:

```
$ gcc -o main main.c
main.c: In function ‘main’:
main.c:6:5: error: implicit declaration of function ‘entrar_na_festa’ [-Wimplicit-function-declaration]
    6 |     entrar_na_festa(true);
      |     ^~~~~~~~~~~~~~~
main.c: At top level:
main.c:11:6: warning: conflicting types for ‘entrar_na_festa’; have ‘void(_Bool)’
   11 | void entrar_na_festa(bool tem_convite)
      |      ^~~~~~~~~~~~~~~
main.c:6:5: note: previous implicit declaration of ‘entrar_na_festa’ with type ‘void(_Bool)’
    6 |     entrar_na_festa(true);
      |     ^~~~~~~~~~~~~~~

```

É a segunda linha da saída do `gcc` que nos interessa: `error: implicit declaration of function ‘entrar_na_festa’`. Esse erro indica que a função foi **implicitamente** declarada, ou seja, o compilador não conhece a **assinatura** da função para conseguir usá-la em `main`. Para resolver esse problema, devemos deixar explícito a declaração da função - declarando a função antes do uso. Para isso, **copiamos e colamos** a assinatura da função na parte da definição, e colocamos um `;` ao final da linha. Veja:

> Outro nome para a declaração é **protótipo**.

``` c
#include <stdio.h>
#include <stdbool.h>

// Declaração da função entrar_na_festa
void entrar_na_festa(bool tem_convite);

int main(void)
{
    entrar_na_festa(true);

    return 0;
}

// Definição da função entrar_na_festa
void entrar_na_festa(bool tem_convite)
{
    if (!tem_convite)
    {
        printf("Você não tem convite! Rala!\n");
        return;
    }

    printf("Seja bem-vindo!\n");
}
```

Se certifique que a assinatura da declaração e definição são as **mesmas**, ou seja, possuem os mesmos tipos de retorno, nomes e parâmetros. Se tudo estiver certo, então o programa será executado com sucesso.

Com isso, vamos organizar os nossos programas da seguinte forma:

1. Importação dos *headers* (arquivos `.h`) com o `#include`.
2. Variáveis constantes.
3. Variáveis globais
4. Declaração das funções.
5. Função `main`.
6. E por último, as definições das funções.

## Retomando a leitura de números

Lembra do problema de copia e cola que apontamos nos exercícios anteriores? Agora, podemos **centralizar** a leitura de dados do usuário em algumas funções, e usá-las em nossos programas.

Sabemos que existem diversas restrições que podemos aplicar a leitura de dados **numéricos**, como estar entre dois números e ser maior que outro. Mas para toda leitura de números, temos uma coisa em comum: caso a entrada **não seja um número**, então **pedimos por outro**.
A leitura falha quando o `scanf` retorna um inteiro diferente de `1` e perguntamos por outro número por meio de um `do while`. Sabendo disso, vamos criar a função de leitura mais básica: uma que lê um inteiro qualquer. Chamamos essa função de `leia`:

``` c
int leia(void)
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
```

E usamos dentro de `main`:

``` c
#include <stdio.h>

int leia(void);

int main(void)
{
    printf("Digite sua idade.\n");
    int idade = leia();

    printf("A sua idade é: %d.\n", idade);
}

int leia(void)
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
```

### Sem Sobrecarga

Agora que temos a função `leia` para `int`, vamos criar outra função que também se chama `leia`, só que para o tipo `double`:

``` c
int leia(void)
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

double leia(void)
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

            printf("Digite um número real!\n");
        }
        else
        {
            leitura_valida = true;
        }
    } while (!leitura_valida);

    return numero;
}
```

A diferença entre as funções é clara: ambas fazem "a mesma coisa", só que para tipos diferentes, então por que não usar o mesmo nome?
Tente compilar esse código e veja o que acontece:

```
$ gcc -o main main.c
main.c:14:8: error: conflicting types for ‘leia’; have ‘double(void)’
   14 | double leia(void)
      |        ^~~~
main.c:1:5: note: previous declaration of ‘leia’ with type ‘int(void)’
    1 | int leia(void)
      |     ^~~~
```

O compilador reclama de **tipos conflitantes** (`conflicting types`) para o identificador `leia`.

### Por que isso acontece

Algumas linguagens permitem que várias funções compartilhem o mesmo nome, desde que seus parâmetros sejam diferentes — isso se chama **sobrecarga de funções** (*function overloading*). A linguagem C **não tem esse recurso**.

Em C, o **tipo de uma função** não é definido só pelos seus parâmetros, mas sim pela combinação entre o **tipo de retorno** e os **tipos dos parâmetros**. E cada identificador só pode ter **um único tipo** dentro do mesmo escopo — nem um a mais. Ao escrever `int leia(void)` e depois `double leia(void)`, você está dizendo ao compilador duas coisas diferentes sobre o mesmo nome `leia`, e ele não tem como decidir qual delas é a verdadeira.

Por outro lado, repetir a **mesma** assinatura, não é um erro:

``` c
int leia(void);
int leia(void); // Ok, apenas repete a mesma promessa
```

O problema nunca foi declarar duas vezes, e sim prometer **coisas diferentes** com o mesmo nome.

### A solução: nomes diferentes

Já que o C não distingue funções pelos parâmetros ou pelo retorno, a única coisa que resta para diferenciá-las é o **nome**. É por isso que, ao invés de uma única `leia`, vamos criar uma **família de funções**, uma para cada tipo e cada regra de validação, seguindo o padrão `leia_<tipo>_<restrição>`:

> Note que esse é o padrão que **eu** escolhi. Você pode escolher qualquer outro, o importante é ser consistente e usá-lo sempre.

``` c
int leia_int(void);

double leia_double(void);
double leia_double_entre(double min, double max);
```

Cada nome já entrega, sozinho, uma pista de **o que a função faz** — muito mais claro do que ficar só no `leia`.

### Com restrições

Agora vamos implementar a função `leia_double_entre`:

``` c
double leia_double_entre(double min, double max);
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

            printf("Digite um número real!\n");
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

    return numero;
}
```

Compare esta função com a `leia_double`, você percebe alguma coisa em comum entre elas? Ambas fazem a mesma lógica que apontamos no início: se a entrada não for um número, peça por outra. A única diferença é que limitar a entrada precisa de Com isso podemos reescrever a função `leia_double_entre` para usar a `leia_double`, ficando assim:

``` c
double leia_double_entre(double min, double max)
{
    double numero;
    bool leitura_valida = false;
    do {
        numero = leia_double();

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

    return numero
}
```

<!--
TODO: Completar esses pontos!
- [x] Falar do por que é necessário colocar o tipo na declaração (sem overloading)
- [ ] Criar uma "família" de funções `leia_<tipo>_<restrição>`, mas não falar como separar em múltiplos arquivos. Isso fica para o próximo capítulo (eu acho).
- [ ] Ao final mostrar como o último exercício fica um pouco mais legível.
- [ ] Tomar cuidado o DRY (Don't Repeat Yourself). Usar como base o caso do caixa. Adicionar uma funcionalidade de retirar e colocar dinheiro em uma função, do exercício 3 anterior. Mostrar que com o crescimento do programa, essas duas operações perdem o sentido de ficar juntas.
-->

