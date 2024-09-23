#pragma once

#include "../aluno/aluno.h"
#include "../matricula/matricula.h"
#include "../arvore/nota/nota.h"

void cadastrarNota(Aluno* aluno, int codDisciplina, float nota);
//Exibe uma informação de nota
void exibirInfoNota(Info info);
//Exibe as informação da arvore de nota
void exibirNotasArvore(ArvoreNota *arvoreNota);
//Mostra Informacao da Nota
void exibirNotaMatricula(ArvoreNota *arvoreNota, int codDisciplina);
//Exibe as notas e a informações das disciplinas
void exibirNotaInfoDisciplina(ArvoreDisciplina *arvoreDisciplina,ArvoreNota *arvoreNota, int matricula);