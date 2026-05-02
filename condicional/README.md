# Condicionais
<!--
- if statment
- else
- else if
- O tipo `bool` por debaixo dos panos (como um inteiro)
-->

As condicionais são estruturas que nos possibilitam avaliar condições e executar diferentes códigos dependendo de seus resultados. Para deixar essa explicação mais clara, vamos pensar em um exemplo do dia a dia: será que eu devo levar o meu guarda chuva ao sair de casa? Quando avaliarmos essa pergunta, primeiro pensamos se irá chover ou não no dia. Se chover, então pegamos o guarda chuva, senão deixamos ele em casa.

## if e else

Para resolvermos o nosso problema do guarda chuva, vamos escrever um programa que irá fazer essa decisão! Primeiro iremos declarar uma variável do tipo `bool`, chamada `vai_chover`. Nós podemos dar o valor de `true` ou `false` para ela, você escolhe. Depois iremos implementar essa lógica do "se e senão".

``` c
// Não se esqueça de importar a definição do tipo bool!
#include <stdbool.h>
#include <stdio.h>

int main()
{
    bool vai_chover = true;

    if (vai_chover)
    {
        printf("Vai chover!\n");
        printf("É melhor levar o guarda chuva.\n");
    }
    else
    {
        printf("Deixe o guarda chuva em casa, não irá chover hoje.\n");
    }

    return 0;
}
```

Para deixar claro, as palavras `if` e `else` são traduções diretas para o "se" e "senão".
Com isso em mente, lemos esse código da seguinte forma: se o valor armazenado na variável `vai_chover` for `true`, então execute tudo entre as chaves abaixo do `if`, senão execute tudo entre as chaves abaixo do `else`.

<!--

## Entrada do Usuário

Antes de trabalharmos com a próxima estrutura condicional, quero mostrar como ler uma entrada do usuário pelo terminal.
Primeiro, vou mostrar o código para ler um valor do tipo `double` e imprimir ele, depois vamos analisa-lo.

``` c
#include <stdio.h> // Para o printf e scanf

int main()
{
    printf("Digite a temperatura do dia: ");

    double temperatura = 0.0;
    scanf("%lf", &temperatura);

    printf("A temperatura é de %.2fºC\n", temperatura);

    return 0;
}
```

Antes de tudo, temos que importar as definições das funções `printf` e `scanf` da Bibliota Padrão.

Depois, imprimimos uma mensagem que deixará claro o que o usuário deve digitar, nesse caso seria a temperatura do dia.
Note que não colocamos um `\n` ao final do primeiro `printf`, mas sim um espaço. Isso se deve ao fato da função `scanf` começar a leitura

-->

## else if

Agora, vamos pensar em outro problema do dia a dia: qual roupa devo vestir hoje? Ao avaliarmos essa pergunta, temos que levar a consideração a temperatura média ao longo do dia. Utilizamos de valores arbitrários para decidir quais faixas de temperaturas são frias, quentes e a ideais.

Para resolver esse problema, vamos criar um programa que declara duas variáveis constantes do tipo `double` chamadas `temp_baixa` e `temp_alta`, que vão determinar as temperaturas que você considera fria e quente, no meu caso é 13ºC e 32ºC. Depois, vamos criar outra variável do tipo `double` chamada `temperatura`, que armazenará a temperatura média no dia. Para a decidirmos qual tipo de roupa é melhor levar, vamos usar de **operadores** de comparação, como $>$ e $<$ da matemática junto a duas condicionais.

``` c
#include <stdio.h>

int main()
{
    const double temp_baixa = 13.0;
    const double temp_alta = 32.0;

    double temperatura = 25.2;

    if (temperatura > temp_alta)
    {
        printf("Hoje vai fazer muito calor!\n");
        printf("Use uma regata e se hidrade.\n");
    }
    else if (temperatura < temp_baixa)
    {
        printf("Hoje vai fazer frio!\n");
        printf("É melhor levar o casaco e passar hidratante.\n");
    }
    else
    {
        printf("Hoje o clima está perfeito!\n");
        printf("Uma camisa já basta.\n");
    }

    return 0;
}
```

> Note que não precisamos importar `stdbool.h`, isso é por que não usamos o tipo `bool` em nenhum momento.

Primeiro, o programa vai verificar, com o uso do `if`, se o valor armazenado na variável `temperatura` é maior do que o armazenado em `temp_alta`. Se esse for o caso, então faça as recomendações para o calor, senão verifique se `temperatura` é menor que `temp_baixa`, com o uso do `if else`. Se a `temperatura` for baixa, então recomende um casaco. Por fim, se a temperatura não está nem muito quente, nem muito frio, então o clima só pode estar perfeito.

Teste com diversos valores de temperatura alterando o valor da variável `temperatura` e veja quais mensagens aparecem.

Logo em seguida, veja oque acontece com os valores exatos de `temp_baixa` e `temp_alta`. Você percebeu que a mensagem indica um clima perfeito? Isso é um erro lógico em nosso programa, já que a variável `temp_alta` e `temp_baixa` deveriam representar **o ponto de mudança das temperaturas**, ou seja, esses valores também fazem parte de suas respectivas faixas de temperatura.

Para corrigir isso, devemos usar os operadores `>=` e `<=`.

> Na escrita do código, vou focar apenas nas mudanças do `if`, mas você deve escrever tudo!

``` c
if (temperatura >= temp_alta)
{
    printf("Hoje vai fazer muito calor!\n");
    printf("Use uma regata e se hidrade.\n");
}
else if (temperatura <= temp_baixa)
{
    printf("Hoje vai fazer frio!\n");
    printf("É melhor levar o casaco e passar hidratante.\n");
}
else
{
    printf("Hoje o clima está perfeito!\n");
    printf("Uma camisa já basta.\n");
}
```

## Negação

É usado inverter uma condição, ou seja, trocar de `true` para `false` e vice-versa.

Para explicar o uso da negação, vamos pensar em uma festa: uma pessoa só pode entrar nela se possuir um convite, senão ela já é barrada na porta.

Primeiro, vamos resolver esse problema usando um `if` junto a um `else` e logo em seguida veremos o por que essa não é a melhor escolha. Vamos criar uma função chamada `entrar_na_festa` que *retorna nada* e tem como argumento uma variável do tipo `bool` chamada `tem_convite`.

> O `void` é um termo que possui varios significados na linguagem C. **Nesse caso**, ele indica que a função não vai *retornar nada*.

``` c
#include <stdio.h>
#include <stdbool.h>

void entrar_na_festa(bool tem_convite)
{
    if (tem_convite)
    {
        printf("Seja bem vindo!\n");
        printf("Pode escolher uma mesa aqui.\n");
        printf("O banheiro fica a direita.\n");
        printf("Tenha uma boa noite!\n");
    }
    else
    {
        printf("Você não tem convite! Rala!\n");
    }
}
```

Logo abaixo, na função `main`:

``` c
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

Se você rodar o programa, verá que a primeira pessoa entrou na festa e a segunda não. O código funcionou, então por que essa não e a melhor escolha?

### Retorno Antecipado

Para chegar a uma resposta, precisamos entender realmente o que significa "entrar em uma festa". Para uma pessoa entrar em uma festa, é **obrigatório** que ela tenha um convite, caso ela não tenha, ela será expulsa **na hora**, logo no **começo**. Pense que ter o convite é algo **válido** para entrar na festa, já não ter um, é **inválido**.

O nosso código atual não traz essa ideia de **válido** e **inválido** em sua construção. Note que é diferente do nosso primeiro exemplo, no começo do capítulo, onde chuver ou não são **dois caminhos válidos** para o programa.

Sendo assim, o nosso problema está no *design* de nosso código, não na lógica. Precisamos de algum jeito de deixar claro a **validez** dos argumentos da função `entrar_na_festa` para outras pessoas que lerão o código. Para isso, vamos simplemente sair antes da nossa função, caso algo inválido aconteça.

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

    printf("Seja bem vindo!\n");
    printf("Pode escolher uma mesa aqui.\n");
    printf("O banheiro fica a direita.\n");
    printf("Tenha uma boa noite!\n");
}
```

Como o tipo `void` indica que a função não retornará nada, simplesmente utilizamos o `return;`, sem nenhum valor seguido dele.

A ideia do **Retorno Antecipado** também pode ser usado em outros contexto. Por exemplo, se você quiser dividír dois números, o divisor tem que ser diferente de 0.

Para resolver esse problema, vamos criar uma função chamada `print_divisao` que retorna nada e tem como argumentos duas variáveis do tipo `double`, chamadas `numero` e `divisor`. Seu propósito é imprimir a divisão entre `numero` e `divisor`.

> Não se esqueça de adicionar o `#include <stdio.h>` e usar `print_divisao` em main!

``` c
void print_divisao(double numero, double divisor)
{
    printf("O resultado é: %f\n", numero / divisor);
}
```

Teste com diferentes valores para `numero` e `divisor`, mas sempre que o `divisor` valer 0, o valor será `inf`. Esse valor de `inf` está relacionado com o padrão IEEE 754, nem tanto com a linguagem C; esse padrão determinada a divisão por 0 como uma operação válida, com um valor especial chamado de `inf`. Mas como poderíamos fazer essa operação inválida? Podemos usar um **Retorno Antecipado** para isso.

``` c
void print_divisao(double numero, double divisor)
{
    if (divisor == 0)
    {
        printf("ERRO, a divisão por zero é inválida!\n");
        return;
    }

    printf("O resultado é: %f\n", numero / divisor);
}
```

Com isso, garantimos que o valor de `divisor` sempre será diferente de 0.
