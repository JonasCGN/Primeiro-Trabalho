#pragma once

#include "../../../struct/arvore_disciplina.h"

//Vai inserir uma disciplina na arvore de disciplina
int inserirDisciplina(ArvoreDisciplina **arvoreDisciplina, Disciplina disciplina);

int removerDisciplina(ArvoreDisciplina **raiz, int codDisciplina);