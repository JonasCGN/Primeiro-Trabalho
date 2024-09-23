#include <stdio.h>
#include <stdlib.h>

#include "./nota.h"

//Flavio
void inserirNota(ArvoreNota** raiz, int codDisciplina, float nota) {
    int insere = 1;

    if (raiz == NULL) {
        ArvoreNota* novaNota = (ArvoreNota*) malloc(sizeof(ArvoreNota));
        
        novaNota->info.codDisciplina = codDisciplina;
        novaNota->info.nota = nota;
        novaNota->esq = novaNota->dir = NULL;

        *raiz = novaNota;
    }else{
        if (codDisciplina < (*raiz)->info.codDisciplina)
            inserirNota(&(*raiz)->esq, codDisciplina, nota);
        else if (codDisciplina > (*raiz)->info.codDisciplina)
            inserirNota(&(*raiz)->dir, codDisciplina, nota);
        else
            insere = 0;

    }

    return 0;

}