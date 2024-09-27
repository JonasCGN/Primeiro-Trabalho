#include <stdio.h>
#include <stdlib.h>

#include "./matricula.h"

int buscarDisciplinaNaMatricula(ArvoreMatricula* raiz, int codDisciplina){
    int exist = 0;

    if(raiz){
        if (raiz->codDisciplina == codDisciplina){
            exist = 1;
        }else{
            exist = buscarDisciplinaNaMatricula(raiz->esq, codDisciplina) || buscarDisciplinaNaMatricula(raiz->dir, codDisciplina);
        }

    }

    
    return exist;
}

void cadastrarMatricula(ArvoreCurso *arvoreCurso,Aluno* aluno){
    ArvoreCurso *curso;

    int codDisciplina;

    if((curso = retornaCursoCod(arvoreCurso,(*aluno).codigoCurso))){
        percorreArvoreDisciplina(curso->disciplina);

        printf("Digite a matricula da disciplina:");
        scanf("%d", &codDisciplina);
        setbuf(stdin,NULL);
        
        if(verificaDisciplina(curso->disciplina,codDisciplina)){
            if(verificaDisciplinaNota(aluno->nota,codDisciplina)){
                printf("O aluno ja pagou essa disciplina!");
            }else{
                if(inserirMatricula(&(aluno->matriculaDisciplina), codDisciplina)){
                    printf("Matricula realizada com sucesso!\n");
                }else{
                    printf("O aluno ja esta matriculado nessa disciplina!\n");
                }
            }
            
        }
    }

}

void mostrarMatriculas(ArvoreMatricula* raiz){
    if (raiz != NULL) {
        mostrarMatriculas(raiz->esq);
        printf("Disciplina: %d\n", raiz->codDisciplina);
        mostrarMatriculas(raiz->dir);
    }
}

void removerMatricula(ListaAluno *listaAluno){
    Aluno* aluno;

    int matricula,codDisciplina,verifica = 0;

    printf("Digite a matricula do aluno:");
    scanf("%d", &matricula);

    aluno = alunoMatricula(listaAluno,matricula,&verifica);

    if(verifica){
        printf("Digite o codigo da disciplina:");
        scanf("%d",&codDisciplina);

        if(removerDisciplinaMatricula(&(aluno->matriculaDisciplina),codDisciplina)){
            printf("Disciplina removida com sucesso!\n");
        }else{
            printf("Disciplina nao encontrada!\n");
        }
    }else{
        printf("Aluno nao encontrado!\n");
    }
}