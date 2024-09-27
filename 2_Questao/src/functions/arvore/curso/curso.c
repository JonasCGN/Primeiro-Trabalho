#include <stdio.h>
#include <stdlib.h>

#include "./curso.h"

int inserirCurso(ArvoreCurso **arvoreCurso, Curso curso){
    int insere = 1;
    
    if(!(*arvoreCurso)){
        ArvoreCurso *novoCurso = (ArvoreCurso*)malloc(sizeof(ArvoreCurso));
        
        novoCurso->curso = curso;
        novoCurso->esq = NULL;
        novoCurso->dir = NULL;

        *arvoreCurso = novoCurso;
    }else{
        if(curso.codCurso < (*arvoreCurso)->curso.codCurso){
            insere = inserirCurso(&(*arvoreCurso)->esq,curso);
        }else if(curso.codCurso > (*arvoreCurso)->curso.codCurso){
            insere = inserirCurso(&(*arvoreCurso)->dir,curso);
        }else{
            insere = 0;
        }
    }

    return insere;
}

