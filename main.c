#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ALUNOS 100
#define MAX_PROFESSORES 100
#define MAX_TURMA 100

void incluir_aluno(void);
void menu_aluno(void);
void menu_professor(void);
void cadastrar_professor(void);
void visualizar_professores(void);

struct ALUNO
{
    char nome[50];
    char matricula[10];
    int idade;
    char telefone[12];
    char celular[12];
    char endereco[30];
    float ira;
};

struct PROFESSOR
{
    char nome[50];
    char matricula[10];
    int idade;
    char telefone[12];
    char celular[12];
    char endereco[30];
};

struct TURMA
{
    char nome[50];
    char codigo[10];
    char numero_turma[3];
    struct PROFESSOR* professor;
    struct ALUNO* alunos[50];
};

struct ALUNO aluno[MAX_ALUNOS];
struct PROFESSOR professor[MAX_PROFESSORES];
struct TURMA turma[MAX_TURMA];

int numero_alunos = 0;
int numero_professores = 0;
int numero_turmas = 0;

//Arquivos
FILE *arquivo_alunos;//Arquivo para gravar informações dos alunos cadastrados
FILE *arquivo_professores;//Arquivo para gravar informações dos professores cadastrados
FILE *arquivo_turmas;//Arquivo para gravar informações das turmas cadastrados

//Função para Importar Dados do Arquivo para Vetor de Structs de Alunos
void importar_alunos()
{
    //Abertura do arquivo: "alunos.txt" para leitura e importação dos dados do arquivo
    arquivo_alunos=fopen("alunos.txt","rt");
    if(arquivo_alunos != NULL)
    {
        while(!feof(arquivo_alunos))
        {
            fscanf(arquivo_alunos,"%s",aluno[numero_alunos].nome);
            fscanf(arquivo_alunos,"%s",aluno[numero_alunos].matricula);
            fscanf(arquivo_alunos,"%d",&aluno[numero_alunos].idade);
            fscanf(arquivo_alunos,"%s",aluno[numero_alunos].telefone);
            fscanf(arquivo_alunos,"%s",aluno[numero_alunos].celular);
            fscanf(arquivo_alunos,"%s",aluno[numero_alunos].endereco);
            fscanf(arquivo_alunos,"%f",&aluno[numero_alunos].ira);
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
            fscanf(arquivo_professores,"%s",professor[numero_professores].nome);
            fscanf(arquivo_professores,"%s",professor[numero_professores].matricula);
            fscanf(arquivo_professores,"%d",&professor[numero_professores].idade);
            fscanf(arquivo_professores,"%s",professor[numero_professores].telefone);
            fscanf(arquivo_professores,"%s",professor[numero_professores].celular);
            fscanf(arquivo_professores,"%s",professor[numero_professores].endereco);
            numero_professores++;
        }
        numero_professores--;
    }
    fclose(arquivo_professores);
}

//Função para exportar aluno para arquivo
void escrever_arquivo_aluno()
{
    //Abertura do arquivo para Escrita
    arquivo_alunos = fopen("alunos.txt","a+");
    
    //Exportar dados dos alunos para arquivo
    fprintf(arquivo_alunos,"%s\n",aluno[numero_alunos].nome);
    fprintf(arquivo_alunos,"%s\n",aluno[numero_alunos].matricula);
    fprintf(arquivo_alunos,"%d\n",aluno[numero_alunos].idade);
    fprintf(arquivo_alunos,"%s\n",aluno[numero_alunos].telefone);
    fprintf(arquivo_alunos,"%s\n",aluno[numero_alunos].celular);
    fprintf(arquivo_alunos,"%s\n",aluno[numero_alunos].endereco);
    fprintf(arquivo_alunos,"%f\n",aluno[numero_alunos].ira);
    
    //Fechar arquivo
    fclose(arquivo_alunos);
}

//Função para exportar professor para arquivo
void escrever_arquivo_professor()
{
    //Abertura do arquivo para Escrita
    arquivo_professores = fopen("professores.txt","a+");
    
    //Exportar dados da turma para arquivo
    fprintf(arquivo_professores,"%s\n",professor[numero_professores].nome);
    fprintf(arquivo_professores,"%s\n",professor[numero_professores].matricula);
    fprintf(arquivo_professores,"%d\n",professor[numero_professores].idade);
    fprintf(arquivo_professores,"%s\n",professor[numero_professores].telefone);
    fprintf(arquivo_professores,"%s\n",professor[numero_professores].celular);
    fprintf(arquivo_professores,"%s\n",professor[numero_professores].endereco);
    
    //Fechar arquivo
    fclose(arquivo_professores);
}

//Função para incluir aluno no arquivo de alunos
void incluir_aluno()
{
    system("CLS");
    
    ///Recebendo os dados
    printf("\n\tCadastro de aluno\n");
    
    printf("\nNome: ");
    scanf("%s", aluno[numero_alunos].nome);
    setbuf(stdin,NULL);
    
    printf("\nMatricula: ");
    scanf("%s", aluno[numero_alunos].matricula);
    setbuf(stdin,NULL);
    
    printf("\nIdade: ");
    scanf("%d", &aluno[numero_alunos].idade);
    
    printf("\nTelefone: ");
    scanf("%s", aluno[numero_alunos].telefone);
    setbuf(stdin,NULL);
    
    printf("\nCelular: ");
    scanf("%s", aluno[numero_alunos].celular);
    setbuf(stdin,NULL);
    
    printf("\nEndereco: ");
    scanf("%s", aluno[numero_alunos].endereco);
    setbuf(stdin,NULL);
    
    printf("\nIRA: ");
    scanf("%f", &aluno[numero_alunos].ira);
    
    ///Escrevendo em um arquivo
    printf("\n\nArquivando Dados!");
    
    escrever_arquivo_aluno();
    
    numero_alunos++;
    
    printf("\n\nDados Armazenado com sucesso!\nRetornando ao Menu - Alunos!\n\n");
}

//Função para incluir professor no arquivo de professores
void incluir_professor()
{
    
    system("CLS");
    
    ///Recebendo os dados
    printf("\n\tCadastro de professor\n");
    
    printf("\nInsira o nome: ");
    scanf("%s", professor[numero_professores].nome);
    setbuf(stdin,NULL);
    
    printf("\nInsira a matricula: ");
    scanf("%s", professor[numero_professores].matricula);
    setbuf(stdin,NULL);
    
    printf("\nIdade: ");
    scanf("%d", &professor[numero_professores].idade);
    
    printf("\nTelefone: ");
    scanf("%s", professor[numero_professores].telefone);
    setbuf(stdin,NULL);
    
    printf("\nCelular: ");
    scanf("%s", professor[numero_professores].celular);
    setbuf(stdin,NULL);
    
    printf("\nEndereco: ");
    scanf("%s", professor[numero_professores].endereco);
    setbuf(stdin,NULL);
    
    ///Escrevendo em um arquivo
    printf("\n\nArquivando Dados!");
    
    escrever_arquivo_professor();
    
    numero_professores++;
    
    printf("\n\nDados Armazenado com sucesso!\nRetornando ao Menu - Professor!\n\n");
    
    //getch();
}

//Função para consultar um aluno dentre os alunos cadastrados
void consultar_aluno()
{
    
}

//Função para consultar um professor dentre os professores cadastrados
void consultar_professor()
{
    
}

//Função para alterar um aluno dentre os alunos cadastrados
void alterar_aluno()
{
    
}

//Função para alterar um professor dentre os professores cadastrados
void alterar_professor()
{
    
}

//Função para listar todos alunos cadastrados
void visualizar_alunos()
{
    int i;
    system("cls");
    
    if(numero_alunos>0)
    {
        for(i=0;i<numero_alunos;i++)
        {
            printf("Aluno: %s\nMatricula: %s\nIdade:%d\nTelefone:%s\nCelular:%s\nEndereco:%s\nIRA:%.4f", aluno[i].nome, aluno[i].matricula, aluno[i].idade, aluno[i].telefone, aluno[i].celular, aluno[i].endereco, aluno[i].ira);
            printf("\n\n\n");
        }
    }
    else
    {
        printf("Nenhum aluno foi cadastrado");
    }
    
    //getch();
}

//Função para listar todos professores cadastrados
void visualizar_professores()
{
    
    int i;
    system("cls");
    
    if(numero_professores>0)
    {
        for(i=0;i<numero_professores;i++)
        {
            printf("Professor: %s\nMatricula: %s\nIdade:%d\nTelefone:%s\nCelular:%s\nEndereco:%s", professor[i].nome, professor[i].matricula, professor[i].idade, professor[i].telefone, professor[i].celular, professor[i].endereco);
            printf("\n\n\n");
        }
    }
    else
    {
        printf("Nenhum professor foi cadastrado");
    }
    
    //getch();
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
            printf("\nAluno %d:\t\t Nome:%s\t Matricula:%s", i+1, aluno[i].nome, aluno[i].matricula);
        }
        
        //Escolha do aluno que sera excluido
        printf("\nAluno ");
        scanf("%d",&escolha_aluno);
        
        //Validação da entrada de dados
        if((escolha_aluno>0) && (escolha_aluno<=numero_alunos))
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
                        strcpy(aluno[i].nome,aluno[i+1].nome);
                        strcpy(aluno[i].matricula,aluno[i+1].matricula);
                        aluno[i].idade = aluno[i+1].idade;
                        strcpy(aluno[i].telefone,aluno[i+1].telefone);
                        strcpy(aluno[i].celular,aluno[i+1].celular);
                        strcpy(aluno[i].endereco,aluno[i+1].endereco);
                        aluno[i].ira = aluno[i+1].ira;
                    }
                    
                    escrever_arquivo_aluno();
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
    
    //getch();
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
            printf("\nProfessor %d:\t\t Nome:%s\t Matricula:%s", i+1, professor[i].nome, professor[i].matricula);
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
                        strcpy(professor[i].nome,professor[i+1].nome);
                        strcpy(professor[i].matricula,professor[i+1].matricula);
                        professor[i].idade = professor[i+1].idade;
                        strcpy(professor[i].telefone,professor[i+1].telefone);
                        strcpy(professor[i].celular,professor[i+1].celular);
                        strcpy(professor[i].endereco,professor[i+1].endereco);
                    }
                    
                    escrever_arquivo_professor();
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
    
    //getch();
}

//Visualizar opcoes do menu de aluno
void menu_aluno()
{
    int escolha;
    do
    {
        system("cls");
        setbuf(stdin,NULL);
        
        printf("\n\t\tC A D A S T R O - A L U N O");
        printf("\n\n\tOpcoes:\n");
        printf("\t1 - Incluir\n");
        printf("\t2 - Consultar\n");
        printf("\t3 - Alterar\n");
        printf("\t4 - Excluir\n");
        printf("\t5 - Listar\n");
        printf("\t6 - Retornar ao Menu Principal\n");
        printf("\n   Selecione uma letra: ");
        scanf("%d", &escolha);
        setbuf(stdin,NULL);
        
        switch(escolha)
        {
            case 1:
                incluir_aluno();
                break;
            case 2:
                consultar_aluno();
                break;
            case 3:
                alterar_aluno();
                break;
            case 4:
                excluir_aluno();
                break;
            case 5:
                visualizar_alunos();
                break;
            case 6:
                break;
            default:
                printf("Opcao nao e valida! Digite um numero entre 1 e 6.");
                break;
        }
        
    } while(escolha != 6);
    
}

//Visualizar opcoes do menu de professor
void menu_professor()
{
    int escolha;
    do
    {
        system("cls");
        setbuf(stdin,NULL);
        
        printf("\n\t\tC A D A S T R O - P R O F E S S O R");
        printf("\n\n\tOpcoes:\n");
        printf("\t1 - Incluir\n");
        printf("\t2 - Consultar\n");
        printf("\t3 - Alterar\n");
        printf("\t4 - Excluir\n");
        printf("\t5 - Listar\n");
        printf("\t6 - Retornar ao Menu Principal\n");
        printf("\n   Selecione uma opção: ");
        scanf("%d", &escolha);
        setbuf(stdin,NULL);
        
        switch(escolha)
        {
            case 1:
                incluir_professor();
                break;
            case 2:
                consultar_professor();
                break;
            case 3:
                alterar_professor();
                break;
            case 4:
                excluir_professor();
                break;
            case 5:
                visualizar_professores();
                break;
            case 6:
                break;
            default:
                printf("Opcao nao e valida! Digite um numero entre 1 e 6.");
                break;
        }
        
    } while(escolha != 6);
    
}

//Visualizar opcoes do menu de turma
void menu_turma()
{
    int escolha;
    do
    {
        system("cls");
        setbuf(stdin,NULL);
        
        printf("\n\t\tC A D A S T R O - T U R M A");
        printf("\n\n\tOpcoes:\n");
        printf("\t1 - Incluir\n");
        printf("\t2 - Consultar\n");
        printf("\t3 - Alterar\n");
        printf("\t4 - Excluir\n");
        printf("\t5 - Listar\n");
        printf("\t6 - Retornar ao Menu Principal\n");
        printf("\n   Selecione uma opção: ");
        scanf("%d", &escolha);
        setbuf(stdin,NULL);
        
        switch(escolha)
        {
            case 1:
                //incluir_professor();
                break;
            case 2:
                //consultar_professor();
                break;
            case 3:
                //alterar_professor();
                break;
            case 4:
                //excluir_professor();
                break;
            case 5:
                //visualizar_professores();
                break;
            case 6:
                break;
            default:
                printf("Opcao nao e valida! Digite um numero entre 1 e 6.");
                break;
        }
        
    } while(escolha != 6);
    
}

int main()
{
    int escolha_menu;
    
    //Chamada de funções para importar dados dos arquivos para structs
    importar_alunos();
    importar_professores();
    
    do
    {
        system("cls");
        printf("\n\t\tM E N U    P R I N C I P A L");
        printf("\n\n\tOpcoes:\n");
        printf("\t1 - Cadastro Alunos\n");
        printf("\t2 - Cadastro Professor\n");
        printf("\t3 - Cadastro Turma\n");
        printf("\t4 - Sair\n");
        printf("\n   Selecione uma letra: ");
        scanf("%d", &escolha_menu);
        setbuf(stdin,NULL);
        
        switch(escolha_menu)
        {
            case 1:
                menu_aluno();
                break;
            case 2:
                menu_professor();
                break;
            case 3:
                menu_turma();
                break;
            case 4:
                break;
            default:
                printf("Opcao nao e valida! Digite um numero entre 1 e 3.");
                break;
        }
        
    } while(escolha_menu != 4);
    
    return 0;
}
