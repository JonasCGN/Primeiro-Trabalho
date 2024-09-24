#include <stdio.h>
#include <stdlib.h>

#include "./disciplina.h"

int inserirDisciplina(ArvoreDisciplina **arvoreDisciplina, Disciplina disciplina){
    int insere = 1;
    if(arvoreDisciplina == NULL){
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

int removerDisciplina(ArvoreDisciplina **raiz, int codDisciplina){
    int existe = 0;

    if((*raiz)){

        if(codDisciplina == (*raiz)->disciplina.codDisciplina){
            existe = 1;

            ArvoreDisciplina *aux = *raiz;
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
                ArvoreDisciplina* menor;
                ArvoreDisciplina* no;
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

                (*raiz)->disciplina = menor->disciplina;
                free(menor);
            }
        }else if(codDisciplina < (*raiz)->disciplina.codDisciplina)
            existe = removerDisciplinaMatricula(&(*raiz)->esq, codDisciplina);
        else
            existe = removerDisciplinaMatricula(&(*raiz)->dir, codDisciplina);
    }

    return existe;
}