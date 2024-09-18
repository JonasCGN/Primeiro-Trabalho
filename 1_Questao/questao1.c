#include "./struct/arvore_matricula.h"
#include "./struct/lista_aluno.h"
#include <stdio.h>
#include <stdlib.h>

ArvoreMatricula* inserirMatricula(ArvoreMatricula* raiz, int codDisciplina) {
    if (raiz == NULL) {
        ArvoreMatricula* novaMatricula = (ArvoreMatricula*) malloc(sizeof(ArvoreMatricula));
        novaMatricula->codDisciplina = codDisciplina;
        novaMatricula->esq = novaMatricula->dir = NULL;
        return novaMatricula;
    }

    if (codDisciplina < raiz->codDisciplina)
        raiz->esq = inserirMatricula(raiz->esq, codDisciplina);
    else if (codDisciplina > raiz->codDisciplina)
        raiz->dir = inserirMatricula(raiz->dir, codDisciplina);

    return raiz;
}

int buscarDisciplinaNaMatricula(ArvoreMatricula* raiz, int codDisciplina) {
    if (raiz == NULL) return 0; 

    if (raiz->codDisciplina == codDisciplina) return 1; 

    if (codDisciplina < raiz->codDisciplina)
        return buscarDisciplinaNaMatricula(raiz->esq, codDisciplina);
    else
        return buscarDisciplinaNaMatricula(raiz->dir, codDisciplina);
}

void cadastrarMatricula(Aluno* aluno, int codDisciplina) {
    if (buscarDisciplinaNaMatricula(aluno->matriculas, codDisciplina)) {
        printf("Erro: Disciplina %d já está cadastrada!\n", codDisciplina);
        return;
    }
    aluno->matriculas = inserirMatricula(aluno->matriculas, codDisciplina);
}

void mostrarMatriculas(ArvoreMatricula* raiz) {
    if (raiz != NULL) {
        mostrarMatriculas(raiz->esq);
        printf("Disciplina: %d\n", raiz->codDisciplina);
        mostrarMatriculas(raiz->dir);
    }
}

void cadastrarNota(Aluno* aluno, int codDisciplina, float nota) {

    if (buscarDisciplinaNaMatricula(aluno->matriculas, codDisciplina)) {

        aluno->nota = inserirNota(aluno->nota, codDisciplina, nota);
        
        aluno->matriculas = removerDisciplinaMatricula(aluno->matriculas, codDisciplina);
        
        printf("Nota cadastrada com sucesso para a disciplina %d!\n", codDisciplina);
    } else {
        printf("Erro: Disciplina %d não está matriculada!\n", codDisciplina);
    }
}

ArvoreNota* inserirNota(ArvoreNota* raiz, int codDisciplina, float nota) {
    if (raiz == NULL) {
        ArvoreNota* novaNota = (ArvoreNota*) malloc(sizeof(ArvoreNota));
        novaNota->codDisciplina = codDisciplina;
        novaNota->nota = nota;
        novaNota->esq = novaNota->dir = NULL;
        return novaNota;
    }

    if (codDisciplina < raiz->codDisciplina)
        raiz->esq = inserirNota(raiz->esq, codDisciplina, nota);
    else if (codDisciplina > raiz->codDisciplina)
        raiz->dir = inserirNota(raiz->dir, codDisciplina, nota);
    
    return raiz;
}

ArvoreMatricula* removerDisciplinaMatricula(ArvoreMatricula* raiz, int codDisciplina) {
    if (raiz != NULL) {  
        if (codDisciplina < raiz->codDisciplina) {
            raiz->esq = removerDisciplinaMatricula(raiz->esq, codDisciplina);
        } else if (codDisciplina > raiz->codDisciplina) {
            raiz->dir = removerDisciplinaMatricula(raiz->dir, codDisciplina);
        } else {
            if (raiz->esq == NULL) {
                ArvoreMatricula* temp = raiz->dir;
                free(raiz);
                return temp;
            } else if (raiz->dir == NULL) {
                ArvoreMatricula* temp = raiz->esq;
                free(raiz);
                return temp;
            }

            ArvoreMatricula* temp = minValueNode(raiz->dir);
            raiz->codDisciplina = temp->codDisciplina;
            raiz->dir = removerDisciplinaMatricula(raiz->dir, temp->codDisciplina);
        }
    }

    return raiz;
}



