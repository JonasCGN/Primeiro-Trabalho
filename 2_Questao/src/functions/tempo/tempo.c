#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tempo.h"

#define TESTE 30
#define QTDINSERCAO 1000

#define QTDINFO 50
#define QTDBUSCA 75

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
    liberarCursos(arvoreTeste);

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

    liberarCursos(arvoreTeste);
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

    liberarCursos(arvoreTeste);

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

static double verificaCrescenteNota(ArvoreNota *arvoreTeste, Info *info){
    clock_t inicio, fim;
    double tempo_gasto,tempo_total=0;


    for(int i=0;i < QTDBUSCA;i++){
        inicio = clock();
    
        inserirNota(&arvoreTeste,info[i]);
    
        fim = clock();
        
        tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
        tempo_total += tempo_gasto;

    }
    liberarNotas(arvoreTeste);

    return tempo_total;
}

static double verificaDecrescenteNota(ArvoreNota *arvoreTeste, Info *info){
    clock_t inicio, fim;
    double tempo_gasto,tempo_total=0;

    for(int i = QTDBUSCA - 1;0 <= i;i--){
        inicio = clock();
        inserirNota(&arvoreTeste,info[i]);
        fim = clock();

        tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
        tempo_total += tempo_gasto;

    }

    liberarNotas(arvoreTeste);
    return tempo_total;
}

static void vetIntAleatorioSemRepeticaoNota(Info **vetor){
    for (int i = 0; i < QTDBUSCA; i++){
        int num = rand() % (QTDBUSCA * 2);
        int j = 0;

        int isRepetido = 0;
        for (j = 0; j < i && !isRepetido; j++)
        if ((*vetor)[j].codDisciplina == num)
            isRepetido = 1;

        if (!isRepetido)
        (*vetor)[i].codDisciplina = num;
        else
        i--;
    }
}

static double verificaAleatorioNota(ArvoreNota *arvoreTeste, Info *info){
    clock_t inicio, fim;
    double tempo_gasto,tempo_total=0;

    vetIntAleatorioSemRepeticaoNota(&info);

    for(int i = 0;i < QTDBUSCA;i++){
        inicio = clock();
        inserirNota(&arvoreTeste,info[i]);
        fim = clock();

        tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
        tempo_total += tempo_gasto;
    }

    liberarNotas(arvoreTeste);

    return tempo_total;
}

void verificaTempoBusca(){
    ArvoreNota *arvoreTeste;
    arvoreTeste = NULL;

    double tempo_gasto,tempo_total=0;
    srand((unsigned int)time(NULL));

    Info *info;
    info = (Info*)malloc(((size_t)QTDINFO) * sizeof(Info) );

    for(int i=0;i < QTDINFO;i++){
        info[i].codDisciplina = i + 1;
    }

    printf("Teste de busca crescente\n");
    for(int i=0;i < TESTE;i++){
        tempo_gasto = verificaCrescenteNota(arvoreTeste,info);
        printf("Duracao do %d teste: %lf\n",i+1,tempo_gasto);
        tempo_total += tempo_gasto;
    }
    printf("A duracao total foi de: %lf\n",  tempo_total);
    printf("A media foi de: %lf\n",  tempo_total / TESTE);
    
    tempo_total = 0;

    printf("Teste de busca decrescente\n");
    for(int i=0;i < TESTE;i++){
        tempo_gasto = verificaDecrescenteNota(arvoreTeste,info);
        printf("Duracao do %d teste: %lf\n",i+1,tempo_gasto);
        tempo_total += tempo_gasto;
    }
    printf("A duracao total foi de: %lf\n",  tempo_total);
    printf("A media foi de: %lf\n",  tempo_total / TESTE);

    tempo_total = 0;

    printf("Teste de busca aleatoria\n");
    for(int i=0;i < TESTE;i++){
        tempo_gasto = verificaAleatorioNota(arvoreTeste,info);
        printf("Duracao do %d teste: %lf\n",i+1,tempo_gasto);
        tempo_total += tempo_gasto;
    }
    printf("A duracao total foi de: %lf\n",  tempo_total);
    printf("A media foi de: %lf\n",  tempo_total / TESTE);

    free(info);

}