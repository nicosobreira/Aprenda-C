# Condicionais
<!-- 
- if statment
- else
- else if
- O tipo `bool` por debaixo dos panos (como um inteiro)
-->

As condicionais são estruturas que nos possibilitam avaliar condições e executar diferentes códigos dependendo de seus resultados. Para deixar essa explicação mais clara, vamos pensar em um exemplo do dia a dia: será que eu devo levar o meu guarda chuva ao sair de casa? Quando avaliarmos essa pergunta, primeiro pensamos se irá chover ou não no dia. Se chover, então pegamos o guarda chuva, senão deixamos ele em casa.

## if

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
        printf("Deixe o guarda chuva em casa, não irá chover hoje\n");
    }

    return 0;
}
```

Para deixar claro, as palavras `if` e `else` são traduções diretas para o "se" e "senão".
Com isso em mente, lemos esse código da seguinte forma: se o valor armazenado na variável `vai_chover` for `true`, então execute tudo entre as chaves abaixo do `if`, senão execute tudo entre as chaves abaixo do `else`.

## else if

Agora, vamos pensar em outro problema do dia a dia: qual camisa eu devo vestir? Ao avaliarmos essa pergunta, temos que levar a consideração a temperatura média ao longo do dia. Utilizamos de valores arbitrários para decidir quais faixas de temperaturas são frias, quentes e a ideais.

Para resolver esse problema, vamos criar um programa que utilize duas variáveis constantes do tipo `double` chamadas `temp_baixa` e `temp_alta`, que vão determinar as temperaturas que você considera fria e quente, no meu caso é 13ºC e 32ºC. Depois, vamos criar outra variável do tipo `double` chamada `temperatura`, que armazenará a temperatura média no dia. Para a decidirmos qual tipo de roupa é melhor levar, vamos usar de **operadores** de comparação, como $>$ e $<$ da matemática junto com duas condicionais.

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
