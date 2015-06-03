#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ALUNOS 100
#define MAX_PROFESSORES 100

void CADASTRAR_ALUNO(void);
void VISUALIZAR_ALUNO(void);
void MENU_ALUNO(void);
void MENU_PROFESSOR(void);
void CADASTRAR_PROFESSOR(void);
void VISUALIZAR_PROFESSOR(void);

struct aluno
{
    char NOME[15];
    char SOBRENOME[20];
    int MATRICULA;
};

struct professor
{
    char NOME[15];
    char SOBRENOME[20];
    int CODIGO;
};

struct aluno ALUNO;
struct professor PROFESSOR;

//struct aluno ALUNO[MAX_ALUNOS];
//struct professor PROFESSOR[MAX_PROFESSORES];

int main()
{
    char ESCOLHA_MENU_PRINCIPAL;
    do
    {
       system("cls");
       printf("\n\t\tM E N U    P R I N C I P A L");
       printf("\n\n\tOpcoes:\n");
       printf("\tA - Menu-Alunos\n");
       printf("\tP - Menu-Professor\n");
       printf("\tS - Sair\n");
       printf("\n   Selecione uma letra: ");
       scanf("%c", &ESCOLHA_MENU_PRINCIPAL);
       setbuf(stdin,NULL);
       switch(ESCOLHA_MENU_PRINCIPAL)
       {
            case 'A':MENU_ALUNO(); break;
            case 'a':MENU_ALUNO(); break;
            case 'P':MENU_PROFESSOR(); break;
            case 'p':MENU_PROFESSOR(); break;
            default: break;
       }

    }while(ESCOLHA_MENU_PRINCIPAL != 'S' && ESCOLHA_MENU_PRINCIPAL != 's');
    return 0;
}

void MENU_ALUNO(void)
{
    char ESCOLHA_ALUNO;
    do
    {
       system("cls");
       printf("\n\t\tM E N U - A L U N O");
       printf("\n\n\tOpcoes:\n");
       printf("\tC - Cadastrar alunos\n");
       printf("\tV - Visualizar cadastros\n");
       printf("\tR - Retornar ao Menu Principal\n");
       printf("\n   Selecione uma letra: ");
       scanf("%c", &ESCOLHA_ALUNO);
       setbuf(stdin,NULL);
       switch(ESCOLHA_ALUNO)
       {
            case 'c':CADASTRAR_ALUNO(); break;
            case 'C':CADASTRAR_ALUNO(); break;
            case 'v':VISUALIZAR_ALUNO(); break;
            case 'V':VISUALIZAR_ALUNO(); break;
            default: break;
       }

    }while(ESCOLHA_ALUNO != 'r' && ESCOLHA_ALUNO != 'R');

};

void MENU_PROFESSOR(void)
{
    char ESCOLHA_PROFESSOR;
    do
    {
       system("cls");
       printf("\n\t\tM E N U - P R O F E S S O R");
       printf("\n\n\tOpcoes:\n");
       printf("\tC - Cadastrar professor\n");
       printf("\tV - Visualizar cadastros\n");
       printf("\tR - Retornar ao Menu Principal\n");
       printf("\n   Selecione uma letra: ");
       scanf("%c", &ESCOLHA_PROFESSOR);
       setbuf(stdin,NULL);
       switch(ESCOLHA_PROFESSOR)
       {
            case 'c':CADASTRAR_PROFESSOR(); break;
            case 'C':CADASTRAR_PROFESSOR(); break;
            case 'v':VISUALIZAR_PROFESSOR(); break;
            case 'V':VISUALIZAR_PROFESSOR(); break;
            default: break;
       }

    }while(ESCOLHA_PROFESSOR != 'r' && ESCOLHA_PROFESSOR != 'R');

};

void CADASTRAR_ALUNO(void)
{

    system("CLS");

    ///Recebendo os dados
    printf("\n\tCadastro de alunos\n");
    printf("\nInsira o nome: ");
    scanf("%s", ALUNO.NOME);
    setbuf(stdin,NULL);
    printf("\nInsira o sobrenome: ");
    scanf("%s", ALUNO.SOBRENOME);
    setbuf(stdin,NULL);
    printf("\nInsira a matricula: ");
    scanf("%d", &ALUNO.MATRICULA);
    setbuf(stdin,NULL);

    char NOME_ARQUIVO[30] = "MATRICULA - ";
    NOME_ARQUIVO[12]=ALUNO.MATRICULA;

    ///Escrevendo em um arquivo
    printf("\n\nArquivando Dados!");
    FILE * Arquivo;
    Arquivo = fopen(NOME_ARQUIVO, "a");
    if(Arquivo==NULL){
        system("CLS");
        printf("\n\tErro de Armazenamento!\n\n");
        system("pause");
        exit(1);
    }

    fprintf(Arquivo, "\nNome completo: %s, ", ALUNO.SOBRENOME);
    fprintf(Arquivo, "%s", ALUNO.NOME);
    fprintf(Arquivo, "\nMatricula: %d", ALUNO.MATRICULA);
    fprintf(Arquivo, "\n\n***************************************\n\n");

    fclose(Arquivo);
    printf("\n\nDados Armazenado com sucesso!\nRetornando ao Menu - Alunos!\n\n");
    system("pause");


};

void VISUALIZAR_ALUNO(void)
{

    system("cls");
    char NOME_ARQUIVO[30]="Matricula - ";
    int matricula;

    printf("Digite a matricula: ");
    scanf("%d", &matricula);

    NOME_ARQUIVO[12]=matricula;

    FILE * Arquivo;
    Arquivo=fopen(NOME_ARQUIVO, "r");
    if(Arquivo==NULL){
        system("CLS");
        printf("\n\nErro de Armazenamento");
        system("pause");
        exit(1);
    }

    char lixo1[5], lixo2[9], lixo3[10];
    fscanf(Arquivo, "%s %s %s %s %s %d", lixo1, lixo2, ALUNO.SOBRENOME, ALUNO.NOME, lixo3, &ALUNO.MATRICULA);

    int tamanho = strlen(ALUNO.SOBRENOME);
    ALUNO.SOBRENOME[tamanho-1]='\0';

    printf("\n\nDados do Aluno: \n");
    printf("\nNome completo: %s %s", ALUNO.NOME, ALUNO.SOBRENOME);
    printf("\nMatricula: %d\n\n", ALUNO.MATRICULA);

    system("pause");
    fclose(Arquivo);
};

void CADASTRAR_PROFESSOR(void)
{

    system("CLS");

    ///Recebendo os dados
    struct professor PROFESSOR;
    printf("\n\tCadastro de professores\n\n");
    printf("\nInsira o nome: ");
    scanf("%s", PROFESSOR.NOME);
    setbuf(stdin,NULL);
    printf("\nInsira o sobrenome: ");
    scanf("%s", PROFESSOR.SOBRENOME);
    setbuf(stdin,NULL);
    printf("\nInsira o codigo do professor: ");
    scanf("%d", &PROFESSOR.CODIGO);
    setbuf(stdin,NULL);

    char NOME_ARQ[20] = "Codigo - ";
    NOME_ARQ[8]=PROFESSOR.CODIGO;

    ///Escrevendo em um arquivo
    printf("\n\nArquivando Dados!");
    FILE * ArquivoProfessor;
    ArquivoProfessor = fopen(NOME_ARQ, "a");
    if(ArquivoProfessor==NULL){
        system("CLS");
        printf("\n\tErro de Armazenamento\n\n");
        system("pause");
        exit(1);
    }

    fprintf(ArquivoProfessor, "\nNome completo: %s, ", PROFESSOR.SOBRENOME);
    fprintf(ArquivoProfessor, "%s", PROFESSOR.NOME);
    fprintf(ArquivoProfessor, "\nCodigo do : %d", PROFESSOR.CODIGO);
    fprintf(ArquivoProfessor, "\n\n***************************************\n\n");

    fclose(ArquivoProfessor);
    printf("\n\nDados Armazenado com sucesso!\nRetornando ao Menu - Professor!\n\n");
    system("pause");

};

void VISUALIZAR_PROFESSOR(void)
{

    system("cls");
    struct professor PROFESSOR;
    char NOME_ARQUIVO[30]="Codigo - ";
    int codigo;

    printf("Digite o codigo do professor: ");
    scanf("%d", &codigo);

    NOME_ARQUIVO[9]=codigo;

    FILE * ArquivoProfessor;
    ArquivoProfessor=fopen(NOME_ARQUIVO, "r");
    if(ArquivoProfessor==NULL){
        system("CLS");
        printf("\n\tErro de Armazenamento\n\n");
        system("pause");
        exit(1);
    }

    char lixo1[5], lixo2[9], lixo3[10];
    fscanf(ArquivoProfessor, "%s %s %s %s %s %d", lixo1, lixo2, PROFESSOR.SOBRENOME, PROFESSOR.NOME, lixo3, &PROFESSOR.CODIGO);

    int tamanho = strlen(PROFESSOR.SOBRENOME);
    PROFESSOR.SOBRENOME[tamanho-1]='\0';

    printf("\n\nDados do professor: \n");
    printf("\nNome completo: %s %s", PROFESSOR.NOME, PROFESSOR.SOBRENOME);
    printf("\nCodigo: %d\n\n", PROFESSOR.CODIGO);

    system("pause");
    fclose(ArquivoProfessor);
}
