#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "frequencia.h"
#include "qrcode.h"

// system("cls"); ou system("clear||cls"); função para limpar terminal.
int main(void) {
  int option = 30;
  FREQData *freq_data = NULL;
  
  while (option != 0) {
    system("clear"); // limpa a tela

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~ REGISTRO DE FREQUÊNCIA ~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    
    // Pegar o nome do usuário de um arquivo.
    printf("Residente : 123456 - Maria Santos\n\n");
  
  
    printf("Digite a opção desejada: \n\n1 - Ler QRCode \n2 - Registro manual \n0 - Sair do menu\n");
    printf("\n");
    scanf("%d", &option);
      
    switch (option) {
    case 1: // Qrcode
       lerQrcode(freq_data);
      option = 30;
      break;
    case 2: // Mmanual
      registerFrequencia(freq_data);
      option = 30;
      break;
    case 0:
      break;
    default:
      printf("Opção Inválida. Digite novamente: ");
      scanf("%d", &option); 
      getchar();
      break;
    }
  }
  //free(freq_data);
  return 0;
}