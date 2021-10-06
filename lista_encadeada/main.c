#include <stdio.h>
#include "estrutura.h"
#include <stdlib.h>

int main(void) {
  ponto* p = criar_ponto(3.0, 4.0);
  ponto* q = criar_ponto(6.0, 4.0);
  float dist = dist_ponto(p, q);
  printf("%f\n", dist);
  liberar_ponto(p);
  liberar_ponto(q);

  printar_algo();

  lista_encadeada* lista;
  lista = lista_cria(); // retorna um ponteiro lista encadeada com valor NULL (cria uma lista) //
  lista = lista_insere(lista, 46); // RETONA UMA NOVA LISTA PRA FICAR NO LUGAR DE lista COM 41 EM i e O ENDEREÇO DE lista em PROX.
  lista = lista_insere(lista, 45); // RETONA UMA NOVA LISTA PRA FICAR NO LUGAR DE lista COM 44 EM i e O ENDEREÇO DE lista41 em PROX.
  lista = lista_insere(lista, 44); // RETONA UMA NOVA LISTA PRA FICAR NO LUGAR DE lista COM 45 EM i e O ENDEREÇO DE lista44 em PROX. 
  lista = lista_insere(lista, 43); // RETONA UMA NOVA LISTA PRA FICAR NO LUGAR DE lista COM 46 EM i e O ENDEREÇO DE lista45 em PROX.
  lista = lista_busca(lista, 43); // RETORNA A LISTA A PARTIR DO VALOR BUSCADO, SE N ACHAR RETORNA UMA LISTA VAZIA
  lista = lista_insere_ord(lista, 47); // CRIA UMA LISTA PRO VALOR ESCOLHIDO, PERCORRE A LISTA ATE ACHAR I > VALOR, QUANDO ACHAR O ANT APONTA PRO VALOR E O PROX DO VALOR APONTA PRA I //


  lista_encadeada* lista2 = NULL;
  lista2 = lista_divide(lista, 2); /// PEGA O N-ESIMO ELEMTNO DE UMA LISTA E APONTA ELE PRA NULL E PEGA O RESTO DA LISTA E COLOCA NA LISTA NOVA;
  lista_imprime(lista);
  printar_algo();
  lista_imprime(lista2);
  printar_algo();

  lista = lista_remove_i(lista, 44); // CRIA UM lista_encadeada ANT Q EH O PONTEIRO ANTERIOR AO VALOR A SER APAGADO, ESSE VETOR ANTERIOR TEM COMO PROX O PONTEIRO APOS O VALOR A SER APAGADO.

  lista = lista_concatena(lista, lista2); // PEGA O ULTIMO VALOR DA PRIMEIRA LISTA E APONTA PRO PRIMEIRO DA SEGUNDA

  lista_imprime(lista); // IMPRIME TODOS OS VALORES DE UMA LISTA
  printar_algo();
  lista_exclui(lista); // APAGA UMA LISTA


  int vetor[4] = {1, 2, 3, 4};
  lista_encadeada* lista3 = NULL;
  lista3 = lista_criar_de_vetor_reverso(lista3, &vetor[0], 4); // INSERE TODOS OS ELEMENTOS DE UM VETOR NUMA LISTA ORDEM CERTA //
  lista3 = lista_insere_no_fim(lista3, 99); // INSERE UM VALOR NO FIM DA LISTA, O ULTIMO VALOR APONTA PRO  VALOR ATUAL E O ATUAL APONTA PRA NULL //
  lista_imprime(lista3);

  printar_algo();
  lista_encadeada* lista4 = NULL;
  lista4 = lista_criar_de_vetor(lista4, &vetor[0], 4); // INSERE TODOS OS ELEMENTOS DE UM VETOR NUMA LISTA //
  lista_imprime(lista4);

  int lenn = lista_len(lista4); // PERCORRE A LISTA E DEFINE QUANTOS ELEMENTOS ELA TEM
  printar_algo();
  printf("%i\n", lenn);
  printar_algo();

  lista4 = lista_insere_em_pos(lista4, 55, 9); // CRIA UM PONTEIRO C O VALOR ESCOLHIDO E INSERE ELE ENTRE ANT E PROXS SELECIONADOS//
  lista_imprime(lista4);
  printar_algo();


  lista_encadeada* lista5 = NULL;
  lista5 = lista_insere_no_fim(lista5, 5);
  lista5 = lista_insere_no_fim(lista5, 3);
  lista5 = lista_insere_no_fim(lista5, 3);
  lista5 = lista_insere_no_fim(lista5, 3);
  lista5 = lista_insere_no_fim(lista5, 3);
  lista5 = lista_insere_no_fim(lista5, 5);
  lista5 = lista_insere_no_fim(lista5, 3);


  lista5 = lista_remove_todos(lista5, 3);

  lista_imprime(lista5);

}