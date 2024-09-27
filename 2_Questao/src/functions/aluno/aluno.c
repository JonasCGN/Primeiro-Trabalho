#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./aluno.h"

void cadastrarAluno(ListaAluno **listaAluno, ArvoreCurso *arvoreCurso){
    Aluno aluno;
    int codCurso;

    printf("Digite o seu nome:");
    fgets(aluno.nomeAluno,sizeof(aluno.nomeAluno),stdin);

    do{
        printf("Digite o codigo do curso:");
        scanf("%d", &codCurso);
        if(!arvoreCurso){
            printf("Nao ha nenhum curso cadastrado!\n");
        }
    }while(!verificaCurso(arvoreCurso,codCurso) && arvoreCurso);
    if(arvoreCurso){
        aluno.codigoCurso = codCurso;
        setbuf(stdin,NULL);

        printf("Digite a sua matricula:");
        scanf("%d", &(aluno.matricula));
        setbuf(stdin,NULL);

        aluno.nota = NULL;
        aluno.matriculaDisciplina = NULL;

        insereAluno(aluno,listaAluno);     
    }
  
}

void alunoCurso(ListaAluno *listaAluno, int cod){
    if(listaAluno){
        if(listaAluno->aluno.codigoCurso == cod)
            exibirInfoAluno(listaAluno->aluno);
        
        alunoCurso(listaAluno->prox,cod);
    }
}

void mostrarAlunoCurso(ListaAluno *listaAluno){
    int cod;

    printf("Digite o codigo do curso:");
    scanf("%d", &cod);

    alunoCurso(listaAluno,cod);
}

void alunoMatriculaInfo(ArvoreDisciplina *arvoreDisciplina, ArvoreMatricula *arvoreMatricula){
    if(arvoreMatricula){
        mostrarInfoDisciplina(arvoreDisciplina, arvoreMatricula->codDisciplina);

        alunoMatriculaInfo(arvoreDisciplina,arvoreMatricula->esq);
        alunoMatriculaInfo(arvoreDisciplina,arvoreMatricula->dir);
    }
}

void mostrarDisciplinaAluno(ArvoreCurso *arvoreCurso,Aluno aluno){
    ArvoreCurso *curso;
    curso = retornaCursoCod(arvoreCurso,aluno.codigoCurso);

    if(aluno.matriculaDisciplina)
        alunoMatriculaInfo(curso->disciplina,aluno.matriculaDisciplina);
    else
        printf("Sem matricula para o aluno");
}

Aluno* alunoMatricula(ListaAluno *listaAluno, int matricula,int *verifica){
    Aluno* aluno;

    if(listaAluno != NULL){
        if(listaAluno->aluno.matricula == matricula){
            *verifica = 1;
            aluno = &(listaAluno->aluno);
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
    for(int i=1;i <= cursoAluno->curso.quantPeriodo;i++){
        printf("------------Periodo %d------------\n", i);
        mostrarNotaDisciplina(aluno.nota,cursoAluno->disciplina,i);
        printf("----------------------------------\n");
    }
}

void mostrarDisciplinaNotaPeriodo(Info info, ArvoreDisciplina *arvoreDisciplina,int periodo){
    if(arvoreDisciplina){
        if(
            periodo == arvoreDisciplina->disciplina.periodo &&
            arvoreDisciplina->disciplina.codDisciplina == info.codDisciplina
        ){
            exibirInfoDisciplina(arvoreDisciplina->disciplina);
            printf("Nota da Disciplina: %.2f\n", info.nota);
        }
        mostrarDisciplinaNotaPeriodo(info, arvoreDisciplina->esq,periodo);
        mostrarDisciplinaNotaPeriodo(info, arvoreDisciplina->dir,periodo);
    }
}

void mostrarNotaDisciplina(ArvoreNota *arvoreNota,ArvoreDisciplina *arvoreDisciplina,int periodo){
    if(arvoreNota){
        mostrarDisciplinaNotaPeriodo(arvoreNota->info, arvoreDisciplina,periodo);

        mostrarNotaDisciplina(arvoreNota->esq,arvoreDisciplina,periodo);
        mostrarNotaDisciplina(arvoreNota->dir,arvoreDisciplina,periodo);
    }
}

int verificaMatriculadoDisciplina(ListaAluno *listaAluno, int codDisciplina){
    int existe = 0;

    if(listaAluno != NULL){
        if(!existe){
            existe = buscarDisciplinaNaMatricula(listaAluno->aluno.matriculaDisciplina,codDisciplina);
        }else{
            existe = verificaMatriculadoDisciplina(listaAluno->prox,codDisciplina);
        }
    }

    return existe;
}
