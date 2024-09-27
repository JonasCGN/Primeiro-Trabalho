#include <stdlib.h>

#include "./liberar.h"

void liberarTudo(
    ListaAluno *listaAluno,
    ArvoreCurso *arvoreCurso
){
    liberarAlunos(listaAluno);
    liberarCursos(arvoreCurso);
}

void liberarAlunos(ListaAluno *listaAluno){
    if(listaAluno){
        liberarAlunos(listaAluno->prox);
        liberarMatriculas(listaAluno->aluno.matriculaDisciplina);
        liberarNotas(listaAluno->aluno.nota);
        free(listaAluno);
    }
}

void liberarMatriculas(ArvoreMatricula *raiz){
    if (raiz){
        liberarMatriculas(raiz->esq);
        liberarMatriculas(raiz->dir);
        free(raiz);
    }
}

void liberarNotas(ArvoreNota *raiz){
    if (raiz){
        liberarNotas(raiz->esq);
        liberarNotas(raiz->dir);
        free(raiz);
    }
}

void liberarDisciplinas(ArvoreDisciplina *raiz){
    if (raiz){
        liberarDisciplinas(raiz->esq);
        liberarDisciplinas(raiz->dir);
        free(raiz);
    }
}

static void liberaCurso(ArvoreCurso *raiz){
    if (raiz->disciplina)
        liberarDisciplinas(raiz->disciplina);

    free(raiz);
}

void liberarCursos(ArvoreCurso *raiz){
    if (raiz){
        liberarCursos(raiz->esq);
        liberarCursos(raiz->dir);
        liberaCurso(raiz);
    }
}