#pragma once

#include "../../aluno/aluno.h"

int inserirNota(ArvoreNota** raiz, Info info);

int alturaArvoreNota(ArvoreNota *raiz);
void rotacaoDireitaNota(ArvoreNota **raiz);
void rotacaoEsquerdaNota(ArvoreNota **raiz);
void balanceamentoArvoreNota(ArvoreNota **raiz);