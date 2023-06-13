#include <stdio.h>

/* Limpar buffer teclado */

void flush_in(){
  int ch;
  do{
    ch =  fgetc(stdin);
  } while (ch != EOF && ch !='\n');
}