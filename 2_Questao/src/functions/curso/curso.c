#include <stdio.h>
#include <stdlib.h>

#include "./curso.h"

void cadastraCurso(ArvoreCurso **arvoreCurso){
    Curso novo;

    printf("Digite o nome do curso:");
    fgets(novo.nomeCurso,sizeof(novo.nomeCurso),stdin);

    printf("Digite o codigo do curso:");
    scanf("%d",&(novo.codCurso));
    setbuf(stdin,NULL);

    printf("Digite a quantidade de periodo do curso:");
    scanf("%d",&(novo.quantPeriodo));
    setbuf(stdin,NULL);

    if(inserirCurso(arvoreCurso, novo)){
        printf("Curso inserido com sucesso!\n");
    }else{
        printf("Curso ja existe!");
    }
}

void mostraInfoCurso(Curso curso){
    printf("Codigo do Curso:%d\n", curso.codCurso);
    printf("Nome do Curso:%s\n", curso.nomeCurso);
    printf("Quantidade de Periodo:%d\n", curso.quantPeriodo);
}

int verificaCurso(ArvoreCurso *arvoreCurso, int codCurso){

    int exist = 0;

    if(arvoreCurso != NULL){
        if(arvoreCurso->curso.codCurso == codCurso){
            exist = 1;
        }else{
            exist = verificaCurso(arvoreCurso->esq,codCurso) || verificaCurso(arvoreCurso->dir,codCurso);
        }
    }

    return exist;

}

ArvoreCurso *retornaCursoCod(ArvoreCurso *arvoreCurso,int codCurso){
    ArvoreCurso *exist= NULL;
    exist = NULL;

    if(arvoreCurso != NULL){

        if(arvoreCurso->curso.codCurso == codCurso){
            exist = arvoreCurso;
        }else{
            exist = retornaCursoCod(arvoreCurso->esq,codCurso);
            if(exist != NULL){
                exist = retornaCursoCod(arvoreCurso->dir,codCurso);
            }
        }
    }

    return exist;
}

void mostrarTodosCursos(ArvoreCurso *arvoreCurso){
    if(arvoreCurso != NULL){
        mostrarTodosCursos(arvoreCurso->esq);
        mostraInfoCurso(arvoreCurso->curso);
        mostrarTodosCursos(arvoreCurso->dir);
    }
}