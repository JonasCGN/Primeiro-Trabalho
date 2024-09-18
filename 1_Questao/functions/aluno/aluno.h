#pragma once

#include "../curso/curso.h"
#include "../lista/aluno/aluno.h"
#include "../disciplina/disciplina.h"

//Cadastra aluno
void cadastrarAluno(ListaAluno **listaAluno, ArvoreCurso *arvoreCurso);
//Exibe a informacao dos alunos que estão em um curso
void alunoCurso(ListaAluno *listaAluno, int cod);
//Mostrar todos os alunos de um determinado curso
void mostrarAlunoCurso(ListaAluno *listaAluno);
//Retorna o aluno com a respectiva matricula
Aluno alunoMatricula(ArvoreDisciplina *arvoreDisciplina, int matricula);
//Mostrar todas as disciplinas que um determinado aluno está matriculado
void mostrarDisciplinaAluno(ArvoreCurso *arvoreCurso, Aluno aluno);