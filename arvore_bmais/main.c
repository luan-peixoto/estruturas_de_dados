#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcao.h"

int main(void) {

  /* 
  NUMERO DE CHAVES POR NO
  MIN T - 1 MAX 2T -1
  NUMERO DE FILHOS POR NO
  MIN T MAX 2T

  RAIZ PODE TER QUALQUER UM
  */

  /*  VAI DESCENDO SE ENCONTRAR N APLICA 3A E 3B, SE FOR ENTRE NOHS INTERNOS APLICA COMO SE FOSSE ARVB, SE FOR NO INTERNO E FOLHA APLICA ARVB+
  */

 
  TARVBM* x = TARVBM_inicializa();
  x = TARVBM_cria(2); // T = 2
  x->folha = 0;
  x->nchaves = 1;
  x->chave[0] = 24;

  x->filho[0] = TARVBM_cria(2);
  x->filho[0]->folha = 0;
  x->filho[0]->nchaves = 2;
  x->filho[0]->chave[0] = 15;
  x->filho[0]->chave[1] = 20;


  x->filho[0]->filho[0] = TARVBM_cria(2);
  x->filho[0]->filho[0]->nchaves = 2;
  x->filho[0]->filho[0]->chave[0] = 10;
  x->filho[0]->filho[0]->chave[1] = 12;

  x->filho[0]->filho[1] = TARVBM_cria(2);
  x->filho[0]->filho[1]->nchaves = 1;
  x->filho[0]->filho[1]->chave[0] = 18;

  x->filho[0]->filho[2] = TARVBM_cria(2);
  x->filho[0]->filho[2]->nchaves = 2;
  x->filho[0]->filho[2]->chave[0] = 21;
  x->filho[0]->filho[2]->chave[1] = 23;

  x->filho[0]->filho[3] = TARVBM_cria(2);
  x->filho[0]->filho[3]->nchaves = 2;
  x->filho[0]->filho[3]->chave[0] = 20;
  x->filho[0]->filho[3]->chave[1] = 21;


  x->filho[1] = TARVBM_cria(2);
  x->filho[1]->folha = 0;
  x->filho[1]->nchaves = 3;
  x->filho[1]->chave[0] = 33;
  x->filho[1]->chave[1] = 45;
  x->filho[1]->chave[2] = 48;

  x->filho[1]->filho[0] = TARVBM_cria(2);
  x->filho[1]->filho[0]->nchaves = 3;
  x->filho[1]->filho[0]->chave[0] = 30;
  x->filho[1]->filho[0]->chave[1] = 31;
  x->filho[1]->filho[0]->chave[2] = 32;

  x->filho[1]->filho[1] = TARVBM_cria(2);
  x->filho[1]->filho[1]->nchaves = 3;
  x->filho[1]->filho[1]->chave[0] = 38;
  x->filho[1]->filho[1]->chave[1] = 39;
  x->filho[1]->filho[1]->chave[2] = 41;

  x->filho[1]->filho[2] = TARVBM_cria(2);
  x->filho[1]->filho[2]->nchaves = 1;
  x->filho[1]->filho[2]->chave[0] = 47;

  x->filho[1]->filho[3] = TARVBM_cria(2);
  x->filho[1]->filho[3]->nchaves = 3;
  x->filho[1]->filho[3]->chave[0] = 50;
  x->filho[1]->filho[3]->chave[1] = 52;
  x->filho[1]->filho[3]->chave[2] = 60;



  TARVBM_imprime(x);

  

  x = TARVBM_insere(x, 29, 2);
  printf("----\n");
  TARVBM_imprime(x);

  x = TARVBM_insere(x, 33, 2);
  printf("----\n");
  TARVBM_imprime(x);
  return 1;
  
  
  TARVBM* a1 = TARVBM_inicializa();
  a1 = TARVBM_insere(a1, 10, 2);
  a1 = TARVBM_insere(a1, 20, 2);
  a1 = TARVBM_insere(a1, 30, 2);

  TARVBM_imprime(a1);
  printf("\n--\n");
  a1 = TARVBM_insere(a1, 5, 2);
  TARVBM_imprime(a1);
  printf("\n--\n");
   a1 = TARVBM_insere(a1, 35, 2);
  TARVBM_imprime(a1);
  printf("\n--\n");
  a1 = TARVBM_insere(a1, 15, 2);
  TARVBM_imprime(a1);
  printf("\n--\n");
  a1 = TARVBM_insere(a1, 40, 2);
  TARVBM_imprime(a1);
  printf("\n--\n");
  
  a1 = TARVBM_insere(a1, 19, 2);
  TARVBM_imprime(a1);
  printf("\n--\n");

  a1 = TARVBM_insere(a1, 21, 2);
  TARVBM_imprime(a1);
  printf("\n--\n");

  a1 = TARVBM_insere(a1, 39, 2);
  TARVBM_imprime(a1);
  printf("\n--\n");
  a1 = TARVBM_insere(a1, 9, 2);
  a1 = TARVBM_insere(a1, 3, 2);
  a1 = TARVBM_insere(a1, 11, 2);
  a1 = TARVBM_insere(a1, 29, 2);
  a1 = TARVBM_insere(a1, 45, 2);
  TARVBM_imprime(a1);
  printf("\n--\n");

  a1 = TARVBM_insere(a1, 50, 2);
  TARVBM_imprime(a1);
  printf("\n--\n");

  a1 = TARVBM_insere(a1, 25, 2);
  TARVBM_imprime(a1);
  printf("\n--\n");

  a1 = TARVBM_insere(a1, 17, 2);
  TARVBM_imprime(a1);
  printf("\n--\n");
  

  /* 
  SÓ insere EM FOLHA 
  SEMPRE QUE O VALOR PASSAR POR UM NIVEL QUE ESTÁ CHEIO (TEM 2T -1 CHAVES) A DIVISAO É FEITA NESSE NIVEL

  EX 39 EM:


      5
  10
      15
      19
  20
      21
      30
  35
      40

  PASSOU PPOR '10 20 35' E 'x 40 x', COMO '10 20 35' ESTAVA COMPLETO, ELE FOI DIVIDIDO.

  SE HOUVESSE ALGUM NO COMPLETO PELO QUAL O NUMERO NÃO PASSASSE, ELE NAO IRIA FAZER NADA.


  */

  printf("\n\n-------------------------\n\n");

  /*
  RETIRADA FUNCIONA ASSIM,
  SE NO NOH QUE A FUNCAO FOR CHAMADA ELE DER FLAG NOS CASOS 1 OU 2(A,B,C), REALIZA A OPERACAO (1 OU 2A,B,C) E DESCE PRO PROXIMO FILHO CASO HAJA E REALIZA PROX OPERACAO

  SE NAO DER FLAG NESSES CASOS ELE VAI PRO ULTIMO FILHO DO NOH E TENTA DAR FLAG EM 3A(A,B)

  SE N DER TAMBEM APENAS DESCE A ARVORE E TENTA DE NOVO

  SE DER FLAG EM 3(A,B), ELE VAI PASSANDO E FAZENDO AS ALTERACOES NECESSARIA (MUDANCA 3A OU 3B) PELO CAMINHO ATE O NO QUE CONTEM O NUMERO A SER REMOVIDO
  */
  

  printf("arvore2\n");

  TARVBM* a2 = TARVBM_inicializa();
  a2 = TARVBM_insere(a2, 7, 3);
  a2 = TARVBM_insere(a2, 5, 3);
  a2 = TARVBM_insere(a2, 2, 3);
  a2 = TARVBM_insere(a2, 3, 3);
  a2 = TARVBM_insere(a2, 1, 3);
  a2 = TARVBM_insere(a2, 4, 3);
  a2 = TARVBM_insere(a2, 9, 3);
  a2 = TARVBM_insere(a2, 8, 3);
  a2 = TARVBM_insere(a2, 6, 3);
  a2 = TARVBM_insere(a2, 100, 3);
  a2 = TARVBM_insere(a2, 50, 3);
  a2 = TARVBM_insere(a2, 30, 3);
  a2 = TARVBM_insere(a2, 20, 3);
  a2 = TARVBM_insere(a2, 40, 3);
  a2 = TARVBM_insere(a2, 60, 3);
  a2 = TARVBM_insere(a2, 70, 3);
  a2 = TARVBM_insere(a2, 90, 3);
  a2 = TARVBM_insere(a2, 80, 3);
  TARVBM_imprime(a2);
  

  printf("\n\n--\n");

  a2 = TARVBM_retira(a2, 3, 3);

  TARVBM_imprime(a2);
  printf("\n--\n");

  a2 = TARVBM_retira(a2, 30, 3);

  TARVBM_imprime(a2);
  printf("\n--\n");

  a2 = TARVBM_retira(a2, 40, 3);

  TARVBM_imprime(a2);
  printf("\n--\n");

  a2 = TARVBM_retira(a2, 80, 3);

  TARVBM_imprime(a2);
  printf("\n--\n");

  a2 = TARVBM_retira(a2, 60, 3);

  TARVBM_imprime(a2);
  printf("\n--\n");

  a2 = TARVBM_retira(a2, 4, 3);

  TARVBM_imprime(a2);

  int c = no_internos(a1);
  printf("......%i....", c);

  return 1;
  printf("\n-----------------------\n");

  return 1;

  /* A ARVORE VAI DESCER, SE FOR CASO 3A E ELA PASSAR 
  POR FILHOS COM T-1 CHAVES Q TÊM IRMAOS IMEDIATOS COM T OU MAIS
  CHAVES APLICA 3A NESSES FILHOS
  SE TODOS OS IRMAOS TEM T - 1, APLICA 3B
  */
  printf("\narvore1\n");
  TARVBM_imprime(a1);
  printf("\n--\n");
  a1 = TARVBM_retira(a1, 3, 2);

  TARVBM_imprime(a1);
  printf("\n--\n");

  a1 = TARVBM_retira(a1, 5, 2);

  TARVBM_imprime(a1);
  printf("\n--\n");
  a1 = TARVBM_retira(a1, 15, 2);

  TARVBM_imprime(a1);
  printf("\n--\n");

  a1 = TARVBM_retira(a1, 17, 2);

  TARVBM_imprime(a1);
  printf("\n--\n");

  a1 = TARVBM_retira(a1, 9, 2);

  TARVBM_imprime(a1);

  printf("\n-----------------------\n");
  /* exerc
  */

  TARVBM* a3 = TARVBM_inicializa();
  a3 = TARVBM_insere(a3, 20, 2);
  a3 = TARVBM_insere(a3, 50, 2);
  a3 = TARVBM_insere(a3, 60, 2);

  TARVBM_imprime(a3);
  a3 = TARVBM_insere(a3, 1, 2);

  TARVBM_imprime(a3);
  
  a3 = TARVBM_insere(a3, 64, 2);
  a3 = TARVBM_insere(a3, 12, 2);
  a3 = TARVBM_insere(a3, 18, 2);
  a3 = TARVBM_insere(a3, 66, 2);
  a3 = TARVBM_insere(a3, 38, 2);
  a3 = TARVBM_insere(a3, 95, 2);
  a3 = TARVBM_insere(a3, 58, 2);
  a3 = TARVBM_insere(a3, 59, 2);
  a3 = TARVBM_insere(a3, 70, 2);
  a3 = TARVBM_insere(a3, 68, 2);
  a3 = TARVBM_insere(a3, 39, 2);
  a3 = TARVBM_insere(a3, 62, 2);
  a3 = TARVBM_insere(a3, 7, 2);
  a3 = TARVBM_insere(a3, 55, 2);
  a3 = TARVBM_insere(a3, 43, 2);
  a3 = TARVBM_insere(a3, 16, 2);
  a3 = TARVBM_insere(a3, 67, 2);
  a3 = TARVBM_insere(a3, 34, 2);
  a3 = TARVBM_insere(a3, 35, 2);
  TARVBM_imprime(a3);

  a3 = TARVBM_retira(a3, 50, 2);

  TARVBM_imprime(a3);
  printf("\n--\n");

  a3 = TARVBM_retira(a3, 95, 2);
  
  TARVBM_imprime(a3);
  printf("\n--\n");

  a3 = TARVBM_retira(a3, 70, 2);
  
  TARVBM_imprime(a3);
  printf("\n--\n");

  a3 = TARVBM_retira(a3, 60, 2);

  TARVBM_imprime(a3);
  printf("\n--\n");

  a3 = TARVBM_retira(a3, 35, 2);

  TARVBM_imprime(a3);
  printf("\n--\n");

  a3 = TARVBM_retira(a3, 20, 2);

  TARVBM_imprime(a3);
  printf("\n--\n");

  a3 = TARVBM_retira(a3, 34, 2);

  TARVBM_imprime(a3);
  printf("\n--\n");

  a3 = TARVBM_retira(a3, 38, 2);

  TARVBM_imprime(a3);
  printf("\n--\n");

  a3 = TARVBM_retira(a3, 59, 2);

  TARVBM_imprime(a3);
  printf("\n--\n");

}