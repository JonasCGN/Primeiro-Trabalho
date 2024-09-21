#pragma once

#include "./arvore_disciplina.h"

typedef struct arvoreCurso{
    int codCurso;
    char nomeCurso[50];
    int quantPeriodo;

    ArvoreDisciplina* disciplina;
}ArvoreCurso;
