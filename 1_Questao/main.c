#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct no{
    int num;
    struct no* esq;
    struct no* dir;
}No;


void inserirValor(No **no, int num){
    if(*no == NULL){
        No *novo = (No*)malloc(sizeof(No));
        
        novo->num = num;
        novo->esq = NULL;
        novo->dir = NULL;

        *no = novo;
    }else{
        if(num < (*no)->num){
            inserirValor(&(*no)->esq,num);
        }else{
            inserirValor(&(*no)->dir,num);
        }
    }
}

int verificaCurso(No *arvoreCurso, int codCurso){

    if(arvoreCurso != NULL){
        if(arvoreCurso->num == codCurso){
            return 1;
        }else{
            verificaCurso(arvoreCurso->esq,codCurso);
            verificaCurso(arvoreCurso->esq,codCurso);
        }


    }

    return 0;
}

void exibirArvore(No *arvoreCurso){
    if(arvoreCurso != NULL){
        exibirArvore(arvoreCurso->esq);
        printf("%d", arvoreCurso->num);
        exibirArvore(arvoreCurso->dir);
    }
}

int main(){

    No *arvore;

    arvore = NULL;

    inserirValor(&arvore,10);
    inserirValor(&arvore,11);
    inserirValor(&arvore,9);

    // printf("%d\n", verificaCurso(arvore,9));

    exibirArvore(arvore);

    return 0;
}