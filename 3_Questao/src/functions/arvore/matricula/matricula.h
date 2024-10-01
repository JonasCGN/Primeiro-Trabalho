#pragma once

#include "../../../struct/arvore_matricula.h"
#include "../../../struct/lista_aluno.h"

int inserirMatricula(ArvoreMatricula** raiz, int codDisciplina);

int alturaArvoreMatricula(ArvoreMatricula *raiz);
void rotacaoDireitaMatricula(ArvoreMatricula **raiz);
void rotacaoEsquerdaMatricula(ArvoreMatricula **raiz);
void balanceamentoArvoreMatricula(ArvoreMatricula **raiz);

int removerDisciplinaMatricula(ArvoreMatricula **raiz, int codDisciplina);