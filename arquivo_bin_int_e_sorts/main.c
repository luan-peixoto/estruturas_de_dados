#include <stdio.h>
#include <limits.h>
#include "funcao.h"
#include <stdlib.h>

int main(void) {
  int veter[10] = {2,6,4,5,3,7,1,9,10,8};
  int vetor[10] = {1,2,4,5,6,7,8,9,10,11};
  int vetor2[10];
  int vetor3[10];
  int vetorRes[20];
  int vetor4[11];
  int vetor5[10];


  // criar de vetor

  cria_arq_binario_vetor("vet", vetor, 10);
  ler_arq_binario("vet", vetor2);
  printf("\n..%i %i %i %i %i %i %i %i %i %i..\n",vetor2[0],vetor2[1],vetor2[2],vetor2[3],vetor2[4],vetor2[5],vetor2[6], vetor2[7], vetor2[8], vetor2[9]);
  
  // criar com scanf
  
  cria_arq_ord_cresc_bin("scan");
  ler_arq_binario("scan", vetor3);

  // juntar 2 arquivos

  arquivo_juntar_bin("vet", "scan", "res");
  ler_arq_binario("res", vetorRes);  


  // insere ordenado

  cria_arq_binario_vetor("ins", vetor, 10);
  arquivo_insere_ord_bin("ins", 3);
  ler_arq_binario("ins", vetor4);
  printf("\n...%i %i %i %i %i %i %i %i %i %i...\n\n",vetor4[0],vetor4[1],vetor4[2],vetor4[3],vetor4[4],vetor4[5],vetor4[6], vetor4[7], vetor4[8], vetor4[9]);

  //

  printf("vet[3] %i\n", vetor2[3]);
  printf("vet2[3] %i\n", vetor3[3]);
  printf("res[10] %i\n", vetorRes[10]);
  printf("vetor4[10] %i  vetor4[2] %i\n\n", vetorRes[10], vetorRes[2]);

  
  int pos = busca_binaria_arquivo_binario("vet", 5, sizeof(int));
  int val = retorna_elemento_arquivo_binario("vet", pos);
  printf("pos: %lu val: %i\n\n", pos/sizeof(int), val);


  cria_arq_binario_vetor("select", veter, 10);

  insertion_sort_arquivo_bin("select", sizeof(int));
  ler_arq_binario("select", vetor5);
  printf("%i %i %i %i %i %i %i %i %i %i\n", vetor5[0], vetor5[1], vetor5[2], vetor5[3], vetor5[4], vetor5[5], vetor5[6], vetor5[7], vetor5[8], vetor5[9]);

  bubble_sort_arquivo_bin("select", sizeof(int));
  ler_arq_binario("select", vetor5);
  printf("%i %i %i %i %i\n", vetor5[0], vetor5[1], vetor5[2], vetor5[3], vetor5[4]);

  quick_sort_arquivo_bin("select", sizeof(int));
  ler_arq_binario("select", vetor5);
  printf("%i\n", vetor5[8]);

  FILE* sim = fopen("select", "r+b");
  selection_sort_arquivo_bin_aberto(sim);
  fclose(sim);
  ler_arq_binario("select", vetor5);
  printf("%i", vetor5[8]);


}
