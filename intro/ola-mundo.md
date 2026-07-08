# Olá, Mundo

O programa "Olá, Mundo!" é a iniciação de todo programador. Ele vai nos mostrar algumas regras básicas da linguagem C.

Antes de escrever o programa em si, vamos ver como usar o Visual Studio Code e o GCC para escrever e compilar os programas que vamos desenvolver.

## Como Organizar seus Códigos

Vamos estabelecer uma regra que seguiremos por todo o guia: **a cada novo módulo, crie uma nova pasta com o nome do módulo**. Isso evita que os arquivos de módulos diferentes se misturem, e já aproveitamos para praticar o uso do terminal.

Abra o VS Code e, dentro dele, abra o terminal integrado com o atalho `` Ctrl + ` `` (ou pelo menu **Terminal > New Terminal**).

> Se você estiver no Windows, configure o terminal integrado do VS Code para usar o **PowerShell** por padrão, já que os comandos que ensinamos neste guia foram pensados para ele, não para o Prompt de Comando (`cmd`). Para isso, aperte `Ctrl + Shift + P`, digite `Terminal: Select Default Profile` e escolha `PowerShell` na lista. Feche o terminal aberto e abra um novo para a mudança ter efeito.

Com o terminal aberto, crie uma pasta chamada `intro` (o nome desse primeiro módulo) e entre nela:

``` bash
mkdir intro
cd intro
```

O comando `mkdir` (de *make directory*) cria uma pasta nova, e o `cd` (de *change directory*) entra dentro dela. A partir de agora, todo comando que rodarmos no terminal vai valer **dentro** dessa pasta `intro`. Esse mesmo padrão se repete nos próximos módulos: ao chegar em Variáveis, por exemplo, você criaria uma pasta `variaveis`, e assim por diante.

## Criando e Editando Arquivos

Para criar e abrir o arquivo do nosso primeiro programa, use o comando `code`, seguido do nome do arquivo:

``` bash
code main.c
```

Se o arquivo `main.c` ainda não existir, o VS Code o cria automaticamente e já abre ele para edição. Esse comando, `code <arquivo>`, vai valer para o resto do guia: sempre que um capítulo pedir para criar um arquivo, use-o dentro da pasta certa.

Por ora, escreva isso dentro de `main.c`:

``` c
int main(void)
{
    return 0;
}
```

Esse é um programa que **não faz nada**, só é necessário para o próximo passo.

## Compilando com o GCC

Escrever o código é só metade do caminho: o computador não entende C diretamente, então precisamos **traduzir** o arquivo `main.c` para um executável, usando o compilador instalado anteriormente, o `gcc`.

Ainda no terminal, dentro da pasta `intro`, e com o `main.c` já salvo, rode:

``` bash
gcc -o app main.c
```

Vamos entender essa linha, pedaço por pedaço:

- `gcc`: é o programa que vai compilar o código.
- `main.c`: é o arquivo de código-fonte que queremos compilar.
- `-o app`: diz ao `gcc` qual nome deve ser dado ao **executável gerado**. Sem essa opção, o `gcc` usaria um nome genérico. Aqui, escolhemos chamar o nosso de `app`.

> No Windows, o `gcc` adiciona a extensão `.exe` automaticamente ao nome escolhido, então o executável se chamará `app.exe`, mesmo você tendo digitado só `app` no comando.

Se tudo ocorrer bem, esse comando **não imprime nada** no terminal, apenas cria o arquivo executável na mesma pasta. Se houver algum erro no seu código, o gcc vai mostrar mensagens indicando a linha e o motivo do erro — leia-as com calma, é assim que vamos aprender a interpretar erros de compilação ao longo do guia.

## Executando o Programa

Por fim, para rodar o programa que acabamos de compilar:

No Linux e no macOS:

``` bash
./app
```

No Windows (PowerShell):

``` powershell
.\app.exe
```

> Repare no `./` (ou `.\`) antes do nome do executável. Isso indica ao terminal que o programa está na **pasta atual**, e não em algum outro lugar do sistema. Sem esse prefixo, o terminal não vai encontrar o `app`.

Esse ciclo — **editar com `code`, compilar com `gcc`, executar com `./app`** — vai se repetir em praticamente todo capítulo do guia, então vale a pena se acostumar com ele desde já.

---

Agora sim, vamos escrever o programa "Olá, Mundo!", e depois analisá-lo linha a linha.

## Código

Dentro do mesmo `main.c`, agora escreva:

```c
#include <stdio.h>

int main(void)
{
    printf("Olá, Mundo!\n");

    return 0;
}
```

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

### Biblioteca Padrão

Você deve estar se perguntando: de onde vem a função `printf`? Nós não escrevemos o código dela em lugar nenhum!

A resposta é a **Biblioteca Padrão do C**: um conjunto de funções prontas que já vêm junto com a linguagem, para tarefas comuns, como exibir texto na tela ou ler dados do usuário. Pense nela como uma caixa de ferramentas: ao invés de cada programador precisar inventar sua própria forma de escrever no terminal, a Biblioteca Padrão já oferece essa ferramenta pronta, chamada `printf`, para todo mundo usar.

Essas ferramentas ficam organizadas em arquivos chamados de ***headers*** (do inglês, "cabeçalhos"), reconhecidos pela extensão `.h`. Cada header guarda um grupo de funções parecidas entre si. O header `stdio.h`, por exemplo, guarda as funções de entrada e saída (*i*nput/*o*utput), como o `printf` e o `scanf`.

O `#include <stdio.h>` é o que **libera o uso** dessas funções no nosso código. Sem essa linha, o compilador não saberia o que é `printf`, e o programa não compilaria.

> Falaremos sobre o porquê de usarmos os símbolos `<>` mais para frente.
