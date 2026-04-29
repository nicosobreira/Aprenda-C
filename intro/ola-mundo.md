# Olá, Mundo

O programa "Olá, Mundo" é a iniciação de todo programador. Ele nos mostra algumas regras básicas da linguagem.

Primeiro, vamos ver como ele é escrito e logo em seguida vamos entender o código linha a linha.

## Código

Em um arquivo chamado `main.c` escreva:

```c
#include <stdio.h>

int main()
{
    printf("Olá, Mundo!\n");

    return 0;
}
```

## Include

O `#include <stdio.h>` serve para importar as declarações das funções de entrada e saída padrão (como o `printf` e o `scanf`), permitindo o seu uso.

Ele avisa o compilador que essas funções existem, enquanto o código real que as executa fica armazenado na Biblioteca Padrão do C (*Standard*) fornecida pelo sistema operacional.

### Biblioteca Padrão

É uma biblioteca cuja a funcionalidade é definida pela linguagem C, mas sua implementação muda de plataforma para plataforma, isso é, cada plataforma tem um jeito diferente de como executar a mesma lógica.

As plataformas são como o Windows, Linux e Android.

As funcionalidades da Biblioteca Padrão estão espalhados por vários arquivos no formato `.h`. Primeiro, precisamos usar o `#include <módulo>` para importar um módulo (conjunto de funcionalidades). Falaremos do porque usamos `<>` mais para frente.

## Main

Essa é a função em que o nosso programa começa a executar. É o ponto inicial de toda a nossa aplicação, por isso do nome "main", do inglês, "principal".

O `int` é usado para indicar que essa função em algum momento retornará um valor inteiro. Note que esse momento não precisa ser no fim do programa. Experimente trocar a posição do `return 0;` com o `printf(Olá, Mundo!);` e veja o que acontece. Nada será exibido no terminal!

Dentro dos parênteses são colocados os argumentos da função, igual na matemática quando escrevemos $f(x)$, onde a variável $x$ é um argumento da função $f$. Nesse caso, o parênteses está vazio, indicando que essa função não recebe nenhum argumento. É importante salientar que nem sempre esse é o caso, a função `main` pode sim receber argumentos, mas vamos ver isso mais para frente.

Após os parênteses, temos as chaves. Talvez você escreva essa função como:

```c
int main() {
    ...
}
```

E está tudo certo. A linguagem C é bem flexível quanto ao modo como você escolhe formatar o seu código. Quebrar uma linha para a abertura das chave é um costume meu, e é o que vou usar ao longo desse guia.

As chaves indicam a definição da função, que é todo o código que será executado quando rodarmos o programa.

## Printf

A função `printf` **imprime** (*print*) textos **formatados** (*f*) para o terminal. Nos veremos os diferentes tipos de formatação em [Variáveis](./../variaveis/primitivas.md), mas o que você precisa saber agora é que o `printf` escreve o texto "Olá, Mundo!" no terminal.

Nos precisamos colocar esse `\n`, lido como "barra *new line*", no final para quebrar a linha. Tire ele e veja como a saída saí meio esquisita.

Temos que colocar esse bendito ponto e vírgula no final para indicar o fim do comando `printf`. Sem ele o compilador irá tentar executar desde o `printf` até o próximo ";", ou seja, até `return 0;`, o que vai gerar um erro.

Lembre-se que nós só podemos executar a função `printf` depois que importamos sua definição com o uso do `#include` em `#include <stdio.h>`.
