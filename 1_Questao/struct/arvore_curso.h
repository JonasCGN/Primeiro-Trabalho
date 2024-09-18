#pragma once

#include "./arvore_disciplina.h"

typedef struct curso{
    int codCurso;
    char nomeCurso[50];
    int quantPeriodo;
}Curso;

typedef struct arvoreCurso{
    Curso curso;
    ArvoreDisciplina* disciplina;

    struct arvoreCurso* esq;
    struct arvoreCurso* dir;
}ArvoreCurso;