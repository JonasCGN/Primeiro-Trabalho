#include <stdio.h>
#include <stdlib.h>

#include "./disciplina.h"

int inserirDisciplina(ArvoreDisciplina **arvoreDisciplina, Disciplina disciplina){
    int insere = 1;
    
    if(!(*arvoreDisciplina)){
        ArvoreDisciplina *novaDisciplina = (ArvoreDisciplina*)malloc(sizeof(ArvoreDisciplina));
        
        novaDisciplina->disciplina = disciplina;
        novaDisciplina->esq = NULL;
        novaDisciplina->dir = NULL;

        *arvoreDisciplina = novaDisciplina;
    }else{
        if(disciplina.codDisciplina < (*arvoreDisciplina)->disciplina.codDisciplina){
            insere = inserirDisciplina(&(*arvoreDisciplina)->esq,disciplina);
        }else if(disciplina.codDisciplina > (*arvoreDisciplina)->disciplina.codDisciplina){
            insere = inserirDisciplina(&(*arvoreDisciplina)->dir,disciplina);
        }else{
            insere = 0;
        }
    }

    return insere;
}

static int ehFolha(ArvoreDisciplina *raiz){
    return (raiz->esq == NULL && raiz->dir == NULL);
}

static ArvoreDisciplina *soUmFilho(ArvoreDisciplina *raiz){
    ArvoreDisciplina *aux;
    aux = NULL;

    if(raiz->dir == NULL){
        aux = raiz->esq;
    }else if(raiz->esq == NULL){
        aux = raiz->dir;
    }

    return aux;
}

static ArvoreDisciplina *menorFilho(ArvoreDisciplina *raiz){
    ArvoreDisciplina *aux;
    aux = raiz;

    if(raiz){
        if(raiz->esq)
            aux = menorFilho(raiz->esq);
    }

    return aux;
}

int removerDisciplina(ArvoreDisciplina **raiz, int codDisciplina){
    ArvoreDisciplina *endFilho;
    int existe = 0;

    if((*raiz)){

        if(codDisciplina == (*raiz)->disciplina.codDisciplina){
            existe = 1;

            ArvoreDisciplina *aux = *raiz;
            if(ehFolha(*raiz)){
                free(aux);
                *raiz = NULL;
            }else if((endFilho = soUmFilho(*raiz)) != NULL){
                free(aux);
                *raiz = endFilho;
            }else {
                endFilho = menorFilho((*raiz)->dir);
                
                (*raiz)->disciplina = endFilho->disciplina;

                removerDisciplina(&(*raiz)->dir,endFilho->disciplina.codDisciplina);
            }
        }else if(codDisciplina < (*raiz)->disciplina.codDisciplina)
            existe = removerDisciplina(&(*raiz)->esq, codDisciplina);
        else
            existe = removerDisciplina(&(*raiz)->dir, codDisciplina);
    }

    return existe;
}