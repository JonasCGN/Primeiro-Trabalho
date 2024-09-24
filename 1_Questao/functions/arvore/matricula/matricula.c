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

/*
- Folha
- Filho
- 2 Filho
*/

int removerDisciplinaMatricula(ArvoreMatricula **raiz, int codDisciplina){
    int existe = 0;

    if((*raiz)){

        if(codDisciplina == (*raiz)->codDisciplina){
            existe = 1;

            ArvoreMatricula *aux = *raiz;
            if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
                free(aux);
                *raiz = NULL;
            }else if((*raiz)->dir == NULL){
                (*raiz) = (*raiz)->esq;
                aux->esq = NULL;
                free(aux);
                aux = NULL;
            }else if((*raiz)->esq == NULL){
                (*raiz) = (*raiz)->dir;
                aux->dir = NULL;
                free(aux);
                aux = NULL;
            }else {
                ArvoreMatricula* menor;
                ArvoreMatricula* no;
                menor = (*raiz)->dir;
                no = NULL;
                
                while(menor->esq != NULL){
                    no = menor;
                    menor = menor->esq;
                }
                
                if(no){
                    no->esq = menor->dir;
                }else{
                    (*raiz)->dir = menor->dir;
                }

                (*raiz)->codDisciplina = menor->codDisciplina;
                free(menor);
            }
        }else if(codDisciplina < (*raiz)->codDisciplina)
            existe = removerDisciplinaMatricula(&(*raiz)->esq, codDisciplina);
        else
            existe = removerDisciplinaMatricula(&(*raiz)->dir, codDisciplina);
    }

    return existe;
}