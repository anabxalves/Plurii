#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "frequencia.h"
#include <time.h>

#define FREQ_FILENAME "database/hc_frequencia.txt"

// Função para imprimir os dados de frequência
void viewFreq() {
    // Abrir o arquivo para leitura
    FILE* file = fopen(FREQ_FILENAME, "r");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    // Variável para armazenar os dados lidos do arquivo
    FREQData freqData;
system("clear"); // limpa a tela

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~ MONITORAMENTO PROGRAMA DE RESIDENCIA ~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~ REGISTRO DE FREQUÊNCIA ~~~~~~~~~~~~~~~~~~~~~~~~~~\n");     
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    
    // Pegar o nome do usuário de um arquivo.
      printf("Residente : 123456 - Maria Santos\n\n");
      printf("Especialidade: %s\n\n", freqData.especialidade);
      printf("Data\t\t");
      printf("Hora\t\t");  
      printf("E/S\t");
      printf("Atividade\t"); 
      printf("Validado\t");
      printf("Data Validação\t");
      printf("Aprovado\t");  
      printf("Preceptor\t"); 
      printf("Observação\t\n");
  
    // Ler e imprimir os dados do arquivo
    while (fread(&freqData, sizeof(FREQData), 1, file) == 1) {
        printf("%02d/%02d/%d\t", freqData.diaFreq, freqData.mesFreq, freqData.anoFreq);
        printf("%02d:%02d:%02d\t", freqData.horaFreq, freqData.minFreq, freqData.segFreq);
        printf("%c\t", freqData.entradasaida);
        printf("%s\t\t", freqData.atividade);
        printf("%c\t\t\t", freqData.validado);
        printf("%02d/%02d/%d\t\t\t", freqData.diaValida, freqData.mesValida, freqData.anoValida);
        printf("%c\t\t", freqData.aprovado);
        printf("%d\t\t\t", freqData.idpreceptor);
        printf("%s\t", freqData.observacao);
        printf("\n");
    }
  delay(5);

    // Fechar o arquivo
    fclose(file);
}

