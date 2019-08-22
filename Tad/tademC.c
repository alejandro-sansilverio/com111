TAD.h

/*
  * File: TAD.h
  * Criado em 22 de Agosto de 2019
 */
 
 #ifndef TAD_H
 #define TAD_H
 
 typedef struct matriz mat;
 
 // Função cria - Aloca e retorna matriz m por n
 
 
 //Libera a memória de uma matriz
 void libera(mat *m);
 
 //Acessa- Retorna o valor de um elemento [i][j]
 float acessa(mat *m, int i, int j);
 
 //Atribui valor ao elemento [i][j];
 float atribui(mat *m, int i, int j, float elemento);
 
 //Retorna o numero de linhas
 int linhas(mat *m);
 
 //Retorna o numero de colunas
 int colunas(mat *m);
 
 //preenche randomicamente
 void preencheAleatoriamente(mat *m);
 
 //Imprime a matriz cojm dimensões m por n
 void imprimeMatriz(mat *m);
 
 #endif /*TAD_H*/
 >
 TAD.c>
 
 #include<stdio.h>
 #include<stdlib.h>
 #include "TAD.h"
 
 struct matriz
 {
  int linhas;
  int colunas;
  float **v;
 };
 
 mat *cria(int m, int n)
 {
  mat *estrutura;
  float **mt;
  int i;
  
  estrutura = (mat*)malloc(sizeof
 }
