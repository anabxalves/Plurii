#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "qrcode.h"
#include "frequencia.h"


#define QR_CODE_FILENAME "database/hc_qrcode.txt"
#define FREQUENCIA_FILENAME "database/hc_frequencia.txt"

/* Representação da imagem do QRCode */
void exibirQRCode() {
    printf("███ ██ █  ███ █  █ ████\n");
    printf("█  █  ██ █  █  ██  █  █\n");
    printf("███ ██  █  ██ ██ █ ████\n");
    printf("█  █  ███ ██  █  ███  █\n");
    printf(" █  ██  ██  ███  ███  █\n");
    printf("█  █  ███ ██  █  ███  █\n");
    printf("████  ██  █ ██ █ █ ████\n");
    printf("█  █  ███  █ ██ ██ █  █\n");
    printf("████  █ ██  █  ██  ████\n");
}

/* Função para obter o último registro do arquivo hc_qrcode.txt */
QRCODE obterUltimoQRCode() {
    FILE *arquivo = fopen(QR_CODE_FILENAME, "r");
    if (arquivo == NULL) {
        QRCODE qrCode;
        qrCode.idQrcode = 0;
        return qrCode; // Se o arquivo não existir, retorna uma struct vazia
    }

    QRCODE qrCode;
    while (fread(&qrCode, sizeof(QRCODE), 1, arquivo)) {
        // Continua lendo até o final do arquivo para obter o último registro
    }

    fclose(arquivo);
    return qrCode;
}

/* Função para registrar a frequência */
void registerFrequenciaQ(FREQUENCIA *freq_data) {
    FILE *arquivo = fopen(FREQUENCIA_FILENAME, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de frequência.\n");
        return;
    }

    fwrite(freq_data, sizeof(FREQUENCIA), 1, arquivo);
    fclose(arquivo);

    printf("Frequência registrada com sucesso!\n");
    delay(1);
    free(freq_data);
}

void lerQrcode(FREQUENCIA *freq_data) {
    char atividade[20];
    char entradaSaida;
    QRCODE ultimoQRCode;
  
    /* Ler o último QRCode registrado */
    ultimoQRCode = obterUltimoQRCode();

/* Inicio da tela de registro de frequencia manual */  
    system("clear"); // limpa a tela
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~ REGISTRO DE FREQUÊNCIA ~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    printf("Ler QRCode: \n\n");
    exibirQRCode();
    delay(1);

    system("clear"); // limpa a tela
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~ REGISTRO DE FREQUÊNCIA ~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

/* Exibir nome do residente logado */
    printf("Residente: XXXXX - AAAAAAAA AAAAAAA\n\n"); 
  
/* Data e Hora local */
    printf("Data atual : %02d/", ultimoQRCode.diaQr); // dia
    printf("%02d/", ultimoQRCode.mesQr);           // mês
    printf("%04d\n", ultimoQRCode.anoQr);      // ano

    printf("Hora atual :%02d:", ultimoQRCode.horaQr); // hora
    printf("%02d:", ultimoQRCode.minQr);             // minuto
    printf("%02d", ultimoQRCode.segQr);            // segundo
    printf("\n");

    printf("Especialidade : %s", ultimoQRCode.especialidade);    
    printf("\n");
    getchar();

    /* Solicitar entrada da Atividade e E/S */
    printf("Atividade: ");
    getchar();
    fgets(atividade, sizeof(atividade), stdin);
    atividade[strcspn(atividade, "\n")] = '\0'; // Remover o caractere de nova linha
    converterMaiuscula(atividade);

    printf("Entrada ou Saída (E/S): ");
    scanf(" %c", &entradaSaida);
    entradaSaida = toupper(entradaSaida);
    printf("\n");
  
    /* Atribuir informações na struct Frequencia */
    FREQUENCIA *frequencia = malloc(sizeof(FREQUENCIA));
    frequencia->idmatric = ultimoQRCode.idQrcode;
    frequencia->anoFreq = ultimoQRCode.anoQr;
    frequencia->mesFreq = ultimoQRCode.mesQr;
    frequencia->diaFreq = ultimoQRCode.diaQr;
    frequencia->horaFreq = ultimoQRCode.horaQr;
    frequencia->minFreq = ultimoQRCode.minQr;
    frequencia->segFreq = ultimoQRCode.segQr;
    frequencia->entradasaida = entradaSaida;
    strcpy(frequencia->especialidade, ultimoQRCode.especialidade);
    strcpy(frequencia->atividade, atividade);

/*  Reservado - validação do Preceptor (Tela Preceptor)*/
    frequencia->validado = 'N';  // Valor inicial 'não validado'
    frequencia->idpreceptor = 0; // Valor inicial zero
    frequencia->anoValida = 0;   // Valor inicial zero
    frequencia->mesValida = 0;   // Valor inicial zero
    frequencia->diaValida = 0;   // Valor inicial zero
    frequencia->horaValida = 0;  // Valor inicial zero
    frequencia->minValida = 0;   // Valor inicial zero
    frequencia->segValida = 0;   // Valor inicial zero

    /* Função para registrar a frequência */
    registerFrequenciaQ(frequencia);
    //free(frequencia);

}