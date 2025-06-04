# 🗂️ Agenda Aprimorada em C

Este projeto implementa uma agenda de contatos simples utilizando **listas encadeadas** em linguagem C. A agenda permite cadastrar, listar, excluir, salvar e carregar contatos de um arquivo `.csv`.

## 📚 Funcionalidades

- 📥 **Cadastrar contato**  
  Adiciona um novo contato com nome e telefone no início da lista.

- 📄 **Listar contatos**  
  Imprime todos os contatos cadastrados.

- ❌ **Deletar contato**  
  Remove um contato da lista pelo nome.

- 💾 **Salvar contatos**  
  Exporta todos os contatos para o arquivo `agenda.csv`.

- 📂 **Carregar contatos**  
  Lê os contatos do arquivo `agenda.csv` ao iniciar o programa.

- 🧹 **Liberar memória**  
  Libera a memória alocada ao final da execução.


## 🧠 Estrutura de Dados

```c
typedef struct contato {
    char nome[128];
    char telefone[15];
    struct contato *prox;
} Contato;
```


