#!/usr/bin/env bash
#
# criar-gravacao: gera as versões clara e escura de gravações de terminal.
#
# Uso:
#   criar-gravacao                      # todos os .tape de DIR_ENTRADA
#   criar-gravacao scanf-loop.tape      # um arquivo
#   criar-gravacao a.tape b.tape        # vários arquivos
#   criar-gravacao gravacoes/           # todos os .tape de uma pasta
#
# Cada argumento é procurado como foi escrito e, se não existir, dentro de
# DIR_ENTRADA (com ou sem a extensão .tape).
#
# Os .tape de entrada devem conter APENAS o corpo da sessão (Type, Enter,
# Sleep...).
#
# Para `scanf-loop.tape`, a saída padrão é:
#   <DIR_SAIDA>/scanf-loop-claro.webm
#   <DIR_SAIDA>/scanf-loop-escuro.webm

set -euo pipefail

# --- Configuração (sobrescreva com variáveis de ambiente) -------------------

DIR_ENTRADA="${DIR_ENTRADA:-gravacoes}"        # onde ficam os .tape
DIR_SAIDA="${DIR_SAIDA:-docs/assets/videos}"   # onde as gravações são salvas

FORMATOS="${FORMATOS:-webm}"                   # separados por espaço: "webm mp4 gif"
SUFIXO_CLARO="${SUFIXO_CLARO:--claro}"
SUFIXO_ESCURO="${SUFIXO_ESCURO:--escuro}"

TEMA_CLARO="${TEMA_CLARO:-Catppuccin Latte}"
TEMA_ESCURO="${TEMA_ESCURO:-Catppuccin Mocha}"

SHELL_GRAVACAO="${SHELL_GRAVACAO:-bash}"
PROMPT="${PROMPT:-\$ }"
TAMANHO_FONTE="${TAMANHO_FONTE:-18}"
LARGURA="${LARGURA:-900}"
ALTURA="${ALTURA:-400}"

# Linhas extras do VHS, uma por linha. Ex.: $'Set Framerate 24\nSet Padding 20'
OPCOES_EXTRAS="${OPCOES_EXTRAS:-}"

# --- Funções ----------------------------------------------------------------

erro()
{
    echo "criar-gravacao: $*" >&2
    exit 1
}

uso()
{
    sed -n '2,/^$/p' "$0" | sed 's/^# \{0,1\}//'
}

# Imprime os caminhos absolutos dos .tape indicados por um argumento.
coletar_tapes()
{
    local alvo="$1"
    local candidato

    for candidato in "$alvo" "$DIR_ENTRADA/$alvo" "$DIR_ENTRADA/$alvo.tape"
    do
        if [[ -d "$candidato" ]]
        then
            find "$(realpath "$candidato")" -type f -name '*.tape' | sort
            return 0
        elif [[ -f "$candidato" ]]
        then
            realpath "$candidato"
            return 0
        fi
    done

    erro "não encontrei '$alvo' (nem em '$DIR_ENTRADA')"
}

# gerar_variante <tape> <nome> <sufixo> <tema>
gerar_variante()
{
    local tape="$1" nome="$2" sufixo="$3" tema="$4" saida="$5" trabalho="$6"

    local embrulho="$DIR_TEMP/${nome}${sufixo}.tape"
    local formato

    {
        for formato in $FORMATOS
        do
            echo "Output \"$saida/${nome}${sufixo}.${formato}\""
        done

        echo
        echo "Set Shell \"$SHELL_GRAVACAO\""
        echo "Set FontSize $TAMANHO_FONTE"
        echo "Set Width $LARGURA"
        echo "Set Height $ALTURA"
        echo "Set Theme \"$tema\""

        if [[ -n "$OPCOES_EXTRAS" ]]
        then
            printf '%s\n' "$OPCOES_EXTRAS"
        fi

        # Deixa o prompt igual ao padrão usado nas saídas do guia.
        echo
        echo "Hide"
        echo "Type \"export PS1='\\$ '\""
        echo "Enter"
        echo "Type \"clear\""
        echo "Enter"
        echo "Show"

        echo
        echo "Source \"$tape\""
    } > "$embrulho"

    echo "==> ${nome}${sufixo} ($tema)"
    (cd "$trabalho" && env -u PROMPT_COMMAND vhs "$embrulho")
}

# --- Programa principal -----------------------------------------------------

if [[ "${1:-}" == "-h" || "${1:-}" == "--help" ]]
then
    uso
    exit 0
fi

command -v vhs > /dev/null || erro "o 'vhs' não está instalado (veja o flake.nix)"

DIR_ENTRADA="$(realpath -m "$DIR_ENTRADA")"
mkdir -p "$DIR_SAIDA"
DIR_SAIDA="$(realpath "$DIR_SAIDA")"

DIR_TEMP="$(mktemp -d)"
trap 'rm -rf "$DIR_TEMP"' EXIT

alvos=("$@")
if [[ ${#alvos[@]} -eq 0 ]]
then
    alvos=("$DIR_ENTRADA")
fi

tapes=()
for alvo in "${alvos[@]}"; do
    mapfile -t encontrados < <(coletar_tapes "$alvo")
    tapes+=("${encontrados[@]}")
done

if [[ ${#tapes[@]} -eq 0 ]]; then
    erro "nenhum arquivo .tape encontrado"
fi

for tape in "${tapes[@]}"; do
nome="$(basename "$tape" .tape)"
    relativo="$(dirname "$(realpath --relative-to="$DIR_ENTRADA" "$tape")")"
    saida="$DIR_SAIDA/$relativo"
    trabalho="$(dirname "$tape")"

    mkdir -p "$saida"

    gerar_variante "$tape" "$nome" "$SUFIXO_CLARO" "$TEMA_CLARO" "$saida" "$trabalho"
    gerar_variante "$tape" "$nome" "$SUFIXO_ESCURO" "$TEMA_ESCURO" "$saida" "$trabalho"
done

echo
echo "Pronto! ${#tapes[@]} gravação(ões) em $DIR_SAIDA"
