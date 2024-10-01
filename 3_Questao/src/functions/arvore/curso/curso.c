#include <stdio.h>
#include <stdlib.h>

#include "./curso.h"

int inserirCurso(ArvoreCurso **raiz, Curso curso){
    int insere = 1;
    
    if(!(*raiz)){
        ArvoreCurso *novoCurso = (ArvoreCurso*)malloc(sizeof(ArvoreCurso));
        
        novoCurso->curso = curso;
        novoCurso->esq = NULL;
        novoCurso->dir = NULL;

        *raiz = novoCurso;
    }else{
        if(curso.codCurso < (*raiz)->curso.codCurso){
            insere = inserirCurso(&(*raiz)->esq,curso);
        }else if(curso.codCurso > (*raiz)->curso.codCurso){
            insere = inserirCurso(&(*raiz)->dir,curso);
        }else{
            insere = 0;
        }
    }

    if(insere){
        (*raiz)->altura = alturaArvoreCurso(*raiz);
        balanceamentoArvoreCurso(raiz);
    }

    return insere;
}

int alturaArvoreCurso(ArvoreCurso *raiz){
    int altura = -1;

    if(raiz){
        int altura_esq = alturaArvoreCurso(raiz->esq);
        int altura_dir = alturaArvoreCurso(raiz->dir);
        altura = ((altura_esq > altura_dir) ? altura_esq : altura_dir) + 1;
    }

    return altura;
}

void rotacaoDireitaCurso(ArvoreCurso **raiz){
    ArvoreCurso *aux;

    aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = (*raiz);

    (*raiz)->altura = alturaArvoreCurso(*raiz);
    aux->altura = alturaArvoreCurso(aux);

    *raiz =  aux;
}

void rotacaoEsquerdaCurso(ArvoreCurso **raiz){
    ArvoreCurso *aux;

    aux = (*raiz)->dir;
    (*raiz)->dir = aux->esq;
    aux->esq = (*raiz);

    (*raiz)->altura = alturaArvoreCurso(*raiz);
    aux->altura = alturaArvoreCurso(aux);

    *raiz =  aux;
}

void balanceamentoArvoreCurso(ArvoreCurso **raiz){
    ArvoreCurso *aux;
    int fb = alturaArvoreCurso((*raiz)->esq) - alturaArvoreCurso((*raiz)->dir);

    if(fb >= 2){
        aux = (*raiz)->esq;

        fb = alturaArvoreCurso((*raiz)->esq) - alturaArvoreCurso((*raiz)->dir);
        if(fb < 0){
            rotacaoEsquerdaCurso(&(*raiz)->esq);
        }

        rotacaoDireitaCurso(raiz);
    }else if(fb <= -2){
        aux = (*raiz)->dir;

        fb = alturaArvoreCurso(aux->esq) - alturaArvoreCurso(aux->dir);
        if(fb > 0){
            rotacaoDireitaCurso(&(*raiz)->dir);
        }

        rotacaoEsquerdaCurso(raiz);
    }
}
