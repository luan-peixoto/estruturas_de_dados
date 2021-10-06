#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"

int main(void) {

  /* 
  NUMERO DE CHAVES POR NO
  MIN T - 1 | MAX 2T - 1
  NUMERO DE FILHOS POR NO
  MIN T MAX 2T
  RAIZ PODE TER QUALQUER UM
  */

  arvore_b* g = inicializa();
  
  g = cria_no(3);
  g->folha = 0;
  g->nchaves = 1;
  g->chave[0] = 13;

  g->filho[0] = cria_no(3);
  g->filho[0]->folha = 0;
  g->filho[0]->nchaves = 2;
  g->filho[0]->chave[0] = 4;
  g->filho[0]->chave[1] = 8;

  g->filho[0]->filho[0] = cria_no(3);
  g->filho[0]->filho[0]->nchaves = 2;
  g->filho[0]->filho[0]->chave[0] = 2;
  g->filho[0]->filho[0]->chave[1] = 3;


  g->filho[0]->filho[1] = cria_no(3);
  g->filho[0]->filho[1]->nchaves = 2;
  g->filho[0]->filho[1]->chave[0] = 6;
  g->filho[0]->filho[1]->chave[1] = 7;

  g->filho[0]->filho[2] = cria_no(3);
  g->filho[0]->filho[2]->nchaves = 3;
  g->filho[0]->filho[2]->chave[0] = 10;
  g->filho[0]->filho[2]->chave[1] = 11;
  g->filho[0]->filho[2]->chave[2] = 12;


  g->filho[1] = cria_no(3);
  
  g->filho[1]->folha = 0;
  g->filho[1]->nchaves = 3;
  g->filho[1]->chave[0] = 17;
  g->filho[1]->chave[1] = 20;
  g->filho[1]->chave[2] = 24;

  g->filho[1]->filho[0] = cria_no(3);
  g->filho[1]->filho[0]->nchaves = 2;
  g->filho[1]->filho[0]->chave[0] = 14;
  g->filho[1]->filho[0]->chave[1] = 16;

  
  g->filho[1]->filho[1] = cria_no(3);
  g->filho[1]->filho[1]->nchaves = 2;
  g->filho[1]->filho[1]->chave[0] = 18;
  g->filho[1]->filho[1]->chave[1] = 19;

  g->filho[1]->filho[2] = cria_no(3);
  g->filho[1]->filho[2]->nchaves = 2;
  g->filho[1]->filho[2]->chave[0] = 22;
  g->filho[1]->filho[2]->chave[1] = 23;

  g->filho[1]->filho[3] = cria_no(3);
  g->filho[1]->filho[3]->nchaves = 2;
  g->filho[1]->filho[3]->chave[0] = 25;
  g->filho[1]->filho[3]->chave[1] = 26;

  imprime(g);
  

  g = TARVB_Retira(g, 11, 3);

  imprime(g);

  g = TARVB_Retira(g, 20, 3);

  imprime(g);

  g = TARVB_Retira(g, 17, 3);

  imprime(g);
  return 1;
  imprime(g);

  g = TARVB_Retira(g, 10, 3);

  imprime(g);

  g = TARVB_Retira(g, 12, 3);

  imprime(g);


  return 1;


  arvore_b* arvore = inicializa();
  arvore = cria_no(2);
  arvore->filho[0] = cria_no(2);
  arvore->filho[1] = cria_no(2);
  arvore->filho[2] = cria_no(2);
  arvore->filho[3] = cria_no(2);
  arvore->nchaves = 3;
  arvore->chave[0] = 3;
  arvore->chave[1] = 6;
  arvore->chave[2] = 9;
  arvore->filho[0]->nchaves = 3;
  arvore->filho[0]->chave[0] = 12;
  arvore->filho[0]->chave[1] = 15;
  arvore->filho[0]->chave[2] = 18;
  arvore->filho[1]->nchaves = 3;
  arvore->filho[1]->chave[0] = 21;
  arvore->filho[1]->chave[1] = 24;
  arvore->filho[1]->chave[2] = 27;
  arvore->filho[2]->nchaves = 3;
  arvore->filho[2]->chave[0] = 30;
  arvore->filho[2]->chave[1] = 33;
  arvore->filho[2]->chave[2] = 36;
  arvore->filho[3]->nchaves = 3;
  arvore->filho[3]->chave[0] = 39;
  arvore->filho[3]->chave[1] = 42;
  arvore->filho[3]->chave[2] = 45;
  imprime(arvore);
  printf("----\n");
  
  arvore_b* a1 = inicializa();
  a1 = insere(a1, 10, 2);
  a1 = insere(a1, 20, 2);
  a1 = insere(a1, 30, 2);

  imprime(a1);
  printf("\n--\n");
  a1 = insere(a1, 5, 2);
  imprime(a1);
  printf("\n--\n");
   a1 = insere(a1, 35, 2);
  imprime(a1);
  printf("\n--\n");
  a1 = insere(a1, 15, 2);
  imprime(a1);
  printf("\n--\n");
  a1 = insere(a1, 40, 2);
  imprime(a1);
  printf("\n--\n");
  
  a1 = insere(a1, 19, 2);
  imprime(a1);
  printf("\n--\n");

  a1 = insere(a1, 21, 2);
  imprime(a1);
  printf("\n--\n");

  a1 = insere(a1, 39, 2);
  imprime(a1);
  printf("\n--\n");
  a1 = insere(a1, 9, 2);
  a1 = insere(a1, 3, 2);
  a1 = insere(a1, 11, 2);
  a1 = insere(a1, 29, 2);
  a1 = insere(a1, 45, 2);
  imprime(a1);
  printf("\n--\n");

  a1 = insere(a1, 50, 2);
  imprime(a1);
  printf("\n--\n");

  a1 = insere(a1, 25, 2);
  imprime(a1);
  printf("\n--\n");

  a1 = insere(a1, 17, 2);
  imprime(a1);
  printf("\n--\n");
  

  /* 
  SÓ INSERE EM FOLHA 
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

  SE NAO DER TAMBEM APENAS DESCE A ARVORE E TENTA DE NOVO

  SE DER FLAG EM 3(A,B), ELE VAI PASSANDO E FAZENDO AS ALTERACOES NECESSARIA (MUDANCA 3A OU 3B) PELO CAMINHO ATE O NO QUE CONTEM O NUMERO A SER REMOVIDO
  */
  

  printf("arvore2\n");

  arvore_b* a2 = inicializa();
  a2 = insere(a2, 7, 3);
  a2 = insere(a2, 5, 3);
  a2 = insere(a2, 2, 3);
  a2 = insere(a2, 3, 3);
  a2 = insere(a2, 1, 3);
  a2 = insere(a2, 4, 3);
  a2 = insere(a2, 9, 3);
  a2 = insere(a2, 8, 3);
  a2 = insere(a2, 6, 3);
  a2 = insere(a2, 100, 3);
  a2 = insere(a2, 50, 3);
  a2 = insere(a2, 30, 3);
  a2 = insere(a2, 20, 3);
  a2 = insere(a2, 40, 3);
  a2 = insere(a2, 60, 3);
  a2 = insere(a2, 70, 3);
  a2 = insere(a2, 90, 3);
  a2 = insere(a2, 80, 3);
  imprime(a2);
  printf("\n\n--\n");

  a2 = TARVB_Retira(a2, 3, 3);

  imprime(a2);
  printf("\n--\n");

  a2 = TARVB_Retira(a2, 30, 3);

  imprime(a2);
  printf("\n--\n");

  a2 = TARVB_Retira(a2, 40, 3);

  imprime(a2);
  printf("\n--\n");

  a2 = TARVB_Retira(a2, 80, 3);

  imprime(a2);
  printf("\n--\n");

  a2 = TARVB_Retira(a2, 60, 3);

  imprime(a2);
  printf("\n--\n");

  a2 = TARVB_Retira(a2, 4, 3);

  imprime(a2);
  printf("\n-----------------------\n");


  /* A ARVORE VAI DESCER, SE FOR CASO 3A E ELA PASSAR 
  POR FILHOS COM T-1 CHAVES Q TÊM IRMAOS IMEDIATOS COM T OU MAIS
  CHAVES APLICA 3A NESSES FILHOS
  SE TODOS OS IRMAOS TEM T - 1, APLICA 3B
  */
  printf("\narvore1\n");
  imprime(a1);
  
  printf("\n--\n");
  a1 = TARVB_Retira(a1, 3, 2);

  imprime(a1);
  printf("\n--\n");

  a1 = TARVB_Retira(a1, 5, 2);

  imprime(a1);
  printf("\n--\n");
  a1 = TARVB_Retira(a1, 15, 2);

  imprime(a1);
  printf("\n--\n");

  a1 = TARVB_Retira(a1, 17, 2);

  imprime(a1);
  printf("\n--\n");

  a1 = TARVB_Retira(a1, 9, 2);

  imprime(a1);
  printf("\n-----------------------\n");
  
  // exercicios
  

  arvore_b* a3 = inicializa();
  a3 = insere(a3, 20, 2);
  a3 = insere(a3, 50, 2);
  a3 = insere(a3, 60, 2);
  
  imprime(a3);

  a3 = insere(a3, 1, 2);

  imprime(a3);
  a3 = insere(a3, 64, 2);
  a3 = insere(a3, 12, 2);
  a3 = insere(a3, 18, 2);
  a3 = insere(a3, 66, 2);
  a3 = insere(a3, 38, 2);
  a3 = insere(a3, 95, 2);
  a3 = insere(a3, 58, 2);
  a3 = insere(a3, 59, 2);
  a3 = insere(a3, 70, 2);
  a3 = insere(a3, 68, 2);
  a3 = insere(a3, 39, 2);
  a3 = insere(a3, 62, 2);
  a3 = insere(a3, 7, 2);
  a3 = insere(a3, 55, 2);
  a3 = insere(a3, 43, 2);
  a3 = insere(a3, 16, 2);
  a3 = insere(a3, 67, 2);
  a3 = insere(a3, 34, 2);
  a3 = insere(a3, 35, 2);
  imprime(a3);

  int c = no_folhas(a3);
  printf("....%i...", c);
  return 1;

  a3 = TARVB_Retira(a3, 50, 2);

  imprime(a3);
  printf("\n--\n");

  a3 = TARVB_Retira(a3, 95, 2);
  
  imprime(a3);
  printf("\n--\n");

  a3 = TARVB_Retira(a3, 70, 2);
  
  imprime(a3);
  printf("\n--\n");

  a3 = TARVB_Retira(a3, 60, 2);

  imprime(a3);
  printf("\n--\n");

  a3 = TARVB_Retira(a3, 35, 2);

  imprime(a3);
  printf("\n--\n");

  a3 = TARVB_Retira(a3, 20, 2);

  imprime(a3);
  printf("\n--\n");

  a3 = TARVB_Retira(a3, 34, 2);

  imprime(a3);
  printf("\n--\n");

  a3 = TARVB_Retira(a3, 38, 2);

  imprime(a3);
  printf("\n--\n");

  a3 = TARVB_Retira(a3, 59, 2);

  imprime(a3);
  printf("\n--\n");

}