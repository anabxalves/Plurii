#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "frequencia.h"
#include "extra.h"

#define FREQUENCIA_FILENAME "database/hc_frequencia.txt"

// Inserir um nó ordenadamente na lista
void insertNodeFreq(Node** head, FREQData dados) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    newNode->dados = dados;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        Node* prev = NULL;

        while (current != NULL) {
            if (dados.anoFreq < current->dados.anoFreq) {
                /* Inserir antes do nó atual */
                if (prev == NULL) {
                    /* O novo nó será o primeiro */
                    newNode->next = *head;
                    *head = newNode;
                } else {
                    /* Inserir no meio da lista */
                    prev->next = newNode;
                    newNode->next = current;
                }
                return;
            } else if (dados.anoFreq == current->dados.anoFreq) {
                if (dados.mesFreq < current->dados.mesFreq) {
                    /* Inserir antes do nó atual */
                    if (prev == NULL) {
                        /* O novo nó será o primeiro */
                        newNode->next = *head;
                        *head = newNode;
                    } else {
                        /* Inserir no meio da lista */
                        prev->next = newNode;
                        newNode->next = current;
                    }
                    return;
                } else if (dados.mesFreq == current->dados.mesFreq) {
                    if (dados.diaFreq < current->dados.diaFreq) {
                        /* Inserir antes do nó atual */
                        if (prev == NULL) {
                            /* O novo nó será o primeiro */
                            newNode->next = *head;
                            *head = newNode;
                        } else {
                            /* Inserir no meio da lista */
                            prev->next = newNode;
                            newNode->next = current;
                        }
                        return;
                    } else if (dados.diaFreq == current->dados.diaFreq) {
                        if (dados.idmatric < current->dados.idmatric) {
                            /* Inserir antes do nó atual */
                            if (prev == NULL) {
                                /* O novo nó será o primeiro */
                                newNode->next = *head;
                                *head = newNode;
                            } else {
                                /* Inserir no meio da lista */
                                prev->next = newNode;
                                newNode->next = current;
                            }
                            return;
                        } else if (dados.atividade == current->dados.atividade) {
                            if (dados.entradasaida < current->dados.entradasaida) {
                                /* Inserir antes do nó atual */
                                if (prev == NULL) {
                                    /* O novo nó será o primeiro */
                                    newNode->next = *head;
                                    *head = newNode;
                                } else {
                                    /* Inserir no meio da lista */
                                    prev->next = newNode;
                                    newNode->next = current;
                                }
                                return;
                            }
                        }
                    }
                }
            }
            /* Avançar para o próximo nó */
           
            prev = current;
            current = current->next;
        }
        /* Inserir no final da lista, pois o novo nó tem o maior valor */
        prev->next = newNode;
    }
}

// Carrega os dados do arquivo na lista
void loadFileToList(const char* filename, Node** head) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    FREQData dados;
    while (fread(&dados, sizeof(FREQData), 1, file)) {
        insertNodeFreq(head, dados);
    }

    fclose(file);
}

// Salvar os dados ordenados no arquivo
void saveSortList(const char* filename, Node* head) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        fwrite(&(current->dados), sizeof(FREQData), 1, file);
        current = current->next;
    }

    fclose(file);
}

void sortFreq() {
    Node* head = NULL;

    // Carregar os dados do arquivo na lista
    loadFileToList(FREQUENCIA_FILENAME, &head);

    // Exibir a lista ordenada
    //displayList(head);

    // Salvar os dados ordenados no arquivo
    saveSortList(FREQUENCIA_FILENAME, head);

    // Liberação da memória
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}
