#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "qrcode.h"
#include "extra.h"

#define FILENAME "database/hc_qrcode.txt"

/* Função para obter o ultimo n° do ID do QrCode */
int obterUltimoID() {
    FILE *arquivo = fopen(FILENAME, "r");
    if (arquivo == NULL) {
        return 0; // Se o arquivo não existir, retorna 0
    }

    QRCODE qrCode;
    while (fread(&qrCode, sizeof(QRCODE), 1, arquivo)) {
        // Continua lendo até o final do arquivo para obter o último registro
    }

    fclose(arquivo);
    return qrCode.idQrcode;
}

/* Função para registrar novo QRCode */
void registerQRCode(QRCODE newQRCode) {
    FILE *arquivo = fopen(FILENAME, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fwrite(&newQRCode, sizeof(QRCODE), 1, arquivo);
    fclose(arquivo);

    printf("\n");
    exibirQRCode();
    delay(1);

    printf("\n");
    printf("QRCode registrado com sucesso!\n");
    delay(1);
}

void gerarQrcode() {
    int IDPreceptor = 987654;
    char especialidade[20];
    QRCODE newQRCode;

/* obter data e hora atual */ 
    time_t segundos = time(NULL);
    struct tm *c_datetime = localtime(&segundos);
    time(&segundos);

    QRCODE *geraQRCode = malloc(sizeof(QRCODE));

/* Tela de gerar QRCode*/  
    system("clear"); 
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~ PLURII - MONITORAMENTO EDUCACIONAL ~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~ GERAR QRCODE ~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

 /* Exibir nome do precpetor logado */
    printf("Preceptor: 987654 - Marcos Ferreira\n");
  
 /* Data e Hora local */
    printf("Data atual : %d/", c_datetime->tm_mday); // dia
    printf("%d/", c_datetime->tm_mon + 1);           // mês
    printf("%d\n", c_datetime->tm_year + 1900);      // ano

    printf("Hora atual :%d:", c_datetime->tm_hour); // hora
    printf("%d:", c_datetime->tm_min);             // minuto
    printf("%d", c_datetime->tm_sec);            // segundo
    printf("\n");
    getchar();

  /* Entrada - especialidade */
    printf("Especialidade: ");
    fgets(especialidade, sizeof(especialidade), stdin);
    //flush_in();
    especialidade[strcspn(especialidade, "\n")] = '\0'; // Remover o caractere de nova linha
    converterMaiuscula(especialidade);

    printf("\n");

/* atribuição de valores as variaveis da struct*/
    geraQRCode->idQrcode = obterUltimoID() + 1;
    geraQRCode->anoQr = c_datetime->tm_year + 1900;
    geraQRCode->mesQr = c_datetime->tm_mon + 1;
    geraQRCode->diaQr = c_datetime->tm_mday;
    geraQRCode->horaQr = c_datetime->tm_hour;
    geraQRCode->minQr = c_datetime->tm_min;
    geraQRCode->segQr = c_datetime->tm_sec;
    strcpy(geraQRCode->especialidade, especialidade);
    
/* Função p/ gravar o registro no arquivo */
    registerQRCode(*geraQRCode);

    free(geraQRCode);
}