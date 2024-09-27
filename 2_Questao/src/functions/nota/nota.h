#pragma once

#include "../aluno/aluno.h"
#include "../matricula/matricula.h"
#include "../arvore/nota/nota.h"
#include "../disciplina/disciplina.h"

void cadastrarNota(ArvoreCurso *arvoreCurso,ListaAluno* listaAluno);
//Exibe uma informação de nota
void exibirInfoNota(Info info);
//Exibe as informação da arvore de nota
void exibirNotasArvore(ArvoreNota *arvoreNota);
//Mostra Informacao da Nota
Info* exibirNotaMatricula(ArvoreNota *arvoreNota, int codDisciplina);
//Exibe as notas e a informações das disciplinas
void exibirNotaInfoDisciplina(ArvoreDisciplina *arvoreDisciplina,ArvoreNota *arvoreNota, int codDisciplina);
//Exibe as notas apartir do periodo
void exibirNotasPeriodo(ArvoreNota *arvoreNota,int periodo);
//Verifica se uma disciplina esta na arvore de nota
int verificaDisciplinaNota(ArvoreNota *arvoreNota, int codDisciplina);