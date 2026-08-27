# Listas

Até agora, quando precisávamos armazenar informações, criávamos variáveis individuais para cada dado: uma variável para a idade, outra para a nota de uma prova ou para o saldo de uma conta.

Mas o que acontece quando precisamos guardar as notas de 50 alunos de uma turma? Criar `nota1`, `nota2`, `nota3` ... `nota50` seria extremamente trabalhoso, impossível de manter e tornaria o nosso código gigante sem nenhuma necessidade.

Para resolver esse problema, a linguagem C nos oferece as **listas** (tecnicamente chamadas de ***arrays* ou vetores**): uma estrutura que nos permite guardar **múltiplos valores do mesmo tipo** dentro de uma **única variável**.

## Declaração e Acesso

Para declarar uma lista em C, informamos o **tipo** dos elementos, o **nome** da lista e, entre colchetes (`[]`), a **quantidade de elementos** que ela poderá guardar.

``` c
int notas[5];
```

A linha acima reserva espaço na memória para guardar exatamente 5 números inteiros.

### Acessando os Elementos pelo Índice

Cada posição dentro de uma lista é identificada por um número chamado de **índice**. Em C (e na maioria das linguagens de programação), os índices das listas **sempre começam no número 0**.

Se declaramos uma lista de tamanho 5, os seus índices válidos serão: `0`, `1`, `2`, `3` e `4`.

Para ler ou alterar o valor de uma posição específica, usamos o nome da variável seguido do índice entre colchetes:

``` c
#include <stdio.h>

int main(void)
{
    int notas[5];

    // Atribuindo valores a cada posição
    notas[0] = 10;
    notas[1] = 8;
    notas[2] = 7;
    notas[3] = 9;
    notas[4] = 6;

    // Exibindo a primeira e a última nota
    printf("Primeira nota: %d\n", notas[0]);
    printf("Última nota:   %d\n", notas[4]);

    return 0;
}
```

## Inicialização

Assim como variáveis normais, se você declarar uma lista e não atribuir valores aos seus elementos, ela conterá **valores aleatórios** (o "lixo de memória").

Podemos inicializar uma lista no momento de sua declaração usando chaves (`{}`):

``` c
int notas[5] = {10, 8, 7, 9, 6};
```

Se você quiser inicializar **todos os elementos com o valor zero**, pode usar a seguinte atalho:

``` c
int notas[5] = {0};
```

> Quando você fornece menos valores do que o tamanho total da lista, o compilador preenche automaticamente as posições restantes com `0`.

Ainda é possível omitir o tamanho da lista entre `[]` ao inicializar o array da seguinte maneira:

``` c
int notas[] = {5, 8, 1};
```

## Percorrendo uma Lista com `for`

A verdadeira força das listas surge quando as combinamos com **estruturas de repetição**. Em vez de acessar cada posição manualmente, usamos a variável de controle do `for` loop como o **índice** da lista.

Vamos ver um programa que calcula a média de 5 notas:

``` c
#include <stdio.h>

int main(void)
{
    const int total_notas = 5;
    int notas[total_notas] = {10, 8, 7, 9, 6};

    int soma = 0;

    for (int i = 0; i < total_notas; i++)
    {
        soma += notas[i];
    }

    double media = (double)soma / total_notas;

    printf("A soma das notas é: %d\n", soma);
    printf("A média da turma é: %.2f\n", media);

    return 0;
}
```

Repare no trecho `i < total_notas`: como o índice vai de `0` até `4`, para `i = 5`, a condição `5 < 5` garante que o laço pare exatamente após processar a última posição válida (`4`).

## O que acontece por debaixo dos panos?

Agora que entendemos a sintaxe básica, vamos entender **como o computador gerencia uma lista na memória RAM**.

Primeiro, vamos ver uma visão um pouco **abstrata** de como as memória funciona. Entenderemos a memória de verdade no módulo [Memória](./memoria.md).

### O que é memória

Pare e pense: a onde os valores das variáveis ficam armazenados?
Talvez sua resposta seja que "elas ficam na memória RAM do computador", mas o que é exatamente essa memória RAM?

Por hora, pense na memória RAM como uma sequência de blocos bem pequenos que, juntos, formam uma grande lista. Cada bloco possui um **tamanho fixo**, determinado pelo *hardware*, mas que na esmagadora maioria dos computadores (incluindo celulares) possui **1 byte**.

> Lembre-se que **1 bit** é um valor que pode ser `0` ou `1`; **1 byte** nada mais é do que um conjunto de 8 zeros ou uns.

Assim como as listas, cada byte possui um **endereço** único, que é literalmente um **número** usado para identificar esse byte na memória. O tamanho do endereço também depende do *hardware*; você provavelmente já ouviu falar em "computadores de 32 bits" e "de 64 bits", esses 32 e 64 indicam o tamanho de cada endereço.

Para vermos o endereço de uma variável em C, usamos do operador `&` (o "e comercial") da seguinte forma: `&variavel` - apenas se `variavel` já foi declarada!
Agora, vamos exibir esse endereço de forma numérica, mas antes, veja se o seu computador é 32 ou 64 bits e siga os passos adequados:

<!-- TODO: Será que eu devo explicar por que usamos os formatadores `%d` e `$lu` em cada caso? -->

<details>
<summary>Para computadores de <strong>32 bits</strong></summary>

``` c
#include <stdio.h>

int main(void)
{
    int idade = 18;

    printf("Endereço da variável idade: %d\n", &idade);

    return 0;
}
```

</details>

<details>
<summary>Para computadores de <strong>64 bits</strong></summary>

``` c
#include <stdio.h>

int main(void)
{
    int idade = 18;

    printf("Endereço da variável idade: %lu\n", &idade);

    return 0;
}
```
</details>

Execute o programa várias vezes e perceberá que o valor do endereço muda constantemente, isso é devido a como o sistema operacional reserva a memória para o programa - detalhe que não falaremos no curso.

> Caso queira saber mais, pesquise por [Endereçamento Virtual](https://en-wikipedia-org.translate.goog/wiki/Virtual_address_space?_x_tr_sl=en&_x_tr_tl=pt&_x_tr_hl=pt&_x_tr_pto=tc).

Você pode ter se assustado com o tamanho do endereço, mas pense que um computador moderno, que possui no mínimo uns 4GB de RAM (Giga ou *G* é um prefixo que indica $10^9$ e *B* significa bytes), tem capacidade de armazenar $4 * 10^9$ bytes, ou seja, $4000000000$ bytes. Lembre-se de que não é apenas o seu programa que está em execução, aplicativos no fundo e até o próprio sistema operacional utilizam a RAM, favorecendo aparecer endereços maiores.

### Alocação Contígua na Memória

Quando você declara `int notas[5];`, o compilador não espalha esses 5 números em lugares aleatórios da memória. Ele reserva 20 **blocos contínuos (lado a lado)** na memória RAM - isso mesmo 20!

Cada variável do tipo `int` não ocupa apenas 1 byte, mas sim **4 bytes** (na esmagadora maioria dos computadores modernos). Uma lista de 5 inteiros ocupará **20 bytes seguidos** (5 $\times$ 4 bytes). Já uma lista com 10 inteiros, 40 bytes (10 $\times$ 4 bytes).

Podemos ver o valor exato de uma variável com operador `sizeof`, de dois jeitos:

1. Pelo tipo:

``` c
int main(void)
{
    printf("Tamanho do tipo int: %d\n", sizeof(int));

    return 0;
}
```

2. Pelo nome de uma variável de determinado tipo:

``` c
int main(void)
{
    int idade = 18;

    printf("Tamanho da variável idade (ou seja, do tipo int): %d\n", sizeof(idade));

    return 0;
}
```

Podemos representar a organização da lista `int notas[5] = {10, 8, 7, 9, 6}` na memória RAM em uma tabela.

> Não temos como saber o endereço de memória, por isso escolhi um valor qualquer, que foi o `1000`.

| Endereço de Memória | Elemento   | Valor |
| :-:                 | :-:        | :-    |
| 1000                | `notas[0]` | 10    |
| 1004                | `notas[1]` | 8     |
| 1008                | `notas[2]` | 7     |
| 1012                | `notas[3]` | 9     |
| 1016                | `notas[4]` | 6     |

### Por que o índice começa em 0?

Essa é uma das dúvidas mais comuns de quem está aprendendo a programar! A resposta está na matemática que o processador faz para encontrar um elemento na memória.

Para o computador, o nome da lista (`notas`) representa o **endereço inicial (endereço base)** onde o bloco começa. O índice não é o "número da posição", mas sim um **deslocamento (*offset*)** a partir da origem.

A fórmula para calcular o endereço de qualquer elemento é:

$$\text{Endereço do Elemento} = \text{Endereço Base} + (\text{Índice} \times \text{Tamanho do Tipo})$$

Veja o cálculo para cada índice considerando o endereço base `1000` e `sizeof(int) = 4 bytes`:

- Para o **primeiro elemento**: $\text{Endereço} = 1000 + (0 \times 4) = 1000$ (deslocamento **zero**!).
- Para o **segundo elemento**: $\text{Endereço} = 1000 + (1 \times 4) = 1004$.
- Para o **terceiro elemento**: $\text{Endereço} = 1000 + (2 \times 4) = 1008$.

Se o primeiro índice fosse `1`, o processador teria que fazer uma subtração extra `(índice - 1)` em **toda leitura de memória**, o que deixaria os programas (um pouco mais) lentos! Começar em `0` elimina essa operação desnecessária.

Note que o compilador do C **já faz essa operação**. Ao acessarmos o segundo elemento de `notas` em `notas[2]`, o compilador já multiplica o tamanho da variável `int` pelo índice e soma ao endereço base.

### Por que `array[100]` não gera erro de compilação?

O que acontece se declararmos uma lista de 5 elementos e tentarmos acessar a posição `100`?

``` c
int notas[5] = {10, 8, 7, 9, 6};

// Acessando um índice fora dos limites!
printf("%d\n", notas[100]);
```

Em linguagens mais modernas (como Python, Java ou C#), o programa imediatamente para e exibe um erro de "Índice fora dos limites" (*Index Out of Bounds Exception*). 

No entanto, **a linguagem C não faz checagem de limites (*bounds checking*)**.

#### Por que o C funciona assim?

O C foi projetado focado em **velocidade máxima**. Fazer uma verificação de limites em cada acesso a um elemento exigiria que o processador executasse instruções extras de comparação antes de ler a memória. O criador do C preferiu dar confiança total ao programador.

Ao executar `notas[100]`, o C aplica a mesma fórmula matemática: pega o endereço base de `notas`, avança $100 \times 4 = 400$ bytes na memória RAM e lê o valor que estiver guardado lá.

Isso pode gerar dois cenários perigosos:

1. **Lixo de memória**: O programa lê um valor aleatório que pertencia a outra variável do sistema.

2. ***Segmentation Fault* (Falha de Segmentação)**: Se o endereço calculado invadir uma área de memória protegida do Sistema Operacional, o SO interrompe e encerra seu programa imediatamente.

Esse comportamento imprevisível é chamado de **Comportamento Indefinido (*Undefined Behavior*)**. É responsabilidade do programador garantir que o código nunca acesse índices inválidos!

### Conectando o operador `&` e o `scanf`

Lembra que no módulo de [Estruturas de Repetição](./repeticao.md) usamos o operador `&` para ler valores no `scanf`?

``` c
int numero;
scanf("%d", &numero);
```

O operador `&` significa **"endereço de memória de"**. Ele informa ao `scanf` em qual endereço de memória o valor lido do teclado deve ser guardado.

Agora veja que curioso: quando queremos ler um valor direto para uma posição da lista, passamos o endereço daquela posição específica:

``` c
#include <stdio.h>

int main(void)
{
    int numeros[3];

    for (int i = 0; i < 3; i++)
    {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    return 0;
}
```

O `&numeros[i]` entrega ao `scanf` o endereço exato do byte onde o elemento da posição `i` está alocado na RAM!

## Boas Práticas

### 1. Nunca use Valores Mágicos para o tamanho da lista

Sempre defina uma variável `const` para armazenar o tamanho da lista. Isso evita ter que alterar o número em múltiplos laços `for` caso o tamanho da lista precise mudar no futuro.

``` c
// Ruim
int notas[5];
for (int i = 0; i < 5; i++) { ... }

// Bom
const int total_notas = 5;
int notas[total_notas];

for (int i = 0; i < total_notas; i++) { ... }
```

Isso também se aplica quando passamos uma lista como argumento para uma função. Na assinatura da função escrevemos:

``` c
void print_int(int tamanho, int lista[tamanho]);
```

E na hora de chamar a função:

``` c
int main(void)
{
    const int total_notas = 5;

    int notas[total_notas] = {10, 8, 2};

    print_int(total_notas, notas);

    return 0;
}
```

### 2. Sempre Inicialize suas Listas

Para evitar trabalhar acidentalmente com lixo de memória, inicialize a lista na declaração:

``` c
int pontuacoes[10] = {0}; // Todos os 10 elementos começam zerados
```

### 3. Cuidado com os limites (`<` vs `<=`)

Ao iterar sobre uma lista de tamanho `N`, a condição do laço deve ser `i < N` (estritamente menor) e **nunca** `i <= N`. Se o tamanho for 5 e você usar `i <= 5`, no último ciclo o laço tentará acessar `lista[5]`, que é a 6ª posição e está fora da área alocada!
