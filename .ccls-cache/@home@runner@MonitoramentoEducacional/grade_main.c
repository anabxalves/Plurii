#include <stdio.h>
#include <string.h>
#include "grade.h"

int gradeMain() {

  
  int opcMainR = 10;

 

      system("clear"); // limpa a tela
  
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      printf("~~~~~~ PLURII - MONITORAMENTO EDUCACIONAL ~~~~~~~~\n");
      printf("~~~~~~~~~~~~~~~~~ MENU PRECEPTOR ~~~~~~~~~~~~~~~~~\n");     
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
      
      // Pegar o nome do usuário de um arquivo.
      printf("Preceptor: 987654 - Marcos Ferreira\n\n");;
  
      printf("Digite a opção desejada: \n\n1 - Inserir nota e feedback de aluno \n2 - Visualizar nota do aluno \n");
      printf("\n");
      scanf("%d", &opcMainR);
        
      switch(opcMainR){
        case 1:
          chooseStudent();
          break;
        case 2:
          viewGrade();
          break;
        default:
          break;
      }
   
     
  return 0;
}