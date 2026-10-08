<p align="center">
  <a href="../exercicios/funcoes.md">← Exercícios: Funções</a>
  &nbsp;|&nbsp;
  <a href="./?.md">? →</a>
</p>

---

# Listas

Até agora, quando precisávamos armazenar informações, criamos variáveis _individuais_ para cada dado: uma variável para a idade, outra para a nota de uma prova ou para o saldo de uma conta. Mas pense em uma situação em que tenhamos que **agrupar valores do mesmo tipo**, como na hora de calcular a **média de temperatura** nos dias úteis da **semana** e notas de um aluno, como faríamos isso? Nesse módulo veremos o conceito de **listas** (formalmente chamadas de **arrays** ou **vetores**), que vai nos possibilitar agrupar vários valores do mesmo tipo.

## O Problema

Pensando no que vimos até agora, poderíamos criar 5 variáveis para armazenar a temperatura, depois somamos as temperaturas e dividimos por `5`:

```c
#include <stdio.h>

int main(void)
{
    double temperatura_1 = 20.0;
    double temperatura_2 = 21.0;
    double temperatura_3 = 22.0;
    double temperatura_4 = 23.0;
    double temperatura_5 = 24.0;

    double media = (temperatura_1 + temperatura_2 + temperatura_3 + temperatura_4 + temperatura_5) / 5.0;

    printf("A média de temperatura é %f°C\n", media);

    return 0;
}
```

> Ufa! Cansei os dedos de tanto digitar!

O tamanho do código é um problema, mas o mais importante é não conseguir expandir o cálculo da média para mais dias (como aumentar para 7 ou 30) de maneira simples.

A seguir, veremos como as listas são declaradas e como as usamos para resolver esse problema.

## Declaração e Acesso

Para declarar uma lista em C, informamos o **tipo** dos elementos, o **nome** da lista e, entre colchetes (`[]`), a **quantidade de elementos** que ela poderá guardar.

```c
double temperaturas[5];
```

A linha acima reserva **espaço na memória** para guardar exatamente 5 números do tipo `double`.

### Acessando os Elementos pelo Índice

Cada posição dentro de uma lista é identificada por um número chamado de **índice**. Em C (e na maioria das linguagens de programação), os índices das listas **sempre começam no número 0**.

Se declaramos uma lista com 3 elementos, os seus índices válidos serão: `0`, `1`, `2` (**não teremos um índice `3`**).

Para ler ou alterar o valor de uma posição específica, usamos o nome da variável seguido do índice entre colchetes. Veja uma solução para uma versão menor do problema:

```c
#include <stdio.h>

int main(void)
{
    // Declaração
    double temperaturas[3];

    // Alteração
    temperaturas[0] = 20.0;
    temperaturas[1] = 21.0;
    temperaturas[2] = 22.0;

    // Leitura
    double media = (temperaturas[0] + temperaturas[1] + temperaturas[2]) / 3.0;

    printf("A média da temperatura em 3 dias foi %f°C\n", media);

    return 0;
}
```

Abaixo do comentário `Declaração` declaramos uma lista do tipo `double` chamada `temperaturas`, que possui 3 elementos. A seguir alteramos cada elemento dessa lista, usando o `=` para atribuir valores aos elementos. Depois acessamos cada valor para calcular a média.

Agora reescrevendo o problema original:

```c
#include <stdio.h>

int main(void)
{
    double temperaturas[5];

    temperaturas[0] = 20.0;
    temperaturas[1] = 21.0;
    temperaturas[2] = 22.0;
    temperaturas[3] = 23.0;
    temperaturas[4] = 24.0;

    double media = (temperaturas[0] + temperaturas[1] + temperaturas[2] + temperaturas[3] + temperaturas[4]) / 5.0;

    printf("A média de temperatura é %f°C\n", media);

    return 0;
}
```

O código ainda possui os mesmos problemas. Primeiro, vamos resolver as atribuições, depois as leituras.

## Inicialização

Assim como variáveis normais, se você declarar uma lista e não atribuir valores aos seus elementos, ela conterá **valores aleatórios** (o "lixo de memória").

Podemos inicializar uma lista no momento de sua declaração usando chaves (`{}`):

```c
double temperaturas[3] = {20.0, 21.0, 22.0};
```

Se você quiser inicializar **todos os elementos com o valor zero**, pode usar o seguinte atalho:

```c
double temperaturas[5] = {0};
```

> Quando você fornece menos valores do que o tamanho total da lista, o compilador preenche automaticamente as posições restantes com `0`.

Ainda é possível omitir o tamanho da lista entre `[]` ao inicializar a lista da seguinte maneira:

```c
double temperaturas[] = {20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0};
```

Aqui, estamos alocando uma lista com 7 elementos.

Reescrevendo o código, temos:

```c
#include <stdio.h>

int main(void)
{
    double temperaturas[5] = {20.0, 21.0, 22.0, 23.0, 24.0};

    double media = (temperaturas[0] + temperaturas[1] + temperaturas[2] + temperaturas[3] + temperaturas[4]) / 5.0;

    printf("A média de temperatura é %f°C\n", media);

    return 0;
}
```

## Percorrendo uma Lista com `for`

A verdadeira força das listas surge quando as combinamos com **estruturas de repetição**. Em vez de acessar cada posição manualmente, usamos a variável de controle do `for` loop como o **índice** da lista.

Podemos aplicar isso na hora em que calculamos a média. Veja:

```c
#include <stdio.h>

int main(void)
{
    double temperaturas[3] = {20.0, 21.0, 22.0};

    double soma = 0;
    for (int i = 0; i < 3; i++)
    {
        soma += temperaturas[i];
    }
    double media = soma / 3.0;

    printf("A média de temperatura é %f°C\n", media);

    return 0;
}
```

Somamos os três elementos da lista `temperaturas` usando um `for` loop: declaramos uma variável chamada `i` que serve como o **í**ndice da lista; depois, verificamos se `i` é menor que 3, ou seja, o tamanho da lista; ao final, incrementamos a variável `i` por 1, avançando para o próximo índice.

Antes de continuarmos, vamos fazer um exercício para relembrarmos a importância das constantes. Reescreva esse programa para calcular a média de temperatura para **5 dias**. Pense em quais lugares do código temos que fazer alterações e por quê.

<details>
<summary>Resposta</summary>

A solução é trocar os `3` por `5`, já que:

1. Temos que armazenar 5 **elementos**.
2. Temos que somar esses 5 **elementos**.
3. A média é resultado da soma dividida pelo total de **elementos**.

```c
#include <stdio.h>

int main(void)
{
    double temperaturas[5] = {20.0, 21.0, 22.0, 23.0, 24.0};

    double soma = 0;
    for (int i = 0; i < 5; i = i + 1)
    {
        soma += temperaturas[i];
    }
    double media = soma / 5.0;

    printf("A média de temperatura é %f°C\n", media);

    return 0;
}
```

</details>

Note a repetição da palavra "elementos". Essa pequena alteração no total de elementos já pediu por uma refatoração minuciosa no código - basta esquecer de trocar o `3` pelo `5` em um lugar no código que o programa quebra. Com o que vimos até agora, a solução esperada seria declarar uma variável constante que armazena o total de elementos. Como a seguir:

```c
#include <stdio.h>

int main(void)
{
    const int total = 7;
    double temperaturas[total] = {20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0};

    double soma = 0;
    for (int i = 0; i < total; i = i + 1)
    {
        soma += temperaturas[i];
    }
    double media = soma / total;

    printf("A média de temperatura é %f°C\n", media);

    return 0;
}
```

Mas veja a saída do compilador:

```
$ gcc -o main main.c
main.c: In function ‘main’:
main.c:6:34: error: variable-sized object may not be initialized except with an empty initializer
    6 |     double temperaturas[total] = {20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0};
      |                                  ^

```

É a linha da saída que contém o `error:` que nos interessa. Ela fala que "um objeto de tamanho variável talvez não seja inicializado, exceto com um inicializador vazio". Esse tal de "objeto" é a lista `temperaturas`, o "inicializador" são os valores entre as chaves (`{}`) e o "**tamanho variável**" se refere à variável `total` que passamos na declaração da lista. Esse erro nos diz que nem sempre é possível criar uma lista **com valores padrões** usando uma variável como o tamanho, **mesmo que ela seja constante**. O motivo disso ficará claro em [Adicionar Referência](). Mas a parte do "exceto com um inicializador vazio" é interessante, isso quer dizer que podemos usar uma variável como o tamanho **apenas** se **não colocarmos valores padrões**, como no código a seguir:

```c
#include <stdio.h>

int main(void)
{
    const int total = 7;
    double temperaturas[total];

    // Atribuir os 7 valores...

    double soma = 0;
    for (int i = 0; i < total; i = i + 1)
    {
        soma += temperaturas[i];
    }
    double media = soma / total;

    printf("A média de temperatura é %f°C\n", media);

    return 0;
}
```

O problema é que agora temos que atribuir cada valor de temperatura nas linhas abaixo. A seguir veremos uma solução possível para esse problema, em [Inserir Referência]() veremos outra. Mas antes, devemos entender o que quer dizer "armazenar valores na memória".

## O que acontece por debaixo dos panos?

Agora que entendemos a sintaxe básica, vamos entender **como o computador gerencia uma lista na memória RAM**.

Primeiro, vamos ver uma visão um pouco **abstrata** de como a memória funciona.

<!-- Entenderemos a memória de verdade no módulo [Memória](./memoria.md). -->

### O que é memória

Pare e pense: onde os valores das variáveis ficam armazenados?
Talvez sua resposta seja que "elas ficam na memória RAM do computador", mas o que é exatamente essa memória RAM?

Por ora, pense na memória RAM como uma sequência de blocos bem pequenos que, juntos, formam uma grande lista (de tamanho fixo), muito parecida com a que estamos lidando. Cada bloco possui um **tamanho fixo**, que é determinado pelo _hardware_, nos computadores modernos (incluindo celulares) o mais comum é **1 byte**.

> Lembre-se de que **1 bit** é um valor que pode ser `0` ou `1`; **1 byte** nada mais é do que um conjunto de 8 bits.

Assim como as listas, cada byte possui um **endereço** único, que é literalmente um **número** usado para identificar esse byte na memória, ou seja, um **índice**. O tamanho do endereço também depende do _hardware_; você provavelmente já ouviu falar em "computadores de 32 bits" e "de 64 bits", esses 32 e 64 bits indicam o tamanho de cada endereço.

Usamos o operador `&` (o "e" comercial) para ver o **endereço de memória de uma variável** da seguinte forma: `&variavel` - apenas se `variavel` já foi declarada!
Agora, vamos exibir esse endereço de forma numérica:

``` c
#include <stdio.h>

int main(void)
{
    int idade = 18;

    printf("Endereço de idade: %p\n", (void *)&idade);

    return 0;
}
```

> Veremos o que é o `(void *)` em [Inserir Referência]().

Execute o programa várias vezes e perceberá que o valor do endereço muda constantemente, isso é devido a como o sistema operacional reserva a memória para o programa - caso nada seja inicializado, a variável vai receber o valor armazenado no endereço de memória atual.

> Caso queira saber mais, pesquise por [Endereçamento Virtual](https://en-wikipedia-org.translate.goog/wiki/Virtual_address_space?_x_tr_sl=en&_x_tr_tl=pt&_x_tr_hl=pt&_x_tr_pto=tc).

<!-- TODO: Melhorar esse parágrafo -->

Você pode ter se assustado com o tamanho do endereço, mas pense que um computador moderno, que possui no mínimo uns 4GB de RAM (Giga ou _G_ é um prefixo que indica $10^9$ e _B_ significa bytes), tem capacidade de armazenar $4 \times 10^9$ bytes, ou seja, $4000000000$ bytes. Lembre-se de que não é apenas o seu programa que está em execução, aplicativos no fundo e até o próprio sistema operacional utilizam a RAM, favorecendo aparecer endereços maiores.

### Alocação Contígua na Memória

Quando você declara `double temperaturas[5];`, o compilador não espalha esses 5 números em lugares aleatórios da memória. Ele reserva 40 **bytes contíguos (lado a lado)** na memória RAM - isso mesmo: 40!

Cada variável do tipo `double` não ocupa apenas 1 byte, mas sim **8 bytes**. Uma lista de 5 doubles ocupará $5 \times 8$ bytes, ou seja, 40 bytes. Já uma lista com 10 doubles ocupará 80 bytes ($10 \times 8$).

Para ver o tamanho **em bytes** de uma variável ou tipo, usamos o operador `sizeof`.

> O formatador `%zu` é utilizado para imprimir o tipo de retorno do `sizeof`, que é chamado de `size_t`.

```c
int main(void)
{
    printf("Tamanho do tipo double: %zu\n", sizeof(double));

    return 0;
}
```

Também podemos passar uma variável:

```c
int main(void)
{
    int idade = 18;

    printf("Tamanho da variável idade (ou seja, do tipo int): %zu\n", sizeof(idade));

    return 0;
}
```

Mas por que os tipos têm tamanhos diferentes? Lembra que, em [Variáveis](./variaveis.md), vimos que o computador só guarda zeros e uns? Cada **bit** guarda um desses dois valores, e um **byte** é um grupo de 8 bits. Quanto mais bits uma variável tem, mais **combinações diferentes** de zeros e uns ela consegue formar, e portanto mais valores distintos consegue representar:

| Bits | Combinações   | Conta            |
| :--: | :-----------: | :--------------: |
| 1    | 2             | $2^1$            |
| 2    | 4             | $2^2$            |
| 8    | 256           | $2^8$            |
| 32   | 4 294 967 296 | $2^{32}$         |

Cada tipo recebe a quantidade de bytes necessária para o tipo de informação que ele guarda:

- O `char` ocupa **1 byte** (8 bits), ou seja, $256$ combinações. É o bastante para a Tabela ASCII, que vimos em [Variáveis](./variaveis.md), cada combinação sendo um caractere.
- O `int` ocupa **4 bytes** (32 bits), ou seja, cerca de 4,3 bilhões de combinações. Como precisamos de números negativos e positivos, essas combinações são divididas entre eles, e o `int` vai de $-2147483648$ até $2147483647$.
- O `double` ocupa **8 bytes** (64 bits). Aqui, mais bits não servem para ir mais longe, mas para ter **mais precisão**: é por isso que o `double` guarda mais casas decimais que o `float` (4 bytes).

Confira no seu computador:

``` c
#include <stdio.h>

int main(void)
{
    printf("char:   %zu byte(s)\n", sizeof(char));
    printf("int:    %zu byte(s)\n", sizeof(int));
    printf("float:  %zu byte(s)\n", sizeof(float));
    printf("double: %zu byte(s)\n", sizeof(double));

    return 0;
}
```

Podemos representar a organização da lista `double temperaturas[7] = {20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0}` na memória RAM em uma tabela. Vamos **supor** que o endereço de memória dessa lista começa em `1000`.

| Endereço de Memória |     Elemento      | Valor |
| :-----------------: | :---------------: | :---- |
|        1000         | `temperaturas[0]` | 20.0  |
|        1008         | `temperaturas[1]` | 21.0  |
|        1016         | `temperaturas[2]` | 22.0  |
|        1024         | `temperaturas[3]` | 23.0  |
|        1032         | `temperaturas[4]` | 24.0  |
|        1040         | `temperaturas[5]` | 25.0  |
|        1048         | `temperaturas[6]` | 26.0  |

### Por que o índice começa em 0?

Essa é uma das dúvidas mais comuns de quem está aprendendo a programar! A resposta está na matemática que o processador faz para encontrar um elemento na memória.

Para o computador, o nome da lista (`temperaturas`) representa o **endereço inicial (endereço base)** onde o bloco começa, em outras palavras: o endereço do **primeiro elemento**. O índice não é o "número da posição", mas sim um **deslocamento (_offset_)** a partir da origem.

A fórmula para calcular o endereço de qualquer elemento é:

$$
\text{Endereço do Elemento} = \text{Endereço Base} + (\text{Índice} \times \text{Tamanho do Tipo})
$$

Veja o cálculo para cada índice considerando o endereço base `1000` e `sizeof(double) = 8 bytes`:

- Para o **primeiro elemento**: $\text{Endereço} = 1000 + (0 \times 8) = 1000$ (deslocamento **zero**!).
- Para o **segundo elemento**: $\text{Endereço} = 1000 + (1 \times 8) = 1008$.
- Para o **terceiro elemento**: $\text{Endereço} = 1000 + (2 \times 8) = 1016$.

Note que o compilador do C **já faz essa operação**. Ao acessarmos o terceiro elemento de `temperaturas` em `temperaturas[2]`, o compilador já multiplica o tamanho da variável `double` pelo índice e soma ao endereço base.

### `sizeof` de uma lista?

Veja o código a seguir:

```c
#include <stdio.h>

int main(void)
{
    double temperaturas[3] = {20.0, 21.0, 22.0};

    printf("O tamanho da lista em bytes é %zu.\n", sizeof(temperaturas));
    return 0;
}
```

Qual você acha que será o tamanho do `sizeof(temperaturas)`? Ao rodarmos o programa, temos que o tamanho é de 24 bytes, o que faz sentido - já que a lista possui 3 elementos de 8 bytes, ou seja, **24 bytes** no total.
Sabendo disso, tente pensar em um jeito de usar o tamanho da lista em bytes e o tamanho de cada elemento para calcular o total de elementos da lista.

<details>
<summary>Clique aqui para ver a resposta.</summary>

Podemos dividir o _tamanho da lista em bytes_ pelo _tamanho de cada elemento_:

```c
#include <stdio.h>

int main(void)
{
    double temperaturas[3] = {20.0, 21.0, 22.0};
    const int total = sizeof(temperaturas) / sizeof(double);

    printf("O total de elementos é %d.\n", total);

    return 0;
}
```

</details>

O resultado são 3 elementos. Aumente a lista para 5 elementos e veja a saída.

O único problema é que essa estratégia nem sempre funciona, tente adivinhar qual é a saída do código a seguir:

```c
#include <stdio.h>

int pegar_tamanho(double lista[])
{
    return sizeof(lista) / sizeof(double);
}

int main(void)
{
    double temperaturas[5] = {21.0, 22.0, 23.0, 24.0, 25.0};

    printf("%d\n", pegar_tamanho(temperaturas));

    return 0;
}
```

O resultado esperado é 5, mas o que foi dado: 1! Lembre-se de que, em [Funções](./funcoes.md), vimos que todos os argumentos da função são **copiados**. O esperado seria que a lista `temperaturas` fosse copiada para a função `pegar_tamanho`, mas o que acontece é que **apenas o endereço de memória da lista é copiado**. Em outras palavras, o esperado seria que o tamanho em bytes da lista fosse 40 bytes ($5 \times 8$), mas o resultado é apenas 8 bytes:

``` c
#include <stdio.h>

int pegar_tamanho(double lista[])
{
    printf("Dentro da função: sizeof(lista) = %zu\n", sizeof(lista));

    return sizeof(lista) / sizeof(double);
}

int main(void)
{
    double temperaturas[5] = {21.0, 22.0, 23.0, 24.0, 25.0};

    printf("Fora da função: sizeof(lista) = %zu\n", sizeof(temperaturas));

    printf("%d\n", pegar_tamanho(temperaturas));

    return 0;
}
```

Ao passarmos uma lista para uma função, a lista passa a ser representada apenas com o **endereço inicial**, e com isso todas as informações sobre o tamanho da lista se perdem dentro da função. Veremos o que isso realmente significa em [Inserir Referência](), mas a solução é passar a lista e o tamanho para a função. Vemos isso no código a seguir, que calcula a soma dos elementos da lista `temperaturas`, por meio da função `somatorio_lista`:

```c
#include <stdio.h>

double somatorio_lista(double lista[], int tamanho);

int main(void)
{
    double temperaturas[5] = {20.0, 21.0, 22.0, 23.0, 24.0};
    const int tamanho = sizeof(temperaturas) / sizeof(double);

    printf("&temperaturas = %p\n", (void *)temperaturas);
    double soma = somatorio_lista(temperaturas, tamanho);

    double media = soma / tamanho;

    printf("A média de temperatura foi de %f°C\n", media);

    return 0;
}

double somatorio_lista(double lista[], int tamanho)
{
    printf("&lista = %p\n", (void *)lista);

    double soma = 0.0;

    for (int i = 0; i < tamanho; i++)
    {
        soma += lista[i];
    }

    return soma;
}
```

Veja que tanto a lista `temperaturas` quanto `lista` possuem o **mesmo endereço**.

### Por que `temperaturas[100]` não gera erro?

O que acontece se declararmos uma lista de 5 elementos e tentarmos acessar a posição `100`?

```c
double temperaturas[5] = {20.0, 21.0, 22.0, 23.0, 24.0};

printf("Valor no índice 100: %f\n", temperaturas[100]);
```

O programa compila e nenhum erro foi gerado. Ao executar o programa, um valor também é exibido, mas ele não é o da lista.

Em linguagens mais modernas (como Python, Java ou C#), o programa imediatamente para e exibe um erro de "Índice fora dos limites" (_Index Out of Bounds Exception_).

No entanto, **a linguagem C não faz checagem de limites (_bounds checking_)**.

### Por que o C funciona assim?

O C foi projetado focado em **velocidade máxima**. Fazer uma verificação de limites em cada acesso a um elemento exigiria que o processador executasse instruções extras de comparação antes de ler a memória. O criador do C preferiu dar confiança total ao programador.

Ao executar `notas[100]`, o C aplica a mesma fórmula matemática: pega o endereço base de `notas`, avança $100 \times 4 = 400$ bytes na memória RAM e lê o valor que estiver guardado lá.

Isso pode gerar o **lixo de memória**, que ocorre quando o programa lê um valor aleatório que pertencia a outra variável do sistema.

Esse comportamento imprevisível é chamado de **Comportamento Indefinido (_Undefined Behavior_)**. É responsabilidade do programador garantir que o código nunca acesse índices inválidos!

### Conectando o operador `&` e o `scanf`

Lembra que no módulo de [Estruturas de Repetição](./repeticao.md) usamos o operador `&` para ler valores no `scanf`?

```c
int numero;
scanf("%d", &numero);
```

O operador `&` significa **"endereço de memória de"**. Ele informa ao `scanf` em **qual endereço de memória** o **valor lido** do teclado deve ser **guardado**.

Agora veja que curioso: quando queremos ler um valor direto para uma posição da lista, passamos o endereço daquela posição específica:

```c
#include <stdio.h>

int main(void)
{
    int numeros[3];
    const int total = sizeof(numeros) / sizeof(int);

    printf("Endereço da lista total: %p\n", (void *)&total);

    for (int i = 0; i < total; i++)
    {
        printf("&numeros[%d] = %p\n", (void *)&numeros[i]);
        scanf("%d", &numeros[i]);
    }

    return 0;
}
```

O `&numeros[i]` entrega ao `scanf` o endereço exato do byte onde o elemento da posição `i` está alocado na RAM!

## Boas Práticas

### 1. Sempre Inicialize suas Listas

Para evitar trabalhar acidentalmente com lixo de memória, inicialize a lista na declaração:

```c
int pontuacoes[10] = {0}; // Todos os 10 elementos começam zerados
```

### 2. Cuidado com os limites (`<` vs `<=`)

Em uma lista com 4 elementos, o último índice válido é 3. Para uma lista de $n$ elementos, o último índice é $n - 1$. Dentro do `for` loop, tome cuidado para não colocar o `<=` sem querer, como no caso a seguir:

``` c
#include <stdio.h>

int main(void)
{
    int numeros[4] = {10, 11, 12, 13};
    const int total = sizeof(numeros) / sizeof(int);

    for (int i = 0; i <= total; i++)
    {
        printf("O número no índice %d é: %d.\n", i, numeros[i]);
    }

    return 0;
}
```

O valor do índice 4 é exibido, mas ele não existe. A correção é usar o `<`.

---

<p align="center">
  <a href="../exercicios/funcoes.md">← Exercícios: Funções</a>
  &nbsp;|&nbsp;
  <a href="./?.md">? →</a>
</p>
