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

int fbCurso(ArvoreCurso *raiz){
    return alturaArvoreCurso(raiz->esq) - alturaArvoreCurso(raiz->dir);
}

void balanceamentoArvoreCurso(ArvoreCurso **raiz){
    ArvoreCurso *aux;
    int fb = fbCurso(*raiz);

    if(fb >= 2){
        aux = (*raiz)->esq;

        fb = fbCurso(aux);
        if(fb < 0){
            rotacaoEsquerdaCurso(&(*raiz)->esq);
        }

        rotacaoDireitaCurso(raiz);
    }else if(fb <= -2){
        aux = (*raiz)->dir;

        fb = fbCurso(aux);
        if(fb > 0){
            rotacaoDireitaCurso(&(*raiz)->dir);
        }

        rotacaoEsquerdaCurso(raiz);
    }
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
                
                (*raiz)->disciplina = endFilho->disciplina;

                removerCurso(&(*raiz)->dir,endFilho->curso.codCurso);
            }
        }else if(codCurso < (*raiz)->curso.codCurso)
            existe = removerCurso(&(*raiz)->esq, codCurso);
        else
            existe = removerCurso(&(*raiz)->dir, codCurso);
        
        if(*raiz){
            (*raiz)->altura = alturaArvoreCurso(*raiz);
            balanceamentoArvoreCurso(raiz);
        }
    }


    return existe;
}
