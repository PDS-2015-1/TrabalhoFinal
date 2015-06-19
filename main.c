#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ALUNOS 100
#define MAX_PROFESSORES 100
#define MAX_DISCIPLINA 100

void cadastrar_aluno(void);
void menu_aluno(void);
void menu_professor(void);
void cadastrar_professor(void);
void visualizar_professores(void);

struct ALUNO
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

struct PROFESSOR
{
    char NOME[50];
    char MATRICULA[50];
    
};

struct DISCIPLINA
{
    char NOME[50];
    char MATRICULA[50];
    
};

struct ALUNO aluno[MAX_ALUNOS];
struct PROFESSOR professor[MAX_PROFESSORES];
struct DISCIPLINA disciplina[MAX_DISCIPLINA];

int numero_alunos = 0;
int numero_professores = 0;
int numero_disciplinas = 0;

//Arquivos
FILE *arquivo_alunos;//Arquivo para gravar informações dos alunos cadastrados
FILE *arquivo_professores;//Arquivo para gravar informações dos professores cadastrados
FILE *arquivo_displinas;//Arquivo para gravar informações das disciplinas cadastrados

//Função para Importar Dados do Arquivo para Vetor de Structs de Alunos
void importar_alunos()
{
    //Abertura do arquivo: "alunos.txt" para leitura e importação dos dados do arquivo
    arquivo_alunos=fopen("alunos.txt","rt");
    if(arquivo_alunos!=NULL)
    {
        while(!feof(arquivo_alunos))
        {
            fscanf(arquivo_alunos,"%s",aluno[numero_alunos].NOME);
            fscanf(arquivo_alunos,"%s",aluno[numero_alunos].MATRICULA);
            fscanf(arquivo_alunos,"%d",&aluno[numero_alunos].SS);
            fscanf(arquivo_alunos,"%d",&aluno[numero_alunos].MS);
            fscanf(arquivo_alunos,"%d",&aluno[numero_alunos].MM);
            fscanf(arquivo_alunos,"%d",&aluno[numero_alunos].MI);
            fscanf(arquivo_alunos,"%d",&aluno[numero_alunos].II);
            fscanf(arquivo_alunos,"%d",&aluno[numero_alunos].SR);
            numero_alunos++;
        }
        numero_alunos--;
    }
    fclose(arquivo_alunos);
}

//Função para Importar Dados do Arquivo para Vetor de Structs de Professores
void importar_professores()
{
    //Abertura do arquivo: "professores.txt" para leitura e importação dos dados do arquivo
    arquivo_professores = fopen("professores.txt","rt");
    if(arquivo_professores != NULL)
    {
        while(!feof(arquivo_professores))
        {
            fscanf(arquivo_professores,"%s",professor[numero_professores].NOME);
            fscanf(arquivo_professores,"%s",professor[numero_professores].MATRICULA);
            numero_professores++;
        }
        numero_professores--;
    }
    fclose(arquivo_professores);
}

void cadastrar_aluno(void)
{
    system("CLS");
    
    ///Recebendo os dados
    printf("\n\tCadastro de aluno\n");
    
    printf("\nInsira o nome: ");
    scanf("%s", aluno[numero_alunos].NOME);
    setbuf(stdin,NULL);
    
    printf("\nInsira a matricula: ");
    scanf("%s", aluno[numero_alunos].MATRICULA);
    setbuf(stdin,NULL);
    
    printf("\nInsira a quantidade de SS do aluno: ");
    scanf("%d", &aluno[numero_alunos].SS);
    
    printf("\nInsira a quantidade de MS do aluno: ");
    scanf("%d", &aluno[numero_alunos].MS);
    
    printf("\nInsira a quantidade de MM do aluno: ");
    scanf("%d", &aluno[numero_alunos].MM);
    
    printf("\nInsira a quantidade de MI do aluno: ");
    scanf("%d", &aluno[numero_alunos].MI);
    
    printf("\nInsira a quantidade de II do aluno: ");
    scanf("%d", &aluno[numero_alunos].II);
    
    printf("\nInsira a quantidade de SR do aluno: ");
    scanf("%d", &aluno[numero_alunos].SR);
    
    ///Escrevendo em um arquivo
    printf("\n\nArquivando Dados!");
    
    //Abertura do arquivo para Escrita
    arquivo_alunos = fopen("alunos.txt","a+");
    
    //Exportar dados dos alunos para arquivo
    fprintf(arquivo_alunos,"%s\n",aluno[numero_alunos].NOME);
    fprintf(arquivo_alunos,"%s\n",aluno[numero_alunos].MATRICULA);
    fprintf(arquivo_alunos,"%d\n",aluno[numero_alunos].SS);
    fprintf(arquivo_alunos,"%d\n",aluno[numero_alunos].MS);
    fprintf(arquivo_alunos,"%d\n",aluno[numero_alunos].MM);
    fprintf(arquivo_alunos,"%d\n",aluno[numero_alunos].MI);
    fprintf(arquivo_alunos,"%d\n",aluno[numero_alunos].II);
    fprintf(arquivo_alunos,"%d\n",aluno[numero_alunos].SR);
    
    //Fechar arquivo
    fclose(arquivo_alunos);
    
    numero_alunos++;
    
    printf("\n\nDados Armazenado com sucesso!\nRetornando ao Menu - Alunos!\n\n");
}

void visualizar_alunos()
{
    int i;
    system("cls");
    
    if(numero_alunos>0)
    {
        for(i=0;i<numero_alunos;i++)
        {
            printf("Aluno: %s\nMatricula: %s\nSS:%d\nMS:%d\nMM:%d\nMI:%d\nII:%d\nSR:%d", aluno[i].NOME, aluno[i].MATRICULA, aluno[i].SS, aluno[i].MS, aluno[i].MM, aluno[i].MI, aluno[i].II, aluno[i].SR);
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
void excluir_aluno()
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
            printf("\nAluno %d:\t\t Nome:%s\t Matricula:%s", i+1, aluno[i].NOME, aluno[i].MATRICULA);
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
                        strcpy(aluno[i].NOME,aluno[i+1].NOME);
                        strcpy(aluno[i].MATRICULA,aluno[i+1].MATRICULA);
                        aluno[i].SS = aluno[i+1].SS;
                        aluno[i].MS = aluno[i+1].MS;
                        aluno[i].MM = aluno[i+1].MM;
                        aluno[i].MI = aluno[i+1].MI;
                        aluno[i].II = aluno[i+1].II;
                        aluno[i].SR = aluno[i+1].SR;
                    }
                    
                    //Abertura do arquivo para Escrita
                    arquivo_alunos = fopen("alunos.txt","a+");
                    
                    //Exportar dados dos alunos para arquivo
                    fprintf(arquivo_alunos,"%s\n",aluno[numero_alunos].NOME);
                    fprintf(arquivo_alunos,"%s\n",aluno[numero_alunos].MATRICULA);
                    fprintf(arquivo_alunos,"%d\n",aluno[numero_alunos].SS);
                    fprintf(arquivo_alunos,"%d\n",aluno[numero_alunos].MS);
                    fprintf(arquivo_alunos,"%d\n",aluno[numero_alunos].MM);
                    fprintf(arquivo_alunos,"%d\n",aluno[numero_alunos].MI);
                    fprintf(arquivo_alunos,"%d\n",aluno[numero_alunos].II);
                    fprintf(arquivo_alunos,"%d\n",aluno[numero_alunos].SR);
                    
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

void cadastrar_professor(void)
{
    
    system("CLS");
    
    ///Recebendo os dados
    printf("\n\tCadastro de professor\n");
    
    printf("\nInsira o nome: ");
    scanf("%s", professor[numero_professores].NOME);
    setbuf(stdin,NULL);
    
    printf("\nInsira a matricula: ");
    scanf("%s", professor[numero_professores].MATRICULA);
    setbuf(stdin,NULL);
    
    ///Escrevendo em um arquivo
    printf("\n\nArquivando Dados!");
    
    //Abertura do arquivo para Escrita
    arquivo_professores = fopen("professores.txt","a+");
    
    //Exportar dados da turma para arquivo
    fprintf(arquivo_professores,"%s\n",professor[numero_professores].NOME);
    fprintf(arquivo_professores,"%s\n",professor[numero_professores].MATRICULA);
    
    //Fechar arquivo
    fclose(arquivo_professores);
    
    numero_professores++;
    
    printf("\n\nDados Armazenado com sucesso!\nRetornando ao Menu - Professor!\n\n");
    
    getch();
}

void visualizar_professores(void)
{
    
    int i;
    system("cls");
    
    if(numero_professores>0)
    {
        for(i=0;i<numero_professores;i++)
        {
            printf("Professor: %s\nMatricula: %s", professor[i].NOME, professor[i].MATRICULA);
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
void excluir_professor()
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
            printf("\nProfessor %d:\t\t Nome:%s\t Matricula:%s", i+1, professor[i].NOME, professor[i].MATRICULA);
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
                arquivo_professores = fopen("professores.txt","wt");
                
                for(i=0;i<numero_professores-1;i++)
                {
                    if(i >= escolha_professor-1)
                    {
                        strcpy(professor[i].NOME,professor[i+1].NOME);
                        strcpy(professor[i].MATRICULA,professor[i+1].MATRICULA);
                    }
                    
                    //Abertura do arquivo para Escrita
                    arquivo_professores = fopen("professores.txt","a+");
                    
                    //Exportar dados dos professores para arquivo
                    fprintf(arquivo_professores,"%s\n",professor[numero_professores].NOME);
                    fprintf(arquivo_professores,"%s\n",professor[numero_professores].MATRICULA);
                    
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

void menu_aluno()
{
    int escolha;
    do
    {
        system("cls");
        setbuf(stdin,NULL);
        
        printf("\n\t\tC A D A S T R O - A L U N O");
        printf("\n\n\tOpcoes:\n");
        printf("\t1 - Cadastrar alunos\n");
        printf("\t2 - Visualizar cadastros\n");
        printf("\t3 - Excluir aluno\n");
        printf("\t6 - Retornar ao Menu Principal\n");
        printf("\n   Selecione uma letra: ");
        scanf("%d", &escolha);
        setbuf(stdin,NULL);
        
        switch(escolha)
        {
            case 1:
                cadastrar_aluno();
                break;
            case 2:
                visualizar_alunos();
                break;
            case 'e':
            case 'E':
                excluir_aluno();
                break;
            default:
                break;
        }
        
    }while(escolha != 0);
    
}

void menu_professor()
{
    char escolha;
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
        scanf("%c", &escolha);
        setbuf(stdin,NULL);
        
        switch(escolha)
        {
            case 'c':
            case 'C':
                cadastrar_professor();
                break;
            case 'v':
            case 'V':
                visualizar_professores();
                break;
            case 'e':
            case 'E':
                excluir_professor();
                break;
            default:
                break;
        }
        
    }while(escolha != 'r' && escolha != 'R');
    
}

int main()
{
    char ESCOLHA_MENU_PRINCIPAL;
    
    //Chamada de funções para importar dados dos arquivos para structs
    importar_alunos();
    importar_professores();
    
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
            case 'A':menu_aluno(); break;
            case 'a':menu_aluno(); break;
            case 'P':menu_professor(); break;
            case 'p':menu_professor(); break;
            default: break;
        }
        
    } while(ESCOLHA_MENU_PRINCIPAL != 'S' && ESCOLHA_MENU_PRINCIPAL != 's');
    return 0;
}
