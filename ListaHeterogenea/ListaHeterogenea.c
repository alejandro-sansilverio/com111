// TAD para Lista Heterogenea

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListaHeterogenea.h"
#define PI 3.14159265

struct noHET {
  int  tipo;  // tipo da info armazenada
  void *info; // ponteiro p/ a  informação
  struct noHET *prox; // ponteiro p/ o  próximo
};
struct retangulo {
  float b;
  float h;
};

struct triangulo {
  float b;
  float h;
};

struct circulo {
  float r;
};

//*************************** F01 *******************************
Retangulo* criar_retangulo()
{
  Retangulo *retangulo = (Retangulo*) malloc(sizeof(Retangulo));

  printf("\n Retangulo: ");
  printf("\n   base: ");
  scanf("%f", &retangulo->b);

  printf("   altura: ");
  scanf("%f", &retangulo->h);

  return retangulo;
}

//*************************** F02 *******************************
Triangulo* criar_triangulo()
{
  Triangulo *triangulo = (Triangulo*) malloc(sizeof(Triangulo));

  printf("\n Triangulo: ");
  printf("\n   base: ");
  scanf("%f", &triangulo->b);

  printf("   altura: ");
  scanf("%f", &triangulo->h);

  return triangulo;
}

//*************************** F03 *******************************
Circulo* criar_circulo()
{
  Circulo *circulo = (Circulo*) malloc(sizeof(Circulo));

  printf("\n Circulo: ");
  printf("\n   raio: ");
  scanf("%f", &circulo->r);

  return circulo;
}

//******************************* F04 *************************************
// função para alocar memória do tipo Lista
TipoLHET *LhetCria( )
{
  // 'lhet' é um ponteiro para ponteiro do tipo Elemento
  TipoLHET *lhet = (TipoLHET*) malloc(sizeof(TipoLHET));

  // se a alocação estiver correta 'lhet' aponta para NULL (lista vazia)
  if(lhet != NULL)
    *lhet = NULL;
  else
    return NULL;
  return lhet;
}


// *********************************** F05 **********************************
// função para liberar memória
int Lhetliberar(TipoLHET *lhet)
{
  // verifica se a lista foi alocada corretamente
  if(lhet == NULL){
    return 0;
  }

  // verifica se a lista não está vazia
  if((*lhet) != NULL){
    TipoNHET *no, *aux;
    no = *lhet;

    // laço percorre a lista até o último elemento, liberando o anterior
    while( no->prox !=  NULL ){
      aux = no;
      no = no-> prox;
      free(aux);
    }

    // libera o último elemento
    free(no);

    // libera o ponteiro de ponteiro (Lista)
    (*lhet) = NULL;
     lhet  = NULL;
  }

  return 1;
}

//*********************************  F06  ***********************************
// função para obter o tamanho da lista
int Lhet_tamanho(TipoLHET *lhet)
{
  // verifica se a lista foi alocada corretamente ou se a lista está vazia
  if(lhet == NULL   || (*lhet) == NULL ){
    return 0;
  }

  // inicializa o contador de elementos
  int cont = 0;

  // cria um ponteiro do tipo Elemento que aponta para o primeiro elemento da lista
  TipoNHET *no;
  no = *lhet;

  // incrementa 'cont' até achar o último elemento da lista
  do{
    cont++;
    no = no->prox;
  } while(no != NULL);

  // retorna a quantidade de elementos da lista
  return cont;

}

//**********************************  F07  *********************************
// função para verificar se a lista está vazia
int Lhet_vazia(TipoLHET *lhet)
{
  // verifica se houve problema na criação da lista
  // ou seja, 'lhet' não é uma lista válida ou não criada
  if(lhet == NULL){
    return -1;
  }

  // verifica se a lista foi criada corretamente
  // mas não contém nenhum valor (lista vazia)
  if((*lhet) == NULL){
    return 1;
  }

  // se houver elementos, retorna 0
  return 0;
}


//******************************* Auxiliar para Inserção ***********************************
// função para alocar memória do tipo Elemento
static TipoNHET* Nhet_criar()
{
  // 'no' é um ponteiro do tipo Elemento
  TipoNHET *no = (TipoNHET*) malloc(sizeof(TipoNHET));

  // verifica se a memória foi alocada corretamente
  if(no == NULL){
    return 0;
  }

  // retorna ponteiro alocado
  return no;
}


//*******************************  F08  *************************************
// função para inserir elemento no início da lista
int Lhet_inserir_inicio(TipoLHET *lhet, int tipo)
{
  //int ok;
  // verifica se a lista foi criada corretamente
  if(lhet == NULL){
    return 0;
  }

  // cria um elemento novo ('no' precisa ser alocado pois estamos inserindo ele na lista)
  TipoNHET *no;
  no = Nhet_criar();

  // atribui valores ao elemento novo
  no->tipo = tipo;
  Retangulo *retangulo;
  Triangulo *triangulo;
  Circulo   *circulo;
  switch(tipo){

      case 0:

        retangulo = criar_retangulo();
        no->info = retangulo;

      break;

      case 1:

        triangulo = criar_triangulo();
        no->info = triangulo;

      break;

      case 2:

        circulo = criar_circulo();
        no->info = circulo;
   }
  // verifica se a lista está vazia
  if((*lhet) == NULL){

    // insere elemento único no início da lista
    no->prox = NULL;  // próximo elemento na lista circular é ele mesmo
    *lhet = no;       // 'no' passa a ser o primeiro elemento da lista

  }else{

     // insere elemento no início da lista
     //  aux->prox = no; // 'no' é o próximo elemento na lista circular após o último
     no->prox = *lhet; // primeiro elemento antigo '*li' é o próximo após o 'no'
     *lhet = no;       // 'no' passa a ser o primeiro elemento

  }
  return 1;
}


//**********************************  F09  *********************************
// função para inserir elemento no final da lista
int Lhet_inserir_final(TipoLHET *lhet, int tipo)
{
  // verifica se a lista foi criada corretamente
  if(lhet == NULL){
    return 0;
  }

  // cria um elemento novo ('no' precisa ser alocado pois estamos inserindo ele na lista)
  TipoNHET *no;
  no = Nhet_criar();

  // atribui valores ao elemento novo
  no->tipo = tipo;
  Retangulo *retangulo;
  Triangulo *triangulo;
  Circulo   *circulo;
  switch(tipo){

      case 0:

        retangulo = criar_retangulo();
        no->info = retangulo;

      break;

      case 1:

        triangulo = criar_triangulo();
        no->info = triangulo;

      break;

      case 2:

        circulo = criar_circulo();
        no->info = circulo;
   }
  // verifica se a lista está vazia
  if((*lhet) == NULL ){

    // insere elemento único no início da lista
    no->prox = NULL;  // próximo elemento na lista circular é ele mesmo
    *lhet = no;       // 'no' passa a ser o primeiro elemento da lista

  }else{

    TipoNHET *aux;
    aux = *lhet;

    // percorre a lista até o último elemento
    while(aux->prox != NULL){
      aux = aux->prox;
    }

    // insere elemento no final da lista
    aux->prox = no;  // 'no' é colcado após o último
   }
  return 1;
}

// ***********************************  F10  *********************************
//  função para remover elemento do início da lista
int Lhet_remover_inicio(TipoLHET *lhet)
{
  // verifica se a lista foi criada corretamente
  if(lhet == NULL){
    return 0;
  }

  // verifica se a lista está vazia (não existem elementos a serem removidos)
  if((*lhet) == NULL){
    return 0;
  }

  // verifica se existe apenas um elemento na lista (após remoção a lista fica vazia)
  if ((*lhet)->prox == NULL){

    // libera elemento único
    free(*lhet);
    // indica que a lista ficou vazia
    *lhet = NULL;

    return 1;
  }

  TipoNHET *no, *aux;
  no  = *lhet; // 'no' é o elemento a ser removido
  aux = *lhet;

  // percorre a lista até o último elemento
  while(aux->prox != NULL){
    aux = aux->prox;
  }

  // remove o primeiro elemento da lista
  //aux->prox = no->prox; // 'no->prox' é o próximo elemento na lista circular após o último
  *lhet = no->prox;       // primeiro elemento da lista '*li' passa a ser o 'no->prox'

  // libera Elemento 'no'
  free(no);

  return 1;
}


// *******************************  F11  ************************************
// função para remover elemento do final da lista
int Lhet_remover_final(TipoLHET *lhet)
{
  // verifica se a lista foi criada corretamente
  if(lhet == NULL){
    return 0;
  }

  // verifica se a lista está vazia (não existem elementos a serem removidos)
  if((*lhet) == NULL){
    return 0;
  }

  // verifica se existe apenas um elemento na lista (após remoção a lista fica vazia)
  if ((*lhet)->prox == NULL){

    // libera elemento único
    free(*lhet);
    // indica que a lista ficou vazia
    *lhet = NULL;

    return 1;
  }

  TipoNHET *anterior, *no;
  no = *lhet; // 'no' é o elemento a ser removido

  // percorre a lista até 'no' ser o último elemento, armazenando o elemento anterior
  while(no->prox != NULL){
    anterior = no;
    no = no->prox;
  }

  // remove o último elemento da lista
  anterior->prox = NULL;
  // libera Elemento 'no'
  free(no);

  return 1;

}

// *******************************  F12  ************************************
//  função para remover o elemento que está na posição 'pos'
//  (primeiro elemento está na posição '1')
int Lhet_remover_pos(TipoLHET *lhet,  int pos)
{
     // verifica se a lista foi criada corretamente
     if(lhet == NULL){
         return 0;
     }

    // verifica se a lista está vazia (não existem elementos a  // serem removidos)
    if((*lhet) == NULL){
         return 0;
    }

    if (pos == 1){
      // verifica se existe apenas um elemento na lista
      // (após remoção a lista fica vazia)
       if ((*lhet)->prox == NULL){

         // libera elemento único
         free(*lhet);
         // indica que a lista ficou vazia
        *lhet = NULL;
         return 1;
       }

    }

    // percorre a lista até achar posicao desejada,
    // ou até encontrar o último elemento

    int i = 1;
    TipoNHET  *anterior, *no ;
    no = *lhet;

    while( no->prox != NULL && i < pos){
         anterior = no;
         no = no->prox;
         i++;
    }
    if(i != pos){
       return 0;
    }
    else {

       // remove o  elemento da lista
       anterior->prox = no->prox;
       // libera Elemento 'no'
       free(no);
    }
    return 1;
}

// *******************************  F13  ************************************
//  função para buscar o elemento que está na posição 'pos' (primeiro elemento está na posição '1')
TipoNHET *Lhet_buscar_pos(TipoLHET *lhet, int pos)
{
  // verifica se a lista foi criada corretamente, se está vazia ou se a posição 'pos' é inválida
  if(lhet == NULL || (*lhet) == NULL || pos <= 0){
    return NULL;
  }

  int i = 1;
  TipoNHET *no;
  no = *lhet;

  // percorre a lista até achar posicao desejada, ou até encontrar o último elemento
  while( no->prox != NULL && i < pos){
    no = no->prox;
    i++;
  }

  // verifica se a posicao desejada existe na lista
  if(i != pos){
    return NULL;
  }

  // retorna o valor do elemento na posicao 'pos'
  return no;

}

// *******************************  F14 ************************************
// função para buscar os elementos de um dado "tipo"
TipoLHET *Lhet_buscar_tipo(TipoLHET *lhet, int tipo)
{
  // verifica se a lista foi criada corretamente ou se está vazia
  if(lhet == NULL || (*lhet) == NULL){
    return NULL;
  }
  TipoLHET *lr;
  lr = LhetCria();
  TipoNHET *no, *noa, *nor;


  no = *lhet;
  // percorre a lista até encontrar o último elemento
  while(no->prox != NULL){
    if (no->tipo == tipo){
       nor = Nhet_criar();
        nor->tipo = no->tipo;
        nor->info = no->info;
        nor->prox = NULL;
        if((*lr) == NULL){
           *lr = nor;
        }
        else{
          noa = *lr;
          while(noa->prox != NULL){
             noa = noa->prox;
          }
          noa->prox = nor;
        }
     }
     no = no->prox;
  }
  //checa o ultimo
  if (no->tipo == tipo){
        nor = Nhet_criar();
        nor->tipo = no->tipo;
        nor->info = no->info;
        nor->prox = NULL;
        if((*lr) == NULL){
           *lr = nor;
        }
        else{
          noa = *lr;
          while(noa->prox != NULL){
             noa = noa->prox;
          }
          noa->prox = nor;
        }
  }
  // retorna a lista

  return lr;

}

//*******************************  F15  ************************************
void Lhet_imprimir(TipoLHET *lhet)
{
  // verifica se a lista foi criada corretamente
   if(lhet == NULL){
      printf(" Lista Não Criada!");
      return;
   }
  // verifica se a lista esta vazia
  if((*lhet) == NULL){
    printf(" Lista vazia!");
    return;
  }

  // posiciona no primeiro elemento
  TipoNHET *no;
  no = (*lhet);

  // percorre lista até o último elemento imprimindo
  while(no->prox != NULL){
    Nhet_imprimir(no);
    no = no->prox;
  }

  // imprime último elemento
  Nhet_imprimir(no);

  return;
}


//********************************  F16 ************************************
int Nhet_imprimir(TipoNHET *no)
{
  Retangulo *r;
  Triangulo *t;
  Circulo   *c;
  switch(no->tipo) {
    case RET:

      r = no->info;
      printf("\n\n   Retangulo:");
      printf("\n\t   base: %f",r->b);
      printf("\n\t   altura: %f",r->h);
      printf("\n\t   area: %f",Nhet_area(no));
      break;

    case TRI:

      t = no->info;
      printf("\n\n   Triangulo:");
      printf("\n\t   base: %f",t->b);
      printf("\n\t   altura: %f",t->h);
      printf("\n\t   area: %f",Nhet_area(no));
      break;

    case CIR:

      c = no->info;
      printf("\n\n   Circulo:");
      printf("\n\t   raio: %f",c->r);
      printf("\n\t   area: %f",Nhet_area(no));
      break;
  }
  return 1;
}
//********************************  Aux ************************************
//Auxiliar no Calcula a área de um elemento
//função para cálculo da área de um retângulo
static float ret_area (Retangulo* r){
   return r->b * r->h;
}
//função para cálculo da área de um triângulo
static float tri_area (Triangulo* t){
   return (t->b * t->h) / 2;
}
//função para cálculo da área de um triângulo
static float cir_area (Circulo* c){
   return PI * c->r * c->r;
}

//********************************  F17 ************************************
//Calcula a área de um elemento
float Nhet_area(TipoNHET *p){
    float a;
    switch (p->tipo) {
      case RET:
         a = ret_area((Retangulo*)p->info);
      break;
      case TRI:
         a = tri_area((Triangulo*)p->info);
      break;
      case CIR:
         a = cir_area((Circulo*)p->info);
      break;
    }
    return a;
}


