#include <stdio.h>
#include <stdlib.h>
#include "myLibs.h"
#include "grade_main.h"
#include "grade.h"


void menuPreceptor() {
  int opcMainR = 10;

      system("clear"); // limpa a tela
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      printf("~~~~~~ PLURII - MONITORAMENTO EDUCACIONAL ~~~~~~~~\n");
      printf("~~~~~~~~~~~~~~~~~ MENU PRECEPTOR ~~~~~~~~~~~~~~~~~\n");     
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

      printf("Preceptor: 987654 - Marcos Ferreira\n\n");
  
      printf("Digite a opção desejada: \n\n1 - Frequência \n2 - Avaliações/Feedbacks \n3 - Atividade Diária \n4 - Calendário Acadêmico \n5 - Residentes \n0 - Retornar ao menu anterior\n");
      printf("\n");
      scanf("%d", &opcMainR);
        
      switch (opcMainR) {
      case 1: // Registro de Frequencia
        mainFreqPreceptor();
        menuPreceptor();
        opcMainR = 10;
        break;
      case 2: 
        gradeMain();
        menuPreceptor();
        opcMainR = 10;
        break;
      case 3: 
        //printf("Menu de Atividades Diária");
        opcMainR = 10;
        break;
      case 4: 
        //printf("Menu de Visualização do Calendário Acadêmico");
        opcMainR = 10;
        break;
      case 5: 
        viewResidentes();
        menuPreceptor();
        opcMainR = 10;
      case 0:
        opcMainR = 0;
        exibirMenuPrincipal();
        break;
      default:
        printf("Opção Inválida. Digite novamente: ");
        scanf("%d", &opcMainR); 
        getchar();
        break;
      }
   
}
