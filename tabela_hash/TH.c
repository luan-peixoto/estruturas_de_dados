#include "TH.h"

int TH_hash(int mat, int tam){
  return mat % tam;
}

void TH_inicializa(TH tab, int n){  
  // inicialia uma hash de TAM (101) posicoes com null em todas
  int i;
  for(i = 0; i < n; i++)tab[i] = NULL;
}

TA* TH_busca(TH tab, int n, int mat){
  int h = TH_hash(mat, n); // acha a posicao a ser buscada
  TA *p = tab[h];
  while((p) && (p->mat != mat)) p = p->prox; // segue a lista até achar o elemento
  return p;
}

TA* TH_aloca(int mat, float cr){ // cria novo elemento
  TA *novo = (TA*) malloc (sizeof (TA));
  novo->mat = mat;
  novo->cr = cr;
  novo->prox = NULL;
  return novo;
}

void TH_insere(TH tab, int n, int mat, float cr){
  int h = TH_hash(mat, n); // acha a posicao da lista a ser buscada
  TA *p = tab[h],*ant = NULL; // cria o TA p que é a 1ª posicao da lista
  while((p) && (p->mat != mat)){ // enquanto nao achar o elemento, anda pra frente
    ant = p;
    p = p->prox;
  }
  if(p){ //se achou o elemento, muda só o cr
    p->cr = cr;
    return;
  }
  TA *novo = TH_aloca(mat,cr); // se nao achou cria um elemento novo e insere no fim
  if(!ant)tab[h] = novo;
  else ant->prox = novo;
}

void TH_libera(TH tab, int n){
  int i;
  for(i = 0; i < n; i++)
    if(tab[i]){
      TA *p = tab[i], *q;
      while(p){
        q = p;
        p = p->prox;
        free(q);
      }
    }
}

float TH_retira(TH tab, int n, int mat){
  int h = TH_hash(mat,n); // acha a posicao da lista ser buscada
  if(!tab[h]) return -1; // se nao tiver lista, retorna -1
  TA *p = tab[h],*ant = NULL; 
  float cr = -1;
  while((p) && (p->mat != mat)){ // começa a percorrer a lista procurando o elemento a ser retirado
    ant = p;
    p = p->prox;
  }
  if(!p) return cr; // nao achou elemento, retorna -1
  if(!ant) tab[h] = p->prox; // se o elemento nao tiver anterior (for unico na lista), a lista volta a apontar pra null;
  else ant->prox = p->prox; // se n for o ultimo, o anterior a ele aponta pro prox dele, e ele é removido
  cr = p->cr;
  free(p);  // removido aqui
  return cr;
}

void TH_imprime(TH tab, int n){
  int i;
  for(i = 0; i < n; i++){
    printf("%d: ", i);
    if(tab[i]){
      TA *p = tab[i];
      printf("\n");
      while(p){
        printf("\t%d\t%f\t%p\n", p->mat, p->cr, p->prox);
        p = p->prox;
      }
    }
    else printf("NULL\n");
  }
}