#pragma once

typedef struct arvoreMatricula{
    int codDisciplina;

    int altura;
    struct arvoreMatricula *esq,*dir;
}ArvoreMatricula;