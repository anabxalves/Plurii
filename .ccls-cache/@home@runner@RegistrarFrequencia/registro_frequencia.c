#include <stdio.h>
#include <time.h> //necessário para usar localtime() e struct tm
#include <stdlib.h>


//system("cls"); ou system("clear||cls"); procurar função para limpar terminal.
int main(void)
{
  // variaveis
  int option = 0;
  //Pegar o nome do usuário de um arquivo.

  //Menu Qr code ou formulário 
  printf("Digite a opção desejada: \n1-Ler QRCode \n2-Registro manual:\n")
  scanf("%d\n", &option);

  switch (option){
    case 1: // Qrcode
       
     break;
    case 2:
      
     break;
    default:
      printf("Opção Inválida. Digite novamente: ");
      break;
  }
  

  
  /* Usar a função localtime() para retornar a data e hora atual (local) em s      seus programas C*/
  //Código da data e hora. 
    // ponteiro para struct que armazena data e hora
    struct tm *data_hora_atual;

    // variável para armazenar o tempo em segundos
    time_t segundos;

    // obtendo o tempo em segundos
    time(&segundos);

    // converter de segundos para o tempo local usando a função localtime
    data_hora_atual = localtime(&segundos);

    /* Formatando a data no formato dia/mes/ano */
    printf("\nData ........: %d/", data_hora_atual->tm_mday);
    printf("%d/", data_hora_atual->tm_mon + 1);      // mês
    printf("%d\n", data_hora_atual->tm_year + 1900); // ano

    /*  Formatando a hora no formato HH: MM: SS  */

    printf("\nHora ........: %d:", data_hora_atual->tm_hour); // hora
    printf("%d:", data_hora_atual->tm_min);                   // minuto
    printf("%d\n", data_hora_atual->tm_sec);                  // segundo

    return 0;
}