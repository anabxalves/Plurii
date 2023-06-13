#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAMANHO_NOME 50
#define MAX_TAMANHO_SENHA 50
#define FILEPATH "database/hc_usuarios.txt"

typedef struct {
    char nome[MAX_TAMANHO_NOME];
    char senha[MAX_TAMANHO_SENHA];
} Usuario;

void login() {
    FILE *arquivo;
    Usuario *usuarios = NULL;
    int totalUsuarios = 0;

    arquivo = fopen(FILEPATH, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir.\n");
    }

    char linha[MAX_TAMANHO_NOME + MAX_TAMANHO_SENHA + 1];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        Usuario usuario;
        sscanf(linha, "%[^:]:%s", usuario.nome, usuario.senha);
        totalUsuarios++;

        Usuario *temp = realloc(usuarios, totalUsuarios * sizeof(Usuario));

        usuarios = temp;
        usuarios[totalUsuarios] = usuario;
    }

    fclose(arquivo);

    char nomeLogin[MAX_TAMANHO_NOME];
    char senhaLogin[MAX_TAMANHO_SENHA];

    printf("Digite o nome de usuário: ");
    fgets(nomeLogin, sizeof(nomeLogin), stdin);
    nomeLogin[strcspn(nomeLogin, "\n")] = '\0'; 

    printf("Digite a senha: ");
    fgets(senhaLogin, sizeof(senhaLogin), stdin);
    senhaLogin[strcspn(senhaLogin, "\n")] = '\0';  

    int i;
    int loginValido = 0;
    for (i = 0; i < totalUsuarios; i++) {
        if (strcmp(nomeLogin, usuarios[i].nome) == 0 && strcmp(senhaLogin, usuarios[i].senha) == 0) {
            loginValido = 1;
            break;
        }
    }

    if (loginValido) {
        printf("Login bem-sucedido.\n");
    } else {
        printf("Nome de usuário ou senha inválidos.\n");
    }

    free(usuarios);


}