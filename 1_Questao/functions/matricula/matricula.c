#include <stdio.h>
#include <stdlib.h>

#include "./matricula.h"

/*Tudo foi flávio*/

int buscarDisciplinaNaMatricula(ArvoreMatricula* raiz, int codDisciplina){
    int exist = 0;

    if(raiz != NULL){
        if (raiz->codDisciplina == codDisciplina){
            exist = 1;
        }  
        exist = buscarDisciplinaNaMatricula(raiz->esq, codDisciplina) || buscarDisciplinaNaMatricula(raiz->dir, codDisciplina);
        
    }
    
    return exist;
}

void cadastrarMatricula(ArvoreCurso *arvoreCurso,Aluno* aluno){
    ArvoreCurso *curso;

    int codDisciplina;
    


    if((curso = retornaCursoCod(arvoreCurso,(*aluno).codigoCurso))){
        percorreArvoreDisciplina(curso->disciplina);

        printf("Digite a matricula da disciplina:");
        scanf("%d", &codDisciplina);
        
        if(verificaDisciplina(curso->disciplina,codDisciplina)){
            if(inserirMatricula(&(aluno->matriculaDisciplina), codDisciplina)){
                printf("Matricula realizada com sucesso!\n");
            }else{
                printf("O aluno ja esta matriculado nessa disciplina!\n");
            }
        }
    }
    

    

}

void mostrarMatriculas(ArvoreMatricula* raiz){
    if (raiz != NULL) {
        mostrarMatriculas(raiz->esq);
        printf("Disciplina: %d\n", raiz->codDisciplina);
        mostrarMatriculas(raiz->dir);
    }
}