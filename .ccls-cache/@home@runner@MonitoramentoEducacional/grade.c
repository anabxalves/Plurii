#include <stdio.h>
#include <string.h>
#include "grade.h"
#include <time.h>


#define NOTAS_FILENAME "database/hc_notas.txt"
#define TEMP_FILENAME "database/temp.txt"

void chooseStudent() {
  FILE *file;
  char studentName[50];
  int flag = 0;
  
  system("clear");
  
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("~~~~~~ MONITORAMENTO PROGRAMA DE RESIDENCIA ~~~~~~\n");
  printf("~~~~~~~~~~~~~~ AVALIAÇÃO RESIDENTES ~~~~~~~~~~~~~~\n");     
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  printf("Preceptor: 987654 - Marcos Ferreira\n\n");
  flush_in();
  printf("Digite o nome do aluno: ");
  fgets(studentName, 51, stdin);
  studentName[strcspn(studentName, "\n")] = '\0';
  
   
  file = fopen(NOTAS_FILENAME, "r");

  if (file == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }
  
  //getchar();
  char line[100];
  while (fgets(line, 100, file) != NULL) {
    if (strstr(line, studentName) != NULL) {
      flag = 1;
      break;
    }
  }

  if (flag) {
    printf("Aluno encontrado.\n");

    Student student;
    strcpy(student.name, studentName);
    fscanf(file, "ID: %d\n", &student.id);
    fgets(line, 100, file);
    fgets(student.activities, 50, file);
    fgets(line, 100, file);

    submitGrade(student, studentName);
  } else {
    printf("Aluno não encontrado.\n");
  }

  fclose(file);
}

void submitGrade(Student student, char *studentName) {
  system("clear");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("~~~~~~ MONITORAMENTO PROGRAMA DE RESIDENCIA ~~~~~~\n");
  printf("~~~~~~~~~~~~~~ AVALIAÇÃO RESIDENTES ~~~~~~~~~~~~~~\n");     
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  printf("Atividade: ");
  fgets(student.activities, 50, stdin);
  student.activities[strcspn(student.activities, "\n")] = '\0';

  printf("Nota: ");
  scanf("%f", &student.grade);
  getchar();
  printf("Feedback: ");
  fgets(student.feedback, 250, stdin);
  student.feedback[strcspn(student.feedback, "\n")] = '\0';

  saveFile(student, studentName);
}

void saveFile(Student student, char *studentName) {
  FILE *arquivo;
  FILE *arquivoTemp;
  char linha[100];
  int encontrado = 0;

  arquivo = fopen(NOTAS_FILENAME, "r");
  arquivoTemp = fopen(TEMP_FILENAME, "w");

  if (arquivo == NULL || arquivoTemp == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  while (fgets(linha, 100, arquivo) != NULL) {
    if (strstr(linha, studentName) != NULL) {
      encontrado = 1;
      fprintf(arquivoTemp, "%s", linha);
      fgets(linha, 100, arquivo);
      fprintf(arquivoTemp, "%s", linha);
      fprintf(arquivoTemp, "Atividade: %s  ->  ", student.activities);
      fprintf(arquivoTemp, "Nota: %.2f\n", student.grade);
      fprintf(arquivoTemp, "Feedback(%s): %s\n", student.activities, student.feedback);
    } else {
      fprintf(arquivoTemp, "%s", linha);
    }
  }

  if (!encontrado) {
    printf("Aluno não encontrado.\n");
  }

  fclose(arquivo);
  fclose(arquivoTemp);

  remove(NOTAS_FILENAME);
  rename(TEMP_FILENAME, NOTAS_FILENAME);
}

void viewGrade() {
    FILE *file;
    char studentName[50];
    int flag = 0;
    flush_in();

    system("clear");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~ PLURII - MONITORAMENTO EDUCACIONAL ~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~ AVALIAÇÃO RESIDENTES ~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("Digite o nome do Aluno: ");
    fgets(studentName, 50, stdin);
    studentName[strcspn(studentName, "\n")] = '\0';

    file = fopen(NOTAS_FILENAME, "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char line[100];
    while (fgets(line, 100, file) != NULL) {
        if (strstr(line, studentName) != NULL) {
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("Aluno encontrado.\n");
        fgets(line, 100, file); 

        printf("Notas do aluno %s:\n", studentName);
        while (fgets(line, 100, file) != NULL && strncmp(line, "Nome do Aluno:", 14) != 0) {
            if (strncmp(line, "Atividade:", 10) == 0) {
                printf("%s", line);
            }
            if (strncmp(line, "Nota:", 5) == 0) {
                printf("%s\n", line);
            }
        }
    } else {
        printf("Aluno não encontrado.\n");
    }
    delay(5);
    fclose(file);
}

void viewFeedback() {
    system("clear");
    FILE *file;
    char studentName[50];
    int flag = 0;
    flush_in();
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~ PLURII - MONITORAMENTO EDUCACIONAL ~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~ AVALIAÇÃO RESIDENTES ~~~~~~~~~~~~~~\n");     
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("Digite o nome do Aluno: ");
    fgets(studentName, 50, stdin);
    studentName[strcspn(studentName, "\n")] = '\0';

    file = fopen(NOTAS_FILENAME, "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char line[100];
    while (fgets(line, 100, file) != NULL) {
        if (strstr(line, studentName) != NULL) {
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("Aluno encontrado.\n");
        fgets(line, 100, file);

        printf("Feedback do aluno %s:\n", studentName);
        while (fgets(line, 100, file) != NULL && strncmp(line, "Nome do Aluno:", 14) != 0) {
            if (strncmp(line, "Feedback(", 9) == 0) {
                printf("%s\n", line);
            }
        }
    } else {
        printf("Aluno não encontrado.\n");
    }
    delay(5);
    fclose(file);
}


void viewResidentes() {
    system("clear");
    FILE *file;
    flush_in();

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~ MONITORAMENTO PROGRAMA DE RESIDENCIA ~~~~~~\n");
    printf("~~~~~~~~~~~~~~ AVALIAÇÃO RESIDENTES ~~~~~~~~~~~~~~\n");     
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    file = fopen(NOTAS_FILENAME, "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char line[100];
    while (fgets(line, 100, file) != NULL) {
        if (strncmp(line, "Nome do Aluno:", 10) == 0) {
            printf("%s\n", line);
        }
    }
    delay(5);
    fclose(file);
}
