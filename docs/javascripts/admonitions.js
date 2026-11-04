// Nome em português -> tipo nativo do tema (de onde vêm cor e ícone).
const APELIDOS = {
  nota: "note",
  resumo: "abstract",
  info: "info",
  dica: "tip",
  sucesso: "success",
  pergunta: "question",
  atenção: "warning",
  falha: "failure",
  perigo: "danger",
  exemplo: "example",
  citação: "quote",
  // Sem equivalente nativo: escolha livre, troque como preferir.
  cuidado: "danger",
  importante: "info",
}

document$.subscribe(({ body }) => {
  for (const [pt, nativo] of Object.entries(APELIDOS)) {
    const seletor = `.admonition.${CSS.escape(pt)}, details.${CSS.escape(pt)}`
    for (const bloco of body.querySelectorAll(seletor)) {
      bloco.classList.add(nativo)
    }
  }
})
