#pragma once

#include "../../struct/arvore_curso.h"
#include "../../struct/arvore_disciplina.h"
#include "../../struct/arvore_matricula.h"
#include "../../struct/arvore_nota.h"
#include "../../struct/lista_aluno.h"

void liberarTudo(ListaAluno *listaAluno, ArvoreCurso *arvoreCurso);
void liberarAlunos(ListaAluno *aluno);
void liberarMatriculas(ArvoreMatricula *raiz);
void liberarNotas(ArvoreNota *raiz);
void liberarDisciplinas(ArvoreDisciplina *raiz);
void liberarCursos(ArvoreCurso *raiz);