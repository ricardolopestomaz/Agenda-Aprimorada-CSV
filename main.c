
#include <stdio.h>
#include "agenda.h"

int main() {
    Contato *lista = NULL;
    int opcao = 0, mudou = 0;

    lista = lerContatos(&mudou);

    while (opcao != 5) {
        printf("_____ Agenda _____\n");
        printf("1 - Cadastro de novo contato\n");
        printf("2 - Imprimir agenda\n");
        printf("3 - Deletar um contato\n");
        printf("4 - Salvar\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
        case 1:
            lista = cadastrar(lista, &mudou);
            break;
        case 2:
            imprimir(lista);
            break;
        case 3:
            lista = deletar(lista, &mudou);
            break;
        case 4:
            salvarContatos(lista);
            mudou = 0;
            break;
        case 5:
            if (mudou) salvarContatos(lista);
            liberarLista(lista);
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}
