#include <stdio.h>
#include <stdlib.h>

#include "./nota.h"


int inserirNota(ArvoreNota **raiz, Info info){
    int insere = 1;
    
    if(!(*raiz)){
        ArvoreNota *novaNota = (ArvoreNota*)malloc(sizeof(ArvoreNota));
        
        novaNota->info = info;
        novaNota->esq = NULL;
        novaNota->dir = NULL;

        *raiz = novaNota;
    }else{
        if(info.codDisciplina < (*raiz)->info.codDisciplina){
            insere = inserirNota(&(*raiz)->esq,info);
        }else if(info.codDisciplina > (*raiz)->info.codDisciplina){
            insere = inserirNota(&(*raiz)->dir,info);
        }else{
            insere = 0;
        }
        
        (*raiz)->altura = alturaArvoreNota(*raiz);
        balanceamentoArvoreNota(raiz);
    }


    return insere;
}

int alturaArvoreNota(ArvoreNota *raiz){
    int altura = -1;

    if(raiz){
        int altura_esq = alturaArvoreNota(raiz->esq);
        int altura_dir = alturaArvoreNota(raiz->dir);
        altura = ((altura_esq > altura_dir) ? altura_esq : altura_dir) + 1;
    }

    return altura;
}

void rotacaoDireitaNota(ArvoreNota **raiz){
    ArvoreNota *aux;

    aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = (*raiz);

    (*raiz)->altura = alturaArvoreNota(*raiz);
    aux->altura = alturaArvoreNota(aux);

    *raiz =  aux;
}

void rotacaoEsquerdaNota(ArvoreNota **raiz){
    ArvoreNota *aux;

    aux = (*raiz)->dir;
    (*raiz)->dir = aux->esq;
    aux->esq = (*raiz);

    (*raiz)->altura = alturaArvoreNota(*raiz);
    aux->altura = alturaArvoreNota(aux);

    *raiz =  aux;
}

int fbNota(ArvoreNota *raiz){
    return alturaArvoreNota(raiz->esq) - alturaArvoreNota(raiz->dir);
}

void balanceamentoArvoreNota(ArvoreNota **raiz){
    ArvoreNota *aux;
    int fb = fbNota(*raiz);

    if(fb >= 2){
        aux = (*raiz)->esq;

        fb = fbNota(aux);
        if(fb < 0){
            rotacaoEsquerdaNota(&(*raiz)->esq);
        }

        rotacaoDireitaNota(raiz);
    }else if(fb <= -2){
        aux = (*raiz)->dir;

        fb = fbNota(aux);
        if(fb > 0){
            rotacaoDireitaNota(&(*raiz)->dir);
        }

        rotacaoEsquerdaNota(raiz);
    }
}
