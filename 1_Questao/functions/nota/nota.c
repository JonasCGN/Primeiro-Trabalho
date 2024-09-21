#include <stdio.h>
#include <stdlib.h>

#include "./nota.h"

void exibirInfoNota(Info info){
    printf("Codigo Disciplina: %.2f\n", info.codDisciplina);
    printf("Nota: %.2f\n", info.nota);
    printf("Semestre Cursado: %d\n", info.semestreCursado);
}

void exibirNotasArvore(ArvoreNota *arvoreNota){
    if(arvoreNota != NULL){
        exibirNotasArvore(arvoreNota->esq);
        exibirInfoNota(arvoreNota->info);
        exibirNotasArvore(arvoreNota->dir);
    }
}

void exibirNotaMatricula(ArvoreNota *arvoreNota, int codDisciplina){
    if(arvoreNota != NULL){
        if(arvoreNota->info.codDisciplina == codDisciplina){
            printf("Nota da Disciplina: %d\n", arvoreNota->info.nota);
        }
        exibirNotaMatricula(arvoreNota->esq,codDisciplina);
        exibirNotaMatricula(arvoreNota->dir,codDisciplina);
    }
}

void exibirNotaInfoDisciplina(ArvoreDisciplina *arvoreDisciplina,ArvoreNota *arvoreNota, int matricula){
    if(arvoreNota != NULL){
        if(arvoreNota->info.codDisciplina == matricula){
            printf("Nota da Disciplina: %d\n", arvoreNota->info.nota);
            printf("Semestre Cursado: %d\n", arvoreNota->info.semestreCursado);
            mostrarInfoDisciplina(arvoreDisciplina,matricula);
        }
        exibirNotaInfoDisciplina(arvoreDisciplina,arvoreNota->esq,matricula);
        exibirNotaInfoDisciplina(arvoreDisciplina,arvoreNota->dir,matricula);
    }
}

