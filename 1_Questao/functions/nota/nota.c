#include <stdio.h>
#include <stdlib.h>

#include "./nota.h"

//Flavio
void cadastrarNota(Aluno* aluno, int codDisciplina, float nota) {

    if (buscarDisciplinaNaMatricula(aluno->matriculaDisciplina, codDisciplina)) {

        inserirNota(&(aluno->nota), codDisciplina, nota);
        
        aluno->matriculaDisciplina = removerDisciplinaMatricula(aluno->matriculaDisciplina, codDisciplina);
        
        printf("Nota cadastrada com sucesso para a disciplina %d!\n", codDisciplina);
    } else {
        printf("Erro: Disciplina %d não está matriculada!\n", codDisciplina);
    }
}

void exibirInfoNota(Info info){
    printf("Codigo Disciplina: %.2f\n", info.codDisciplina);
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

void exibirNotaMatricula(ArvoreNota *arvoreNota, int codDisciplina){
    if(arvoreNota != NULL){
        if(codDisciplina == arvoreNota->info.codDisciplina){
            printf("Nota da Disciplina: %d\n", arvoreNota->info.nota);
        }else if(codDisciplina < arvoreNota->info.codDisciplina){
            exibirNotaMatricula(arvoreNota->esq,codDisciplina);
        }else{
            exibirNotaMatricula(arvoreNota->dir,codDisciplina);
        }
    }
}

void exibirNotaInfoDisciplina(ArvoreDisciplina *arvoreDisciplina,ArvoreNota *arvoreNota, int matricula){
    if(arvoreNota != NULL){
        if(matricula == arvoreNota->info.codDisciplina){
            printf("Nota da Disciplina: %d\n", arvoreNota->info.nota);
            printf("Semestre Cursado: %d\n", arvoreNota->info.semestreCursado);
            mostrarInfoDisciplina(arvoreDisciplina,matricula);
        }else if(matricula < arvoreNota->info.codDisciplina){
            exibirNotaInfoDisciplina(arvoreDisciplina,arvoreNota->esq,matricula);
        }else{
            exibirNotaInfoDisciplina(arvoreDisciplina,arvoreNota->dir,matricula);
        }
    }
}

