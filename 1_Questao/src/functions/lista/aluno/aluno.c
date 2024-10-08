#include <stdio.h>
#include <stdlib.h>

#include "./aluno.h"
#include "../../backend/backend.h"

int insereAluno(Aluno aluno,ListaAluno **listaAluno){
    int insere = 1;

    if(*listaAluno && aluno.matricula == (*listaAluno)->aluno.matricula)
        insere = 0;
    else{
        if(!(*listaAluno) || comparaString(aluno.nomeAluno, (*listaAluno)->aluno.nomeAluno) < 0){
            ListaAluno *novo = (ListaAluno *)malloc(sizeof(ListaAluno));
            
            novo->aluno = aluno;
            novo->prox = *listaAluno;
            
            *listaAluno = novo;

        }else{
            insere = insereAluno(aluno, &(*listaAluno)->prox);
        }
    }
    return insere;
}

void exibirInfoAluno(Aluno aluno){
    printf("\n------------------------------------------\n");
    printf("Nome: %s\n", aluno.nomeAluno);
    printf("Codigo do Curso: %d\n", aluno.codigoCurso);
    printf("Matricula do Aluno: %d\n", aluno.matricula);
    printf("------------------------------------------\n");
}

void exibirListaAluno(ListaAluno *listaAluno){

    if(listaAluno){
        exibirInfoAluno(listaAluno->aluno);
        exibirListaAluno(listaAluno->prox);
    }

}