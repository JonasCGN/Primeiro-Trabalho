#pragma once

#include "../../../struct/lista_aluno.h"

// Insere aluno na lista
int insereAluno(Aluno aluno,ListaAluno **listaAluno);
// Exibe uma informacao de um aluno
void exibirInfoAluno(Aluno aluno);
// Exibe uma informacao de todos os alunos
void exibirListaAluno(ListaAluno *listaAluno);