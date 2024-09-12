#pragma once

typedef struct arvoreNota{
    int codDisciplina;
    int semestreCursado;
    float nota;

    struct arvoreNota* esq; 
    struct arvoreNota* dir; 
}ArvoreNota;