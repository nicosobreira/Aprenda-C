# Instalando o C

Quando falo em "instalar o C", me refiro a instalar um **compilador** da linguagem (veremos o que é um compilador em [O que é C?](./linguagem-c.md)). Ao longo do guia, vamos usar o compilador chamado GCC.

Também vamos instalar o Visual Studio Code, também chamado de VS Code, para escrever os códigos.

Siga os passos dependendo do sistema operacional que está usando: Windows, Linux ou macOS.

## No Windows

### Instalando o GCC pelo PowerShell

> Não confunda com o "Prompt de Comando". O PowerShell é o terminal mais atualizado do Windows.

Vamos usar o PowerShell, o terminal padrão do Windows, para instalar o GCC. A Microsoft oferece `winget`, um gerenciador de pacotes que já vem instalado no Windows 10 e 11 por padrão.

#### Passo 1: Verificando o winget

Abra o PowerShell (aperte a tecla `Win`, digite "PowerShell" e aperte `Enter`). Para conferir se o `winget` está disponível, rode:

``` powershell
winget --version
```

Se aparecer um número de versão, como `v1.7.10582`, pode seguir para o próximo passo. Caso apareça um erro dizendo que o comando não foi encontrado, você precisa instalar o aplicativo "App Installer" pela Microsoft Store antes de continuar.

#### Passo 2: Instalando o GCC

Vamos instalar o **WinLibs**.

``` powershell
winget install --id BrechtSanders.WinLibs.POSIX.UCRT -e
```

Esse comando baixa e extrai o compilador em uma pasta do seu computador, **normalmente** em `C:\Program Files\WinLibs\...`. Dentro dessa pasta, procure por uma subpasta chamada `mingw64\bin` (ou `mingw32\bin`, dependendo da versão baixada) — é ela que contém o arquivo `gcc.exe`. **Anote o caminho para essa pasta.**

#### Passo 3: Adicionando o compilador ao PATH

Diferente de outros programas, o `gcc.exe` não fica disponível automaticamente em qualquer lugar do terminal. Precisamos avisar ao Windows onde encontrá-lo, adicionando a pasta `bin` do compilador à variável de ambiente PATH.

Ainda no PowerShell, rode o comando abaixo, trocando o caminho pelo caminho da pasta `bin` que você anotou no passo anterior, caso eles sejam diferentes:

``` powershell
[Environment]::SetEnvironmentVariable("Path", $env:Path + ";C:\Program Files\WinLibs\mingw64\bin", "User")
```

> Repare no último argumento, `"User"`. Ele indica que a mudança vale apenas para a sua conta de usuário, e não para o sistema inteiro, o que significa que você **não precisa de permissões de administrador** para rodar esse comando. Além disso, essa mudança é permanente: continua valendo mesmo depois de reiniciar o computador.

#### Passo 4: Verificando a instalação

Feche a janela do PowerShell e abra uma nova — o PATH atualizado só é reconhecido em terminais abertos **depois** da mudança. Em seguida, rode:

``` powershell
gcc --version
```

Se aparecer o número da versão do GCC instalado, a instalação deu certo, e o compilador já está pronto para ser usado, inclusive dentro do VS Code.

> Se o comando não for reconhecido, revise o caminho usado no Passo 3. É comum errar o nome exato da subpasta (`mingw64` em vez de `mingw32`, por exemplo), então volte na pasta de instalação e confirme o caminho certo.

### Instalando o VS Code pelo PowerShell

O processo é parecido com o do GCC, só que mais simples.

#### Passo 1: Instalando o Visual Studio Code

Ainda no PowerShell, rode:

``` powershell
winget install --id Microsoft.VisualStudioCode -e
```

#### Passo 2: Verificando a instalação

Feche a janela do PowerShell e abra uma nova, para garantir que o terminal reconheça o comando recém-instalado. Depois, rode:

``` powershell
code --version
```

Se aparecerem três linhas (a versão do VS Code, um código de commit e a arquitetura, como `x64`), a instalação deu certo.

> Diferente do GCC, aqui você não precisa mexer manualmente no PATH: o instalador do VS Code já se encarrega disso, adicionando o comando `code` automaticamente durante a instalação.

#### Passo 3: Instalando a extensão de C/C++

Já que estamos no terminal, também é possível instalar a extensão de C/C++ (da Microsoft) sem precisar abrir o VS Code e navegar até a loja de extensões:

``` powershell
code --install-extension ms-vscode.cpptools
```

#### Passo 4: Abrindo uma pasta de projeto

Para testar se tudo está funcionando junto, crie uma pasta para praticar e abra ela diretamente no VS Code, pelo terminal:

``` powershell
mkdir aprenda-c
cd aprenda-c
code .
```

> O `code .` abre a pasta atual (representada pelo `.`) no VS Code. Essa pasta se torna o seu **workspace**, e é dentro dela que o VS Code vai guardar as configurações de compilação que criamos mais para frente, na pasta `.vscode`.

Se o VS Code abrir mostrando a pasta `aprenda-c` no Explorador de Arquivos, à esquerda, está tudo certo: o compilador e o editor já estão prontos para o restante do guia.

## No Linux

Vou me basear no **Ubuntu** e **Debian** nos passos de instalação, caso use outra distribuição, pesquise os pacotes adequados.

### Instalando o GCC pelo Terminal

A maioria das distribuições Linux já vem com um gerenciador de pacotes. No caso do Ubuntu e do Debian, ele se chama `apt`.

#### Passo 1: Atualizando a lista de pacotes

Abra o terminal e rode:

``` bash
sudo apt update
```

> O `sudo` (*super user do*) pede a sua senha de usuário para executar o comando com privilégios administrativos, necessário para instalar programas no sistema.

#### Passo 2: Instalando o GCC

``` bash
sudo apt install build-essential
```

> `build-essential` não é só o GCC, é um **pacote de pacotes**: ele já vem com o GCC, o `make` (usado para compilar projetos maiores) e o `gdb` (um depurador), tudo que você vai precisar ao longo do guia.

#### Passo 3: Verificando a instalação

``` bash
gcc --version
```

Se aparecer o número da versão instalada, deu tudo certo.

### Instalando o Visual Studio Code

#### Passo 1: Instalando o VS Code

``` bash
sudo apt install code
```

> Dependendo da distribuição, o pacote `code` pode não estar disponível de cara no `apt`. Caso o comando acima retorne um erro dizendo que o pacote não foi encontrado, use o instalador via Snap, que já vem pronto na maioria das instalações do Ubuntu:
> ``` bash
> sudo snap install code --classic
> ```

#### Passo 2: Verificando a instalação

Feche e abra um novo terminal, depois rode:

``` bash
code --version
```

Se aparecerem três linhas (versão, commit e arquitetura), a instalação deu certo.

#### Passo 3: Instalando a extensão de C/C++

Esse passo é igual nos dois sistemas, e também no Windows:

``` bash
code --install-extension ms-vscode.cpptools
```

### Passo 4: Abrindo uma pasta de projeto

``` bash
mkdir aprenda-c
cd aprenda-c
code .
```

Se o VS Code abrir mostrando a pasta `aprenda-c` no Explorador de Arquivos, o compilador e o editor já estão prontos para o restante do guia.

## No macOS

### Instalando o GCC

O macOS não vem com um gerenciador de pacotes de fábrica, então o primeiro passo é instalar o **Homebrew**, o gerenciador de pacotes mais usado no sistema.

#### Passo 1: Instalando o Homebrew

``` bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

> Esse comando baixa e executa o script oficial de instalação do Homebrew. Ele vai pedir a sua senha em algum momento, e ao final, pode pedir para você rodar mais um ou dois comandos para adicionar o Homebrew ao PATH — siga as instruções que aparecerem no próprio terminal.

#### Passo 2: Instalando o GCC

O macOS já vem com o **Clang** pré-instalado (disfarçado de `gcc`, veremos isso já já), mas caso você prefira instalar o GCC de verdade, use:

``` bash
brew install gcc
```

#### Passo 3: Verificando a instalação

``` bash
gcc --version
```

> Uma pegadinha comum no macOS: mesmo sem instalar nada, o comando `gcc --version` pode já funcionar, mas o que ele executa por baixo dos panos é, na verdade, o **Clang**, não o GCC. Se você seguiu o Passo 2 e quer usar o GCC de verdade, talvez seja necessário chamá-lo pelo nome completo, como `gcc-14` (o número muda de acordo com a versão instalada pelo Homebrew), já que o Apple reserva o nome `gcc` para o Clang.

### Instalando o Visual Studio Code

#### Passo 1: Instalando o VS Code

Com o Homebrew já instalado (do tutorial do GCC), rode:

``` bash
brew install --cask visual-studio-code
```

> O `--cask` indica ao Homebrew que estamos instalando um aplicativo com interface gráfica, e não apenas uma ferramenta de linha de comando.

#### Passo 2: Verificando a instalação

``` bash
code --version
```

Caso a versão seja retornada, deu tudo certo.

#### Passo 3: Instalando a extensão de C/C++

Esse passo é igual nos dois sistemas, e também no Windows:

``` bash
code --install-extension ms-vscode.cpptools
```

### Passo 4: Abrindo uma pasta de projeto

``` bash
mkdir aprenda-c
cd aprenda-c
code .
```

Se o VS Code abrir mostrando a pasta `aprenda-c` no Explorador de Arquivos, o compilador e o editor já estão prontos para o restante do guia.
