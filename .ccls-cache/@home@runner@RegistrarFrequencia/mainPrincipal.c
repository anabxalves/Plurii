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
      
  
      printf("Digite a opção desejada: \n\n1 - Menu Residente \n2 - Menu Preceptor \n0 - Sair do menu\n");
      printf("\n");
      scanf("%d", &opcMain);
        
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
