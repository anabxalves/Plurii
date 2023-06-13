#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "qrcode.h"
#include "frequencia.h"
#include "myLibs.h"
#include "extra.h"

#define QR_CODE_FILENAME "database/hc_qrcode.txt"
#define FREQUENCIA_FILENAME "database/hc_frequencia.txt"

/* Função para obter o último registro do arquivo hc_qrcode.txt */
QRCODE obterUltimoQRCode() {
    flush_in();
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
void registerFrequenciaQ(FREQData *freq_data) {
   
    FILE *arquivo = fopen(FREQUENCIA_FILENAME, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de frequência.\n");
        return;
    }

    fwrite(freq_data, sizeof(FREQData), 1, arquivo);
    fclose(arquivo);

    printf("Frequência registrada com sucesso!\n");
    delay(1);
    //free(freq_data);
}

void lerQrcode(FREQData *freq_data) {
   
    char atividade[20];
    char entradaSaida;
    QRCODE ultimoQRCode;
  
    /* Ler o último QRCode registrado */
    ultimoQRCode = obterUltimoQRCode();

/* Inicio da tela de registro de frequencia manual */  
    system("clear"); // limpa a tela
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~ PLURII - MONITORAMENTO EDUCACIONAL ~~~~~~~~\n");
    printf("~~~~~~~~~~~~ REGISTRO DE FREQUÊNCIA ~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    printf("Ler QRCode: \n\n");
    exibirQRCode();
    delay(1);

    system("clear"); // limpa a tela
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~ PLURII - MONITORAMENTO EDUCACIONAL ~~~~~~~~\n");
    printf("~~~~~~~~~~~~ REGISTRO DE FREQUÊNCIA ~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

  /* Exibir nome do usuário logado */
    printf("Residente : 123456 - Maria Santos\n\n");
  
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
    

    /* Solicitar entrada da Atividade e E/S */
    printf("Atividade: ");
    fgets(atividade, 10, stdin);
    atividade[strcspn(atividade, "\n")] = '\0'; // Remover o caractere de nova linha
    flush_in();
    converterMaiuscula(atividade);

    printf("Entrada ou Saída (E/S): ");
    scanf(" %c", &entradaSaida);
    entradaSaida = toupper(entradaSaida);
    printf("\n");
  
    /* Atribuir informações na struct Frequencia */
    /* alocação dinamica para registro da frequencia */
    //frequencia = (FREQData *)malloc(sizeof(FREQData));
    //FREQData *frequencia =(FREQData*)malloc(sizeof(FREQData));
    freq_data = (FREQData *)malloc(sizeof(FREQData));
    if (freq_data == NULL) {
        printf("Erro ao alocar memória para frequencia.\n");
        return;
    }
    freq_data->idmatric = ultimoQRCode.idQrcode;
    freq_data->anoFreq = ultimoQRCode.anoQr;
    freq_data->mesFreq = ultimoQRCode.mesQr;
    freq_data->diaFreq = ultimoQRCode.diaQr;
    freq_data->horaFreq = ultimoQRCode.horaQr;
    freq_data->minFreq = ultimoQRCode.minQr;
    freq_data->segFreq = ultimoQRCode.segQr;
    freq_data->entradasaida = entradaSaida;
    strcpy(freq_data->especialidade, ultimoQRCode.especialidade);
    strcpy(freq_data->atividade, atividade);

/*  Reservado - validação do Preceptor (Tela Preceptor)*/
    freq_data->validado = 'N';  // Valor inicial 'não validado'
    freq_data->aprovado = 'N';  // Valor inicial 'não validado'
    freq_data->idpreceptor = 0; // Valor inicial zero
    freq_data->anoValida = 0;   // Valor inicial zero
    freq_data->mesValida = 0;   // Valor inicial zero
    freq_data->diaValida = 0;   // Valor inicial zero
    freq_data->horaValida = 0;  // Valor inicial zero
    freq_data->minValida = 0;   // Valor inicial zero
    freq_data->segValida = 0;   // Valor inicial zero
    strcpy(freq_data->observacao,"");   // 
  
    /* Função para registrar a frequência */
    registerFrequenciaQ(freq_data);
    //free(frequencia);

}