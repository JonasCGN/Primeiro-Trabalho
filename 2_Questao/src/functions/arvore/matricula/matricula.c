#include <stdio.h>
#include <stdlib.h>

#include "./matricula.h"

int inserirMatricula(ArvoreMatricula** raiz, int codDisciplina) {
    int insere = 1;

    if (!(*raiz)) {
        ArvoreMatricula* novaMatricula = (ArvoreMatricula*)malloc(sizeof(ArvoreMatricula));

        novaMatricula->codDisciplina = codDisciplina;
        novaMatricula->esq = novaMatricula->dir = NULL;

        *raiz = novaMatricula;
    }else{
        if (codDisciplina < (*raiz)->codDisciplina)
            insere = inserirMatricula(&((*raiz)->esq), codDisciplina);
        else if (codDisciplina > (*raiz)->codDisciplina)
            inserirMatricula(&((*raiz)->dir), codDisciplina);
        else
            insere = 0;
    }

    return insere;
}

static int ehFolha(ArvoreMatricula *raiz){
    return (raiz->esq == NULL && raiz->dir == NULL);
}

static ArvoreMatricula *soUmFilho(ArvoreMatricula *raiz){
    ArvoreMatricula *aux;
    aux = NULL;

    if(raiz->dir == NULL){
        aux = raiz->esq;
    }else if(raiz->esq == NULL){
        aux = raiz->dir;
    }

    return aux;
}

static ArvoreMatricula *menorFilho(ArvoreMatricula *raiz){
    ArvoreMatricula *aux;
    aux = raiz;

    if(raiz){
        if(raiz->esq)
            aux = menorFilho(raiz->esq);
    }

    return aux;
}

int removerDisciplinaMatricula(ArvoreMatricula **raiz, int codDisciplina){
    ArvoreMatricula *endFilho;
    int existe = 0;

    if((*raiz)){

        if(codDisciplina == (*raiz)->codDisciplina){
            existe = 1;

            ArvoreMatricula *aux = *raiz;
            if(ehFolha(*raiz)){
                free(aux);
                *raiz = NULL;
            }else if((endFilho = soUmFilho(*raiz)) != NULL){
                free(aux);
                *raiz = endFilho;
            }else {
                endFilho = menorFilho((*raiz)->dir);

                (*raiz)->codDisciplina = endFilho->codDisciplina;

                removerDisciplinaMatricula(&(*raiz)->dir,endFilho->codDisciplina);
            }
        }else if(codDisciplina < (*raiz)->codDisciplina)
            existe = removerDisciplinaMatricula(&(*raiz)->esq, codDisciplina);
        else
            existe = removerDisciplinaMatricula(&(*raiz)->dir, codDisciplina);
    }

    return existe;
}