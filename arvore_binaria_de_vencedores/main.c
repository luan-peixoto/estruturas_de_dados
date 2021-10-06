#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VALOR_MIN -200000
#define INT_MAX 2147483647

typedef struct arvore_bin_vencedores {
  FILE* fp;
  int info;
  struct arvore_bin_vencedores *esq;
  struct arvore_bin_vencedores *dir;
} abv;

typedef struct fila_arvore_bin_vencedores {
  struct fila_arvore_bin_vencedores *prox;
  struct arvore_bin_vencedores *arvore;
} fila_abv;

fila_abv* init_fila_abv() {
  fila_abv* fila = (fila_abv*) malloc (sizeof(fila_abv));
  return fila;
}

fila_abv* push_fila_abv(fila_abv* fila, abv* arv) {
    if(fila->arvore == NULL) {
      fila->arvore = arv;
      return fila;
    }
    else {
      fila_abv* aux = init_fila_abv();
      aux->arvore = arv;
      
      aux->prox = fila;
      return aux;
    }
}

abv* pop_fila_abv(fila_abv* fila) {
  if (fila->prox == NULL) {
    if (fila->arvore == NULL) {
      return NULL;
    }
    else {
      abv* aux = fila->arvore;
      fila->arvore = NULL;
      return aux;
    }
  }
  else {
    abv* aux = fila->arvore;
    fila->arvore = fila->prox->arvore;
    fila->prox = fila->prox->prox;
    return aux;
  }
}

int fila_vazia_abv(fila_abv* fila) {
  if (fila->arvore == NULL) {
    return 1;
  }
  else {
    return 0;
  }
}

abv* criar_no_abv(char* nome) {
  abv* arq_fechados = NULL;
  arq_fechados = (abv*) malloc(sizeof(abv));
  arq_fechados->fp = fopen(nome, "rt");
  fscanf(arq_fechados->fp, "%d", &arq_fechados->info);
  return arq_fechados;
}

abv* intercala_maior(abv* a1, abv* a2) {
  abv* novo = NULL;
  novo = (abv*) malloc(sizeof(abv));
  if (a1->info > a2->info) {
    novo->fp = a2->fp;
    novo->info = a2->info;
    novo->esq = a1; 
    novo->dir = a2;
  }
  else {
    novo->fp = a1->fp;
    novo->info = a1->info;
    novo->esq = a1; 
    novo->dir = a2;
  }
  return novo;
}


abv* criar_arvore_abv(char *nome, int qtd) {
  char arq[51];
  int atual = 0;
  fila_abv* fila1 = init_fila_abv();
  fila_abv* fila2 = init_fila_abv();
  for (int i = 1; i <= qtd; i++) {
    char aux[5];
    strcpy(arq, nome);
    sprintf(aux, "%i", i);
    strcat(arq, aux);
    strcat(arq, ".txt");
    fila1 = push_fila_abv(fila1, criar_no_abv(arq));
  }

  abv* aux1 = NULL;
  abv* aux2 = NULL;
  while(1) {
    if (atual == 0) {
      aux1 = pop_fila_abv(fila1);
      aux2 = pop_fila_abv(fila1);
      if (aux2 == NULL) {
        atual = 1;
        if (aux1 != NULL) {
          if ((fila_vazia_abv(fila1) == 1) && (fila_vazia_abv(fila2) == 1)) {
            break;
          }
          else {
            fila2 = push_fila_abv(fila2, aux1);
          }
        }
      }
      else {
        aux1 = intercala_maior(aux1, aux2);
        fila2 = push_fila_abv(fila2, aux1);
        aux1 = NULL;
      }
    }
    else {
      aux1 = pop_fila_abv(fila2);
      aux2 = pop_fila_abv(fila2);
      if (aux2 == NULL) {
        atual = 0;
        if (aux1 != NULL) {
          if ((fila_vazia_abv(fila1) == 1) && (fila_vazia_abv(fila2) == 1)) {
            break;
          }
          else {
            fila1 = push_fila_abv(fila1, aux1);
            aux1 = NULL;
          }
        }
      }
      else {
        aux1 = intercala_maior(aux1, aux2);
        fila1 = push_fila_abv(fila1, aux1);
        aux1 = NULL;
        aux2 = NULL;
      }
    }
  }
  return aux1;
}

void intercala_arquivo_abv(char* entrada, char*saida, int qtd) {
  int arq_fechados = 0; 
  int b = 0;
  FILE* res = fopen(saida,"wt");
  fila_abv * fila = init_fila_abv();
  abv* vencedores = criar_arvore_abv(entrada, qtd);
  while (arq_fechados != qtd) {
    abv* aux = vencedores;
    fprintf(res, "%d\n",aux->info);
    int atual = aux->info;
    int prox;
    if (fscanf(aux->fp, "%d", &prox) != 1) {
      prox = INT_MAX;
      fclose(aux->fp);
      arq_fechados += 1;
    }
    aux->info = prox;
    while (aux->esq != NULL) {
      if (aux->esq->info == atual) {
        fila = push_fila_abv(fila, aux);
        aux->esq->info = prox;
        aux = aux->esq;
      }
      else {
        fila = push_fila_abv(fila, aux);
        aux->dir->info = prox;
        aux = aux->dir;
      }
    }

    while (fila_vazia_abv(fila) == 0) {
      abv* aux2 = pop_fila_abv(fila);
      if (aux2->esq->info > aux2->dir->info) {
        aux2->info = aux2->dir->info;
        aux2->fp = aux2->dir->fp;
      }
      else {
        aux2->info = aux2->esq->info;
        aux2->fp = aux2->esq->fp;
      }
    }
    
  }
  fclose(res);
}



int main(void) {
  abv * arvore = NULL;
  char nome[] = "ss";
  char ress[] = "res.txt";
  
  arvore = criar_arvore_abv(nome,5);
  
  printf("   %i \n", arvore->info);
  printf(" %i    ", arvore->esq->info);
  printf("%i \n", arvore->dir->info);
  printf("%i ", arvore->esq->esq->info);
  printf("%i ", arvore->esq->dir->info);
  printf("%i ", arvore->dir->esq->info);
  printf(" %i \n", arvore->dir->dir->info);
  printf("       %i ", arvore->dir->dir->esq->info);
  printf("%i \n", arvore->dir->dir->dir->info);
  
  
  intercala_arquivo_abv(nome,ress,5);
  

  /*
  r = scanf(asdasodka); 
  if (r != 1) nao funciona

  tem q ser
  if (scanf(sajdasd) != 1)
  */
}