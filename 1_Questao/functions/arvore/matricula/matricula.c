#include <stdio.h>
#include <stdlib.h>

#include "./matricula.h"

/*Tudo foi flávio*/
int inserirMatricula(ArvoreMatricula** raiz, int codDisciplina) {
    int insere = 1;

    if (raiz == NULL) {
        ArvoreMatricula* novaMatricula = (ArvoreMatricula*) malloc(sizeof(ArvoreMatricula));
        novaMatricula->codDisciplina = codDisciplina;
        novaMatricula->esq = novaMatricula->dir = NULL;

        *raiz = novaMatricula;
    }else{
        if (codDisciplina < (*raiz)->codDisciplina)
            insere = inserirMatricula(&((*raiz)->esq), codDisciplina);
        else if (codDisciplina > (*raiz)->codDisciplina)
            inserirMatricula(&((*raiz)->dir), codDisciplina);
        else
            insere = 0;
    }

    return insere;
}

/*
- Folha
- Filho
- 2 Filho
*/

int removerDisciplinaMatricula(ArvoreMatricula** raiz, int codDisciplina) {
    int removido = 1;

    if ((*raiz) != NULL) {  

        if((*raiz)->codDisciplina == codDisciplina){


            if(folhaArvore(*raiz)){
                
            }else if((*raiz)->esq != NULL || (*raiz)->dir != NULL){
                
                filho = filhoArvore(*raiz);
                aux = filho;

            }else{
                aux = menorDireita((*raiz)->dir,&filho);
            }

        }else if(codDisciplina < (*raiz)->codDisciplina){
            removido = removerDisciplinaMatricula((*raiz)->esq,codDisciplina);
        }else if(codDisciplina > (*raiz)->codDisciplina){
            removido = removerDisciplinaMatricula((*raiz)->dir,codDisciplina);
        }else{
            removido = 0;
        }
    
    }
    
    return removido;

}

int folhaArvore(ArvoreMatricula *arvoreMatricula){
    return (arvoreMatricula->esq == arvoreMatricula->dir == NULL) ? 1 : 0;
}

ArvoreMatricula *filhoArvore(ArvoreMatricula *arvoreMatricula){
    ArvoreMatricula *filho;

    if(arvoreMatricula->dir != NULL){
        filho = arvoreMatricula->dir;
    }else if(arvoreMatricula->esq != NULL){
        filho = arvoreMatricula->esq;
    } 

    return filho;
}

ArvoreMatricula* menorDireita(ArvoreMatricula *arvoreMatricula,ArvoreMatricula **filho){
    ArvoreMatricula *aux;
    aux = arvoreMatricula;

    if(arvoreMatricula != NULL){
        aux = menorDireita(arvoreMatricula->esq,filho);
        filho = &(arvoreMatricula->dir);
    }

    return aux;
}

ArvoreMatricula* paiFilho(ArvoreMatricula *arvoreMatricula,ArvoreMatricula **filho, int codDisciplina){
    ArvoreMatricula *aux;
    aux = arvoreMatricula;

    if(arvoreMatricula != NULL){
        if(arvoreMatricula->codDisciplina == codDisciplina){
            aux = arvoreMatricula;
            filho = &arvoreMatricula;
        }else if(codDisciplina > arvoreMatricula->codDisciplina){
            aux = menorDireita(arvoreMatricula->esq,filho,codDisciplina);
        }else{
            aux = menorDireita(arvoreMatricula->dir,filho,codDisciplina);
        }
    }

    return aux;
}