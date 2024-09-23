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