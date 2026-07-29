# Instalando o C

Quando falo em "instalar o C", me refiro a instalar um **compilador** da linguagem (veremos o que é um compilador em [O que é C?](./linguagem-c.md)). Ao longo do guia, vamos usar o compilador chamado GCC.

Também vamos instalar o Visual Studio Code, também chamado de VS Code, para escrever os códigos.

Siga os passos dependendo do sistema operacional que está usando: Windows, Linux ou macOS.

## No Windows

### Instalando o GCC pelo PowerShell

> Não confunda com o "Prompt de Comando". O PowerShell é o terminal mais atualizado do Windows.

Vamos usar o PowerShell, o terminal padrão do Windows, para instalar o GCC. A Microsoft oferece `winget`, um gerenciador de pacotes que já vem instalado no Windows 10 e 11 por padrão.

Cole os comandos com o atalho `Ctrl + Shift + v`.

#### Passo 1: Verificando o winget

Abra o PowerShell (aperte a tecla `Win`, digite "PowerShell" e aperte `Enter`). Para conferir se o `winget` está disponível, rode:

``` powershell
winget --version
```

Se aparecer um número de versão, como `v1.7.10582`, pode seguir para o próximo passo. Caso apareça um erro dizendo que o comando não foi encontrado, você precisa instalar o aplicativo "App Installer" pela Microsoft Store antes de continuar.

#### Passo 2: Atualizando o PowerShell

A versão do PowerShell deve ser a 7, esse comando vai atualizar o PowerShell.

``` powershell
winget install --id Microsoft.PowerShell --exact
```

Feche o terminal atual e abre um novo PowerShell.

#### Passo 3: Instalando o GCC

``` powershell
winget install --id BrechtSanders.WinLibs.POSIX.UCRT --exact
```

Caso tudo der certo, no final da instalação, deve-se falar que diversos "alias" foram criados.

#### Passo 4: Verificando a instalação

Feche o terminal atual e abre um novo PowerShell.

``` powershell
gcc --version
```

Se aparecer o número da versão do GCC instalado, a instalação deu certo, e o compilador já está pronto para ser usado, inclusive dentro do VS Code.

### Configurando o PowerShell

Para que nossos programas consigam mostrar **caracteres com acentos** dentro do PowerShell, é necessário configurá-lo. O comando a seguir vai criar um arquivo de configuração do PowerShell, se ele ainda não existir; depois vai permitir carácteres:

``` powershell
if (!(Test-Path $PROFILE)) { New-Item -Type File -Path $PROFILE -Force }; Add-Content -Path $PROFILE -Value "`n[Console]::OutputEncoding = [System.Text.Encoding]::UTF8"   
```

Feche o terminal atual e abre um novo PowerShell.

### Instalando o VS Code pelo PowerShell

#### Passo 1: Instalando o Visual Studio Code

Ainda no PowerShell, rode:

``` powershell
winget install --id Microsoft.VisualStudioCode --exact
```

#### Passo 2: Verificando a instalação

Feche a janela do PowerShell e abra uma nova, para garantir que o terminal reconheça o comando recém-instalado. Depois, rode:

``` powershell
code --version
```

Se aparecerem três linhas (a versão do VS Code, um código de commit e a arquitetura, como `x64`), a instalação deu certo.

#### Passo 3: Instalando a extensão de C/C++

Já que estamos no terminal, também é possível instalar a extensão de C/C++ (da Microsoft) sem precisar abrir o VS Code e navegar até a loja de extensões:

``` powershell
code --install-extension ms-vscode.cpptools
```

#### Passo 4: Abrindo uma pasta de projeto

Para testar se tudo está funcionando, vamos criar uma pasta chamada `aprenda-c`, em `Documents`. Vamos usar essa pasta ao longo do guia.

``` powershell
mkdir ~/Documents/aprenda-c
cd ~/Documents/aprenda-c
code .
```

> O `code .` abre a pasta atual (representada pelo `.`) no VS Code. Essa pasta se torna o seu **workspace**, e é dentro dela que o VS Code vai guardar as configurações de compilação que criamos mais para frente, na pasta `.vscode`.

Se o VS Code abrir mostrando a pasta `aprenda-c` no Explorador de Arquivos, à esquerda, está tudo certo: o compilador e o editor já estão prontos para o restante do guia. A partir de agora, use o PowerShell **dentro do VS Code**.

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
