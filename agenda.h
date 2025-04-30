#ifndef AGENDA_H
#define AGENDA_H

typedef struct contato Contato;

Contato* cadastrar(Contato *inicio, int *mudou);

void imprimir(Contato *inicio);

Contato* deletar(Contato *inicio, int *mudou);

void salvarContatos(Contato *inicio);

Contato* lerContatos(int *mudou);

void liberarLista(Contato *inicio);

#endif
