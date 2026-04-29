# Escopos

Os escopos delimitam a região em nosso código que uma variável fica disponível.

Por exemplo, no programa a seguir, a variável `numero` foi criada no **escopo global**, e portanto, fica disponível para a função `main` e qualquer outra declarada no mesmo arquivo.

Em um arquivo chamado `main.c`, digite:

``` c
#include <stdio.h>

int numero = 0;

int main()
{
    printf("Numero: %d\n", numero);

    return 0;
}
```

Sempre que inicilizar uma variável, é recomendado que você inicialize ela com um valor padrão, independente do escopo da variável. Nesse caso, inicializamos a variável `numero`. O motivo disso ficará claro em [Ponteiros](../ponteiros/README.md), por hora sempre inicialize as variáveis.

Agora, vamos declarar outra função, chamada `copia_numero`, que retorna a variável **global** `numero` e recebe nenhum argumento.

``` c
#include <stdio.h>

int numero = 0;

int retorna_numero()
{
    return numero;
}

int main()
{
    printf("Numero: %d\n", retorna_numero());

    return 0;
}
```

 Note que declaramos a função `retorna_numero` à cima de `main`. Se declararmos ela em baixo, o compilador não irá saber o que executar quando rodarmos `retorna_numero`. Tente mover a ordem e veja o que acontece.
