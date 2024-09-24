#pragma once

#include "../../struct/arvore_matricula.h"
#include "../../struct/lista_aluno.h"
#include "../curso/curso.h"
#include "../disciplina/disciplina.h"
#include "../arvore/matricula/matricula.h"

int buscarDisciplinaNaMatricula(ArvoreMatricula* raiz, int codDisciplina);
void cadastrarMatricula(ArvoreCurso *arvoreCurso,Aluno* aluno);
void mostrarMatriculas(ArvoreMatricula* raiz);