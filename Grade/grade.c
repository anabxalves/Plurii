#include "grade.h"
#include <stdio.h>
#include <string.h>

void chooseStudent() {
  FILE *file;
  char studentName[50];
  int flag = 0;

  printf("Digite o nome do aluno: ");
  fgets(studentName, 50, stdin);
  studentName[strcspn(studentName, "\n")] = '\0';

  file = fopen("notas.txt", "r");

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

  arquivo = fopen("notas.txt", "r");
  arquivoTemp = fopen("temp.txt", "w");

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

  remove("notas.txt");
  rename("temp.txt", "notas.txt");
}

void viewGrade() {
    FILE *file;
    char studentName[50];
    int flag = 0;

    printf("Digite o nome do Aluno: ");
    fgets(studentName, 50, stdin);
    studentName[strcspn(studentName, "\n")] = '\0';

    file = fopen("notas.txt", "r");

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
                printf("%s", line);
            }
        }
    } else {
        printf("Aluno não encontrado.\n");
    }

    fclose(file);
}

