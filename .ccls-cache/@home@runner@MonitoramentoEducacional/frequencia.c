#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "frequencia.h"
#include "extra.h"
#include "myLibs.h"

/* Registro Frequencia manual */
void registerFrequencia(FREQData *freq_data)
{
  
  char atividade[20], especialidade[20];
  char entradasaida;
  int matricula = 123456;
  
/* ponteiro para struct que armazena data e hora */ 
  struct tm *c_datetime;
/*  variável para armazenar o tempo em segundos */ 
  time_t segundos = time(NULL);
/*  obtendo o tempo em segundos */ 
  time(&segundos);
/* converção segundos para o tempo local */ 
  c_datetime = localtime(&segundos);

/* alocação dinamica para registro da frequencia */
  freq_data = (FREQData *)malloc(sizeof(FREQData));

/* Inicio da tela de registro de frequencia manual */  
  system("clear"); // limpa a tela
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("~~~~~~ PLURII - MONITORAMENTO EDUCACIONAL ~~~~~~~~\n");
  printf("~~~~~~~~~~~~ REGISTRO DE FREQUÊNCIA ~~~~~~~~~~~~~~\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");


/* Exibir nome do usuário logado */
   printf("Residente : 123456 - Maria Santos\n\n");
  
/* Data e Hora local */
  printf("Data atual : %d/", c_datetime->tm_mday); // dia
  printf("%d/", c_datetime->tm_mon + 1);           // mês
  printf("%d\n", c_datetime->tm_year + 1900);      // ano

  printf("Hora atual :%d:", c_datetime->tm_hour); // hora
  printf("%d:", c_datetime->tm_min);             // minuto
  printf("%d\n", c_datetime->tm_sec);            // segundo
  
   
/* Entrada - especialidade */
  printf("Especilidade : ");
  flush_in();
  fgets(especialidade, 20, stdin);
  especialidade[strcspn(especialidade, "\n")] = '\0';
  
  converterMaiuscula(especialidade);

/* Entrada - Atividade */
  printf("Atividade : ");
  fgets(atividade, 10, stdin);
  atividade[strcspn(atividade, "\n")] = '\0'; // Remover o caractere de nova linha
 
  converterMaiuscula(atividade);
  
  /* Informe do registro da frequencia - Entrada ou Saída */
  printf("Digite (E)entrada ou (S)saída : ");
  scanf(" %c", &entradasaida);
  entradasaida = toupper(entradasaida); 

  printf("\n");
  
/* atribuição de valores as variaveis da struct*/
   freq_data->idmatric = matricula;
   freq_data->anoFreq = (*c_datetime).tm_year + 1900;  
   freq_data->mesFreq = (*c_datetime).tm_mon + 1; 
   freq_data->diaFreq = (*c_datetime).tm_mday;
   freq_data->horaFreq = (*c_datetime).tm_hour;
   freq_data->minFreq = (*c_datetime).tm_min;
   freq_data->segFreq = (*c_datetime).tm_sec;
   freq_data->entradasaida = entradasaida; 
   strcpy(freq_data->especialidade, especialidade);
   strcpy(freq_data->atividade, atividade);

 /* Reservado - validação do Preceptor (Tela Preceptor)*/
    freq_data->validado = 'N';  // Valor inicial 'não validado'
    freq_data->aprovado = 'N';  // Valor inicial 'não validado'
    freq_data->idpreceptor = 0; // Valor inicial zero
    freq_data->anoValida = 0;   // Valor inicial zero
    freq_data->mesValida = 0;   // Valor inicial zero
    freq_data->diaValida = 0;   // Valor inicial zero
    freq_data->horaValida = 0;  // Valor inicial zero
    freq_data->minValida = 0;   // Valor inicial zero
    freq_data->segValida = 0;   // Valor inicial zero
    strcpy(freq_data->observacao,"");   // 
  
/* Função p/ gravar o registro no arquivo */
  char filename[] = ("database/hc_frequencia.txt");
  frequencia_write(filename, freq_data); 
 
}

/* Gravar registro da frequencia num arquivo */
void frequencia_write(char *filename, FREQData *freq_data) {
  FILE *fp = fopen(filename, "a");
  if (fp == NULL || freq_data == NULL) {
    printf("Não foi possível abrir o arquivo para gravação\n");
    return;
  }

  fwrite(freq_data, sizeof(FREQData), 1, fp);
  printf("Registro da frequência realizado com sucesso.\n");
  delay(1);
  fclose(fp);
  free(freq_data);
}