#include <stdio.h>
#include <stdlib.h>

#include "./matricula.h"

/*Tudo foi flávio*/

int buscarDisciplinaNaMatricula(ArvoreMatricula* raiz, int codDisciplina) {
    int exist = 0;

    if(raiz != NULL){
        if (raiz->codDisciplina == codDisciplina){
            exist = 1;
        }  

        exist = buscarDisciplinaNaMatricula(raiz->esq, codDisciplina) || buscarDisciplinaNaMatricula(raiz->dir, codDisciplina);
        
    }
    
    return exist;
}

void cadastrarMatricula(Aluno* aluno, int codDisciplina) {
    if (buscarDisciplinaNaMatricula(aluno->matriculaDisciplina, codDisciplina)) {
        printf("Erro: Disciplina %d já está cadastrada!\n", codDisciplina);
        return;
    }
    aluno->matriculaDisciplina = inserirMatricula(aluno->matriculaDisciplina, codDisciplina);
}

void mostrarMatriculas(ArvoreMatricula* raiz) {
    if (raiz != NULL) {
        mostrarMatriculas(raiz->esq);
        printf("Disciplina: %d\n", raiz->codDisciplina);
        mostrarMatriculas(raiz->dir);
    }
}