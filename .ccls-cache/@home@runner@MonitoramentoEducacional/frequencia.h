#ifndef FREQUENCIA_H
#define FREQUENCIA_H

/*
 * Define estrutura do arquivo
 */
struct frequencia {
    int idmatric;
    int anoFreq;
    int mesFreq;
    int diaFreq;
    int horaFreq;
    int minFreq;
    int segFreq;
    char entradasaida;
    char especialidade[10];
    char atividade[10];
    char validado; // valor S (sim) ou N(não)
    char aprovado; // valor S (sim) ou N(não)
    int idpreceptor; // ID do preceptor que validou a presença
    int anoValida;
    int mesValida;
    int diaValida;
    int horaValida;
    int minValida;
    int segValida;
    char observacao[50];
   
};

typedef struct frequencia FREQData;

// Estrutura da lista encadeada
struct Node {
    FREQData dados;
    struct Node* next;
};

typedef struct Node Node;

/* Funções da tela do residente */
void registerFrequencia(FREQData *freq_data);
void registerFrequenciaQ(FREQData *freq_data);
void frequencia_write(char *filename, FREQData *freq_data);
void lerQrcode(FREQData *freq_data);
void lerArquivoFrequencia();
void flush_in();

//void printFreq();
void viewFreq();
void sortFreq();
void loadFileToList(const char* filename, Node** head);
void insertNodeFreq(Node** head, FREQData data);
void displayList(Node* head);
void saveSortList(const char* filename, Node* head) ;


/* Funções da tela preceptor */
void insertNode(struct Node** head, FREQData dados);
void saveListToFile(struct Node* head);
void validaFrequencia(int anoI,int mesI,int diaI,int anoF,int mesF,int diaF, int diaA, int mesA, int anoA, int horaA, int minA, int segA);

/* Funções extras - complementares */
void converterMaiuscula(char *str);
void delay(int seconds);


#endif /* FREQUENCIA_H */