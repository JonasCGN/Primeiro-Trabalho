#include <stdio.h>
#include <stdlib.h>

#include "./matricula.h"

/*Tudo foi flávio*/
int inserirMatricula(ArvoreMatricula** raiz, int codDisciplina) {
    int insere = 1;

    if (raiz == NULL) {
        ArvoreMatricula* novaMatricula = (ArvoreMatricula*) malloc(sizeof(ArvoreMatricula));
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

int ehFolha(ArvoreMatricula *raiz){
    return (raiz->esq != NULL && raiz->dir != NULL);
}

ArvoreMatricula *soUmFilho(ArvoreMatricula *raiz){
    ArvoreMatricula *aux;

    if(raiz->dir == NULL){
        aux = raiz->esq;
    }else if(raiz->esq == NULL){
        aux = raiz->dir;
    }

    return aux;
}

ArvoreMatricula *menorFilho(ArvoreMatricula *raiz){
    ArvoreMatricula *aux;
    aux = NULL;

    if(raiz){
        aux = menorFilho(raiz->esq);
        if(!aux)
            aux = raiz;
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
                *raiz = NULL;
                free(aux);
            }else if((endFilho = soUmFilho(*raiz)) != NULL){
                aux = *raiz;
                *raiz = endFilho;
                free(aux);
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