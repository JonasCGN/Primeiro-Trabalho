#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tempo.h"

#define TESTE 30
#define QTDINSERCAO 1000

#define QTDINFO 1000
#define QTDBUSCA 1200

static void limpaCurso(ArvoreCurso *raiz){
    if (raiz){
        limpaCurso(raiz->esq);
        limpaCurso(raiz->dir);
        free(raiz);
    }
}

static double verificaCrescenteCurso(ArvoreCurso *arvoreTeste, Curso *curso){
    clock_t inicio, fim;
    double tempo_gasto,tempo_total=0;


    for(int i=0;i < QTDINSERCAO;i++){
        inicio = clock();
    
        inserirCurso(&arvoreTeste,curso[i]);
    
        fim = clock();
        
        tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
        tempo_total += tempo_gasto;

    }

    limpaCurso(arvoreTeste);
    return tempo_total;
}

static double verificaDecrescenteCurso(ArvoreCurso *arvoreTeste, Curso *curso){
    clock_t inicio, fim;
    double tempo_gasto,tempo_total=0;

    for(int i = QTDINSERCAO - 1;0 <= i;i--){
        inicio = clock();

        inserirCurso(&arvoreTeste,curso[i]);

        fim = clock();

        tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
        tempo_total += tempo_gasto;

    }

    limpaCurso(arvoreTeste);
    return tempo_total;
}

static void vetIntAleatorioSemRepeticaoCurso(Curso **vetor){
    for (int i = 0; i < QTDINSERCAO; i++){
        int num = rand() % (QTDINSERCAO * 2);
        int j = 0;

        int isRepetido = 0;
        for (j = 0; j < i && !isRepetido; j++)
        if ((*vetor)[j].codCurso == num)
            isRepetido = 1;

        if (!isRepetido)
        (*vetor)[i].codCurso = num;
        else
        i--;
    }
}

static double verificaAleatorioCurso(ArvoreCurso *arvoreTeste, Curso *curso){
    clock_t inicio, fim;
    double tempo_gasto,tempo_total=0;

    vetIntAleatorioSemRepeticaoCurso(&curso);

    for(int i = 0;i < QTDINSERCAO;i++){
        inicio = clock();
        inserirCurso(&arvoreTeste,curso[i]);
        fim = clock();

        tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
        tempo_total += tempo_gasto;
    }

    limpaCurso(arvoreTeste);

    return tempo_total;
}

void verificaTempoInsercao(){
    ArvoreCurso *arvoreTeste;
    arvoreTeste = NULL;

    double tempo_gasto,tempo_total=0;
    srand((unsigned int)time(NULL));

    Curso *curso;
    curso = (Curso*)malloc(((size_t)QTDINSERCAO) * sizeof(Curso) );

    for(int i=0;i<QTDINSERCAO;i++){
        curso[i].codCurso = i + 1;
    }

    printf("Teste de insercao crescente\n");
    for(int i=0;i < TESTE;i++){
        tempo_gasto = verificaCrescenteCurso(arvoreTeste,curso);
        printf("Duracao do %d teste: %lf\n",i+1,tempo_gasto);
        tempo_total += tempo_gasto;
    }
    printf("A duracao total foi de: %lf\n",  tempo_total);
    printf("A media foi de: %lf\n",  tempo_total / TESTE);
    
    tempo_total = 0;

    printf("Teste de insercao decrescente\n");
    for(int i=0;i < TESTE;i++){
        tempo_gasto = verificaDecrescenteCurso(arvoreTeste,curso);
        printf("Duracao do %d teste: %lf\n",i+1,tempo_gasto);
        tempo_total += tempo_gasto;
    }
    printf("A duracao total foi de: %lf\n",  tempo_total);
    printf("A media foi de: %lf\n",  tempo_total / TESTE);

    tempo_total = 0;

    printf("Teste de insercao aleatoria\n");
    for(int i=0;i < TESTE;i++){
        tempo_gasto = verificaAleatorioCurso(arvoreTeste,curso);
        printf("Duracao do %d teste: %lf\n",i+1,tempo_gasto);
        tempo_total += tempo_gasto;
    }
    printf("A duracao total foi de: %lf\n",  tempo_total);
    printf("A media foi de: %lf\n",  tempo_total / TESTE);

    free(curso);
}

static double verificaCrescenteNota(ArvoreNota *arvoreTeste, ArvoreDisciplina *arvoreDisciplina,Info *info,Disciplina *disciplina){
    clock_t inicio, fim;
    double tempo_gasto,tempo_total=0;
    
    for(int i=0;i < QTDINFO;i++){
        inserirNota(&arvoreTeste,info[i]);
        inserirDisciplina(&arvoreDisciplina,disciplina[i]);
    }

    for(int i=0;i < QTDBUSCA;i++){
        inicio = clock();
    
        exibirNotaMatricula(arvoreTeste,info[i].codDisciplina);
        verificaDisciplina(arvoreDisciplina,info[i].codDisciplina);

        fim = clock();
        
        tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
        tempo_total += tempo_gasto;

    }
    
    liberarNotas(arvoreTeste);
    liberarDisciplinas(arvoreDisciplina);

    return tempo_total;
}

static double verificaDecrescenteNota(ArvoreNota *arvoreTeste,ArvoreDisciplina *arvoreDisciplina, Info *info,Disciplina *disciplina){
    clock_t inicio, fim;
    double tempo_gasto,tempo_total=0;
    
    for(int i=0;i < QTDINFO;i++){
        inserirNota(&arvoreTeste,info[i]);
        inserirDisciplina(&arvoreDisciplina,disciplina[i]);
    }

    for(int i = QTDBUSCA - 1;0 <= i;i--){
        inicio = clock();
        exibirNotaMatricula(arvoreTeste,info[i].codDisciplina);
        verificaDisciplina(arvoreDisciplina,info[i].codDisciplina);
        fim = clock();  

        tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
        tempo_total += tempo_gasto;
    }
    
    liberarNotas(arvoreTeste);
    liberarDisciplinas(arvoreDisciplina);

    return tempo_total;
}

static void vetIntAleatorioSemRepeticaoNota(Info **vetor,Disciplina **disciplina){
    for (int i = 0; i < QTDINFO; i++){
        int num = rand() % (QTDINFO * 2);
        int j = 0;

        int repetido = 0;
        for (j = 0; j < i && !repetido; j++)
            if ((*vetor)[j].codDisciplina == num)
                repetido = 1;

        if (!repetido){
            (*vetor)[i].codDisciplina = num;
            (*disciplina)[i].codDisciplina = num;
        }
        else
            i--;
    }
}

static double verificaAleatorioNota(ArvoreNota *arvoreTeste,ArvoreDisciplina *arvoreDisciplina, Info *info,Disciplina *disciplina){
    clock_t inicio, fim;
    double tempo_gasto,tempo_total=0;

    vetIntAleatorioSemRepeticaoNota(&info,&disciplina);
    
    for(int i=0;i < QTDINFO;i++){
        inserirNota(&arvoreTeste,info[i]);
        inserirDisciplina(&arvoreDisciplina,disciplina[i]);
    }

    for(int i = 0;i < QTDBUSCA;i++){
        inicio = clock();
        exibirNotaMatricula(arvoreTeste,info[i].codDisciplina);
        verificaDisciplina(arvoreDisciplina,info[i].codDisciplina);
        fim = clock();  

        tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
        tempo_total += tempo_gasto;
    }

    liberarNotas(arvoreTeste);
    liberarDisciplinas(arvoreDisciplina);

    return tempo_total;
}

void verificaTempoBusca(){
    ArvoreNota *arvoreTeste;
    arvoreTeste = NULL;
    ArvoreDisciplina *arvoreDisciplina;
    arvoreDisciplina = NULL;
    
    double tempo_gasto,tempo_total=0;
    
    Info *info;
    info = (Info*)malloc(((size_t)QTDINFO) * sizeof(Info));

    Disciplina *disciplina;
    disciplina = (Disciplina*)malloc(((size_t)QTDINFO) * sizeof(Disciplina));

    for(int i=0;i < QTDINFO;i++){
        info[i].codDisciplina = i + 1;
        disciplina[i].codDisciplina = i + 1;
    }

    printf("Teste de busca crescente\n");
    for(int i=0;i < TESTE;i++){
        tempo_gasto = verificaCrescenteNota(arvoreTeste,arvoreDisciplina,info,disciplina);
        printf("Duracao do %d teste: %lf\n",i+1,tempo_gasto);
        tempo_total += tempo_gasto;
    }
    printf("A duracao total foi de: %lf\n",  tempo_total);
    printf("A media foi de: %lf\n",  tempo_total / TESTE);

    tempo_total=0;

    printf("Teste de busca decrescente\n");
    for(int i=0;i < TESTE;i++){
        tempo_gasto = verificaDecrescenteNota(arvoreTeste,arvoreDisciplina,info,disciplina);
        printf("Duracao do %d teste: %lf\n",i+1,tempo_gasto);
        tempo_total += tempo_gasto;
    }
    printf("A duracao total foi de: %lf\n",  tempo_total);
    printf("A media foi de: %lf\n",  tempo_total / TESTE);

    tempo_total=0;

    printf("Teste de busca aleatoria\n");
    for(int i=0;i < TESTE;i++){
        tempo_gasto = verificaAleatorioNota(arvoreTeste,arvoreDisciplina,info,disciplina);
        printf("Duracao do %d teste: %lf\n",i+1,tempo_gasto);
        tempo_total += tempo_gasto;
    }
    printf("A duracao total foi de: %lf\n",  tempo_total);
    printf("A media foi de: %lf\n",  tempo_total / TESTE);

    free(disciplina);
    free(info);
}