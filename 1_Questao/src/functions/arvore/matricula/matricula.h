#pragma once

#include "../../../struct/arvore_matricula.h"
#include "../../../struct/lista_aluno.h"

int inserirMatricula(ArvoreMatricula** raiz, int codDisciplina);

int removerDisciplinaMatricula(ArvoreMatricula **raiz, int codDisciplina);