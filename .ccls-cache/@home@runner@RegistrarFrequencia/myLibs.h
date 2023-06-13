#ifndef MAIN_H
#define MAIN_H

/* Prototipo das Funções do Menu */
void exibirMenuPrincipal();
void menuPreceptor();
void menuResidente();
int main();

/* Prototipo das Funções do Menu do Residente */
//int mainFreqResidente(void);
void menuFreqResidente();

/* Prototipo das Funções do Menu do Preceptor */
int mainFreqPreceptor(void);

/* Limpar buffer */
void flush_in();

#endif /* MAIN_H */