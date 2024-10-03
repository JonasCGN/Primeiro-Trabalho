#include <stdio.h>
#include <stdlib.h>

#include "./functions/cabecario.h"

void menu() {
    ArvoreCurso *arvoreCurso;
    ListaAluno *listaAluno;
    arvoreCurso = NULL;
    listaAluno = NULL;

    int opcao,periodo,opc,matricula,codDisciplina;
    Aluno* aluno;

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
        // printf("16 - Mostrar lista aaluno\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        setbuf(stdin,NULL);

        switch(opcao) {
            case 1:
                cadastraCurso(&arvoreCurso);
                break;
            case 2:
                cadastrarAluno(&listaAluno,arvoreCurso);
                break;
            case 3:
                cadastrarDisciplina(&arvoreCurso);
                break;
            case 4:
                printf("Digite a matricula do aluno:");
                scanf("%d",&opc);

                aluno = alunoMatricula(listaAluno,opc);
                if(aluno){
                    cadastrarMatricula(arvoreCurso,aluno);
                }
                break;
            case 5:
                cadastrarNota(arvoreCurso,listaAluno);
                break;
            case 6:
                mostrarAlunoCurso(listaAluno);
                break;
            case 7:
                mostrarTodosCursos(arvoreCurso);
                break;
            case 8:

                printf("Digite o codigo do curso:");
                scanf("%d", &opc);

                mostrarDisciplinasCurso(arvoreCurso,opc);
                break;
            case 9:

                printf("Digite o codigo do curso:");
                scanf("%d", &opc);

                printf("Digite o periodo do curso:");
                scanf("%d", &periodo);
 
                mostraDisciplinaPeriodoCurso(arvoreCurso,opc, periodo);
                break;
            case 10:

                printf("Digite  a matricula do aluno:");
                scanf("%d", &matricula);

                aluno = alunoMatricula(listaAluno,matricula);
                if(aluno){
                    mostrarDisciplinaAluno(arvoreCurso,*aluno);
                }else{
                    printf("Aluno nao entrado!\n");
                }

                break;
            case 11:
                printf("Digite  a matricula do aluno:");
                scanf("%d", &matricula);

                aluno = alunoMatricula(listaAluno,matricula);
                if(aluno){
                    printf("Digite o periodo do curso:");
                    scanf("%d", &periodo);

                    exibirNotasPeriodo(aluno->nota,periodo);
                }
                break;
            case 12:
                printf("Digite  a matricula do aluno:");
                scanf("%d", &matricula);

                aluno = alunoMatricula(listaAluno,matricula);
                if(aluno){
                    printf("Digite a o codigo da disicplina:");
                    scanf("%d", &codDisciplina);
                    ArvoreDisciplina* disciplinas = retornaCursoCod(arvoreCurso,aluno->codigoCurso)->disciplina;

                    exibirNotaInfoDisciplina(disciplinas,aluno->nota,codDisciplina);
                }else{
                    printf("Aluno nao esta matriculado!\n");
                }

                break;
            case 13:
                removerDisciplinaCurso(arvoreCurso,listaAluno);
                break;
            case 14:
                removerMatricula(listaAluno);
                break;
            case 15:
                printf("Digite  a matricula do aluno:");
                scanf("%d", &matricula);

                aluno = alunoMatricula(listaAluno,matricula);
                if(aluno){
                    historicoAluno(arvoreCurso,*aluno);
                }
                break;
            // case 16:

            //     exibirListaAluno(listaAluno);
            //     break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while(opcao != 0);

    liberarTudo(listaAluno,arvoreCurso);
}

int main() {
    
    menu();
    
    verificaTempoInsercao();
    verificaTempoBusca();

    getchar();
    
    return 0;
}
