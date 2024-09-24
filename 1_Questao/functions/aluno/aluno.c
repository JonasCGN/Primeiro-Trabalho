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
    aluno.matriculaDisciplina = NULL;

    insereAluno(aluno,listaAluno);       
}

void alunoCurso(ListaAluno *listaAluno, int cod){
    if(listaAluno != NULL){
        
        if(listaAluno->aluno.codigoCurso == cod){
            exibirInfoAluno(listaAluno->aluno);
        }else{
            alunoCurso(listaAluno->prox,cod);
        }

    }
}

void mostrarAlunoCurso(ListaAluno *listaAluno){
    int cod;

    printf("Digite o codigo do curso:");
    scanf("%d", &cod);

    alunoCurso(listaAluno,cod);
}

void alunoMatriculaInfo(ArvoreDisciplina *arvoreDisciplina, ArvoreMatricula *arvoreMatricula){
    if(arvoreDisciplina != NULL){
        if(arvoreMatricula->codDisciplina == arvoreDisciplina->disciplina.codDisciplina){
            mostrarInfoDisciplina(arvoreDisciplina, arvoreMatricula->codDisciplina);
        }else if(arvoreMatricula->codDisciplina < arvoreDisciplina->disciplina.codDisciplina){
            alunoMatricula(arvoreDisciplina,arvoreMatricula->esq);
        }else{
            alunoMatricula(arvoreDisciplina,arvoreMatricula->dir);
        }
    }
}

void mostrarDisciplinaAluno(ArvoreCurso *arvoreCurso,Aluno aluno){
    ArvoreCurso *curso;
    curso = retornaCursoCod(arvoreCurso,aluno.codigoCurso);

    alunoMatriculaInfo(curso->disciplina,aluno.matriculaDisciplina);
}

Aluno alunoMatricula(ListaAluno *listaAluno, int matricula,int *verifica){
    Aluno aluno;

    if(listaAluno != NULL){
        if(listaAluno->aluno.matricula == matricula){
            *verifica = 1;
            aluno = (listaAluno->aluno);
        }else{
            aluno = alunoMatricula(listaAluno->prox,matricula,verifica);
        }
    }

    return aluno;
}

void historicoAluno(ArvoreCurso *arvoreCurso,Aluno aluno){
    ArvoreCurso *cursoAluno = retornaCursoCod(arvoreCurso,aluno.codigoCurso);
    Curso curso = cursoAluno->curso;

    printf("Nome Curso: %s\n",curso.nomeCurso);
    for(int i=0;i <= cursoAluno->curso.quantPeriodo;i++){
        printf("------------Periodo %d------------\n", i);
        mostrarInfoNotaDisciplina(aluno.nota,cursoAluno->disciplina,i);
        mostrarDisciplinaAluno(cursoAluno,aluno);
        printf("----------------------------------\n");
    }
}

void mostrarInfoNotaDisciplina(ArvoreNota *arvoreNota,ArvoreDisciplina *arvoreDisciplina,int periodo){
    if(arvoreNota != NULL){
        if(periodo == arvoreDisciplina->disciplina.periodo){
            exibirNotaMatricula(arvoreNota,arvoreDisciplina->disciplina.codDisciplina);
        }else if(periodo < arvoreDisciplina->disciplina.periodo){
            mostrarInfoNotaDisciplina(arvoreNota,arvoreDisciplina->esq,periodo);
        }else{
            mostrarInfoNotaDisciplina(arvoreNota,arvoreDisciplina->dir,periodo);
        }
    }
}