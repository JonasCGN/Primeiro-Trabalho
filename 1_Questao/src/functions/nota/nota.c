#include <stdio.h>
#include <stdlib.h>

#include "./nota.h"

void cadastrarNota(ArvoreCurso *arvoreCurso,ListaAluno* listaAluno) {
    Aluno* aluno;
    int matricula,verifica;

    printf("Digite a matricula do aluno:");
    scanf("%d", &matricula);

    aluno = alunoMatricula(listaAluno,matricula,&verifica);
    
    if(verifica){
        Info info;
        ArvoreCurso *curso;

        curso = retornaCursoCod(arvoreCurso,aluno->codigoCurso);

        printf("Digite a sua disciplina:");
        scanf("%d", &(info.codDisciplina));
        setbuf(stdin,NULL);

        if (buscarDisciplinaNaMatricula(aluno->matriculaDisciplina, info.codDisciplina)) {
            printf("Digite a nota do aluno:");
            scanf("%f", &(info.nota));
            setbuf(stdin,NULL);

            printf("Digite o semestre do aluno:");
            do{
                scanf("%d", &(info.semestreCursado));
                setbuf(stdin,NULL);
             
                if(info.semestreCursado < 1 || info.semestreCursado > curso->curso.quantPeriodo){
                    printf("Digite um periodo certo!\n");
                }
            }while(info.semestreCursado < 1 || info.semestreCursado > curso->curso.quantPeriodo);
            
            inserirNota(&(aluno->nota), info);
            
            removerDisciplinaMatricula(&(aluno->matriculaDisciplina), info.codDisciplina);
            
            printf("Nota cadastrada com sucesso para a disciplina %d!\n", info.codDisciplina);
        } else {
            printf("Erro: Disciplina %d não está matriculada!\n", info.codDisciplina);
        }
    }else{
        printf("Aluno nao encontrado!\n");
    }

    
}

void exibirInfoNota(Info info){
    printf("Codigo Disciplina: %d\n", info.codDisciplina);
    printf("Nota: %.2f\n", info.nota);
    printf("Semestre Cursado: %d\n", info.semestreCursado);
}

void exibirNotasArvore(ArvoreNota *arvoreNota){
    if(arvoreNota != NULL){
        exibirNotasArvore(arvoreNota->esq);
        exibirInfoNota(arvoreNota->info);
        exibirNotasArvore(arvoreNota->dir);
    }
}

void exibirNotasPeriodo(ArvoreNota *arvoreNota,int periodo){
    if(arvoreNota != NULL){
        exibirNotasArvore(arvoreNota->esq);
        if(arvoreNota->info.semestreCursado == periodo)
            exibirInfoNota(arvoreNota->info);
        exibirNotasArvore(arvoreNota->dir);
    }
}

void exibirNotaMatricula(ArvoreNota *arvoreNota, int codDisciplina){
    if(arvoreNota != NULL){
        if(codDisciplina == arvoreNota->info.codDisciplina){
            printf("Nota da Disciplina: %.2f\n", arvoreNota->info.nota);
        }else if(codDisciplina < arvoreNota->info.codDisciplina){
            exibirNotaMatricula(arvoreNota->esq,codDisciplina);
        }else{
            exibirNotaMatricula(arvoreNota->dir,codDisciplina);
        }
    }
}

int verificaDisciplinaNota(ArvoreNota *arvoreNota, int codDisciplina){
    int exist = 0;
    
    if(arvoreNota){
        if(arvoreNota->info.codDisciplina == codDisciplina){
            exist = 1;
        }else{
            exist = verificaDisciplinaNota(arvoreNota->esq,codDisciplina) || verificaDisciplinaNota(arvoreNota->dir,codDisciplina);
        }
    }

    return exist;
}

void exibirNotaInfoDisciplina(ArvoreDisciplina *arvoreDisciplina,ArvoreNota *arvoreNota, int matricula){
    if(arvoreNota != NULL){
        if(matricula == arvoreNota->info.codDisciplina){
            printf("Nota da Disciplina: %.2f\n", arvoreNota->info.nota);
            printf("Semestre Cursado: %d\n", arvoreNota->info.semestreCursado);
            mostrarInfoDisciplina(arvoreDisciplina,matricula);
        }else if(matricula < arvoreNota->info.codDisciplina){
            exibirNotaInfoDisciplina(arvoreDisciplina,arvoreNota->esq,matricula);
        }else{
            exibirNotaInfoDisciplina(arvoreDisciplina,arvoreNota->dir,matricula);
        }
    }
}

