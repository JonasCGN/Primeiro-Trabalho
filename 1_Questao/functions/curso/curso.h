#pragma once

#include "../../struct/arvore_curso.h"

// Ele cadastra o curso
void cadastraCurso(ArvoreCurso **arvoreCurso);
//Mostra a informação de um curso
void mostraInfoCurso(Curso curso);
//Mostrar todos os cursos do campus
void mostrarTodosCursos(ArvoreCurso *arvoreCurso);


/* Acabar */
// Ele verifica se o curso existe
int verificaCurso(ArvoreCurso *arvoreCurso, int codCurso);
//Retorna o curso encontrado
ArvoreCurso *retornaCursoCod(ArvoreCurso *arvoreCurso,int codCurso);