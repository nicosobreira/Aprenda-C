# Funções

Já estamos usando diversas funções, como o `main`, `printf` e `scanf`. Agora, vamos entender sua sintaxe e, principalmente, **como criar nossas funções** e **por que** elas são tão importantes.

<!-- TODO: Usar a função `printf` como base para explicar o que quer dizer "chamar uma função" e o que são argumentos de funções. -->

## Declarando uma função

<!-- NOTE: O meu exemplo inicial pode ser o mesmo que usei em variáveis para explicar o `const`. -->

## Tipo de Retorno

## Nomes das funções

Os nomes das funções seguem as mesmas regras de nomenclatura que **todos os outros** identificadores na linguagem C. Veja [Regras de Nomenclatura](./variaveis.md#regras-de-nomenclatura) caso tenha esquecido.

## Parâmetros

## Declaração e Definição

## Retomando a leitura de números

Lembra do problema de copia e cola que apontamos no exercício anterior? Agora, podemos **centralizar** a leitura de dados do usuário em algumas funções, e usá-las em nossos programas.

Sabemos que existem diversas restrições que podemos aplicar a leitura de dados **numéricos**, como estar entre dois números e ser maior que outro. Mas para toda leitura de números, temos uma coisa em comum: caso a entrada **não seja um número**, então **pedimos por outro**.
A leitura falha quando o `scanf` retorna um inteiro diferente de `1` e perguntamos por outro número por meio de um `do while`. Sabendo disso, vamos criar a função de leitura mais básica: uma que lê um inteiro qualquer. Chamamos essa função de `leia`:

```c
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

```c
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

```c
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

Algumas linguagens permitem que várias funções compartilhem o mesmo nome, desde que seus parâmetros sejam diferentes — isso se chama **sobrecarga de funções** (_function overloading_). A linguagem C **não tem esse recurso**.

Em C, o **tipo de uma função** não é definido só pelos seus parâmetros, mas sim pela combinação entre o **tipo de retorno** e os **tipos dos parâmetros**. E cada identificador só pode ter **um único tipo** dentro do mesmo escopo. Ao escrever `int leia(void)` e depois `double leia(void)`, você está dizendo ao compilador duas coisas diferentes sobre o mesmo nome `leia`, e ele não tem como decidir qual delas é a verdadeira.

Por outro lado, repetir a **mesma** assinatura, não é um erro:

```c
int leia(void);
int leia(void); // Ok, apenas repete a mesma promessa
```

O problema nunca foi declarar duas vezes, e sim prometer **coisas diferentes** com o mesmo nome.

### A solução: nomes diferentes

Já que o C não distingue funções pelos parâmetros ou pelo retorno, a única coisa que resta para diferenciá-las é o **nome**. É por isso que, ao invés de uma única `leia`, vamos criar uma **família de funções**, uma para cada tipo e cada regra de validação, seguindo o padrão `leia_<tipo>_<restrição>`:

> Note que esse é o padrão que **eu** escolhi. Você pode escolher qualquer outro, o importante é ser consistente e usá-lo sempre.

```c
int leia_int(void);

double leia_double(void);
double leia_double_entre(double min, double max);
```

Cada nome já entrega, sozinho, uma pista de **o que a função faz** — muito mais claro do que ficar só no `leia`.

### Com restrições

Agora vamos implementar a função `leia_double_entre`:

```c
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

```c
double leia_double_entre(double min, double max)
{
    double numero;
    bool leitura_valida = false;
    do {
        numero = leia_double();

        if (numero < min)
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
    } while(!leitura_valida);

    return numero;
}
```

Usamos as funções, nesse caso, para eliminar a **repetição** do nosso código: se precisarmos alterar a mensagem de erro fazemos isso em um único lugar.
Reescreva o exercício [Menu de Caixa Eletrônico](../exercicios/repeticao.md#menu-de-caixa-eletrônico), agora usando as funções `leia_int_entre` e `leia_double_positivo`, implemente essas funções usando `leia_int` e `leia_double` como bases.

> Quando reescrevemos o código de uma forma diferente mas sem mudar a lógica falamos na programação que: **refatoramos** o código.

<details>
<summary>Clique aqui para ver a resposta</summary>

Separei cada seção do arquivo em títulos diferentes, mas você teve colocar tudo no mesmo arquivo e de forma sequencial.

#### Importação e Declaração

```c
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

Antes de continuar, perceba como essa parte do código está muito mais **autoexplicativa** do que a solução original do exercício. Ao ler este código, não precisamos saber **como** a função `leia_int_entre` funciona, mas sim apenas do que ela _precisa_ e _o que_ ela faz, informações que os **parâmetros** e o **nome** da função já nos dão. Isso é vantajoso, já que a medida que o número de funções aumentam podemos variar o modo como analisamos nosso programa: de maneira mais detalhada a partir das definições ou mais geral, com as definições - não nos prendendo aos mínimos detalhes.

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

        if (numero < 0.0)
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

E o mais importante: essas 155 linhas pagam um preço **uma única vez**. Da próxima vez que você precisar ler um número validado, em outro exercício ou em outro programa, as funções `leia_<tipo>_<restrição>` já estarão prontas — zero linhas extras.

---

<p align="center">
  <a href="../exercicios/repeticao.md">← Exercícios: Estruturas de Repetição</a>
  &nbsp;|&nbsp;
  <a href="../exercicios/funcoes.md">Exercícios: Funções →</a>
</p>

## Boas Práticas

### Retorno Antecipado

Esse é uma estratégia usada junto com o `#!c if`. Vamos pensar em uma festa: uma pessoa só pode entrar nela se possuir um convite, senão ela é barrada na entrada.

Primeiro, vamos resolver esse problema usando um `#!c if` junto a um `#!c else`. Logo em seguida, veremos um jeito melhor, usando apenas um `#!c if`.
Para tal, vamos criar uma função chamada `entrar_na_festa` que _retorna nada_ e tem como argumento uma variável do tipo `#!c bool` chamada `tem_convite`.

```c
#include <stdio.h>
#include <stdbool.h>

void entrar_na_festa(bool tem_convite)
{
    if (tem_convite)
    {
        printf("Seja bem-vindo!\n");
        printf("Pode escolher uma mesa aqui.\n");
        printf("O banheiro fica à direita.\n");
        printf("Tenha uma boa noite!\n");
    }
    else
    {
        printf("Você não tem convite! Rala!\n");
    }
}
```

Logo abaixo, na função `main`:

```c
int main()
{
    printf("-- Pessoa 1\n");
    entrar_na_festa(true);

    printf("\n");

    printf("-- Pessoa 2\n");
    entrar_na_festa(false);

    return 0;
}
```

Se você rodar o programa, verá que a primeira pessoa entrou na festa e a segunda não. O código funcionou, então por que essa pode não ser a melhor escolha?

Para chegar a uma resposta, precisamos entender realmente o que significa "entrar em uma festa". Para uma pessoa entrar em uma festa, é **obrigatório** que ela tenha um convite, caso ela não tenha, ela será expulsa **na hora**, logo no **começo**. Pense que ter o convite é algo **válido** para entrar na festa, já não ter um, é **inválido**.

O nosso código atual não traz essa ideia de **válido** e **inválido** em sua construção. Note que é diferente do nosso primeiro que vimos em [Condicional](./condicionais.md), onde chover ou não são **dois caminhos válidos** para um dia.

Sendo assim, o problema está no _design_ de nosso código, não na lógica. Precisamos de algum jeito de comunicar a **validez** dos argumentos da função `entrar_na_festa` para outras pessoas que lerão o código. Para isso, vamos simplesmente sair no começo da função, caso algo inválido aconteça.

Vamos **negar** o valor da variável `tem_convite` com o uso da exclamação `!` e analisar o código logo em seguida.

```c
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

Logo no começo da função, verificamos se a pessoa **não tem um convite** com `#!c !tem_convite`, lido como "a negação da variável `tem_convite`". Depois, **saímos da função** por meio do `#!c return` (O tipo `#!c void` indica que a função não retornará nada, simplesmente utilizamos o `#!c return;`, sem nenhum valor seguido dele). Mas se a pessoa tiver um convite, ela não pode entrar, e com isso o bloco do `#!c if` não irá rodar.

Com essas mudanças, passamos a indicar que não ter um convite é algo inválido. Chamamos essa estratégia de **Retorno Antecipado**;
Usar ela fica a sua escolha: você acha que é preciso transmitir a ideia de obrigatoriedade em um problema?

A ideia do **Retorno Antecipado** também pode ser usado em outros contextos. Por exemplo, se você quiser dividir dois números, o divisor tem que ser diferente de `#!c 0`.

Para isso, vamos criar uma função chamada `print_divisao` que retorna nada e tem como argumentos duas variáveis do tipo `#!c double`, chamadas `numero` e `divisor`. Seu propósito é imprimir a divisão entre `numero` e `divisor`.

```c
void print_divisao(double numero, double divisor)
{
    printf("O resultado é: %f\n", numero / divisor);
}
```

Teste com diferentes valores para `numero` e `divisor`, mas sempre que o `divisor` valer 0, o valor será `inf`. Esse valor de `inf` está relacionado com o padrão IEEE 754, usado pela linguagem C.
Esse padrão determina a divisão por 0 como uma operação válida, com um valor especial chamado de `inf`. Mas como poderíamos fazer a divisão se tornar inválida? Podemos usar um **Retorno Antecipado** para tal.

```c
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

Com isso, garantimos que o valor de `divisor` sempre será diferente de 0.

> Note que, devido às imprecisões do padrão IEEE 754, não é recomendado comparar diretamente valores `float` ou `double` com o `==`, prefira as desigualdade, como `<` e `>=`. A única exceção é o `0.0`.
