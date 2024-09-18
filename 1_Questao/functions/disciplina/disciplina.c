#include <stdio.h>
#include <stdlib.h>

#include "./disciplina.h"

void cadastrarDisciplina(ArvoreCurso **arvoreCurso){
    ArvoreCurso **curso;
    curso = NULL;
    int cod;

    printf("Digite o codigo do curso:");
    scanf("%d", &cod);
    
    curso = retornaCursoCod(*arvoreCurso, cod);
    if(curso != NULL){
        Disciplina novo;

        printf("Digite o codigo da disciplina:");
        scanf("%d", &(novo.codDisciplina));

        printf("Digite o nome da disciplina:");
        scanf("%s", &(novo.nomeDisciplina));

        printf("Digite a carga horaria da disciplina:");
        do{
            scanf("%d",&(novo.cargaHoraria));
            if(novo.cargaHoraria % 15 != 0){
                printf("\nDigite um numero multiplo de 15:");
            }
        }while(novo.cargaHoraria % 15 != 0);

        printf("Digite o periodo da disciplina:");
        do{
            scanf("%d", &(novo.periodo));
            if(novo.periodo < 1 && novo.periodo > (*arvoreCurso)->curso.quantPeriodo){
                printf("Digite um periodo valido");
            }
        }while(novo.periodo < 1 && novo.periodo > (*arvoreCurso)->curso.quantPeriodo);

        inserirDisciplina(&curso, novo);
    }else{
        printf("Curso nao encontrado\n");
    }
    
}

void exibirInfoDisciplina(Disciplina disciplina){
    printf("Codigo da Disciplina: %d\n", disciplina.codDisciplina);
    printf("Nome da Disciplina: %s\n", disciplina.nomeDisciplina);
    printf("Periodo: %d\n", disciplina.periodo);
    printf("Carga Horaria da Disciplina: %d\n", disciplina.cargaHoraria);
}

void percorreArvoreDisciplina(ArvoreDisciplina *arvoreDisciplina){
    if(arvoreDisciplina != NULL){
        percorreArvoreDisciplina(arvoreDisciplina->esq);
        exibirInfoDisciplina(arvoreDisciplina->disciplina);
        percorreArvoreDisciplina(arvoreDisciplina->dir);
    }
}

void mostrarDisciplinasCurso(ArvoreCurso *arvoreCurso, int cod){
    if(arvoreCurso != NULL){
        if(arvoreCurso->curso.codCurso == cod){
            percorreArvoreDisciplina(arvoreCurso->disciplina);
        }
        mostrarDisciplinasCurso(arvoreCurso->esq,cod);
        mostrarDisciplinasCurso(arvoreCurso->dir,cod);
    }
}

int verificaDisciplina(ArvoreDisciplina *arvoreDisciplina, int codDisciplina){
    int exist = 0;
    
    if(arvoreDisciplina != NULL){
        if(arvoreDisciplina->disciplina.codDisciplina == codDisciplina){
            exist = 1;
        }else{
            exist = verificaDisciplina(arvoreDisciplina->esq,codDisciplina);
            if(!exist){
                exist = verificaDisciplina(arvoreDisciplina->dir,codDisciplina);
            }
        }
    }

    return exist;
}

//Percorre as disciplinas de um periodo
void disciplinaPeriodoCurso(ArvoreDisciplina *arvoreDisciplina, int periodo){
    if(arvoreDisciplina != NULL){
        if(arvoreDisciplina->disciplina.periodo == periodo){
            exibirInfoDisciplina(arvoreDisciplina->disciplina);
        }
        disciplinaPeriodoCurso(arvoreDisciplina->esq,periodo);
        disciplinaPeriodoCurso(arvoreDisciplina->dir,periodo);
    }
}

void mostraDisciplinaPeriodoCurso(ArvoreCurso *arvoreCurso, int cod,int periodo){
    ArvoreCurso *curso;
    curso = retornaCursoCod(arvoreCurso,cod);
    for(int i = 1;i <= curso->curso.quantPeriodo;i++){
        disciplinaPeriodoCurso(curso->disciplina,periodo);
    }
}

void mostrarInfoDisciplina(ArvoreDisciplina *arvoreDisciplina,int codDisciplina){
    if(arvoreDisciplina != NULL){
        
        if(arvoreDisciplina->disciplina.codDisciplina == codDisciplina){
            exibirInfoDisciplina(arvoreDisciplina->disciplina);
        }

        mostrarInfoDisciplina(arvoreDisciplina->esq,codDisciplina);
        mostrarInfoDisciplina(arvoreDisciplina->dir,codDisciplina);
    }
}
