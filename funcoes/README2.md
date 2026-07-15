# Funções

Já estamos usando diversas funções, como a `main`, a `printf` e a `scanf`, e até criamos algumas próprias, como a `entrar_na_festa` e `print_divisao`, lá no capítulo de [Condicionais](../condicional/README.md). Agora, vamos entender a sintaxe e, principalmente, **por que** elas são tão importantes.

## Declarando uma função

Agora, vamos entender o exemplo da **entrada da festa** que vimos em [Negação](../condicional/README.md#negacao). Aqui está a função `entrar_na_festa`, caso tenha esquecido.

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

## Tipo de Retorno

O primeiro termo do exemplo é o `void`. O tipo `void` tem alguns usos na linguagem C, o que nos interessa é quando ele indica o **tipo de retorno** da função. Isso significa que **nenhum valor será retornado** da função.

Note o uso do `return;` na função `entrar_na_festa`, não existe **nenhum valor** entre o `return` e `;`. Agora, na função `main` que escrevemos:

``` c
int main(void)
{
    return 0;
}
```

Existe um `0` após o `return`, que é um valor do tipo `int` - como indicado pela assinatura da função.

É importante saber que quando o `void` vem antes de um asterisco (`*`), ou seja, `void *`, seu significado muda. Veremos esse significado mais para frente.

<!-- TODO: Preciso falar qual capítulo o `void *` será apresentado -->

---

Agora vamos olhar para uma função muito simples: que retorna o valor `2`. Vamos criar uma função chamada `retorna_dois`, que vai retornar o inteiro `2`.

``` c
int retorna_dois(void)
{
    return 2;
}
```

Vamos usá-la em `main`:

``` c
int main(void)
{
    int numero = retorna_dois();

    printf("O número retornado é %d.\n", numero);

    return 0;
}
```

Usamos a função quando escrevemos `retorna_dois()`, ou seja, colocamos parênteses depois do nome da função. Esse "uso" também é conhecido como uma **chamada da função**.

É importante salientar que os valores retornados das funções são **copias**. Trago um exemplo mais a frente em [Escopos](#escopos).

## Nomes das funções

Os nomes das funções, também chamados de **identificadores** das funções, seguem as mesmas regras das variáveis. Veja [Regras de Nomenclatura](../variaveis/variaveis-1.md#regras-de-nomenclatura) caso tenha esquecido.

## Parâmetros

Os parâmetros são variáveis que passamos para as funções quando chamamos elas. Como exemplo vamos usar a função `print_divisao`, que vimos em [Negação](../condicional/README.md#negacao), só que dessa vez vamos colocar um **erro proposital** dentro da declaração da função.

> A partir de agora, os lembretes para incluir os headers ficaram menos frequentes.

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

As variáveis `numero` e `divisor` são os **parâmetros** da função `print_divisao`.

Agora vamos chamar a função com as variáveis `soma_das_notas` e `total`. O valor exibido por `print_divisao` é a média de uma aluno.

``` c
int main(void)
{
    double soma_das_notas = 23.0;
    double total = 3.0;

    print_divisao(numero, divisor);

    return 0;
}
```

<!--TODO: Continuar o exemplo até falar que os parâmetros são copias dos argumentos -->

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

### Boas Práticas

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

Até agora, sempre declaramos nossas funções **antes** da `main`. Mas o que acontece se quisermos coloca-las **depois**?

``` c
int main()
{
    saudar("Ana");

    return 0;
}

void saudar(char *nome)
{
    printf("Olá, %s!\n", nome);
}
```

Esse código **não compila**. Isso acontece porque o compilador lê o arquivo de **cima para baixo** (devido a uma regra da linguagem C), e quando encontra `saudar("Ana");` dentro de `main`, ele ainda não sabe que essa função existe, muito menos qual o seu tipo de retorno ou quais parâmetros ela espera.

Para resolver isso, sem precisar mover o código de lugar, usamos uma **declaração antecipada**, também chamada de **protótipo** da função. Ela é apenas a "assinatura" da função (tipo de retorno, nome e parâmetros), seguida de um ponto e vírgula, sem o corpo.

``` c
#include <stdio.h>

void saudar(char *nome); // Protótipo

int main()
{
    saudar("Ana");

    return 0;
}

void saudar(char *nome) // Definição
{
    printf("Olá, %s!\n", nome);
}
```

Chamamos o `void saudar(char *nome);` de **declaração** da função, e o bloco com o corpo completo de **definição** ou **implementação** da função. Isso permite organizar nosso código na ordem que fizer mais sentido para a leitura, geralmente dessa forma:

1. Importação dos header files com `#include <>`.
2. Variáveis globais e constantes.
3. Declaração das funções.
4. Função `main`.
5. E por último, as definições das funções.

## Retomando a leitura de números

Lembra do problema de copia e cola que apontamos nos exercícios anteriores? Agora, podemos **centralizar** a leitura de dados do usuário em algumas funções, e usá-las em nossos programas.

Primeiro, vamos criar uma função muito simples, chamada `leia_int`, que vai apenas validar se o número que o usuário digitou é um inteiro, e não um texto. A definição da função fica assim:

``` c
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
```

Note que não exibimos nenhuma mensagem instruindo o usuário o que ele deve digitar. O motivo disso é para permitir mensagens personalizadas que **utilizam os formatadores do `printf`** na hora em que **chamamos** a função, por exemplo:


``` c
char *nome = "Pedro";

printf("Qual é a sua idade %s?\n", nome);
int idade = leia_int();
```

Ou sem nenhum formatador:

``` c
printf("Digite um número inteiro.\n");
int inteiro = leia_int();
```



<!--
TODO: Completar esses pontos!
- Falar do por que é necessário colocar o tipo na declaração (sem overloading)
- Criar uma "família" de funções `leia_<tipo>_<restrição>`, mas não falar como separar em múltiplos arquivos. Isso fica para o próximo capítulo (eu acho).
- Ao final mostrar como o último exercício fica um pouco mais legível.
-->

## Módulos

Você pode pensar que a única vantagem das funções é evitar a repetição de código, mas essa é apenas a ponta do iceberg. A vantagem mais importante das funções é nos permitir **organizar** o código em **módulos**: uma ou mais funções que **escondem a complexidade interna** de um sistema, e mostram para o resto do código apenas o que é **necessário**.

Para elucidar essa ideia, vamos pensar em um exemplo: um sensor de temperatura.
O código a seguir faz a leitura da temperatura atual desse sensor:

``` c
if (sensor_esta_pronto() && sensor_verificar_energia())
{
    sensor_acionar_hardware();

    int bruto = sensor_ler_dados_brutos();
    int dado = sensor_aplicar_filtro(bruto);
}
```

Quem lê o código precisa entender **todos os passos** necessários para ler o sensor:

- verificar se está pronto,
- verificar sua energia,
- acionar o hardware,
- ler os dados brutos, e
- aplicar um filtro de tratamento.

Uma abordagem melhor seria **esconder** toda essa lógica em uma função, chamamos ela de `sensor_obter_temperatura`, que retornará `-1` em caso de erro:

``` c
int sensor_obter_temperatura(void)
{
    if (sensor_esta_pronto() && sensor_verificar_energia())
    {
        sensor_acionar_hardware();

        int bruto = sensor_ler_dados_brutos();
        int dado = sensor_aplicar_filtro(bruto);

        return dado;
    }
    else
    {
        return -1;
    }
}
```
> Como esse código é pequeno, não usei o retorno antecipado.

Agora, para obter o dado do sensor, só chamamos a função:

``` c
int temperatura = sensor_obter_temperatura();
```

Uma única função, `sensor_obter_temperatura`, esconde toda essa sequência. Se um dia o sensor mudar (por exemplo, deixar de precisar verificar a energia), só precisamos alterar o **interior** dessa função, sem tocar em nenhum outro lugar do código que a utiliza.

Um erro comum é pensar que modularizar significa apenas "dividir os processos em pedaços menores". Mas o critério mais importante não é o tamanho dos pedaços, e sim **o que cada pedaço esconde**. Devemos isolar aquilo que é **complicado** e o que **pode mudar com frequência**, escondendo esses detalhes de quem usará o módulo.

Falar sobre esses dois aspectos da modularização vai além do escopo desse guia, e sinceramente do meu domino sobre o assunto, caso tenha interesse, recomendo ler o artigo [On the Criteria To Be Used in Decomposing Systems into Modules](https://wstomv.win.tue.nl/edu/2ip30/references/criteria_for_modularization.pdf), escrito por David Parnas, que foi da onde tirei alguns critérios para modularizar o código:

- **Sequência de um processo**: os passos necessários para executar um processo devem ficar junto com o próprio processo, e não espalhados pelo código que apenas os utiliza. Foi exatamente isso que fizemos ao mover a leitura do sensor para a função `sensor_obter_temperatura`.
- **Acesso indireto**: no futuro, quando estudarmos [Structs](../variaveis/struct.md), veremos que não devemos acessar diretamente os membros de uma estrutura de dados de fora dela, preferindo funções auxiliares para isso.
- **Flexibilidade**: alguns módulos existem apenas para permitir que uma parte do código mude no futuro sem afetar o resto, mesmo que hoje pareçam "código a mais".
- **Esconder o como**: quem usa uma função não precisa saber **como** ela faz o que faz, apenas **o que** ela faz. É por isso que conseguimos usar `scanf` e `printf` sem entender como elas foram implementadas por dentro.

## Reflexão

Perceba que, quanto mais o nosso programa cresce, mais importante fica a organização em funções. Elas não servem apenas para economizar linhas de código, mas para **isolar responsabilidades**: cada função deve fazer bem uma única coisa, e esconder de quem a chama os detalhes de como ela faz isso.

Nos próximos capítulos, vamos aprofundar essa ideia de organização, principalmente quando falarmos sobre múltiplos arquivos, onde veremos como espalhar nossas funções entre diferentes módulos em um projeto.
