#pragma once

typedef struct arvoreMatricula{
    int codDisciplina;

    struct arvoreMatricula *esq;
    struct arvoreMatricula *dir;
}ArvoreMatricula;

