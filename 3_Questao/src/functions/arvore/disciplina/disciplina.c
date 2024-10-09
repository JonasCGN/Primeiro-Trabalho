#include <stdio.h>
#include <stdlib.h>

#include "./disciplina.h"

int inserirDisciplina(ArvoreDisciplina **raiz, Disciplina disciplina){
    int insere = 1;
    
    if(!(*raiz)){
        ArvoreDisciplina *novaDisciplina = (ArvoreDisciplina*)malloc(sizeof(ArvoreDisciplina));
        
        novaDisciplina->disciplina = disciplina;
        novaDisciplina->esq = NULL;
        novaDisciplina->dir = NULL;

        *raiz = novaDisciplina;
    }else{
        if(disciplina.codDisciplina < (*raiz)->disciplina.codDisciplina){
            insere = inserirDisciplina(&(*raiz)->esq,disciplina);
        }else if(disciplina.codDisciplina > (*raiz)->disciplina.codDisciplina){
            insere = inserirDisciplina(&(*raiz)->dir,disciplina);
        }else{
            insere = 0;
        }
    }

    if(insere){
        (*raiz)->altura = alturaArvoreDisciplina(*raiz);
        balanceamentoArvoreDisciplina(raiz);
    }

    return insere;
}

int alturaArvoreDisciplina(ArvoreDisciplina *raiz){
    int altura = -1;

    if(raiz){
        int altura_esq = alturaArvoreDisciplina(raiz->esq);
        int altura_dir = alturaArvoreDisciplina(raiz->dir);
        altura = ((altura_esq > altura_dir) ? altura_esq : altura_dir) + 1;
    }

    return altura;
}

void rotacaoDireitaDisciplina(ArvoreDisciplina **raiz){
    ArvoreDisciplina *aux;

    aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = (*raiz);

    (*raiz)->altura = alturaArvoreDisciplina(*raiz);
    aux->altura = alturaArvoreDisciplina(aux);

    *raiz =  aux;
}

void rotacaoEsquerdaDisciplina(ArvoreDisciplina **raiz){
    ArvoreDisciplina *aux;

    aux = (*raiz)->dir;
    (*raiz)->dir = aux->esq;
    aux->esq = (*raiz);

    (*raiz)->altura = alturaArvoreDisciplina(*raiz);
    aux->altura = alturaArvoreDisciplina(aux);

    *raiz =  aux;
}

int fbDisciplina(ArvoreDisciplina *raiz){
    return alturaArvoreDisciplina(raiz->esq) - alturaArvoreDisciplina(raiz->dir);
}

void balanceamentoArvoreDisciplina(ArvoreDisciplina **raiz){
    ArvoreDisciplina *aux;
    int fb = fbDisciplina(*raiz);

    if(fb >= 2){
        aux = (*raiz)->esq;

        fb = fbDisciplina(aux);
        if(fb < 0){
            rotacaoEsquerdaDisciplina(&(*raiz)->esq);
        }

        rotacaoDireitaDisciplina(raiz);
    }else if(fb <= -2){
        aux = (*raiz)->dir;

        fb = fbDisciplina(aux);
        if(fb > 0){
            rotacaoDireitaDisciplina(&(*raiz)->dir);
        }

        rotacaoEsquerdaDisciplina(raiz);
    }
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

    if(existe){
        (*raiz)->altura = alturaArvoreDisciplina(*raiz);
        balanceamentoArvoreDisciplina(raiz);
    }

    return existe;
}
