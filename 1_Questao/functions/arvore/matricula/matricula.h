#pragma once

#include "../../../struct/arvore_matricula.h"
#include "../../../struct/lista_aluno.h"

int inserirMatricula(ArvoreMatricula** raiz, int codDisciplina);
void removerDisciplinaMatricula(ArvoreMatricula** raiz, int codDisciplina);
ArvoreMatricula *filhoArvore(ArvoreMatricula *arvoreMatricula);
int folhaArvore(ArvoreMatricula *arvoreMatricula);