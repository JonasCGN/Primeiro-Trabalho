#pragma once

#include "../curso/curso.h"
#include "../lista/aluno/aluno.h"
#include "../disciplina/disciplina.h"
#include "../nota/nota.h"

//Cadastra aluno
void cadastrarAluno(ListaAluno **listaAluno, ArvoreCurso *arvoreCurso);
//Exibe a informacao dos alunos que estão em um curso
void alunoCurso(ListaAluno *listaAluno, int cod);
//Mostrar todos os alunos de um determinado curso
void mostrarAlunoCurso(ListaAluno *listaAluno);
//Exibe o Aluno e suas disciplinas
void alunoMatriculaInfo(ArvoreDisciplina *arvoreDisciplina, ArvoreMatricula *arvoreMatricula);
//Mostrar todas as disciplinas que um determinado aluno está matriculado
void mostrarDisciplinaAluno(ArvoreCurso *arvoreCurso, Aluno aluno);
//Retorna o aluno com a respectiva matricula
Aluno* alunoMatricula(ListaAluno *listaAluno, int matricula,int *verifica);
//Mostar Informacao da Nota Apartir da Disciplina
void mostrarNotaDisciplina(ArvoreNota *arvoreNota,ArvoreDisciplina *arvoreDisciplina,int periodo);
//Histórico do Aluno
void historicoAluno(ArvoreCurso *arvoreCurso,Aluno aluno);

int verificaMatriculadoDisciplina(ListaAluno *listaAluno, int codDisciplina);

void mostrarDisciplinaNotaPeriodo(Info info, ArvoreDisciplina *arvoreDisciplina,int periodo);