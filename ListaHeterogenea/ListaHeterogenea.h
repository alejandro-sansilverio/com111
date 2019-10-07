// TAD para Lista Dinâmica Heterogenea
#ifndef LISTAHETEROGENEA_H
#define LISTAHETEROGENEA_H
#define RET 0
#define TRI 1
#define CIR 2

typedef struct retangulo Retangulo;
typedef struct triangulo Triangulo;
typedef struct circulo Circulo;

typedef struct noHET TipoNHET;
typedef TipoNHET* TipoLHET;


typedef struct retangulo Retangulo;
typedef struct triangulo Triangulo;
typedef struct circulo Circulo;

// funções para Criar Objetos Heterogenos
Retangulo * criar_retangulo( );//F01
Triangulo * criar_triangulo( );//F02
Circulo   * criar_circulo(  );//F03

// funções para alocar e desalocar memória
TipoLHET * LhetCria( );//F04
//TipoNHET * NhetCria(int tipo);//F05
int Lhetliberar(TipoLHET *lhet);//F05

// funções para obter informações da lista
int Lhet_tamanho(TipoLHET *lhet);//F06
int Lhet_vazia(TipoLHET *lhet);//F07

// funções para inserção de elementos da lista
int Lhet_inserir_inicio(TipoLHET *lhet, int tipo);//F08
int Lhet_inserir_final(TipoLHET *lhet, int tipo);//F09

// funções para remoção de elementos da lista
int Lhet_remover_inicio(TipoLHET *lhet);//F10
int Lhet_remover_final(TipoLHET *lhet);//F11
int Lhet_remover_pos(TipoLHET *lhet,  int pos);//F12

// funções para buscar elementos na lista
TipoNHET *Lhet_buscar_pos(TipoLHET *lhet, int pos);//F13
TipoLHET *Lhet_buscar_tipo(TipoLHET *lhet, int tipo);//F14

// funções para ver os elementos na lista
void Lhet_imprimir(TipoLHET *lhet);//F15
int Nhet_imprimir(TipoNHET *nhet);//F16

// funções para calculos sobre os elementos da lista
float Nhet_area(TipoNHET *nhet);//F17

#endif /* LISTAHETEROGENEA_H */
