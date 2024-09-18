#include <stdio.h>
#include <stdlib.h>

#include "./curso.h"
#include "../arvore/curso/curso.h"

void cadastraCurso(ArvoreCurso **arvoreCurso){
    Curso novo;

    printf("Digite o nome do curso:");
    scanf("%s",novo.nomeCurso);

    printf("Digite o codigo do curso:");
    scanf("%d",&(novo.codCurso));

    printf("Digite a quantidade de periodo do curso:");
    scanf("%d",&(novo.quantPeriodo));

    inserirCurso(arvoreCurso, novo);
}

void mostraInfoCurso(Curso curso){
    printf("Codigo do Curso:%d\n", curso.codCurso);
    printf("Nome do Curso:%s\n", curso.nomeCurso);
    printf("Quantidade de Periodo:%d\n", curso.quantPeriodo);
}

int verificaCurso(ArvoreCurso *arvoreCurso, int codCurso){

    if(arvoreCurso != NULL){
        if(arvoreCurso->curso.codCurso == codCurso){
            return 1;
        }

        verificaCurso(arvoreCurso->esq,codCurso);
        verificaCurso(arvoreCurso->dir,codCurso);

    }

}

ArvoreCurso *retornaCursoCod(ArvoreCurso *arvoreCurso,int cod){

    return arvoreCurso;
    
}

void mostrarTodosCursos(ArvoreCurso *arvoreCurso){
    if(arvoreCurso != NULL){
        mostrarTodosCursos(arvoreCurso->esq);
        mostraInfoCurso(arvoreCurso->curso);
        mostrarTodosCursos(arvoreCurso->dir);
    }
}