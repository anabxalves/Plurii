#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define MAX 50

void clearScreen();
int validateResident(char** argv, char* user, char* password);
int validatePreceptor(char** argv, char* user, char* password);
int analyseLogin(FILE * fp, char** user, char** password);

int main(int argc, char *argv[])
{
    clearScreen();

    int access = -1;
    char user[MAX];
    char password[MAX];

    while (access != 1 || access != 2)
    {
        printf("-\tPLURII\t\t-\nMonitoramento Educacional\n");
        printf("==========================\n\n");

        printf("Selecione o tipo de acesso:\n[1] - Residente\n[2] - Preceptor\n[0] - Sair\n");
        scanf("%d", &access);

        if (access == 1)
        {
            printf("\nLOGIN RESIDENTE\n");
            break;
        }
        else if (access == 2)
        {
            printf("\nLOGIN PRECEPTOR\n");
            break;
        }
        else if (access == 0)
        {
            printf("\nObrigado por utilizar o sistema Plurii, ate a proxima!\n");
            exit(1);
        }
        else
        {
            printf("Opcao invalida. Favor inserir uma das operacoes possiveis.\n");
            Sleep(2000);
            printf("Recarregando pagina inicial.\n");
            for(int i=0; i<3; i++)
            {
                Sleep(1000);
                printf(".\n");
            }
            Sleep(1000);
            clearScreen();
            continue;
        }
    }

    int bool = 1, cont = 0;

    getchar(); // limpando o buffer do stdin

    while(bool != 0)
    {
        if(cont == 0)
        {
            bool = 1;
            cont++;
            continue;
        }

        printf("Insira seu usuario: ");
        fgets(user, sizeof(user), stdin);
        user[strcspn(user, "\n")] = '\0';
        // altera o último caracter da entrada (\n) para um fim de linha (\0), para que não ocorra erro no strcmp da validação

        printf("Insira sua senha: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = '\0';
        // altera o último caracter da entrada (\n) para um fim de linha (\0), para que não ocorra erro no strcmp da validação

        switch (access){
        case 1:
            if (validateResident(argv, user, password))
            {
                printf("Login realizado com sucesso. Seja bem vindo, %s!\n", user);
                bool = 0;
                exit(1);
            }
            else printf("Login nao realizado. Usuario ou senha invalidos.\n");
            break;
        case 2:
            if (validatePreceptor(argv, user, password))
            {
                printf("Login realizado com sucesso. Seja bem vindo, %s!\n", user);
                bool = 0;
                exit(1);
            }
            else printf("Login nao realizado. Usuario ou senha invalido.\n");
            break;
        default:
            bool = 0;
            break;
        }
    }
    return 0;
}

void clearScreen()
{
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #else
    #endif
}

int validateResident(char** argv, char* user, char* password)
{
    FILE* fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        printf("Erro: Nao foi possível o acesso ao bando de dados.\n");
        return 0;
    }

    if (analyseLogin(fp, &user, &password) == 1) return 1;

    fclose(fp);
    return 0;
}

int validatePreceptor(char** argv, char* user, char* password)
{
    FILE* fp = fopen(argv[2], "r");

    if (fp == NULL)
    {
        printf("Erro: Nao foi possível o acesso ao bando de dados.\n");
        return 0;
    }

    if (analyseLogin(fp, &user, &password) == 1) return 1;

    fclose(fp);
    return 0;
}

int analyseLogin(FILE * fp, char** user, char** password)
{
    char line[MAX];

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char* storedUser = strtok(line, " ");
        char* storedPassword = strtok(NULL, " ");

        if (storedUser != NULL && storedPassword != NULL)
        {
            storedPassword[strcspn(storedPassword, "\n")] = '\0';

            if (strcmp((*user), storedUser) == 0 && strcmp((*password), storedPassword) == 0)
            {
                fclose(fp);
                return 1;
            }
        }
    }
    return 0;
}