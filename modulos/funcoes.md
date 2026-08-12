# Funções

Já estamos usando diversas funções, como o `main`, `printf` e `scanf`, e até criamos algumas próprias, como a `entrar_na_festa` e `print_divisao`, lá no capítulo de [Condicionais](./condicional.md). Agora, vamos entender a sintaxe e, principalmente, **por que** elas são tão importantes.

## Declarando uma função

Vamos usar como base o exemplo da **entrada da festa** que vimos em [Negação](./condicional.md#negacao). Aqui está a função `entrar_na_festa`, caso tenha esquecido:

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
    printf("O banheiro fica à direita.\n");
    printf("Tenha uma boa noite!\n");
}
```

A linha `void entrar_na_festa(bool tem_convite)` é chamada de **assinatura** da função chamada de `entrar_na_festa`. A assinatura é separada em partes: primeiro vem o **tipo de retorno**, depois o **nome** da função, por último - entre parênteses - ficam os **parâmetros**.

Após a assinatura, entre as chaves (`{}`), fica a **declaração** da função - tudo aquilo que será executado ao usarmos a função. Essa parte também é chamada de **corpo** da função.

Para usarmos a função, devemos **chamá-la** em outra função. Por exemplo, podemos **chamar** a função `entrar_na_festa` dentro da função `main` da seguinte forma:

``` c
int main(void)
{
    entrar_na_festa(true);

    return 0;
}
```

Escrevemos o nome da função seguido por - entre parênteses - os valores que vamos passar.

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

É importante saber que quando o `void` vem antes de um asterisco (`*`), ou seja, `void *`, seu significado muda. Veremos esse significado em [Memória](./memoria.md)

## Nomes das funções

Os nomes das funções seguem as mesmas regras de nomenclatura que **todos os outros** identificadores na linguagem C. Veja [Regras de Nomenclatura](./variaveis.md#regras-de-nomenclatura) caso tenha esquecido.

## Parâmetros

Os parâmetros são **variáveis** que passamos para as funções quando chamamos elas. Veja a função `print_divisao`, que vimos em [Negação](../condicional.md#negacao):

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

Nesse caso, os valores `20.0` e `2.0` são os argumentos. Também podemos passar variáveis como argumentos, por exemplo:

``` c
int main(void)
{
    double total_da_conta = 20.0;
    double pessoas = 2.0;

    print_divisao(total_da_conta, pessoas);

    return 0;
}
```

Aqui, passamos como argumentos os valores das variáveis `total_da_conta` e `pessoas`, que no caso são `20.0` e `2.0`. Na linguagem C, os argumentos são **copiados** para os parâmetros - em todos os casos. Veja o que acontece se alterarmos a variável `divisor` e exibir o seu valor antes e depois de chamarmos a função `print_divisao`:

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

Veremos em [Memória](./memoria.md) como usar parâmetros que **mudam** os argumentos.

### Escopos

Assim como os parâmetros, toda variável em C só existe dentro de uma região específica do código. Essa região se chama escopo, e é isso que vamos entender agora.

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

Agora, vamos declarar outra função, chamada `retorna_numero`, que retorna uma **copia** do valor armazenado na variável **global** `numero` e não recebe nenhum argumento:

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

Esse código não irá compilar devido a uma regra da linguagem C: é permitida a declaração de variáveis com o mesmo nome, contanto que as variáveis fiquem em **escopos diferentes**. Como ambas as variáveis `numero` fazem parte do escopo da função `main`, elas violam a regra.

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

É a segunda linha da saída do `gcc` que nos interessa: `error: implicit declaration of function ‘entrar_na_festa’`. Esse erro indica que a função foi **implicitamente** declarada, ou seja, o compilador não conhece a **assinatura** da função para conseguir usá-la em `main`. Para resolver esse problema, devemos deixar explícita a declaração da função. Fazemos isso declarando a função antes do uso. Para isso, **copiamos e colamos** a assinatura da função na parte da definição, e colocamos um `;` ao final da linha. Veja:

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

> Outro nome para a declaração é **protótipo**.

Se certifique que a assinatura da declaração e definição são as **mesmas**, ou seja, possuem os mesmos tipos de retorno, nomes e parâmetros. Se tudo estiver certo, então o programa será executado com sucesso.

### Organização dos arquivos

Colocar as declarações logo no início funciona como um índice do arquivo: dá pra saber quais funções existem e o que cada uma espera, sem precisar procurar pelo meio das definições.

Com isso, vamos organizar os nossos programas da seguinte forma:

1. Importação dos *headers* (arquivos `.h`) com o `#include`.
2. Variáveis constantes.
3. Variáveis globais.
4. Declaração das funções.
5. Função `main`.
6. E por último, as definições das funções.

### Boas Práticas

Não é obrigatório informar o **nome** dos parâmetros na **declaração**, apenas o tipo basta. Podemos reescrever `void entrar_na_festa(bool tem_convite)` como:

``` c
void entrar_na_festa(bool);
```

> E claro, mantendo o nome do parâmetro na **definição**.

Por enquanto, nossos programas estão bem pequenos, as funções são concisas e bem simples - mas pense: e quando os programas aumentarem? A tendência é que o número de funções aumente muito. Veremos em [Modularização](./modularizacao.md) que é possível **separar** a definição e declaração das funções em arquivos diferentes. Isso nos possibilita ignorar a declaração da função e apenas ler a definição para entender o que a função faz, ou seja, ignorar todas as complexidades do funcionamento interno e focar apenas na entrada e saída.
Ao nomearmos os parâmetros, facilitamos a leitura de quem só tem acesso ao arquivo de declarações — algo que vai fazer ainda mais sentido quando falarmos em separar código em múltiplos arquivos.

## Retomando a leitura de números

Lembra do problema de copia e cola que apontamos no exercício anterior? Agora, podemos **centralizar** a leitura de dados do usuário em algumas funções, e usá-las em nossos programas.

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

    return 0;
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

Em C, o **tipo de uma função** não é definido só pelos seus parâmetros, mas sim pela combinação entre o **tipo de retorno** e os **tipos dos parâmetros**. E cada identificador só pode ter **um único tipo** dentro do mesmo escopo. Ao escrever `int leia(void)` e depois `double leia(void)`, você está dizendo ao compilador duas coisas diferentes sobre o mesmo nome `leia`, e ele não tem como decidir qual delas é a verdadeira.

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
double leia_double_entre(double min, double max)
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

            printf("Digite um número maior ou igual a %g!\n", min);
        }
        else if (numero > max)
        {
            printf("Digite um número menor ou igual a %g!\n", max);
        }
        else
        {
            leitura_valida = true;
        }
    } while (!leitura_valida);

    return numero;
}
```

Compare esta função com a `leia_double`, você percebe alguma coisa em comum entre elas? Ambas fazem a mesma lógica que apontamos no início: se a entrada não for um número, peça por outra. A única diferença é que limitar a entrada exige mais validações. Com isso, podemos reescrever a função `leia_double_entre` para usar a `leia_double`, ficando assim:

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

    return numero;
}
```

Usamos as funções, nesse caso, para eliminar a **repetição** do nosso código: se precisarmos alterar a mensagem de erro fazemos isso em um único lugar.
Reescreva o exercício [Menu de Caixa Eletrônico](../exercicios/repeticao.md#menu-de-caixa-eletronico), agora usando as funções `leia_int_entre` e `leia_double_positivo`, implemente essas funções usando `leia_int` e `leia_double` como bases.

> Quando reescrevemos o código de uma forma diferente mas sem mudar a lógica falamos na programação que: **refatoramos** o código.

<details>
<summary>Clique aqui para ver a resposta</summary>

Separei cada seção do arquivo em títulos diferentes, mas você teve colocar tudo em no mesmo arquivo e de forma sequencial.

#### Importação e Declaração

``` c
#include <stdbool.h>
#include <stdio.h>

int leia_int(void);
int leia_int_entre(int min, int max);

double leia_double(void);
double leia_double_positivo(void);
```

#### Função `main`

```c
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
```

Antes de continuar, perceba como essa parte do código está muito mais **autoexplicativa** do que a solução original do exercício. Ao ler este código, não precisamos saber **como** a função `leia_int_entre` funciona, mas sim apenas do que ela *precisa* e *o que* ela faz, informações que os **parâmetros** e o **nome** da função já nos dão. Isso é vantajoso já que a medida que o número de funções aumentam podemos variar o modo como analisamos nosso programa, de maneira mais detalhada a partir das definições ou mais geral, com as definições - não nos prendendo aos mínimos detalhes.

#### Definição

```c
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

            printf("Digite um número real!\n");
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
```

</details>

O código foi de, aproximadamente, 95 linhas para 155! À primeira vista parece muito, mas ao olharmos apenas para a função `main`, temos uma redução de 41 linhas.

Repare que essas linhas a mais não sumiram, elas só **mudaram de lugar**. Antes, a lógica de validação — o `do while`, o `scanf` e o tratamento de cada erro — ficava **misturada** com a lógica do próprio caixa eletrônico: saber se era hora de ver o saldo, depositar ou sair. Agora essa validação mora isolada dentro de `leia_int`, `leia_int_entre`, `leia_double` e `leia_double_positivo`, e a main só decide **o que fazer** com o número, não **como conseguir** esse número.

Isso traz pelo menos duas vantagens que a contagem de linhas sozinha não mostra:

Se um dia você quiser trocar a mensagem "Digite um número inteiro!" por algo mais gentil, ou adicionar uma nova regra de validação, você mexe em **um único lugar** — a função `leia_int`, por exemplo — e o programa inteiro se beneficia da mudança.

E o mais importante: essas 155 linhas pagam um preço **uma única vez**. Da próxima vez que você precisar ler um número validado, em outro exercício ou em outro programa, as funções leia_* já estarão prontas — zero linhas extras. A pergunta certa não é "quantas linhas o arquivo tem hoje?", mas sim "quantas vezes eu teria que reescrever essa validação se ela não estivesse isolada em funções?".
