#include <stdio.h>
#include <stdlib.h>

#include "./curso.h"

void inserirCurso(ArvoreCurso **arvoreCurso, Curso curso){
    if(*arvoreCurso == NULL){
        ArvoreCurso *novoCurso = (ArvoreCurso*)malloc(sizeof(ArvoreCurso));
        
        novoCurso->curso = curso;
        novoCurso->esq = NULL;
        novoCurso->dir = NULL;

        *arvoreCurso = novoCurso;
    }else{
        if(curso.codCurso < (*arvoreCurso)->curso.codCurso){
            inserirCurso(&(*arvoreCurso)->esq,curso);
        }else{
            inserirCurso(&(*arvoreCurso)->dir,curso);
        }
    }
}

