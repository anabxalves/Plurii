#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "frequencia.h"
#include "qrcode.h"
#include "myLibs.h"

void menuFreqResidente(){  
  int option = 30;
  FREQData *freq_data = NULL;
  
  while (option != 0) {
    system("clear"); // limpa a tela

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~ PLURII - MONITORAMENTO EDUCACIONAL ~~~~~~~~\n");
    printf("~~~~~~~~~~~~~ REGISTRO DE FREQUÊNCIA ~~~~~~~~~~~~~\n");     
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    
    // Pegar o nome do usuário de um arquivo.
      printf("Residente : 123456 - Maria Santos\n\n");
  
    printf("Digite a opção desejada: \n\n1 - Ler QRCode \n2 - Registro manual \n3 - Visualizar Frequências\n0 - Retornar ao menu anterior\n");
    printf("\n");
    scanf("%d", &option);
      
    switch (option) {
    case 1: // Qrcode
       lerQrcode(freq_data);
      option = 30;
      break;
    case 2: // Manual
      registerFrequencia(freq_data);
      option = 30;
      break;
    case 3: // Teste leitura do arquivo
      //printFreq(freq_data);
      viewFreq();
      option = 30;
      break;
    case 0:
      sortFreq();

      break;
    default:
      printf("Opção Inválida. Digite novamente: ");
      scanf("%d", &option); 
      getchar();
      break;
    }
  }
  return 0;
}