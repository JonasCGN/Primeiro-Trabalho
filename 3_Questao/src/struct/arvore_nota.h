#pragma once

typedef struct info{
    int codDisciplina;
    int semestreCursado;
    float nota;
}Info;


typedef struct arvoreNota{
    Info info;

    int altura;
    struct arvoreNota* esq; 
    struct arvoreNota* dir; 
}ArvoreNota;