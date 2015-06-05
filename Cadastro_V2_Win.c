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
    char NOME[50];
    char MATRICULA[10];
    int SS;
    int MS;
    int MM;
    int MI;
    int II;
    int SR;
};

struct professor
{
    char NOME[50];
    char MATRICULA[50];
};

struct aluno ALUNO[MAX_ALUNOS];
struct professor PROFESSOR[MAX_PROFESSORES];

int numero_alunos = 0;
int numero_professores = 0;

//Arquivos
FILE *arquivo_alunos;//Arquivo para gravar informações dos alunos cadastrados
FILE *arquivo_professores;//Arquivo para gravar informações dos professores cadastrados

//Função para Importar Dados do Arquivo para Vetor de Structs de Alunos
void IMPORTAR_ALUNOS()
{
    //Abertura do arquivo: "alunos.txt" para leitura e importação dos dados do arquivo
    arquivo_alunos=fopen("alunos.txt","rt");
    if(arquivo_alunos!=NULL)
    {
        while(!feof(arquivo_alunos))
        {
            fscanf(arquivo_alunos,"%s",ALUNO[numero_alunos].NOME);
            fscanf(arquivo_alunos,"%s",ALUNO[numero_alunos].MATRICULA);
            fscanf(arquivo_alunos,"%d",&ALUNO[numero_alunos].SS);
            fscanf(arquivo_alunos,"%d",&ALUNO[numero_alunos].MS);
            fscanf(arquivo_alunos,"%d",&ALUNO[numero_alunos].MM);
            fscanf(arquivo_alunos,"%d",&ALUNO[numero_alunos].MI);
            fscanf(arquivo_alunos,"%d",&ALUNO[numero_alunos].II);
            fscanf(arquivo_alunos,"%d",&ALUNO[numero_alunos].SR);
            numero_alunos++;
        }
        numero_alunos--;
    }
    fclose(arquivo_alunos);
}

//Função para Importar Dados do Arquivo para Vetor de Structs de Professores
void IMPORTAR_PROFESSORES()
{
    //Abertura do arquivo: "professores.txt" para leitura e importação dos dados do arquivo
    arquivo_professores = fopen("professores.txt","rt");
    if(arquivo_professores != NULL)
    {
        while(!feof(arquivo_professores))
        {
            fscanf(arquivo_professores,"%s",PROFESSOR[numero_professores].NOME);
            fscanf(arquivo_professores,"%s",PROFESSOR[numero_professores].MATRICULA);
            numero_professores++;
        }
        numero_professores--;
    }
    fclose(arquivo_professores);
}

void CADASTRAR_ALUNO(void)
{
    system("CLS");
    
    ///Recebendo os dados
    printf("\n\tCadastro de aluno\n");
    
    printf("\nInsira o nome: ");
    scanf("%s", ALUNO[numero_alunos].NOME);
    setbuf(stdin,NULL);
    
    printf("\nInsira a matricula: ");
    scanf("%s", ALUNO[numero_alunos].MATRICULA);
    setbuf(stdin,NULL);
    
    printf("\nInsira a quantidade de SS do aluno: ");
    scanf("%d", &ALUNO[numero_alunos].SS);
    
    printf("\nInsira a quantidade de MS do aluno: ");
    scanf("%d", &ALUNO[numero_alunos].MS);
    
    printf("\nInsira a quantidade de MM do aluno: ");
    scanf("%d", &ALUNO[numero_alunos].MM);
    
    printf("\nInsira a quantidade de MI do aluno: ");
    scanf("%d", &ALUNO[numero_alunos].MI);
    
    printf("\nInsira a quantidade de II do aluno: ");
    scanf("%d", &ALUNO[numero_alunos].II);
    
    printf("\nInsira a quantidade de SR do aluno: ");
    scanf("%d", &ALUNO[numero_alunos].SR);
    
    ///Escrevendo em um arquivo
    printf("\n\nArquivando Dados!");
    
    //Abertura do arquivo para Escrita
    arquivo_alunos = fopen("alunos.txt","a+");
    
    //Exportar dados dos alunos para arquivo
    fprintf(arquivo_alunos,"%s\n",ALUNO[numero_alunos].NOME);
    fprintf(arquivo_alunos,"%s\n",ALUNO[numero_alunos].MATRICULA);
    fprintf(arquivo_alunos,"%d\n",ALUNO[numero_alunos].SS);
    fprintf(arquivo_alunos,"%d\n",ALUNO[numero_alunos].MS);
    fprintf(arquivo_alunos,"%d\n",ALUNO[numero_alunos].MM);
    fprintf(arquivo_alunos,"%d\n",ALUNO[numero_alunos].MI);
    fprintf(arquivo_alunos,"%d\n",ALUNO[numero_alunos].II);
    fprintf(arquivo_alunos,"%d\n",ALUNO[numero_alunos].SR);
    
    //Fechar arquivo
    fclose(arquivo_alunos);
    
    numero_alunos++;
    
    printf("\n\nDados Armazenado com sucesso!\nRetornando ao Menu - Alunos!\n\n");
    
    getch();
}

void VISUALIZAR_ALUNOS()
{
    int i;
    system("cls");
    
    if(numero_alunos>0)
    {
        for(i=0;i<numero_alunos;i++)
        {
            printf("Aluno: %s\nMatricula: %s\nSS:%d\nMS:%d\nMM:%d\nMI:%d\nII:%d\nSR:%d", ALUNO[i].NOME, ALUNO[i].MATRICULA, ALUNO[i].SS, ALUNO[i].MS, ALUNO[i].MM, ALUNO[i].MI, ALUNO[i].II, ALUNO[i].SR);
            printf("\n\n\n");
        }
    }
    else
    {
        printf("Nenhum aluno foi cadastrado");
    }
    
    getch();
}

//Funcao para excluir aluno
void EXCLUIR_ALUNO()
{
    int i;
    int escolha_aluno;
    char escolha;
    system("cls");
    if(numero_alunos>0)
    {
        printf("Digite o numero do aluno que deseja excluir:\n");
        
        //Laço de Repetição para mostrar alunos cadastrados
        for(i=0;i<numero_alunos;i++)
        {
            printf("\nAluno %d:\t\t Nome:%s\t Matricula:%s", i+1, ALUNO[i].NOME, ALUNO[i].MATRICULA);
        }
        
        //Escolha do aluno que sera excluido
        printf("\nAluno ");
        scanf("%d",&escolha_aluno);
        
        //Validação da entrada de dados
        if((escolha_aluno>0)&&(escolha_aluno<=numero_alunos))
        {
            printf("Deseja confirmar exclusao do aluno? (S/N): ");
            setbuf(stdin,NULL);
            scanf("%c",&escolha);
            
            if((escolha=='S') || (escolha=='s'))
            {
                arquivo_alunos=fopen("alunos.txt","wt");
                
                for(i=0;i<numero_alunos-1;i++)
                {
                    if(i >= escolha_aluno-1)
                    {
                        strcpy(ALUNO[i].NOME,ALUNO[i+1].NOME);
                        strcpy(ALUNO[i].MATRICULA,ALUNO[i+1].MATRICULA);
                        ALUNO[i].SS = ALUNO[i+1].SS;
                        ALUNO[i].MS = ALUNO[i+1].MS;
                        ALUNO[i].MM = ALUNO[i+1].MM;
                        ALUNO[i].MI = ALUNO[i+1].MI;
                        ALUNO[i].II = ALUNO[i+1].II;
                        ALUNO[i].SR = ALUNO[i+1].SR;
                    }
                    
                    //Abertura do arquivo para Escrita
                    arquivo_alunos = fopen("alunos.txt","a+");
                    
                    //Exportar dados dos alunos para arquivo
                    fprintf(arquivo_alunos,"%s\n",ALUNO[numero_alunos].NOME);
                    fprintf(arquivo_alunos,"%s\n",ALUNO[numero_alunos].MATRICULA);
                    fprintf(arquivo_alunos,"%d\n",ALUNO[numero_alunos].SS);
                    fprintf(arquivo_alunos,"%d\n",ALUNO[numero_alunos].MS);
                    fprintf(arquivo_alunos,"%d\n",ALUNO[numero_alunos].MM);
                    fprintf(arquivo_alunos,"%d\n",ALUNO[numero_alunos].MI);
                    fprintf(arquivo_alunos,"%d\n",ALUNO[numero_alunos].II);
                    fprintf(arquivo_alunos,"%d\n",ALUNO[numero_alunos].SR);
                    
                    //Fechar arquivo
                    fclose(arquivo_alunos);
                }
                numero_alunos--;
                fclose(arquivo_alunos);
                
                printf("\nAluno excluido com sucesso!");
            }
        }
        else
        {
            printf("Digite um numero valido");
        }
    }
    else
    {
        printf("Nao existem alunos cadastrados!");
    }
    
    getch();
}

void CADASTRAR_PROFESSOR(void)
{
    
    system("CLS");
    
    ///Recebendo os dados
    printf("\n\tCadastro de professor\n");
    
    printf("\nInsira o nome: ");
    scanf("%s", PROFESSOR[numero_professores].NOME);
    setbuf(stdin,NULL);
    
    printf("\nInsira a matricula: ");
    scanf("%s", PROFESSOR[numero_professores].MATRICULA);
    setbuf(stdin,NULL);
    
    ///Escrevendo em um arquivo
    printf("\n\nArquivando Dados!");
    
    //Abertura do arquivo para Escrita
    arquivo_professores = fopen("professores.txt","a+");
    
    //Exportar dados da turma para arquivo
    fprintf(arquivo_professores,"%s\n",PROFESSOR[numero_professores].NOME);
    fprintf(arquivo_professores,"%s\n",PROFESSOR[numero_professores].MATRICULA);
    
    //Fechar arquivo
    fclose(arquivo_professores);
    
    numero_professores++;
    
    printf("\n\nDados Armazenado com sucesso!\nRetornando ao Menu - Professor!\n\n");
    
    getch();
}

void VISUALIZAR_PROFESSOR(void)
{
    
    int i;
    system("cls");
    
    if(numero_professores>0)
    {
        for(i=0;i<numero_professores;i++)
        {
            printf("Professor: %s\nMatricula: %s", PROFESSOR[i].NOME, PROFESSOR[i].MATRICULA);
            printf("\n\n\n");
        }
    }
    else
    {
        printf("Nenhum professor foi cadastrado");
    }
    
    getch();
}

//Funcao para excluir professor
void EXCLUIR_PROFESSOR()
{
    int i;
    int escolha_professor;
    char escolha;
    system("cls");
    if(numero_professores>0)
    {
        printf("Digite o numero do professor que deseja excluir:\n");
        
        //Laço de Repetição para mostrar professores cadastrados
        for(i=0;i<numero_professores;i++)
        {
            printf("\nProfessor %d:\t\t Nome:%s\t Matricula:%s", i+1, PROFESSOR[i].NOME, PROFESSOR[i].MATRICULA);
        }
        
        //Escolha do professor que sera excluido
        printf("\nProfessor ");
        scanf("%d",&escolha_professor);
        
        //Validação da entrada de dados
        if((escolha_professor>0)&&(escolha_professor<=numero_professores))
        {
            printf("Deseja confirmar exclusao do professor? (S/N): ");
            setbuf(stdin,NULL);
            scanf("%c",&escolha);
            
            if((escolha=='S') || (escolha=='s'))
            {
                arquivo_professores=fopen("professores.txt","wt");
                
                for(i=0;i<numero_professores-1;i++)
                {
                    if(i >= escolha_professor-1)
                    {
                        strcpy(PROFESSOR[i].NOME,PROFESSOR[i+1].NOME);
                        strcpy(PROFESSOR[i].MATRICULA,PROFESSOR[i+1].MATRICULA);
                    }
                    
                    //Abertura do arquivo para Escrita
                    arquivo_professores = fopen("professores.txt","a+");
                    
                    //Exportar dados dos professores para arquivo
                    fprintf(arquivo_professores,"%s\n",PROFESSOR[numero_professores].NOME);
                    fprintf(arquivo_professores,"%s\n",PROFESSOR[numero_professores].MATRICULA);
                    
                    //Fechar arquivo
                    fclose(arquivo_professores);
                }
                numero_professores--;
                fclose(arquivo_professores);
                
                printf("\nProfessor excluido com sucesso!");
            }
        }
        else
        {
            printf("Digite um numero valido");
        }
    }
    else
    {
        printf("Nao existem professores cadastrados!");
    }
    
    getch();
}

void MENU_ALUNO(void)
{
    char ESCOLHA_ALUNO;
    do
    {
        system("cls");
        setbuf(stdin,NULL);
        
        printf("\n\t\tM E N U - A L U N O");
        printf("\n\n\tOpcoes:\n");
        printf("\tC - Cadastrar alunos\n");
        printf("\tV - Visualizar cadastros\n");
        printf("\tE - Excluir aluno\n");
        printf("\tR - Retornar ao Menu Principal\n");
        printf("\n   Selecione uma letra: ");
        scanf("%c", &ESCOLHA_ALUNO);
        setbuf(stdin,NULL);
        
        switch(ESCOLHA_ALUNO)
        {
            case 'c':
            case 'C':
                CADASTRAR_ALUNO();
                break;
            case 'v':
            case 'V':
                VISUALIZAR_ALUNOS();
                break;
            case 'e':
            case 'E':
                EXCLUIR_ALUNO();
                break;
            default:
                break;
        }
        
    }while(ESCOLHA_ALUNO != 'r' && ESCOLHA_ALUNO != 'R');
    
}

void MENU_PROFESSOR(void)
{
    char ESCOLHA_PROFESSOR;
    do
    {
        system("cls");
        setbuf(stdin,NULL);
        
        printf("\n\t\tM E N U - P R O F E S S O R");
        printf("\n\n\tOpcoes:\n");
        printf("\tC - Cadastrar professor\n");
        printf("\tV - Visualizar cadastros\n");
        printf("\tE - Excluir professor\n");
        printf("\tR - Retornar ao Menu Principal\n");
        printf("\n   Selecione uma letra: ");
        scanf("%c", &ESCOLHA_PROFESSOR);
        setbuf(stdin,NULL);
        
        switch(ESCOLHA_PROFESSOR)
        {
            case 'c':
            case 'C':
                CADASTRAR_PROFESSOR();
                break;
            case 'v':
            case 'V':
                VISUALIZAR_PROFESSOR();
                break;
            case 'e':
            case 'E':
                EXCLUIR_PROFESSOR();
                break;
            default:
                break;
        }
        
    }while(ESCOLHA_PROFESSOR != 'r' && ESCOLHA_PROFESSOR != 'R');
    
}

int main()
{
    char ESCOLHA_MENU_PRINCIPAL;
    
    //Chamada de funções para importar dados dos arquivos para structs
    IMPORTAR_ALUNOS();
    IMPORTAR_PROFESSORES();
    
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
        
    } while(ESCOLHA_MENU_PRINCIPAL != 'S' && ESCOLHA_MENU_PRINCIPAL != 's');
    return 0;
}
