#pragma once

#include "../arvore/disciplina/disciplina.h"
#include "../curso/curso.h"

//Cadastra a Disciplina no respectivo curso
void cadastrarDisciplina(ArvoreCurso **arvoreCurso);
//Mostra a informacao da disciplina
void exibirInfoDisciplina(Disciplina disciplina);
//Percorre todas as disciplinas da arvore de disciplina
void percorreArvoreDisciplina(ArvoreDisciplina *arvoreDisciplina);
//Mostrar todas as disciplinas de um determinado curso
void mostrarDisciplinasCurso(ArvoreCurso *arvoreCurso, int cod);
//Busca o curso e exibe todas as disciplinas
void mostraDisciplinaPeriodoCurso(ArvoreCurso *arvoreCurso, int cod,int periodo);
//Mostra informação de uma disciplina
void mostrarInfoDisciplina(ArvoreDisciplina *arvoreDisciplina,int codDisciplina);
//Verifica se a disciplina existe
int verificaDisciplina(ArvoreDisciplina *arvoreDisciplina, int codDisciplina);