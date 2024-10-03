#pragma once

#include "../../../struct/arvore_disciplina.h"

//Vai inserir uma disciplina na arvore de disciplina
int inserirDisciplina(ArvoreDisciplina **arvoreDisciplina, Disciplina disciplina);

int alturaArvoreDisciplina(ArvoreDisciplina *raiz);
void rotacaoDireitaDisciplina(ArvoreDisciplina **raiz);
void rotacaoEsquerdaDisciplina(ArvoreDisciplina **raiz);
void balanceamentoArvoreDisciplina(ArvoreDisciplina **raiz);

int removerDisciplina(ArvoreDisciplina **raiz, int codDisciplina);