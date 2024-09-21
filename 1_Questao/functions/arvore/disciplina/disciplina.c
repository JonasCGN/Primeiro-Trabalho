#include <stdio.h>
#include <stdlib.h>

#include "./disciplina.h"

void inserirDisciplina(ArvoreDisciplina **arvoreDisciplina, Disciplina disciplina){
    if(arvoreDisciplina == NULL){
        ArvoreDisciplina *novaDisciplina = (ArvoreDisciplina*)malloc(sizeof(ArvoreDisciplina));
        
        novaDisciplina->disciplina = disciplina;
        novaDisciplina->esq = NULL;
        novaDisciplina->dir = NULL;

        *arvoreDisciplina = novaDisciplina;
    }else{
        if(disciplina.codDisciplina < (*arvoreDisciplina)->disciplina.codDisciplina){
            inserirDisciplina(&(*arvoreDisciplina)->esq,disciplina);
        }else{
            inserirDisciplina(&(*arvoreDisciplina)->dir,disciplina);
        }
    }
}