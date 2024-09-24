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

// No* verificaCurso(No *arvoreCurso, int codCurso){
//     No* exist;
//     exist = NULL;

//     if(arvoreCurso != NULL){
//         if(arvoreCurso->num == codCurso){
//             exist = arvoreCurso;
//         }else{
//             exist = verificaCurso(arvoreCurso->esq,codCurso);

//             if(!exist){
//                 exist = verificaCurso(arvoreCurso->dir,codCurso);
//             }
//         }
//     }

//     return exist;
// }

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

int removerDisciplinaMatricula(No **m, int cod){
    int existe = 0;

    if((*m)){

        if(cod == (*m)->num){
            existe = 1;

            No *aux = *m;
            if((*m)->esq == NULL && (*m)->dir == NULL){
                free(aux);
                *m = NULL;
            }
            /* Só tem o filho da esquerda */
            else if((*m)->dir == NULL){
                (*m) = (*m)->esq;
                aux->esq = NULL;
                free(aux);
                aux = NULL;
            }
            /* Só tem o filho da direita */
            else if((*m)->esq == NULL){
                (*m) = (*m)->dir;
                aux->dir = NULL;
                free(aux);
                aux = NULL;
            }
            /* O nó mais a esquerda da sub-árvore à direita */
            else {
                No *menor;
                No *no;
                menor = (*m)->dir;
                no = NULL;
                
                while(menor->esq != NULL){
                    no = menor;
                    menor = menor->esq;
                }
                
                if(no){
                    no->esq = menor->dir;
                }else{
                    (*m)->dir = menor->dir;
                }

                (*m)->num = menor->num;
                free(menor);
            }
        }else if(cod < (*m)->num)
            existe = removerDisciplinaMatricula(&(*m)->esq, cod);
        else
            existe = removerDisciplinaMatricula(&(*m)->dir, cod);
    }

    return existe;
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

int verificaCurso(No *arvoreCurso, int codCurso){
    int exist = 0;

    if(arvoreCurso != NULL){
        if(arvoreCurso->num == codCurso){
            exist = 1;
        }else if(codCurso < arvoreCurso->num){
            exist = verificaCurso(arvoreCurso->esq,codCurso);
        }else if(codCurso > arvoreCurso->num){
            exist = verificaCurso(arvoreCurso->dir,codCurso);
        }
    }

    return exist;
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
    inserirValor(&arvore,2);
    inserirValor(&arvore,12);
    // inserirValor(&arvore,7);
    // inserirValor(&arvore,10);

    exibirArvore(arvore);
    printf("\n");
    printf("Remove = %d\n",removerDisciplinaMatricula(&arvore,7));

    // int n=11;

    // if(verificaCurso(arvore,n)){
    //     printf("%d\n", verificaCurso(arvore,n));
    // }

    exibirArvore(arvore);

    return 0;
}