#pragma once

#include "../../../struct/arvore_curso.h"

//Vai inserir um curso na arvore de curso
int inserirCurso(ArvoreCurso **arvoreCurso, Curso curso);

int alturaArvoreCurso(ArvoreCurso *raiz);
void rotacaoDireitaCurso(ArvoreCurso **raiz);
void rotacaoEsquerdaCurso(ArvoreCurso **raiz);
void balanceamentoArvoreCurso(ArvoreCurso **raiz);
