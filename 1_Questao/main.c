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

No* verificaCurso(No *arvoreCurso, int codCurso){
    No* exist;
    exist = NULL;

    if(arvoreCurso != NULL){
        if(arvoreCurso->num == codCurso){
            exist = arvoreCurso;
        }else{
            exist = verificaCurso(arvoreCurso->esq,codCurso);

            if(!exist){
                exist = verificaCurso(arvoreCurso->dir,codCurso);
            }
        }
    }

    return exist;
}

void exibirArvore(No *arvoreCurso){
    if(arvoreCurso != NULL){
        exibirArvore(arvoreCurso->esq);
        printf("%d ", arvoreCurso->num);
        exibirArvore(arvoreCurso->dir);
    }
}

int main(){

    No *arvore;

    arvore = NULL;

    inserirValor(&arvore,8);
    inserirValor(&arvore,12);
    inserirValor(&arvore,6);
    inserirValor(&arvore,7);
    inserirValor(&arvore,10);

    int n=11;

    if(verificaCurso(arvore,n)){
        printf("%d\n", verificaCurso(arvore,n)->num);
    }

    exibirArvore(arvore);

    return 0;
}