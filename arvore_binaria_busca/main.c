#include <stdio.h>
#include "estrutura.h"
#include <stdlib.h>

int main(void) {
  arvore_bin* a5 = criar_noh(5, NULL, NULL);
  arvore_bin* a4 = criar_noh(4, NULL, NULL);
  arvore_bin* a2 = criar_noh(2, NULL, NULL);
  arvore_bin* a3 = criar_noh(3, a4, a5);
  arvore_bin* a1 = criar_noh(1, a2, a3);

  arvore_bin* xll = espelho(a1);

  arvore_bin* xl = copia(a1);

  imprime_larg_fila(xl);

  printf("\n");

   imprime_larg_fila(xll);

  printf("\n");

  int igual = iguais(xl,a1);


  printf("igual? %i\n", igual);

  int maiorr = maior(xl);
  int menorr = menor(xl);

  printf("max %i min %i\n", maiorr, menorr);

  xl = remove_arvore(xl, 1);

  imprime_larg_fila(xl);
  
  printf("\n");

  xll = remove_pares_arvore(xll);

  imprime_larg_fila(xll);

  printf("\n");

  int folhas = contar_folhas(a1);
  int internos = contar_internos(a1);
  printf("folhas: %i internos: %i\n", folhas, internos);


  arvore_bin* cu = copia(a1);
  colore(cu);

  imprime_larg_fila(cu);
  
  printf("\n");

  

  // IMPRIMIR EM LARGURA COM FILA

  
  imprime_larg_fila(a1);

  printf("\n");

  // IMPRIMIR PRE RED COM PILHA

  imprime_pre_red_pilha(a1);

  printf("\n");

  // IMPRIMIR PRE RED NORMAL

  imprime_pre_red(a1);

  printf("\n");

  // BUSCAR NA ARVORE

  arvore_bin* c = arv_busca(4, a1);
  printf("%i", c->info);

  printf("\n");

  // ALTURA DA ARVORE
  
  printf("altura %i", altura(a1));
  
  printf("\n");

  // LIBERAR ARVORE

  libera_arv_bin(a1);

  // IMPRIMIR COM PILHA

  pilha_arvore_bin* PILHA = init(PILHA);

  arvore_bin* teste = criar_noh(10, NULL, NULL);
  arvore_bin* teste2 = criar_noh(9, NULL, NULL);
  arvore_bin* teste3 = criar_noh(8, NULL, NULL);

  PILHA = push(PILHA, teste);
  PILHA = push(PILHA, teste2);
  PILHA = push(PILHA, teste3);
 
  arvore_bin* print = pop(PILHA);
  printf("%i ", print->info);
  print = pop(PILHA);
  printf("%i ", print->info);
  print = pop(PILHA);
  printf("%i \n", print->info);

  // IMPRIMIR COM FILA

  fila_arvore_bin* FILHA = init_fila();

  FILHA = push_fila(FILHA, teste);
  FILHA = push_fila(FILHA, teste2);
  FILHA = push_fila(FILHA, teste3);

  arvore_bin* print2 = pop_fila(FILHA);
  printf("%i ", print2->info);
  print2 = pop_fila(FILHA);
  printf("%i ", print2->info);
  print2 = pop_fila(FILHA);
  printf("%i \n", print2->info);

  ///////////// CRIAR ARV COM FUNÇAO !FICA PRONTO PRA IMPRIMIR EM SIMETRICO

  int vetor[] = {1,2,3,4,5,6,7,8,9};
  arvore_bin* a = criar_arv_vetor_simetrica(vetor, 9);

  imprime_larg_fila(a);
  printf("\n");
  imprime_pre_red(a);
  printf("\n");

  int v1[] = {25,22,40,30,45,27,20,21,48};
  arvore_bin* b1 = NULL;
  for (int x = 0; x < 9; x++) {
    b1 = insere_arv_bin_busca(b1, v1[x]);
  }
  imprime_larg_fila(b1);

  printf("\n");

  int v2[] = {40,25,20,30,45,27,22,21,48};
  arvore_bin* b2 = NULL;
  for (int x = 0; x < 9; x++) {
    b2 = insere_arv_bin_busca(b2, v2[x]);
  }
  imprime_larg_fila(b2);

  printf("\n");

  // INSERÇAO EM ARV DE BUSCA BINARIA

  arvore_bin* c10 = criar_noh(79, NULL, NULL);
  arvore_bin* c9 = criar_noh(65, NULL, NULL);
  arvore_bin* c8 = criar_noh(70, c9, c10);
  arvore_bin* c7 = criar_noh(130, NULL, NULL);
  arvore_bin* c6 = criar_noh(110, NULL, NULL);
  arvore_bin* c5 = criar_noh(120, c6, c7);
  arvore_bin* c40 = criar_noh(260, NULL, NULL);
  arvore_bin* c4 = criar_noh(270, c40, NULL);
  arvore_bin* c3 = criar_noh(220, NULL, NULL);
  arvore_bin* c2 = criar_noh(250, c3, c4);
  arvore_bin* c1 = criar_noh(500, NULL, NULL);
  arvore_bin* c0 = criar_noh(350, NULL, NULL);
  arvore_bin* c09 = criar_noh(400, c0, c1);
  arvore_bin* c08 = criar_noh(80, c8, NULL);
  arvore_bin* c07 = criar_noh(150, c5, NULL);
  arvore_bin* c06 = criar_noh(100, c08, c07);
  arvore_bin* c05 = criar_noh(300, c2, c09);
  arvore_bin* c00 = criar_noh(200, c06, c05);


  imprime_larg_fila(c00);

  printf("\n");

  retira_arv_bin_busca(c00, 100);
  retira_arv_bin_busca(c00, 150);
  retira_arv_bin_busca(c00, 80);
  retira_arv_bin_busca(c00, 270);
  retira_arv_bin_busca(c00, 400);
  retira_arv_bin_busca(c00, 200);

  imprime_larg_fila(c00);

  printf("\n");

  arvore_bin* menor = menor_arv__bin_busca(c00);
  arvore_bin* maior = maior_arv__bin_busca(c00);
  printf("menor %i | maior %i", menor->info, maior->info);

  printf("\n");

  c00 = retira_impares_arv__bin_busca(c00);

  imprime_larg_fila(c00);

  printf("\n");
  
  int v[20];

  vetor_menores_arv_bin_busca(&v[0], c00, 130);

  printf("%i %i %i %i",v[0],v[1],v[2],v[3]);

  printf("\n\n");

  printf("AVL:\n");

  // 1º INSERE O NO NA ARVORE DPS VAI CHECANDO O FATOR DE BALANCEAMENTO DE BAIXO PARA CIMA
  
  arvore_bin_avl* avl = NULL;
  avl = insere_avl(avl, 50);
  avl = insere_avl(avl, 40);
  avl = insere_avl(avl, 30);
  avl = insere_avl(avl, 45);
  avl = insere_avl(avl, 47);
  avl = insere_avl(avl, 55);
  avl = insere_avl(avl, 56);
  avl = insere_avl(avl, 1);
  avl = insere_avl(avl, 2);
  avl = insere_avl(avl, 3);
  avl = insere_avl(avl, 9);

  imprime_larg_fila_avl(avl);
  printf("\n");

  arvore_bin_avl* aaa = arv_busca_avl(2, avl);

  printf("\n");
  printf("exerc\n");


  arvore_bin_avl* avl2 = NULL;
  avl2 = insere_avl(avl2, 50);
  avl2 = insere_avl(avl2, 1);
  avl2 = insere_avl(avl2, 64);
  avl2 = insere_avl(avl2, 12);
  
  avl2 = insere_avl(avl2, 18);
  avl2 = insere_avl(avl2, 66);
  avl2 = insere_avl(avl2, 38);
  avl2 = insere_avl(avl2, 95);
  avl2 = insere_avl(avl2, 58);
  avl2 = insere_avl(avl2, 59);
  avl2 = insere_avl(avl2, 70);
  avl2 = insere_avl(avl2, 68);
  avl2 = insere_avl(avl2, 39);

  avl2 = insere_avl(avl2, 62);
  avl2 = insere_avl(avl2, 7);
  avl2 = insere_avl(avl2, 60);
  avl2 = insere_avl(avl2, 43);
  avl2 = insere_avl(avl2, 16);
  avl2 = insere_avl(avl2, 67);
  avl2 = insere_avl(avl2, 34);

  imprime_avl(avl2);

  avl2 = insere_avl(avl2, 35);
  imprime_avl(avl2);
  return 0;
  avl2 = remove_avl(avl2, 50);
  avl2 = remove_avl(avl2, 95);
  imprime_avl(avl2);
}