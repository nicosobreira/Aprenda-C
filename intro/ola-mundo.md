# Olá, Mundo

O programa "Olá, Mundo!" é a iniciação de todo programador. Ele vai nos mostrar algumas regras básicas da linguagem C.

Primeiro, vamos ver como ele é escrito, logo em seguida vamos entender o código linha a linha.

## Código

Em um arquivo chamado `main.c` escreva:

```c
#include <stdio.h>

int main(void)
{
    printf("Olá, Mundo!\n");

    return 0;
}
```

Execute o programa antes de continuar.

## include

O `#include <stdio.h>` nos permite usar as chamadas: **funções de entrada e saída**. Essas funções permitem **mostrar** textos no terminal, assim como **pedir** informações para o usuário.

O `.h` é um apelido para *header*, em português **cabeçalho**. Veremos o conteúdo desse tipo de arquivo mais para frente.

É a partir do `#include <stdio.h>` que podemos usar a função `printf`, que nos permite **exibir** o texto `Olá, Mundo!` no terminal.

## main

É uma função especial dentro do C; ela é o **ponto inicial** de nosso programa, por isso do nome "main", do inglês, principal.

O `int` é usado para indicar que essa função retornará um valor do tipo inteiro em algum momento da execução da função `main`. Esse valor vai para o **sistema operacional** e mostra para ele se o programa executou corretamente, retornando `0`, ou falhou em algum momento, retornando um valor diferente de `0`, como `1` ou `128`. Diferentes números normalmente indicam diferentes erros.
O comando `return` encerra a função na mesma hora. Se você colocar o `return 0;` antes do `printf`, o programa fechará imediatamente e o texto nunca será exibido.

Dentro dos parênteses são colocados os parâmetros da função, igual na matemática quando escrevemos `f(x)`, onde a variável `x` é um parâmetro da função `f`. Nesse caso, o parênteses está com a palavra `void`, indicando que essa função não recebe nenhum argumento. É importante salientar que nem sempre esse é o caso, a função `main` pode sim receber parâmetros, mas veremos isso mais para frente.

Após os parênteses, temos as chaves. Elas indicam a definição da função, que é todo o código que será executado quando o programa iniciar. Diferentemente das outras funções, o `main` é executado automaticamente ao rodarmos o nosso programa.

### Formatação do código

Você pode escrever a função da seguinte maneira:

```c
int main() {
    ...
}
```

E está tudo certo. A linguagem C é bem flexível quanto ao modo como escolhemos formatar o nosso código. Quebrar uma linha para a abertura das chave é um costume meu, e é o que vou usar ao longo desse guia.

## printf

A função `printf` **imprime** (*print*) textos **formatados** (*f*) para o terminal. Nos veremos os diferentes tipos de formatação em [Variáveis](./../variaveis/primitivas.md), mas o que você precisa saber agora é que o `printf` escreve o texto "Olá, Mundo!" no terminal.

Nos precisamos colocar esse `\n`, lido como "barra **n**ova linha", no final para quebrar a linha. Tire ele e veja como a saída sai meio grudada.

O ponto e vírgula vai ao final dos comandos. Sem ele o compilador irá tentar executar desde o `printf` até o próximo ponto e vírgula, ou seja, até `return 0;`, o que vai gerar um erro.

Lembre-se que nós só podemos executar a função `printf` **depois** que importamos sua definição com o uso do `#include <stdio.h>`.
