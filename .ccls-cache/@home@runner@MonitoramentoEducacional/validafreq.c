#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "frequencia.h"
#include "extra.h"

#define FREQUENCIA_FILENAME "database/hc_frequencia.txt"

void saveValidaFreq(struct Node* head) {
    FILE* arquivo = fopen(FREQUENCIA_FILENAME, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        fwrite(&(current->dados), sizeof(FREQData), 1, arquivo);
        current = current->next;
    }

    fclose(arquivo);
}

struct Node* loadFreqValida() {
    struct Node* head = NULL;
    FILE* arquivo = fopen(FREQUENCIA_FILENAME, "rb");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo para leitura!\n");
        return NULL;
    }
    while (!feof(arquivo)) {
        FREQData frequencia;
        if (fread(&frequencia, sizeof(FREQData), 1, arquivo) == 1) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->dados = frequencia;
            newNode->next = NULL;

            if (head == NULL) {
                head = newNode;
            } else {
                struct Node* current = head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }
    }

    fclose(arquivo);
    return head;
}

void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

void validaFrequencia(int anoI, int mesI, int diaI, int anoF, int mesF, int diaF, int diaA, int mesA, int anoA, int horaA, int minA, int segA) {
    char status = 'S', valida;
    char obs[100];
    int option = 1;
  
    struct Node* head = loadFreqValida();
    if (head == NULL) {
        printf("Não há frequências pendentes de validação para o período informado!\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        if (current->dados.validado == 'S'){
           status = 'N';
        } else {
          if ((current->dados.anoFreq >= anoI && current->dados.anoFreq <= anoF) &&
            (current->dados.mesFreq >= mesI && current->dados.mesFreq <= mesF) &&
            (current->dados.diaFreq >= diaI && current->dados.diaFreq <= diaF) &&
            (current->dados.validado == 'N')) {

            printf("Data : %02d/%02d/%d\n", current->dados.diaFreq, current->dados.mesFreq, current->dados.anoFreq);
            printf("Hora: %02d:%02d:%02d\n", current->dados.horaFreq, current->dados.minFreq, current->dados.segFreq);
            printf("Entrada/Saída (E/S) : %c\n", current->dados.entradasaida);
            printf("Atividade : %s\n\n", current->dados.atividade);
                
            printf("Valida Frequencia (S/N)? ");
            scanf(" %c", &valida);
            getchar();
            printf("Observação : ");
            fgets(obs, 100, stdin);
            obs[strcspn(obs, "\n")] = '\0'; // Remover o caractere de nova linha
            converterMaiuscula(obs);
              
            if (valida == 'S' || valida == 's' ) {
                // Atualiza o registro
                current->dados.validado = 'S';
                current->dados.aprovado = 'S';
                current->dados.idpreceptor = 987654;
                current->dados.anoValida = anoA;
                current->dados.mesValida = mesA;
                current->dados.diaValida = diaA;
                current->dados.horaValida = horaA;
                current->dados.minValida = minA;
                current->dados.segValida = segA;
                strcpy(current->dados.observacao,obs);
                status = 'S';
            } else if (valida == 'N' || valida == 'n' ){
                current->dados.validado = 'S';
                current->dados.aprovado = 'N';
                current->dados.idpreceptor = 987654;
                current->dados.anoValida = anoA;
                current->dados.mesValida = mesA;
                current->dados.diaValida = diaA;
                current->dados.horaValida = horaA;
                current->dados.minValida = minA;
                current->dados.segValida = segA;
                strcpy(current->dados.observacao,obs);
                status = 'S';
            } 
            printf("------------------------------------------------\n");
          }        
        }
        current = current->next;
    }

    if (status == 'N') {
        printf("Não há frequências pendentes de validação.\n");
    } else {
        // Salva a lista ordenada no arquivo hc_frequencia.txt
        saveValidaFreq(head);
    }

    // Liberar a memória alocada para a lista encadeada
    freeList(head);
}

int validarFreq() {
    int anoI, mesI, diaI, anoF, mesF, diaF;
    int diaA, mesA, anoA, horaA, minA, segA;
    int opcValFreq = 10;
    char opcVF;

    /* obter data e hora atual */
    time_t segundos = time(NULL);
    struct tm *c_datetime = localtime(&segundos);
    time(&segundos);

    diaA = c_datetime->tm_mday;
    mesA = c_datetime->tm_mon + 1;
    anoA = c_datetime->tm_year + 1900;
    horaA = c_datetime->tm_hour;
    minA = c_datetime->tm_min;
    segA = c_datetime->tm_sec;

    system("clear"); // limpa a tela
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~ MONITORAMENTO PROGRAMA DE RESIDENCIA ~~~~~~\n");
    printf("~~~~~~~~~~~~~~ VALIDAÇÃO FREQUENCIA ~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    printf("Preceptor: 987654 - Marcos Ferreira\n\n");

    while (opcValFreq != 0) {
        // Data inicio para validação
        printf("Digite o período desejado:\n");
        printf("Data Inicial (DD MM AAAA): ");
        scanf("%d %d %d", &diaI, &mesI, &anoI);
        printf("Data final (DD MM AAAA): ");
        scanf("%d %d %d", &diaF, &mesF, &anoF);
        printf("\n\n");

        if ((anoI > anoA) || (anoF > anoA) || (anoF < anoI)) {
            printf("Data inválida. Digite novamente!\n");
        } else if ((mesI <= 0) || (mesF > 12) || (mesI > mesA) || (mesF > mesA)) {
            printf("Data inválida. Digite novamente!");
        } else if (((diaI <= 0) || (diaI > 31)) || ((diaF <= 0) || (diaF > 31)) || (diaI > diaA) || (diaF > diaA)) {
            printf("Data Inválida. Digite novamente!\n");
        } else {
            validaFrequencia(anoI, mesI, diaI, anoF, mesF, diaF, diaA, mesA, anoA, horaA, minA, segA);
            printf("Deseja continuar a validação das Frequências (S/N)? ");
            scanf(" %c", &opcVF);
            if (opcVF == 'N' || opcVF == 'n') {
                opcValFreq = 0;
            }
        }
    }
    return 0;
}

