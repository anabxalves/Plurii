#include <stdio.h>
#include <string.h>
#include "grade.h"

int main() {

  int flag;
  
  printf("[1] Inserir note de aluno\n");
  printf("[2] Visualizar nota do aluno\n");
  scanf("%i", &flag);
  getchar();

  switch(flag){
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
