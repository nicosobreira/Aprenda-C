# Condicionais

As condicionais são estruturas que nos possibilitam avaliar condições e executar diferentes códigos dependendo de seus resultados. Para deixar essa explicação mais clara, vamos pensar em um exemplo do dia a dia: será que eu devo levar o meu guarda chuva ao sair de casa? Ao avaliarmos essa pergunta, primeiro pensamos se irá chover ou não no dia. **Se** chover, então pegamos o guarda chuva, **senão** deixamos ele em casa.

## if e else

Para resolvermos o nosso problema do guarda chuva, vamos escrever um programa que irá fazer essa decisão! Primeiro iremos declarar uma variável do tipo `bool`, chamada `vai_chover`. Nós podemos dar o valor de `true` ou `false` para ela, você escolhe. Depois iremos implementar essa lógica do "se e senão".

> Não se esqueça de importar a definição do tipo bool.

``` c
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

As palavras `if` e `else` são traduções diretas para o "se" e "senão".
Com isso em mente, lemos esse código da seguinte forma: **se** o valor armazenado na variável `vai_chover` for `true`, **então** execute tudo entre as chaves abaixo do `if`, senão execute tudo entre as chaves abaixo do `else`.

Mude o valor da variável `vai_chover` para `false` e veja como a saída muda.

## else if

Agora, vamos pensar em outro problema do dia a dia: qual tipo de roupa devo vestir hoje? Ao avaliarmos essa pergunta, temos que levar em consideração a temperatura média ao longo do dia. Utilizamos de valores arbitrários para decidir quais faixas de temperaturas são frias, quentes e a ideais.

Para resolver esse problema, vamos criar um programa que declara duas variáveis constantes do tipo `double` chamadas `temp_baixa` e `temp_alta`, que vão determinar as faixas de temperatura que você considera como frias e quentes, no meu caso são 13ºC e 32ºC. Depois, vamos criar outra variável do tipo `double` chamada `temperatura`, que armazenará a temperatura média no dia. Para decidirmos qual tipo de roupa é melhor levar, vamos usar de **operadores** de comparação, como `>` e `<` da matemática junto a duas condicionais.

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
        printf("Use uma regata e se hidrate.\n");
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

> Note que não precisamos importar `stdbool.h`, isso por que não usamos o tipo `bool` em nenhum momento.

Primeiro, o programa vai verificar, com o uso do primeiro `if`, se o valor armazenado na variável `temperatura` é maior do que o armazenado em `temp_alta`. Se esse for o caso, então faça as recomendações para o calor, senão verifique se a `temperatura` é menor que `temp_baixa`, com o uso do `else if`. Se a `temperatura` for baixa, então recomende um casaco. Por fim, se a temperatura não está nem muito quente, nem muito frio, então o clima só pode estar perfeito.

Teste com diversos valores de temperatura, alterando o valor da variável `temperatura`, e veja quais mensagens aparecem.

Agora, veja o que acontece com os valores exatos de `temp_baixa` e `temp_alta`. Você percebeu que a mensagem indica um clima perfeito? Isso é um erro lógico em nosso programa, já que a variável `temp_alta` e `temp_baixa` deveriam representar **o ponto de mudança das temperaturas**, ou seja, esses valores **também fazem parte de suas respectivas faixas de temperatura**.

Para corrigir isso, devemos usar os operadores `>=` e `<=`.

> Na escrita do código, vou focar apenas nas mudanças do `if`, mas você deve escrever tudo!

``` c
if (temperatura >= temp_alta)
{
    printf("Hoje vai fazer muito calor!\n");
    printf("Use uma regata e se hidrate.\n");
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

É usado para inverter uma condição, ou seja, trocar de `true` para `false` e vice-versa.

Para explicar o uso da negação, vamos pensar em uma festa: uma pessoa só pode entrar nela se possuir um convite, senão ela é barrada na entrada.

Primeiro, vamos resolver esse problema usando um `if` junto a um `else`. Logo em seguida, veremos um jeito melhor, usando apenas um `if`. Vamos criar uma função chamada `entrar_na_festa` que *retorna nada* e tem como argumento uma variável do tipo `bool` chamada `tem_convite`.

> O `void` é um termo que possui vários significados na linguagem C. **Nesse caso**, ele indica que a função vai retornar nenhum valor.

``` c
#include <stdio.h>
#include <stdbool.h>

void entrar_na_festa(bool tem_convite)
{
    if (tem_convite)
    {
        printf("Seja bem-vindo!\n");
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

O nosso código atual não traz essa ideia de **válido** e **inválido** em sua construção. Note que é diferente do nosso primeiro exemplo, no começo do capítulo, onde chuver ou não são **dois caminhos válidos** para um dia.

Sendo assim, o problema está no *design* de nosso código, não na lógica. Precisamos de algum jeito de comunicar a **validez** dos argumentos da função `entrar_na_festa` para outras pessoas que lerão o código. Para isso, vamos simplemente sair no começo da função, caso algo inválido aconteça.

Vamos **negar** o valor da variável `tem_convite` com o uso da exclamação `!` e analisar o código logo em seguida.

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

Logo no começo da função, verificamos se a pessoa **não tem um convite** em `!tem_convite`, lido como "a negação da variável `tem_convite`". Depois, **saímos da função** por meio do `return` (O tipo `void` indica que a função não retornará nada, simplesmente utilizamos o `return;`, sem nenhum valor seguido dele). Mas se a pessoa tiver um convite, é mentira que ela não pode entrar, e com isso o bloco do `if` não irá rodar.

Com essas mudanças, passamos a indicar que não ter um convite é algo inválido. Chamamos essa estratégia de **Retorno Antecipado**.

A ideia do **Retorno Antecipado** também pode ser usado em outros contextos. Por exemplo, se você quiser dividir dois números, o divisor tem que ser diferente de 0.

Para isso, vamos criar uma função chamada `print_divisao` que retorna nada e tem como argumentos duas variáveis do tipo `double`, chamadas `numero` e `divisor`. Seu propósito é imprimir a divisão entre `numero` e `divisor`.

> Não se esqueça de adicionar o `#include <stdio.h>` e usar `print_divisao` em `main`!

``` c
void print_divisao(double numero, double divisor)
{
    printf("O resultado é: %f\n", numero / divisor);
}
```

Teste com diferentes valores para `numero` e `divisor`, mas sempre que o `divisor` valer 0, o valor será `inf`. Esse valor de `inf` está relacionado com o padrão IEEE 754. Esse padrão determina a divisão por 0 como uma operação válida, com um valor especial chamado de `inf`. Mas como poderíamos fazer a divisão se tornar inválida? Podemos usar um **Retorno Antecipado** para tal.

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

Com isso, garantimos que o valor de `divisor` sempre será diferente de 0.

> Note que, devido as imprecisões do padrão IEEE 754, não é recomendado comparar diretamente valores `float` ou `double` com o `==`, prefira as desigualdade, como `<` e `>=`. A única excecão é o `0.0`.

## O bool por debaixo dos panos

As condições em C sempre resultam em valores numéricos. Vejamos um exemplo:

``` c
#include <stdio.h>

int main()
{
    printf("Condição Verdadeira: %d\n", 3 == 3);
    printf("Condição Falsa: %d\n", 1 > 10);

    return 0;
}
```

No primeiro caso, o resultado da condição `3 == 3` é 1, já que de fato, 3 é igual a 3. Já no segundo, como 1 não é maior que 10, o resultado é 0.

A linguagem C define o valor 0 como falso, qualquer outro valor é verdadeiro. Dessa forma, o tipo `bool` e os valores `true` e `false` são apenas números. Utilizamos desse tipo para trazer clareza em nosso código.
