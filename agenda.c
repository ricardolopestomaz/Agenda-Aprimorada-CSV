#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

struct contato {
    char nome[128];
    char telefone[15];
    struct contato *prox;
};

Contato* criarLista() {
    return NULL;
}

Contato* cadastrar(Contato *inicio, int *mudou) {
    Contato *novo = (Contato *) malloc(sizeof(Contato));
    if (!novo) return inicio;

    printf("_____ Cadastro _____\n");
    printf("Nome do contato: ");
    fgets(novo->nome, sizeof(novo->nome), stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0';

    printf("Telefone do contato: ");
    fgets(novo->telefone, sizeof(novo->telefone), stdin);
    novo->telefone[strcspn(novo->telefone, "\n")] = '\0';

    novo->prox = inicio;
    *mudou = 1;

    printf("Contato cadastrado!\n");
    return novo;
}

void imprimir(Contato *inicio) {
    printf("_____ Imprimir _____\n");
    if (!inicio) {
        printf("Agenda vazia!\n");
        return;
    }

    int i = 1;
    for (Contato *atual = inicio; atual; atual = atual->prox) {
        printf("Contato %d:\nNome: %s\nTelefone: %s\n", i++, atual->nome, atual->telefone);
    }
}

Contato* deletar(Contato *inicio, int *mudou) {
    char nome[128];
    printf("_____ Deletar _____\n");
    printf("Informe o nome do contato a ser deletado: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    Contato *anterior = NULL, *atual = inicio;

    while (atual && strcmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (!atual) {
        printf("Contato nao encontrado.\n");
        return inicio;
    }

    if (!anterior) {
        inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    *mudou = 1;
    printf("Contato %s deletado com sucesso.\n", nome);
    return inicio;
}

void salvarContatos(Contato *inicio) {
    FILE *f = fopen("agenda.csv", "w");
    if (!f) {
        printf("Erro ao salvar arquivo.\n");
        return;
    }

    for (Contato *atual = inicio; atual; atual = atual->prox) {
        fprintf(f, "%s,%s\n", atual->nome, atual->telefone);
    }

    fclose(f);
    printf("Contatos salvos!\n");
}

Contato* lerContatos(int *mudou) {
    FILE *f = fopen("agenda.csv", "r");
    if (!f) {
        printf("Arquivo nao encontrado. Criando novo...\n");
        return NULL;
    }

    Contato *inicio = NULL;
    char nome[128], telefone[15];

    while (fscanf(f, " %127[^,],%14[^\n]\n", nome, telefone) == 2) {
        Contato *novo = (Contato *) malloc(sizeof(Contato));
        strcpy(novo->nome, nome);
        strcpy(novo->telefone, telefone);
        novo->prox = inicio;
        inicio = novo;
    }

    fclose(f);
    *mudou = 0;
    return inicio;
}

void liberarLista(Contato *inicio) {
    while (inicio) {
        Contato *tmp = inicio;
        inicio = inicio->prox;
        free(tmp);
    }
}
