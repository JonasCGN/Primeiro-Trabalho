#include <stdio.h>
#include <stdlib.h>

#include "./aluno.h"

void cadastrarAluno(ListaAluno **listaAluno, ArvoreCurso *arvoreCurso){
    Aluno aluno;
    int codCurso;

    printf("Digite o seu nome:");
    scanf("^[\n]", aluno.nomeAluno);

    printf("Digite o codigo do curso:");
    do{
        scanf("%d", &codCurso);
    }while(verificaCurso(arvoreCurso,codCurso));
    aluno.codigoCurso = codCurso;

    printf("Digite a sua matricula:");
    scanf("%d", &(aluno.matricula));

    aluno.nota = NULL;

    insereAluno(aluno,listaAluno);       
}

void alunoCurso(ListaAluno *listaAluno, int cod){
    if(listaAluno != NULL){
        
        if(listaAluno->aluno.codigoCurso == cod){
            exibirInfoAluno(listaAluno->aluno);
        }

        alunoCurso(listaAluno->prox,cod);

    }
}

void mostrarAlunoCurso(ListaAluno *listaAluno){
    int cod;

    printf("Digite o codigo do curso:");
    scanf("%d", &cod);

    alunoCurso(listaAluno,cod);
}

Aluno alunoMatricula(ArvoreDisciplina *arvoreDisciplina, int matricula){
    if(arvoreDisciplina != NULL){
        
        if(arvoreDisciplina->disciplina.codDisciplina == matricula){
            exibirInfoDisciplina(arvoreDisciplina->disciplina);
        }

        alunoMatricula(arvoreDisciplina->esq,matricula);
        alunoMatricula(arvoreDisciplina->dir,matricula);
    }
}

void mostrarDisciplinaAluno(ArvoreCurso *arvoreCurso,Aluno aluno){
    ArvoreCurso *curso;
    curso = retornaCursoCod(arvoreCurso,aluno.codigoCurso);

    alunoMatricula(curso->disciplina,aluno.matricula);
}