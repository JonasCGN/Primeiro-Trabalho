#pragma once

typedef struct arvoreDisciplina{
    int codDisciplina;
    char nomeDisciplina[50];
    int periodo;
    int cargaHoraria;

    struct arvoreDisciplina* esq; 
    struct arvoreDisciplina* dir; 
}ArvoreDisciplina;