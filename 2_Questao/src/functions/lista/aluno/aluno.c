#include <stdio.h>
#include <stdlib.h>

#include "./aluno.h"
#include "../../backend/backend.h"

void insereAluno(Aluno aluno,ListaAluno **listaAluno){
    ListaAluno *novo;
    novo = (ListaAluno*)malloc(sizeof(ListaAluno));

    novo->aluno = aluno;

    if(*listaAluno == NULL || comparaString(novo->aluno.nomeAluno, (*listaAluno)->aluno.nomeAluno) < 0){
        
        novo->prox = *listaAluno;
        *listaAluno = novo;

    }else{
        ListaAluno *aux = *listaAluno;

        while(aux->prox != NULL && !(comparaString(novo->aluno.nomeAluno, aux->prox->aluno.nomeAluno) < 0)){
            aux = aux->prox;
        }

        novo->prox = aux->prox;
        aux->prox = novo;
    }
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