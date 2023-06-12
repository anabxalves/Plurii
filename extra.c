#include <time.h>

/* delay para mensagem exibida na tela */
void delay(int seconds) {
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait) {}
}

/* converter em maiuscula*/
void converterMaiuscula(char *str) {
    int i = 0;
    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}

/* Representação da imagem do QRCode */
void exibirQRCode() {
    printf("████ █ █  ███ █  █ ████\n");
    printf("█  █  ██ █  █  ██  █  █\n");
    printf("████ █  █  ██ ██ █ ████\n");
    printf("█   █  ███ ██  █ ██   █\n");
    printf("█ ██  ██  ███  ███    █\n");
    printf("█   █  ███ ██  █ ███  █\n");
    printf("████  ██  █ ██ █ █ ████\n");
    printf("█  █  ███  █ ██ ██ █  █\n");
    printf("████  █ ██  █  ██  ████\n");
}

