#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "qrcode.h"
#include "myLibs.h"

// system("cls"); ou system("clear||cls"); função para limpar terminal.
int mainFreqPreceptor(void) {
  int option = 30;
  
  while (option != 0) {
    //freq_data = (FREQData *)malloc(sizeof(FREQData));
    system("clear"); // limpa a tela
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~ PLURII - MONITORAMENTO EDUCACIONAL ~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~ MENU DE FREQUENCIA ~~~~~~~~~~~~~~\n");     
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    
    // Pegar o nome do usuário de um arquivo.
    printf("987654 - Marcos Ferreira\n\n");
  
    printf("Digite a opção desejada: \n\n1 - Gerar QRCode \n2 - Validar Frequencia\n0 - Retornar ao menu anterior\n");
    printf("\n");
    scanf("%d", &option);
      
    switch (option) {
    case 1:
      // Gerar qrcode
      gerarQrcode();
      option = 30;
      break;
    case 2:    
      validarFreq();
      option = 30; 
      return 0;
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