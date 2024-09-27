#include <stdio.h>
#include <stdlib.h>

#include "./nota.h"

//Flavio
int inserirNota(ArvoreNota** raiz, Info info) {
    int insere = 1;

    if (!(*raiz)) {
        ArvoreNota* novaNota = (ArvoreNota*) malloc(sizeof(ArvoreNota));
        
        novaNota->info = info;
        novaNota->esq = novaNota->dir = NULL;

        *raiz = novaNota;
    }else{
        if (info.codDisciplina < (*raiz)->info.codDisciplina)
            inserirNota(&(*raiz)->esq, info);
        else if (info.codDisciplina > (*raiz)->info.codDisciplina)
            inserirNota(&(*raiz)->dir, info);
        else
            insere = 0;

    }

    return insere;
}