#pragma once

#include "../../struct/arvore_matricula.h"
#include "../../struct/lista_aluno.h"

int buscarDisciplinaNaMatricula(ArvoreMatricula* raiz, int codDisciplina);
void cadastrarMatricula(Aluno* aluno, int codDisciplina);
void mostrarMatriculas(ArvoreMatricula* raiz);