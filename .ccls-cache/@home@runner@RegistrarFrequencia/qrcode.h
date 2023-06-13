#ifndef QRCODE_H
#define QRCODE_H

struct qrCode {
    int idQrcode;
    int anoQr;
    int mesQr;
    int diaQr;
    int horaQr;
    int minQr;
    int segQr;
    char especialidade[20];
    int idpreceptor; // ID do preceptor que gerou o QRCode  
};

typedef struct qrCode QRCODE;
typedef struct frequencia FREQUENCIA;

/* Prototipo das funções da Tela do Preceptor */
void converterMaiuscula(char *str);
void delay(int seconds);
void exibirQRCode();
void registerQRCode(QRCODE newQRCode);

/* Prototipo das Funções da Tela do Residente */
void exibirQRCode();
void registerQRCode(QRCODE newQRCode);
QRCODE obterUltimoQRCode();
void lerQrcode(FREQUENCIA *freq_data);
void registerFrequenciaQ(FREQUENCIA *freq_data);

#endif /* QRCODE_H */