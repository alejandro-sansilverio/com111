#include<stdio.h>
#include<stdlib.h>

#ifndef FILAENC_H
#define FILAENC_H

typedef struct no No;
typedef struct filaEnc FilaEnc;

FilaEnc* Fenc_criar();
int Fenc_liberar(FilaEnc* f);
int Fenc_enfileirar(FilaEnc* f, float v);
float Fenc_desenfileirar(FilaEnc* f);
float Fenc_comeco (FilaEnc* f);
int Fenc_esvaziar(FilaEnc* f);
int Fenc_vazia(FilaEnc* f);
int Fenc_tamanho(FilaEnc* f);
int Fenc_imprimir(FilaEnc* f);

#endif
