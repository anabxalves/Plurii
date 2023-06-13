#include <stdio.h>
#include <stdlib.h>
#include "myLibs.h"

int main() {
  exibirMenuPrincipal();
  return 0;
}

void exibirMenuPrincipal() {
  int opcMain = 10;

      system("clear"); // limpra a tela
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      printf("~~~~~~~ PLURII - MONITORAMENTO EDUCACIONAL ~~~~~~~\n");
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
      
      login();
        
      switch (opcMain) {
      case 1: // Qrcode
        menuResidente();
        opcMain = 10;
        break;
      case 2: // Manual
        menuPreceptor();
        opcMain = 10;
        break;
      case 0:
        exit(0);
        break;
      default:
        printf("Opção Inválida. Digite novamente: ");
        scanf("%d", &opcMain); 
        getchar();
        break;
      }
  
}
