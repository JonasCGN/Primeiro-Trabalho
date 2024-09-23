#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct no{
    int num;
    struct no* esq;
    struct no* dir;
}No;


void inserirValor(No **no, int num){
    if(*no == NULL){
        No *novo = (No*)malloc(sizeof(No));
        
        novo->num = num;
        novo->esq = NULL;
        novo->dir = NULL;

        *no = novo;
    }else{
        if(num < (*no)->num){
            inserirValor(&(*no)->esq,num);
        }else{
            inserirValor(&(*no)->dir,num);
        }
    }
}

No* verificaCurso(No *arvoreCurso, int codCurso){
    No* exist;
    exist = NULL;

    if(arvoreCurso != NULL){
        if(arvoreCurso->num == codCurso){
            exist = arvoreCurso;
        }else{
            exist = verificaCurso(arvoreCurso->esq,codCurso);

            if(!exist){
                exist = verificaCurso(arvoreCurso->dir,codCurso);
            }
        }
    }

    return exist;
}

/*

int folhaArvore(No *arvoreMatricula){
    return (arvoreMatricula->esq == NULL && arvoreMatricula->dir == NULL) ? 1 : 0;
}

No *filhoArvore(No *arvoreMatricula){
    No *filho;

    if(arvoreMatricula->dir != NULL){
        filho = arvoreMatricula->dir;
    }else if(arvoreMatricula->esq != NULL){
        filho = arvoreMatricula->esq;
    } 

    return filho;
}



No* paiFilho(No *no,No **filho, int codDisciplina){
    No *aux;
    aux = NULL;

    if(no != NULL){
        
        if(no->num == codDisciplina){
            aux = no;
            // printf("%p - %p\n",filho,&no);
        }else if(codDisciplina < no->num){
            aux = paiFilho(no->esq,filho,codDisciplina);
        }else{
            aux = paiFilho(no->dir,filho,codDisciplina);
        }

        if(
            (aux) && 
            (no->dir == aux || (no->esq == aux))
        ){
            *filho = no;
        }
    }

    return aux;
}

int removerDisciplinaMatricula(No** raiz, int codDisciplina) {
    int removido = 1;

    if ((*raiz) != NULL) {  
        No *aux;
        No *filho;
        aux = NULL;
        filho = NULL;   

        filho = paiFilho((*raiz),&aux, codDisciplina);

        if(aux){
            printf("Pai = %d - %p\n",aux->num,&aux);
        }
        if(filho){
            printf("Filho = %d - %p\n",filho->num,&filho);
            if(folhaArvore(filho)){
                printf("Sou folha\n");
                if(aux){
                    if(){

                    }else{

                    }
                }else{

                }
                free(filho);

            }else if(filho->dir != NULL && filho->esq != NULL){
                printf("Menor a Direita: %d\n", menorDireita(filho->dir,&aux)->num);
            }else{
                printf("Filho: %d\n", filhoArvore(filho)->num);
            }
        }else{
            removido = 0;
        }
        
    }
    
    return removido;

}

*/

No* menorDireita(No *no,No **filho){
    No *aux;
    aux = NULL;

    if(no != NULL){
        aux = menorDireita(no->esq,filho);
        if(!aux){
            aux = no;
            *filho = no->dir;
        }
    }

    return aux;
}

void exibirArvore(No *arvoreCurso){
    if(arvoreCurso != NULL){
        printf("%d ", arvoreCurso->num);
        exibirArvore(arvoreCurso->esq);
        exibirArvore(arvoreCurso->dir);
    }else{
        printf("Nada ");
    }
}

int main(){

    No *arvore;

    arvore = NULL;

    inserirValor(&arvore,7);
    inserirValor(&arvore,3);
    inserirValor(&arvore,10);
    inserirValor(&arvore,9);
    inserirValor(&arvore,8);
    inserirValor(&arvore,11);
    // inserirValor(&arvore,7);
    // inserirValor(&arvore,10);

    printf("Remove = %d\n",removerDisciplinaMatricula(&arvore,3));

    int n=11;

    if(verificaCurso(arvore,n)){
        printf("%d\n", verificaCurso(arvore,n)->num);
    }

    exibirArvore(arvore);

    return 0;
}