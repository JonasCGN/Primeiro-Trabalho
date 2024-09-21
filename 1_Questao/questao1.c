#include "./struct/arvore_matricula.h"
#include "./struct/lista_aluno.h"
#include <stdio.h>
#include <stdlib.h>

ArvoreMatricula* inserirMatricula(ArvoreMatricula* raiz, int codDisciplina) {
    if (raiz == NULL) {
        ArvoreMatricula* novaMatricula = (ArvoreMatricula*) malloc(sizeof(ArvoreMatricula));
        novaMatricula->codDisciplina = codDisciplina;
        novaMatricula->esq = novaMatricula->dir = NULL;
        return novaMatricula;
    }

    if (codDisciplina < raiz->codDisciplina)
        raiz->esq = inserirMatricula(raiz->esq, codDisciplina);
    else if (codDisciplina > raiz->codDisciplina)
        raiz->dir = inserirMatricula(raiz->dir, codDisciplina);

    return raiz;
}

int buscarDisciplinaNaMatricula(ArvoreMatricula* raiz, int codDisciplina) {
    if (raiz == NULL) return 0; 

    if (raiz->codDisciplina == codDisciplina) return 1; 

    if (codDisciplina < raiz->codDisciplina)
        return buscarDisciplinaNaMatricula(raiz->esq, codDisciplina);
    else
        return buscarDisciplinaNaMatricula(raiz->dir, codDisciplina);
}

void cadastrarMatricula(Aluno* aluno, int codDisciplina) {
    if (buscarDisciplinaNaMatricula(aluno->matriculas, codDisciplina)) {
        printf("Erro: Disciplina %d já está cadastrada!\n", codDisciplina);
        return;
    }
    aluno->matriculas = inserirMatricula(aluno->matriculas, codDisciplina);
}

void mostrarMatriculas(ArvoreMatricula* raiz) {
    if (raiz != NULL) {
        mostrarMatriculas(raiz->esq);
        printf("Disciplina: %d\n", raiz->codDisciplina);
        mostrarMatriculas(raiz->dir);
    }
}

void cadastrarNota(Aluno* aluno, int codDisciplina, float nota) {

    if (buscarDisciplinaNaMatricula(aluno->matriculas, codDisciplina)) {

        aluno->nota = inserirNota(aluno->nota, codDisciplina, nota);
        
        aluno->matriculas = removerDisciplinaMatricula(aluno->matriculas, codDisciplina);
        
        printf("Nota cadastrada com sucesso para a disciplina %d!\n", codDisciplina);
    } else {
        printf("Erro: Disciplina %d não está matriculada!\n", codDisciplina);
    }
}

ArvoreNota* inserirNota(ArvoreNota* raiz, int codDisciplina, float nota) {
    if (raiz == NULL) {
        ArvoreNota* novaNota = (ArvoreNota*) malloc(sizeof(ArvoreNota));
        novaNota->codDisciplina = codDisciplina;
        novaNota->nota = nota;
        novaNota->esq = novaNota->dir = NULL;
        return novaNota;
    }

    if (codDisciplina < raiz->codDisciplina)
        raiz->esq = inserirNota(raiz->esq, codDisciplina, nota);
    else if (codDisciplina > raiz->codDisciplina)
        raiz->dir = inserirNota(raiz->dir, codDisciplina, nota);
    
    return raiz;
}

ArvoreMatricula* removerDisciplinaMatricula(ArvoreMatricula* raiz, int codDisciplina) {
    if (raiz != NULL) {  // Alterado para if (raiz != NULL)
        if (codDisciplina < raiz->codDisciplina) {
            raiz->esq = removerDisciplinaMatricula(raiz->esq, codDisciplina);
        } else if (codDisciplina > raiz->codDisciplina) {
            raiz->dir = removerDisciplinaMatricula(raiz->dir, codDisciplina);
        } else {
            // Caso em que encontramos a disciplina
            if (raiz->esq == NULL) {
                ArvoreMatricula* temp = raiz->dir;
                free(raiz);
                return temp;
            } else if (raiz->dir == NULL) {
                ArvoreMatricula* temp = raiz->esq;
                free(raiz);
                return temp;
            }

            // Encontrar o menor valor na subárvore direita
        
        }
    }

    return raiz;
}
void menu() {
    int opcao;

    do {
        printf("\n======== MENU PRINCIPAL ========\n");
        printf("1. Cadastrar Curso\n");
        printf("2. Cadastrar Aluno\n");
        printf("3. Cadastrar Disciplina\n");
        printf("4. Cadastrar Matricula\n");
        printf("5. Cadastrar Nota\n");
        printf("6. Mostrar Alunos de um Curso\n");
        printf("7. Mostrar Todos os Cursos do Campus\n");
        printf("8. Mostrar Disciplinas de um Curso\n");
        printf("9. Mostrar Disciplinas de um Período de um Curso\n");
        printf("10. Mostrar Disciplinas Matriculadas de um Aluno\n");
        printf("11. Mostrar Notas de um Período de um Aluno\n");
        printf("12. Mostrar Nota de uma Disciplina de um Aluno\n");
        printf("13. Remover Disciplina de um Curso\n");
        printf("14. Remover Disciplina de Matricula de um Aluno\n");
        printf("15. Mostrar Histórico de um Aluno\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            case 7:
                
                break;
            case 8:
                
                break;
            case 9:
                
                break;
            case 10:
                
                break;
            case 11:
                
                break;
            case 12:
                
                break;
            case 13:
                
                break;
            case 14:
                
                break;
            case 15:
                
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while(opcao != 0);
}





int main() {
    Aluno aluno;  
    aluno.matriculas = NULL;  

    cadastrarMatricula(&aluno, 101);
    cadastrarMatricula(&aluno, 202);
    cadastrarMatricula(&aluno, 303);

    printf("Disciplinas matriculadas:\n");
    mostrarMatriculas(aluno.matriculas); 

    cadastrarNota(&aluno, 101, 9.5);
    cadastrarNota(&aluno, 202, 8.0);

    printf("Disciplinas restantes após cadastro de notas:\n");
    mostrarMatriculas(aluno.matriculas);

    printf("Notas cadastradas:\n");
    mostrarNotas(aluno.nota);



    return 0;
}
