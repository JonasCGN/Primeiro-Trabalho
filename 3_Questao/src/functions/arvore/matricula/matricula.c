#include <stdio.h>
#include <stdlib.h>

#include "./matricula.h"

/*Tudo foi flávio*/
int inserirMatricula(ArvoreMatricula **raiz, int codDisciplina){
    int insere = 1;
    
    if(!(*raiz)){
        ArvoreMatricula *novaMatricula = (ArvoreMatricula*)malloc(sizeof(ArvoreMatricula));
        
        novaMatricula->codDisciplina = codDisciplina;
        novaMatricula->esq = NULL;
        novaMatricula->dir = NULL;

        *raiz = novaMatricula;
    }else{
        if(codDisciplina < (*raiz)->codDisciplina){
            insere = inserirMatricula(&(*raiz)->esq,codDisciplina);
        }else if(codDisciplina > (*raiz)->codDisciplina){
            insere = inserirMatricula(&(*raiz)->dir,codDisciplina);
        }else{
            insere = 0;
        }
    }

    if(insere){
        (*raiz)->altura = alturaArvoreMatricula(*raiz);
        balanceamentoArvoreMatricula(raiz);
    }

    return insere;
}

int alturaArvoreMatricula(ArvoreMatricula *raiz){
    int altura = -1;

    if(raiz){
        int altura_esq = alturaArvoreMatricula(raiz->esq);
        int altura_dir = alturaArvoreMatricula(raiz->dir);
        altura = ((altura_esq > altura_dir) ? altura_esq : altura_dir) + 1;
    }

    return altura;
}

void rotacaoDireitaMatricula(ArvoreMatricula **raiz){
    ArvoreMatricula *aux;

    aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = (*raiz);

    (*raiz)->altura = alturaArvoreMatricula(*raiz);
    aux->altura = alturaArvoreMatricula(aux);

    *raiz =  aux;
}

void rotacaoEsquerdaMatricula(ArvoreMatricula **raiz){
    ArvoreMatricula *aux;

    aux = (*raiz)->dir;
    (*raiz)->dir = aux->esq;
    aux->esq = (*raiz);

    (*raiz)->altura = alturaArvoreMatricula(*raiz);
    aux->altura = alturaArvoreMatricula(aux);

    *raiz =  aux;
}

void balanceamentoArvoreMatricula(ArvoreMatricula **raiz){
    ArvoreMatricula *aux;
    int fb = alturaArvoreMatricula((*raiz)->esq) - alturaArvoreMatricula((*raiz)->dir);

    if(fb >= 2){
        aux = (*raiz)->esq;

        fb = alturaArvoreMatricula(aux->esq) - alturaArvoreMatricula(aux->dir);
        if(fb < 0){
            rotacaoEsquerdaMatricula(&(*raiz)->esq);
        }

        rotacaoDireitaMatricula(raiz);
    }else if(fb <= -2){
        aux = (*raiz)->dir;

        fb = alturaArvoreMatricula(aux->esq) - alturaArvoreMatricula(aux->dir);
        if(fb > 0){
            rotacaoDireitaMatricula(&(*raiz)->dir);
        }

        rotacaoEsquerdaMatricula(raiz);
    }
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

    if(existe){
        (*raiz)->altura = alturaArvoreMatricula(*raiz);
        balanceamentoArvoreMatricula(raiz);
    }

    return existe;
}
