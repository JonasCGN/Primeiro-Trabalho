#include <stdio.h>
#include <stdlib.h>

#include "./curso.h"

int inserirCurso(ArvoreCurso **arvoreCurso, Curso curso){
    int insere = 1;
    
    if(!(*arvoreCurso)){
        ArvoreCurso *novoCurso = (ArvoreCurso*)malloc(sizeof(ArvoreCurso));
        
        novoCurso->curso = curso;
        novoCurso->esq = NULL;
        novoCurso->dir = NULL;

        *arvoreCurso = novoCurso;
    }else{
        if(curso.codCurso < (*arvoreCurso)->curso.codCurso){
            insere = inserirCurso(&(*arvoreCurso)->esq,curso);
        }else if(curso.codCurso > (*arvoreCurso)->curso.codCurso){
            insere = inserirCurso(&(*arvoreCurso)->dir,curso);
        }else{
            insere = 0;
        }
    }

    return insere;
}

static int ehFolha(ArvoreCurso *raiz){
    return (raiz->esq == NULL && raiz->dir == NULL);
}

static ArvoreCurso *soUmFilho(ArvoreCurso *raiz){
    ArvoreCurso *aux;
    aux = NULL;

    if(raiz->dir == NULL){
        aux = raiz->esq;
    }else if(raiz->esq == NULL){
        aux = raiz->dir;
    }

    return aux;
}

static ArvoreCurso *menorFilho(ArvoreCurso *raiz){
    ArvoreCurso *aux;
    aux = raiz;

    if(raiz){
        if(raiz->esq)
            aux = menorFilho(raiz->esq);
    }

    return aux;
}

int removerCurso(ArvoreCurso **raiz, int codCurso){
    ArvoreCurso *endFilho;
    int existe = 0;

    if((*raiz)){

        if(codCurso == (*raiz)->curso.codCurso){
            existe = 1;

            ArvoreCurso *aux = *raiz;
            if(ehFolha(*raiz)){
                free(aux);
                *raiz = NULL;
            }else if((endFilho = soUmFilho(*raiz)) != NULL){
                free(aux);
                *raiz = endFilho;
            }else {
                endFilho = menorFilho((*raiz)->dir);
                
                (*raiz)->curso = endFilho->curso;

                removerCurso(&(*raiz)->dir,endFilho->curso.codCurso);
            }
        }else if(codCurso < (*raiz)->curso.codCurso)
            existe = removerCurso(&(*raiz)->esq, codCurso);
        else
            existe = removerCurso(&(*raiz)->dir, codCurso);
    }

    return existe;
}