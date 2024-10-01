#pragma once

typedef struct disciplina{
    int codDisciplina;
    char nomeDisciplina[50];
    int periodo;
    int cargaHoraria;
}Disciplina;

typedef struct arvoreDisciplina{
    Disciplina disciplina;

    int altura;
    struct arvoreDisciplina* esq; 
    struct arvoreDisciplina* dir; 
}ArvoreDisciplina;