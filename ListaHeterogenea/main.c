// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
// bibliotecas do projeto
#include "ListaHeterogenea.h"

// funcao principal
int main(void) {
  TipoLHET *lhet = NULL, no, *lr = NULL;

 // Retangulo *retangulo;
 // Triangulo *triangulo;
 // Circulo   *circulo;

  int opcao, ok,tipo, pos;
  char continua;
 // menu de opções para execuções de operações sobre a lista
  do
  {
    printf("\nLista Heterogena");

    printf("\n\nMenu de opções: ");
    printf("\n  - Alocação da Lista:");
    printf("\n\t1 - Criar");
    printf("\n\t2 - Liberar");
    printf("\n  - Inserir elementos:");
    printf("\n\t3 - No início");
    printf("\n\t4 - No final");
    printf("\n  - Remover elementos:");
    printf("\n\t5-  Do início");
    printf("\n\t6 - Do final");
    printf("\n\t7 - De qualquer posição");
    printf("\n  - Buscar elementos:");
    printf("\n\t8  - Pela posição");
    printf("\n\t9  - Pelo tipo");
    printf("\n  - Detalhes da Lista:");
    printf("\n\t10 - Checar se vazia");
    printf("\n\t11 - Tamanho");
    printf("\n\t12 - Imprimir os elementos");
    printf("\n13 - Sair");
    printf("\n\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1:

        // criar lista
        lhet = LhetCria();

        if(lhet != NULL){
          printf("\n Lista criada com sucesso!");
        }else{
          printf("\n Lista não criada!");
        }
      break;


      case 2:
        if(lhet == NULL )
            printf("\n Lista Não Criada");
        else{
          // liberar lista
          ok = Lhetliberar(lhet);

          if(ok){
            printf("\n Lista liberada com sucesso!");
          }else{
            printf("\n Lista não liberada!");
          }
        }
      break;

      case 3:
        if(lhet == NULL )
            printf("\n Lista Não Criada");

        else{
          // inserir elemento no início
          do{
            printf("\n Tipo de Objeto a inserir: ");
            printf("\n\t 0 - retânguo: ");
            printf("\n\t 1 - triânguo: ");
            printf("\n\t 2 - circulo: ");
            printf("\nTipo: ");
            scanf("%d", &tipo);
          }while (tipo < 0 && tipo > 2);

          ok = Lhet_inserir_inicio(lhet, tipo);

          if(ok == 1)
            printf("\n Inserção realizada com sucesso!");
          else
            printf("\n Falha na inserção!");

        }
      break;

      case 4:
        if(lhet == NULL )
            printf("\n Lista Não Criada");

        else{
          // inserir elemento no final
          do{
            printf("\n Objeto a inserir: ");
            printf("\n\t 0 - retânguo: ");
            printf("\n\t 1 - triânguo: ");
            printf("\n\t 2 - circulo: ");
            printf("\n\t  tipo: ");
            scanf("%d", &tipo);
          }while (tipo < 0 && tipo > 2);

          ok = Lhet_inserir_final(lhet, tipo);

          if(ok == 1)
            printf("\n Inserção realizada com sucesso!");
          else
            printf("\n Falha na inserção!");

        }
      break;


      case 5:

        // remover elemento do início
        ok = Lhet_remover_inicio(lhet);

        if(ok == 1)
          printf("\n Remoção realizada com sucesso!");
        else
          printf("\n Falha na remoção!");

      break;

      case 6:

        // remover elemento do final
        ok = Lhet_remover_final(lhet);

        if(ok == 1)
          printf("\n Remoção realizada com sucesso!");
        else
          printf("\n Falha na remoção!");

        break;

      case 7:

        // remover elemento de qualquer posição
        printf("\n Posição do objeto a ser removido: ");
        scanf("%d", &pos);

        ok = Lhet_remover_pos(lhet, pos);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;


      case 8:

        // busca elemento pela posicao
        printf("\n Posição do elemento a ser buscado: ");
        scanf("%d", &pos);

        no = Lhet_buscar_pos(lhet, pos);

        if(no != NULL){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento da %dª posição: ", pos);
          Nhet_imprimir(no);
        }else printf("\n Posição não existe!");

        break;

      case 9:

        // busca elemento pelo tipo
        printf("\n Tipo do objeto a ser buscado: ");
        printf("\n\t 0 - retânguo: ");
        printf("\n\t 1 - triânguo: ");
        printf("\n\t 2 - circulo: ");
        printf("\n\t  tipo: ");
        scanf("%d", &tipo);
        lr = Lhet_buscar_tipo(lhet, tipo);
        if((*lr) != NULL ){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento com tipo %d : ", tipo);
          Lhet_imprimir(lr);
        }else{
          printf("\n Tipo não encontrado!");
        }

        break;

      case 10:
        // Checa se Lista Vazia
         ok = Lhet_vazia(lhet);
         if(ok == -1)
           printf("\n Lista inválida ou não criada");
         else
           if(ok == 1)
              printf("\n Lista vazia");
           else
              printf("\n Lista com elementos:  %d",Lhet_tamanho(lhet));
         break;

      case 11:

        // imprime Tamanho lista
        if( lhet != NULL)
            printf("\n Tamanho da Lista: %d", Lhet_tamanho(lhet));
        else
          if(lhet == NULL )
            printf("\n Lista Não Criada");
          else
           if(lhet == NULL )
              printf("\n Lista Vazia");

        break;

      case 12:

        // imprime a lista
        if(lhet != NULL)
        {
          printf("\n Lista Heterogenea: ");
          Lhet_imprimir(lhet);
        }
        else{
          if(lhet == NULL )
            printf("\n Lista Não Criada");
          else
           if(lhet == NULL )
              printf("\n Lista Vazia");
        }
        break;

      case 13:
        //SAIR
         if(lhet != NULL)
            // libera memória e finaliza programa
            Lhetliberar(lhet);
         printf("\nFinalizando...");
      break;

      default:
        printf("\nOpção inválida!");
      break;
    }
    while (getchar() != '\n');
    printf("\n\nTecle enter para continuar: ");
    scanf("%c",&continua);
    system("clear");

  }while(opcao != 13);

  return 0;
}
