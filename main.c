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
    char disciplina[50];
    char codigo[10];
    char numero_turma[3];
    struct PROFESSOR* professor;
    int numero_alunos;
    struct ALUNO* alunos[50];
};

struct ALUNO aluno[MAX_ALUNOS];
struct PROFESSOR professor[MAX_PROFESSORES];
struct TURMA turma[MAX_TURMA];

int numero_alunos = 0;
int numero_professores = 0;
int numero_turmas = 0;
int numero_alunos_turmas = 0;

//Arquivos
FILE *arquivo_alunos;//Arquivo para gravar informações dos alunos cadastrados
FILE *arquivo_professores;//Arquivo para gravar informações dos professores cadastrados
FILE *arquivo_turmas;//Arquivo para gravar informações das turmas cadastrados
FILE *arquivo_alunos_turmas;//Arquivo para gravar informações dos alunos cadastrados nas turmas

//Nome dos Arquivos
char nome_arquivo_alunos[30] = "alunos.txt";
char nome_arquivo_professores[30] = "professores.txt";
char nome_arquivo_turmas[30] = "turmas.txt";
char nome_arquivo_alunos_turmas[30] = "alunos_turmas.txt";

//Função para Importar Dados do Arquivo para Vetor de Structs de Alunos
void importar_alunos()
{
    //Abertura do arquivo: "alunos.txt" para leitura e importação dos dados do arquivo
    arquivo_alunos=fopen(nome_arquivo_alunos,"rt");
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
    //Abertura do arquivo: nome_arquivo_professores para leitura e importação dos dados do arquivo
    arquivo_professores = fopen(nome_arquivo_professores,"rt");
    if(arquivo_professores != NULL)
    {
        while(!feof(arquivo_professores))
        {
            fscanf(arquivo_professores,"%s,",professor[numero_professores].nome);
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

//Função para Importar Dados do Arquivo para Vetor de Structs de Turmas
void importar_turmas()
{
    //Abertura do arquivo: nome_arquivo_turmas para leitura e importação dos dados do arquivo
    arquivo_turmas = fopen(nome_arquivo_turmas,"rt");
    if(arquivo_turmas != NULL)
    {
        while(!feof(arquivo_turmas))
        {
            fscanf(arquivo_turmas,"%s",turma[numero_turmas].disciplina);
            fscanf(arquivo_turmas,"%s",turma[numero_turmas].codigo);
            fscanf(arquivo_turmas,"%s",turma[numero_turmas].numero_turma);
            fscanf(arquivo_turmas,"%s",turma[numero_turmas].professor->matricula);
            fscanf(arquivo_turmas,"%d",&turma[numero_turmas].numero_alunos);
            numero_turmas++;
        }
        numero_turmas--;
    }
    fclose(arquivo_turmas);
}

//Função para Importar Dados do Arquivo para Vetor de Structs de Alunos das Turmas
void importar_alunos_turmas()
{
    //Abertura do arquivo: nome_arquivo_alunos_turmas para leitura e importação dos dados do arquivo
    arquivo_alunos_turmas = fopen(nome_arquivo_alunos_turmas,"rt");
    if(arquivo_alunos_turmas != NULL)
    {
        while(!feof(arquivo_alunos_turmas))
        {
            char codigo_disciplina[10];
            char numero_turma[3];
            
            fscanf(arquivo_alunos_turmas,"%s",codigo_disciplina);
            fscanf(arquivo_alunos_turmas,"%s",numero_turma);
            int i = 0;
            for(i=0;i<numero_turmas;i++)
            {
                if((turma[i].codigo == codigo_disciplina)&&(turma[i].numero_turma == numero_turma))
                {
                    break;
                }
            }
            fscanf(arquivo_alunos_turmas,"%s",turma[i].alunos[numero_alunos_turmas]->matricula);
            numero_alunos_turmas++;
        }
        numero_alunos_turmas--;
    }
    fclose(arquivo_alunos_turmas);
}

//Função para esperar o usuario digitar uma letra para prosseguir com a execução do programa
void digitar_letra()
{
    getch();
}

//Função para exportar aluno para arquivo
void escrever_arquivo_aluno()
{
    //Abertura do arquivo para Escrita
    arquivo_alunos = fopen(nome_arquivo_alunos,"a+");
    
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
    arquivo_professores = fopen(nome_arquivo_professores,"a+");
    
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

//Função para exportar turma para arquivo
void escrever_arquivo_turma()
{
    //Abertura do arquivo para Escrita
    arquivo_turmas = fopen(nome_arquivo_turmas,"a+");
    
    //Exportar dados da turma para arquivo
    fprintf(arquivo_turmas,"%s\n",turma[numero_turmas].disciplina);
    fprintf(arquivo_turmas,"%s\n",turma[numero_turmas].codigo);
    fprintf(arquivo_turmas,"%s\n",turma[numero_turmas].numero_turma);
    fprintf(arquivo_turmas,"%s\n",turma[numero_turmas].professor->matricula);
    fprintf(arquivo_turmas,"%d\n",turma[numero_turmas].numero_alunos);
    
    //Fechar arquivo
    fclose(arquivo_turmas);
}

//Função para exportar alunos das turmas para arquivo
void escrever_arquivo_alunos_turma()
{
    //Abertura do arquivo para Escrita
    arquivo_alunos_turmas = fopen(nome_arquivo_alunos_turmas,"a+");
    
    //Exportar dados da turma para arquivo
    fprintf(arquivo_alunos_turmas,"%s\n",turma[numero_turmas].codigo);
    fprintf(arquivo_alunos_turmas,"%s\n",turma[numero_turmas].numero_turma);
    fprintf(arquivo_alunos_turmas,"%s\n",turma[numero_turmas].alunos[numero_alunos_turmas]->matricula);
    
    //Fechar arquivo
    fclose(arquivo_turmas);
}

//Função para incluir aluno no arquivo de alunos
void incluir_aluno()
{
    int procura = 0, i;
    char strconsulta[50];
    
    system("CLS");
    
    ///Recebendo os dados
    printf("\n\tIncluir aluno\n");
    
    do
    {
        printf("\nNome: ");
        fflush(stdin);
        gets(strconsulta);
        setbuf(stdin,NULL);
        
        //Validação do nome
        for(i=0;i<numero_alunos;i++)
        {
            if(strcmp(strconsulta,aluno[i].nome) == 0)
            {
                procura++;
            }
        }
        if(procura==1)
        {
            printf("\nOutro aluno cadastrado ja possui esse nome.\nInsira outro nome!");
        }
        else
        {
            strcpy(aluno[numero_alunos].nome,strconsulta);
        }
    }while((strconsulta[0]=='\0')||(procura!=0));
    
    do
    {
        fflush(stdin);
        printf("\nMatricula: ");
        gets(strconsulta);
        setbuf(stdin,NULL);
        
        //Validação da matricula
        for(i=0;i<numero_alunos;i++)
        {
            if(strcmp(strconsulta,aluno[i].matricula) == 0)
            {
                procura++;
            }
        }
        if(procura==1)
        {
            printf("\nOutro aluno cadastrado ja possui essa matricula.\nInsira outra matricula!");
        }
        else
        {
            strcpy(aluno[numero_alunos].matricula,strconsulta);
        }
    }while((strconsulta[0]=='\0')||(procura!=0));
    
    fflush(stdin);
    printf("\nIdade: ");
    scanf("%d", &aluno[numero_alunos].idade);
    
    fflush(stdin);
    setbuf(stdin,NULL);
    printf("\nTelefone: ");
    gets(aluno[numero_alunos].telefone);
    setbuf(stdin,NULL);
    
    fflush(stdin);
    printf("\nCelular: ");
    gets(aluno[numero_alunos].celular);
    setbuf(stdin,NULL);
    
    fflush(stdin);
    printf("\nEndereco: ");
    gets(aluno[numero_alunos].endereco);
    setbuf(stdin,NULL);
    
    fflush(stdin);
    setbuf(stdin,NULL);
    printf("\nIRA: ");
    scanf("%f", &aluno[numero_alunos].ira);
    
    ///Escrevendo em um arquivo
    printf("\n\nArquivando Dados . . .");
    
    escrever_arquivo_aluno();
    
    numero_alunos++;
    
    printf("\n\nDados armazenados com sucesso!\nRetornando ao Menu - Alunos!\n\n");
}

//Função para incluir professor no arquivo de professores
void incluir_professor()
{
    
    system("CLS");
    
    ///Recebendo os dados
    printf("\n\tIncluir professor\n");
    
    printf("\nNome: ");
    gets(professor[numero_professores].nome);
    setbuf(stdin,NULL);
    
    fflush(stdin);
    printf("\nMatricula: ");
    gets(professor[numero_professores].matricula);
    setbuf(stdin,NULL);
    
    fflush(stdin);
    printf("\nIdade: ");
    scanf("%d", &professor[numero_professores].idade);
    
    fflush(stdin);
    setbuf(stdin,NULL);
    printf("\nTelefone: ");
    gets(professor[numero_professores].telefone);
    setbuf(stdin,NULL);
    
    fflush(stdin);
    printf("\nCelular: ");
    gets(professor[numero_professores].celular);
    setbuf(stdin,NULL);
    
    fflush(stdin);
    printf("\nEndereco: ");
    gets(professor[numero_professores].endereco);
    setbuf(stdin,NULL);
    
    ///Escrevendo em um arquivo
    printf("\n\nArquivando Dados . . .");
    
    escrever_arquivo_professor();
    
    numero_professores++;
    
    printf("\n\nDados armazenados com sucesso!\nRetornando ao Menu - Professor!\n\n");
    
    digitar_letra();
}

//Função para incluir professor no arquivo de professores
void incluir_turma()
{
    int quantidade_alunos = 0;
    int i = 0;
    int procura = 0;
    char strconsulta[50];
    
    system("CLS");
    
    if (numero_professores > 0)
    {
        if (numero_alunos > 0)
        {
            ///Recebendo os dados
            printf("\n\tIncluir turma\n");
            
            printf("\nDisciplina: ");
            gets(turma[numero_turmas].disciplina);
            setbuf(stdin,NULL);
            
            printf("\nCodigo Disciplina: ");
            gets(turma[numero_turmas].codigo);
            setbuf(stdin,NULL);
            
            do
            {
                printf("\nNumero Turma: ");
                fflush(stdin);
                gets(strconsulta);
                setbuf(stdin,NULL);
                
                //Validação do numero da turma
                for(i=0;i<numero_turmas;i++)
                {
                    if(strcmp(strconsulta,turma[i].numero_turma) == 0)
                    {
                        procura++;
                    }
                }
                if(procura==1)
                {
                    printf("\nOutra turma dessa disciplina cadastrada ja possui esse numero.\nInsira outro numero da turma!");
                }
                else
                {
                    strcpy(turma[numero_turmas].numero_turma,strconsulta);
                }
            }while((strconsulta[0]=='\0')||(procura!=0));
            
            do
            {
                procura = 0;
                
                printf("\nMatricula Professor: ");
                fflush(stdin);
                gets(strconsulta);
                setbuf(stdin,NULL);
                
                //Validação do numero da turma
                for(i=0;i<numero_professores;i++)
                {
                    if(strcmp(strconsulta,professor[i].matricula) == 0)
                    {
                        procura++;
                        turma[numero_turmas].professor = &professor[i];
                    }
                }
                if(procura==0)
                {
                    printf("\nNenhum professor possui essa matricula! Digite uma matricula dos professores abaixo:\n");
                    for(i=0;i<numero_professores;i++)
                    {
                        printf("%s - %s", professor[i].nome, professor[i].matricula);
                        printf("\n");
                    }
                }
            }while((strconsulta[0]=='\0')||(procura==0));
            
            do
            {
                procura = 0;
                printf("\nQuantidade Alunos: ");
                scanf("%d",&quantidade_alunos);
                
                if(quantidade_alunos>numero_alunos)
                {
                    printf("Apenas %d aluno(s) foram cadastrado(s). Digite um numero entre 1 e %d",numero_alunos,numero_alunos);
                }
            }while(quantidade_alunos>numero_alunos);
            
            turma[numero_turmas].numero_alunos = quantidade_alunos;
            
            for(i=0;i<quantidade_alunos;i++)
            {
                do
                {
                    procura = 0;
                    
                    setbuf(stdin,NULL);
                    printf("Matricula Aluno %d: ",i+1);
                    gets(strconsulta);
                    setbuf(stdin,NULL);
                    
                    int j;
                    //Validação da matricula
                    for(j=0;j<numero_alunos;j++)
                    {
                        if(strcmp(strconsulta,aluno[j].matricula) == 0)
                        {
                            procura++;
                            turma[numero_turmas].alunos[i] = &aluno[j];
                            break;
                        }
                    }
                    if(procura==0)
                    {
                        printf("\nNenhum aluno possui essa matricula! Digite uma matricula dos alunos abaixo:\n");
                        for(j=0;j<numero_alunos;j++)
                        {
                            printf("%s - %s", aluno[j].nome, aluno[j].matricula);
                            printf("\n");
                        }
                        printf("\n");
                    }
                }while(procura==0);
                
                escrever_arquivo_alunos_turma();
                
                numero_alunos_turmas++;
            }
            
            ///Escrevendo em um arquivo
            printf("\n\nArquivando Dados . . .");
            
            escrever_arquivo_turma();
            
            numero_turmas++;
            
            printf("\n\nDados armazenados com sucesso!\nRetornando ao Cadastro - Turma!\n\n");
        }
        else
        {
            printf("Cadastre pelo menos um aluno antes de cadastrar uma turma!");
        }
    }
    else
    {
        printf("Cadastre pelo menos um professor antes de cadastrar uma turma!");
    }
    
    
    digitar_letra();
}

//Função para consultar um aluno dentre os alunos cadastrados
void consultar_aluno()
{
    int i = 0;
    int procura = 0;
    char strconsulta[50];
    
    system("CLS");
    
    ///Recebendo os dados
    printf("\n\tConsultar Aluno\n");
    
    do
    {
        printf("\nMatricula: ");
        fflush(stdin);
        gets(strconsulta);
        setbuf(stdin,NULL);
    }while((strconsulta[0]=='\0')||(procura==0));
    
    //Validação da matricula
    for(i=0;i<numero_alunos;i++)
    {
        if(strcmp(strconsulta,aluno[i].matricula) == 0)
        {
            procura = i+1;
        }
    }
    if(procura==0)
    {
        printf("\nNenhum aluno possui a matricula digitada!");
    }
    else
    {
        procura = procura - 1;
        printf("\n\nAluno encontrado!!\n\n\nAluno: %s\nMatricula: %s\nIdade:%d\nTelefone:%s\nCelular:%s\nEndereco:%s\nIRA:%.4f", aluno[procura].nome, aluno[procura].matricula, aluno[procura].idade, aluno[procura].telefone, aluno[procura].celular, aluno[procura].endereco, aluno[procura].ira);
        printf("\n\n");
    }
    
    digitar_letra();
}

//Função para consultar um professor dentre os professores cadastrados
void consultar_professor()
{
    int i = 0;
    int procura = 0;
    char strconsulta[50];
    
    system("CLS");
    
    ///Recebendo os dados
    printf("\n\tConsultar Professor\n");
    
    do
    {
        printf("\nMatricula: ");
        fflush(stdin);
        gets(strconsulta);
        setbuf(stdin,NULL);
    }while((strconsulta[0]=='\0')||(procura==0));
    
    //Validação da matricula
    for(i=0;i<numero_professores;i++)
    {
        if(strcmp(strconsulta,professor[i].matricula) == 0)
        {
            procura = i+1;
        }
    }
    if(procura==0)
    {
        printf("\nNenhum professor possui a matricula digitada!");
    }
    else
    {
        procura = procura - 1;
        printf("\n\nProfessor encontrado!!\n\n\nProfessor: %s\nMatricula: %s\nIdade:%d\nTelefone:%s\nCelular:%s\nEndereco:%s", professor[procura].nome, professor[procura].matricula, professor[procura].idade, professor[procura].telefone, professor[procura].celular, professor[procura].endereco);
        printf("\n\n");
    }
    
    digitar_letra();
}

//Função para consultar uma turma dentre as turmas cadastradas
void consultar_turma()
{
    int i = 0;
    int procura = 0;
    char strconsulta[50];
    
    system("CLS");
    
    ///Recebendo os dados
    printf("\n\tConsultar Turma\n");
    
    do
    {
        printf("\nCodigo disciplina: ");
        fflush(stdin);
        gets(strconsulta);
        setbuf(stdin,NULL);
    }while(strconsulta[0]=='\0');
    
    //Validação do codigo disciplina
    for(i=0;i<numero_turmas;i++)
    {
        if(strcmp(strconsulta,turma[i].codigo) == 0)
        {
            procura = i+1;
        }
    }
    if(procura==0)
    {
        printf("\nNenhuma turma possui o codigo da discplina digitado!");
    }
    else
    {
        do
        {
            printf("\nNumero da turma: ");
            fflush(stdin);
            gets(strconsulta);
            setbuf(stdin,NULL);
        }while(strconsulta[0]=='\0');
        
        //Validação do codigo disciplina
        for(i=0;i<numero_turmas;i++)
        {
            if(strcmp(strconsulta,turma[i].numero_turma) == 0)
            {
                procura = i+1;
            }
        }
        if(procura==0)
        {
            printf("\nNenhuma turma possui o numero da turma digitado!");
        }
        else
        {
            procura = procura - 1;
            printf("\n\nTurma encontrada!!\n\n\nDisciplina: %s\nCodigo Disciplina: %s\nNumero da Turma:%s\n", turma[procura].disciplina, turma[procura].codigo, turma[procura].numero_turma);
            
            for(i=0;i<numero_professores;i++)
            {
                if(strcmp(turma[procura].professor->matricula,professor[i].matricula) == 0)
                {
                    printf("Professor:%s",professor[i].nome);
                }
            }
            int j;
            for(j=0;j<turma[procura].numero_alunos;j++)
            {
                for(i=0;i<numero_alunos;i++)
                {
                    if(strcmp(turma[procura].alunos[j]->matricula,aluno[i].matricula) == 0)
                    {
                        printf("Aluno %d:%s",j+1,professor[i].nome);
                    }
                }
            }
        }
    }
    
    digitar_letra();
}

//Função para alterar um aluno dentre os alunos cadastrados
void alterar_aluno()
{
    int i;
    int escolha_aluno;
    char strconsulta[50];
    system("cls");
    if(numero_alunos>0)
    {
        printf("Digite o numero do aluno que deseja alterar:\n");
        
        //Laço de Repetição para mostrar alunos cadastrados
        for(i=0;i<numero_alunos;i++)
        {
            printf("\nAluno %d:\t\t Nome:%s\t Matricula:%s", i+1, aluno[i].nome, aluno[i].matricula);
        }
        
        //Escolha do aluno que sera alterado
        printf("\nAluno ");
        scanf("%d",&escolha_aluno);
        
        //Validação da entrada de dados
        if((escolha_aluno>0) && (escolha_aluno<=numero_alunos))
        {
            escolha_aluno = escolha_aluno - 1;
            
            do
            {
                printf("\nNome: ");
                fflush(stdin);
                gets(strconsulta);
                setbuf(stdin,NULL);
                
                strcpy(aluno[escolha_aluno].nome,strconsulta);
                
            }while(strconsulta[0]=='\0');
            
            do
            {
                fflush(stdin);
                printf("\nMatricula: ");
                gets(strconsulta);
                setbuf(stdin,NULL);
                
                strcpy(aluno[escolha_aluno].matricula,strconsulta);
                
            }while(strconsulta[0]=='\0');
            
            fflush(stdin);
            printf("\nIdade: ");
            scanf("%d", &aluno[escolha_aluno].idade);
            
            fflush(stdin);
            printf("\nTelefone: ");
            gets(aluno[escolha_aluno].telefone);
            setbuf(stdin,NULL);
            
            fflush(stdin);
            printf("\nCelular: ");
            gets(aluno[escolha_aluno].celular);
            setbuf(stdin,NULL);
            
            fflush(stdin);
            printf("\nEndereco: ");
            gets(aluno[escolha_aluno].endereco);
            setbuf(stdin,NULL);
            
            fflush(stdin);
            printf("\nIRA: ");
            scanf("%f", &aluno[escolha_aluno].ira);
            
            arquivo_alunos=fopen(nome_arquivo_alunos,"wt");
            
            for(i=0;i<numero_alunos-1;i++)
            {
                escrever_arquivo_aluno();
            }
            
            fclose(arquivo_alunos);
                
            printf("\nAluno alterado com sucesso!");

        }
        else
        {
            printf("Digite um numero valido. Entre 1 e %d", numero_alunos);
        }
    }
    else
    {
        printf("Nao existem alunos cadastrados!");
    }
    
    digitar_letra();
}

//Função para alterar um professor dentre os professores cadastrados
void alterar_professor()
{
    int i;
    int escolha_professor;
    char strconsulta[50];
    system("cls");
    if(numero_professores>0)
    {
        printf("Digite o numero do professor que deseja alterar:\n");
        
        //Laço de Repetição para mostrar professores cadastrados
        for(i=0;i<numero_professores;i++)
        {
            printf("\nProfessor %d:\t\t Nome:%s\t Matricula:%s", i+1, professor[i].nome, professor[i].matricula);
        }
        
        //Escolha do professor que sera alterado
        printf("\nProfessor ");
        scanf("%d",&escolha_professor);
        
        //Validação da entrada de dados
        if((escolha_professor>0) && (escolha_professor<=numero_professores))
        {
            escolha_professor = escolha_professor - 1;
            
            do
            {
                printf("\nNome: ");
                fflush(stdin);
                gets(strconsulta);
                setbuf(stdin,NULL);
                
                strcpy(professor[escolha_professor].nome,strconsulta);
                
            }while(strconsulta[0]=='\0');
            
            do
            {
                fflush(stdin);
                printf("\nMatricula: ");
                gets(strconsulta);
                setbuf(stdin,NULL);
                
                strcpy(professor[escolha_professor].matricula,strconsulta);
                
            }while(strconsulta[0]=='\0');
            
            fflush(stdin);
            printf("\nIdade: ");
            scanf("%d", &professor[escolha_professor].idade);
            
            fflush(stdin);
            printf("\nTelefone: ");
            gets(professor[escolha_professor].telefone);
            setbuf(stdin,NULL);
            
            fflush(stdin);
            printf("\nCelular: ");
            gets(professor[escolha_professor].celular);
            setbuf(stdin,NULL);
            
            fflush(stdin);
            printf("\nEndereco: ");
            gets(professor[escolha_professor].endereco);
            setbuf(stdin,NULL);
            
            arquivo_professores=fopen(nome_arquivo_professores,"wt");
            
            for(i=0;i<escolha_professor;i++)
            {
                escrever_arquivo_professor();
            }
            
            fclose(arquivo_professores);
            
            printf("\nProfessor alterado com sucesso!");
            
        }
        else
        {
            printf("Digite um numero valido. Entre 1 e %d", escolha_professor);
        }
    }
    else
    {
        printf("Nao existem professores cadastrados!");
    }
    
    digitar_letra();
}

//Função para alterar uma turma dentre as turmas cadastradas
void alterar_turma()
{
    int i;
    int escolha_turma;
    char strconsulta[50];
    system("cls");
    if(numero_turmas>0)
    {
        printf("Digite o numero da turma que deseja alterar:\n");
        
        //Laço de Repetição para mostrar professores cadastrados
        for(i=0;i<numero_turmas;i++)
        {
            printf("\nTurma %d\t\tDisciplina %s-%s:\t Numero Turma:%s", i+1, turma[i].disciplina, turma[i].codigo,turma[i].numero_turma);
        }
        
        //Escolha do turma que sera alterado
        printf("\nTurma ");
        scanf("%d",&escolha_turma);
        
        escolha_turma = escolha_turma - 1;
        
        //Validação da entrada de dados
        if((escolha_turma>0) && (escolha_turma<=numero_turmas))
        {
            do
            {
                printf("\nDisplina: ");
                fflush(stdin);
                gets(strconsulta);
                setbuf(stdin,NULL);
                
                strcpy(turma[escolha_turma].disciplina,strconsulta);
                
            }while(strconsulta[0]=='\0');
            
            do
            {
                fflush(stdin);
                printf("\nCodigo Disciplina: ");
                gets(strconsulta);
                setbuf(stdin,NULL);
                
                strcpy(turma[escolha_turma].codigo,strconsulta);
                
            }while(strconsulta[0]=='\0');
            
            fflush(stdin);
            printf("\nNumero Turma: ");
            gets(turma[escolha_turma].numero_turma);
            
            fflush(stdin);
            printf("\nMatricula Professor: ");
            gets(turma[escolha_turma].professor->matricula);
            setbuf(stdin,NULL);
            
            arquivo_turmas = fopen(nome_arquivo_turmas,"wt");
            
            for(i=0;i<escolha_turma;i++)
            {
                escrever_arquivo_turma();
            }
            
            fclose(arquivo_turmas);
            
            printf("\nTurma alterada com sucesso!");
            
        }
        else
        {
            printf("Digite um numero valido. Entre 1 e %d", escolha_turma);
        }
    }
    else
    {
        printf("Nao existem turmas cadastradas ate o momento!");
    }
    
    digitar_letra();
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
            printf("Aluno: %s\nMatricula: %s\nIRA:%.4f", aluno[i].nome, aluno[i].matricula, aluno[i].ira);
            printf("\n\n\n");
        }
    }
    else
    {
        printf("Nenhum aluno foi cadastrado");
    }
    
    digitar_letra();
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
            printf("Professor: %s\nMatricula: %s\nTelefone:%s", professor[i].nome, professor[i].matricula, professor[i].telefone);
            printf("\n\n\n");
        }
    }
    else
    {
        printf("Nenhum professor foi cadastrado");
    }
    
    digitar_letra();
}

//Função para listar todas turmas cadastradas
void visualizar_turmas()
{
    
    int i;
    system("cls");
    
    if(numero_turmas>0)
    {
        for(i=0;i<numero_turmas;i++)
        {
            printf("Displina: %s\nCodigo Disciplina: %s\nTurma:%s", turma[i].disciplina, turma[i].codigo, turma[i].numero_turma);
            printf("\n\n\n");
        }
    }
    else
    {
        printf("Nenhuma turma foi cadastrada");
    }
    
    digitar_letra();
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
                arquivo_alunos=fopen(nome_arquivo_alunos,"wt");
                
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
            printf("Digite um numero valido. Entre 1 e %d", numero_alunos);
        }
    }
    else
    {
        printf("Nao existem alunos cadastrados!");
    }
    
    digitar_letra();
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
                arquivo_professores = fopen(nome_arquivo_alunos,"wt");
                
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
            printf("Digite um numero valido. Entre 1 e %d", numero_professores);
        }
    }
    else
    {
        printf("Nao existem professores cadastrados!");
    }
    
    digitar_letra();
}

//Funcao para excluir turma
void excluir_turma()
{
    int i;
    int escolha_professor;
    char escolha;
    system("cls");
    if(numero_turmas>0)
    {
        printf("Digite o numero da turma que deseja excluir:\n");
        
        //Laço de Repetição para mostrar professores cadastrados
        for(i=0;i<numero_turmas;i++)
        {
            printf("\nTurma %d\t\tDisciplina %s-%s:\t Numero Turma:%s", i+1, turma[i].disciplina, turma[i].codigo,turma[i].numero_turma);
        }
        
        //Escolha da turma que sera excluida
        printf("\nTurma ");
        scanf("%d",&escolha_professor);
        
        //Validação da entrada de dados
        if((escolha_professor>0)&&(escolha_professor<=numero_professores))
        {
            printf("Deseja confirmar exclusao da turma? (S/N): ");
            setbuf(stdin,NULL);
            scanf("%c",&escolha);
            
            if((escolha=='S') || (escolha=='s'))
            {
                printf("\nTurma excluida com sucesso!");
            }
        }
        else
        {
            printf("Digite um numero valido. Entre 1 e %d", numero_turmas);
        }
    }
    else
    {
        printf("Nao existem turmas cadastradas!");
    }
    
    digitar_letra();
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
        printf("\n   Selecione uma opcao: ");
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
                incluir_turma();
                break;
            case 2:
                consultar_turma();
                break;
            case 3:
                alterar_turma();
                break;
            case 4:
                excluir_turma();
                break;
            case 5:
                visualizar_turmas();
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
    importar_turmas();
    
    do
    {
        system("cls");
        printf("\n\t\tM E N U    P R I N C I P A L");
        printf("\n\n\tOpcoes:\n");
        printf("\t1 - Cadastro Alunos\n");
        printf("\t2 - Cadastro Professor\n");
        printf("\t3 - Cadastro Turma\n");
        printf("\t4 - Sair\n");
        printf("\n   Selecione uma opcao: ");
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
                printf("Opcao nao e valida! Digite um numero entre 1 e 4.");
                break;
        }
        
    } while(escolha_menu != 4);
    
    return 0;
}
