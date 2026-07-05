# Funções

Já estamos usando diversas funções, como a `main`, a `printf` e a `scanf`, e até criamos algumas próprias, como a `entrar_na_festa` e `print_divisao`, lá no capítulo de [Condicionais](../condicional/README.md). Agora, vamos entender como criar as nossas próprias funções e, principalmente, **por que** elas são tão importantes.

## Declarando uma função

Toda função possui três partes: um **tipo de retorno**, um **nome** e uma lista de **parâmetros**, entre parênteses. Vamos começar com o caso mais simples: uma função que não recebe nada e não retorna nada.

``` c
#include <stdio.h>

void saudar(void)
{
    printf("Olá! Seja bem-vindo(a)!\n");
}

int main(void)
{
    saudar();

    return 0;
}
```

O `void` antes do nome `saudar` indica que essa função **não devolve nenhum valor**. Depois, o `(void)` indica que ela **não recebe nenhum parâmetro**. Entre as chaves (`{}`), fica o **corpo** da função, ou seja, tudo que será executado quando ela for chamada.

Falamos que a função `saudar` foi **chamada** dentro de `main`, usando `saudar();`. Se chamarmos a função `saudar` da seguinte forma: `saudar(3)`, o compilador vai avisar que estamos passando muitos argumentos para a função `saudar`, o esperado são zero argumentos, ou seja, nenhum.

## Parâmetros

Uma função que não recebe nenhuma entrada tem uma utilidade limitada. Para tornarmos nossas funções mais flexíveis, usamos **parâmetros**: variáveis que a função recebe como entrada.

Vamos alterar a função `saudar` para que ela receba o nome da pessoa a ser saudada. Para isso vamos utilizar de um parâmetro chamado `nome`, que tem um tipo que ainda não vimos: `char *`. Por ora, saiba que esse tipo indica que estamos passando um texto, no caso um nome, para a função `saudar` - chamos isso de *string*. Veremos esse tipo com mais detalhe em [Strings](../variaveis/string.md).
Também utilizamos do formatador `%s` para indicar ao `printf` que queremos exibir a variável do tipo `char *`.

``` c
#include <stdio.h>

void saudar(char *nome)
{
    printf("Olá, %s! Seja bem-vindo(a)!\n", nome);
}

int main()
{
    saudar("Maria");
    saudar("João");

    return 0;
}
```

Perceba que o parâmtro `nome` funciona como qualquer outra variável **dentro** da função `saudar`, mas seu valor muda a cada chamada, de acordo com o que passamos entre os parênteses, como `"Maria"` e `"João"`, que são chamados de **argumentos** da função. Podemos ter quantos parâmetros quisermos, bastando separá-los por vírgula, como já fizemos com a função `print_divisao(double numero, double divisor)`.

## Retorno de valores

Até agora, nossas funções apenas **imprimem** algo na tela, mas nunca **devolveram** um valor para quem as chamou. Para isso, trocamos o tipo `void` por algum outro, e usamos a palavra-chave `return` para devolvê-lo.

Vamos criar uma função chamada `somar`, que recebe dois números inteiros e devolve a soma entre eles.

``` c
#include <stdio.h>

int somar(int a, int b)
{
    return a + b;
}

int main()
{
    int resultado = somar(5, 3);

    printf("O resultado da soma é %d.\n", resultado);

    return 0;
}
```

Diferente do `return` que usamos dentro de `main` (onde `return 0;` avisa o sistema operacional que tudo ocorreu bem), aqui o `return a + b;` devolve o valor calculado para quem chamou a função, nesse caso, a variável `resultado`, dentro de `main`. O `return` também **encerra a execução da função na hora**, então qualquer código escrito depois dele, dentro da mesma função, nunca vai rodar.

Reescreva a função `somar` da seguinte forma, e veja que a mensagem nunca será exibida:

``` c
int somar(int a, int b)
{
    return a + b;

    printf("Eu não vou aparecer!\n");
}
```

## Escopos

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

Para resolver isso, sem precisar mover o código de lugar, usamos uma **declaração antecipada**, também chamada de **protótipo**. Ela é apenas a "assinatura" da função (tipo de retorno, nome e parâmetros), seguida de um ponto e vírgula, sem o corpo.

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

Chamamos o `void saudar(char *nome);` de **declaração** da função, e o bloco com o corpo completo de **definição** ou **implementação** da função. Isso permite organizar nosso código na ordem que fizer mais sentido para a leitura, geralmente deixando a `main` no topo do arquivo, como o ponto de partida.

## Retomando a leitura de números

Lembra do problema de copia e cola que apontamos nos exercícios anteriores? Agora podemos esconder a leitura de dados em diferentes funções.

<!--
TODO: Completar esses pontos!
-->
- Criar uma "família" de funções `leia_<tipo>_<restrição>`, mas não falar como separar em múltiplos arquivos. Isso fica para o próximo capítulo (eu acho).
- Ao final mostrar como o último exercício fica um pouco mais legível.

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
