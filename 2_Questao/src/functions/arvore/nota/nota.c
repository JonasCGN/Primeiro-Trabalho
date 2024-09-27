#include <stdio.h>
#include <stdlib.h>

#include "./nota.h"

//Flavio
int inserirNota(ArvoreNota **arvoreNota, Info info){
    int insere = 1;
    
    if(!(*arvoreNota)){
        ArvoreNota *novaNota = (ArvoreNota*)malloc(sizeof(ArvoreNota));
        
        novaNota->info = info;
        novaNota->esq = NULL;
        novaNota->dir = NULL;

        *arvoreNota = novaNota;
    }else{
        if(info.codDisciplina < (*arvoreNota)->info.codDisciplina){
            insere = inserirNota(&(*arvoreNota)->esq,info);
        }else if(info.codDisciplina > (*arvoreNota)->info.codDisciplina){
            insere = inserirNota(&(*arvoreNota)->dir,info);
        }else{
            insere = 0;
        }
    }

    return insere;
}