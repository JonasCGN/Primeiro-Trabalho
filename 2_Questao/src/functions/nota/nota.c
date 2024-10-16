#include <stdio.h>
#include <stdlib.h>

#include "./nota.h"

void cadastrarNota(ArvoreCurso *arvoreCurso,ListaAluno* listaAluno) {
    Aluno* aluno;
    int matricula;

    printf("Digite a matricula do aluno:");
    scanf("%d", &matricula);

    aluno = alunoMatricula(listaAluno,matricula);
    
    if(aluno){
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

Info* exibirNotaMatricula(ArvoreNota *arvoreNota, int codDisciplina){
    Info* info;
    info = NULL;

    if(arvoreNota){
        if(codDisciplina == arvoreNota->info.codDisciplina){
            info = &arvoreNota->info;
        }else if(codDisciplina < arvoreNota->info.codDisciplina){
            info = exibirNotaMatricula(arvoreNota->esq,codDisciplina);
        }else{
            info = exibirNotaMatricula(arvoreNota->dir,codDisciplina);
        }
    }

    return info;
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

int verificaDisciplinaNotaAlunos(ListaAluno *listaAluno, int codDisciplina){
    int existe = 0;

    if(listaAluno != NULL){
        if(!existe){
            existe = verificaDisciplinaNota(listaAluno->aluno.nota,codDisciplina);
        }else{
            existe = verificaDisciplinaNotaAlunos(listaAluno->prox,codDisciplina);
        }
    }

    return existe;
}

void exibirNotaInfoDisciplina(ArvoreDisciplina *arvoreDisciplina,ArvoreNota *arvoreNota, int codDisciplina){
    Info* info;
    if( (info = exibirNotaMatricula(arvoreNota,codDisciplina))){
        printf("Nota da disciplina: %.2f\n",info->nota);
        mostrarInfoDisciplina(arvoreDisciplina,codDisciplina);
    }else{
        printf("O aluno nao foi matriculado na disciplina!\n");
    }
}