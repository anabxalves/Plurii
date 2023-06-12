#include <stdio.h>
#include <stdlib.h>
#include "myLibs.h"
#include "grade.h"

void menuResidente() {
  int opcMainR = 10;

 //  while (opcMainR != 0) {
      system("clear"); // limpa a tela
  
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      printf("~~~~~~ PLURII - MONITORAMENTO EDUCACIONAL ~~~~~~~~\n");
      printf("~~~~~~~~~~~~~~~~~ MENU RESIDENTE ~~~~~~~~~~~~~~~~~\n");     
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
      
      // Pegar o nome do usuário de um arquivo.
      printf("Residente : 123456 - Maria Santos\n\n");
  
      printf("Digite a opção desejada: \n\n1 - Frequência \n2 - Avaliações \n3 - Feedbacks \n4 - Calendário Acadêmico(Em Desenvolvimento) \n0 - Sair\n");
      printf("\n");
      scanf("%d", &opcMainR);
        
      switch (opcMainR) {
      case 1: // Registro de Frequencia
        menuFreqResidente();
        menuResidente();
        opcMainR = 10;
        break;
      case 2: // Manual
        viewGrade();
        menuResidente();
        opcMainR = 10;
        break;
      case 3: 
        viewFeedback();
        menuResidente();
        opcMainR = 10;
        break;
      case 4: 
        // Visualização do Calendário Acadêmico
        opcMainR = 10;
        break;
      case 0:
        flush_in();
        //exibirMenuPrincipal();
        exit(0);
        break;
      default:
        printf("Opção Inválida. Digite novamente: ");
        scanf("%d", &opcMainR); 
        getchar();
        break;
      }
   //menuResidente(); 
//  }
}
