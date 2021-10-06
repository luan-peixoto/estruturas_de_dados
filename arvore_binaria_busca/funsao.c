#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "estrutura.h"

fila_arvore_bin* init_fila() {
  fila_arvore_bin* fila = (fila_arvore_bin*) malloc (sizeof(fila_arvore_bin));
  return fila;
}

fila_arvore_bin* push_fila(fila_arvore_bin* fila, arvore_bin* arv) {
    if(fila->arvore == NULL) {
      fila->arvore = arv;
      return fila;
    }
    else {
      fila_arvore_bin* aux = init_fila();
      aux->arvore = arv;
      fila_arvore_bin* aux2 = fila;
      while(aux2->prox != NULL) {
        aux2 = aux2->prox;
      }
      aux2->prox = aux;
      return fila;
    }
}

arvore_bin* pop_fila(fila_arvore_bin* fila) {
  if (fila->prox == NULL) {
    if (fila->arvore == NULL) {
      return NULL;
    }
    else {
      arvore_bin* aux = fila->arvore;
      fila->arvore = NULL;
      return aux;
    }
  }
  else {
    arvore_bin* aux = fila->arvore;
    fila->arvore = fila->prox->arvore;
    fila->prox = fila->prox->prox;
    return aux;
  }
}

int fila_vazia(fila_arvore_bin* fila) {
  if (fila->arvore == NULL) {
    return 1;
  }
  else {
    return 0;
  }
}
/////////////

pilha_arvore_bin* init() {
  pilha_arvore_bin* pilha = (pilha_arvore_bin*) malloc (sizeof(pilha_arvore_bin));
  return pilha;
}

pilha_arvore_bin* push(pilha_arvore_bin* pilha, arvore_bin* arv) {
  if (pilha->arvore == NULL) {
    pilha->arvore = arv;
    return pilha;
  }
  else {
    pilha_arvore_bin* aux = init();
    aux->anterior = pilha;
    aux->arvore = arv;
    return aux;
  }
}

arvore_bin* pop(pilha_arvore_bin* pilha) {
  if (pilha->anterior == NULL) {
    if (pilha->arvore == NULL) {
      return NULL;
    }
    else {
      arvore_bin* aux = pilha->arvore;
      pilha->arvore = NULL;
      return aux;
    }
  }
  else {
    arvore_bin* aux = pilha->arvore;
    pilha->arvore = pilha->anterior->arvore;
    pilha->anterior = pilha->anterior->anterior;
    return aux;
  }
}

int pilha_vazia(pilha_arvore_bin* pilha) {
  if (pilha->arvore == NULL) {
    return 1;
  }
  else {
    return 0;
  }
}

///////////

arvore_bin* inicializa() {
  return NULL;
}

arvore_bin* criar_noh(int i, arvore_bin* sub_arv_esq, arvore_bin* sub_arv_dir) {
  arvore_bin* novo;
  novo = (arvore_bin*) malloc(sizeof(arvore_bin));
  novo->info = i;
  novo->esq = sub_arv_esq;
  novo->dir = sub_arv_dir;
  return novo;
}

arvore_bin* criar_arv_vetor_simetrica(int* vetor, int len) {
  if (len < 1) {
    return NULL;
  }
  else {
    return criar_noh(vetor[len/2], criar_arv_vetor_simetrica(vetor, len/2), criar_arv_vetor_simetrica(&vetor[len/2 + 1], len - len/2 - 1));
  }
}

void libera_arv_bin(arvore_bin* arvore) {
  if (arvore) {
    libera_arv_bin(arvore->esq);
    libera_arv_bin(arvore->dir);
    free(arvore);
  }
}

void imprime_pre_red(arvore_bin* arvore) {
  if(arvore) {
    printf("%i ", arvore->info);
    imprime_pre_red(arvore->esq);
    imprime_pre_red(arvore->dir);
  }
}

void imprime_pre_red_pilha(arvore_bin* arvore) {
  if(!arvore) {
    return;
  }
  else {
    pilha_arvore_bin* p = init();
    p = push(p, arvore);
    while(pilha_vazia(p) == 0) {
      arvore_bin* aux = pop(p);
      printf("%i ", aux->info);
      if(aux->dir) {
        p = push(p, aux->dir);
      }
      if(aux->esq) {
        p = push(p, aux->esq);
      }
    }
    free(p);
  }
}

void imprime_larg_fila(arvore_bin* arvore) {
  if (!arvore) {
    return;
  }
  else {
    fila_arvore_bin* f = init_fila();
    push_fila(f, arvore);
    while (fila_vazia(f) == 0) {
      arvore_bin* aux = pop_fila(f);
      printf("%i ", aux->info);
      if(aux->esq) {
        f = push_fila(f, aux->esq);
      }
      if(aux->dir) {
        f = push_fila(f, aux->dir);
      }
    }
    free(f);
  }
}

void imprime_sim_erd(arvore_bin* arvore) {
  if(arvore){
    imprime_sim_erd(arvore->esq);
    printf("%i ", arvore->info);
    imprime_sim_erd(arvore->dir);
  }
}

void imprime_pos_edr(arvore_bin* arvore) {
  if(arvore){
    imprime_pos_edr(arvore->esq);
    imprime_pos_edr(arvore->dir);
    printf("%i ", arvore->info);
  }
}

arvore_bin* arv_busca(int i, arvore_bin* arvore) {
  if((arvore == NULL) || (arvore->info == i)) {
    return arvore;
  }
  arvore_bin* resp = arv_busca(i, arvore->esq);
  if(resp) {
    return resp;
  }
  return arv_busca(i, arvore->dir);
}

int altura(arvore_bin* arvore) {
  if (arvore == NULL) {
    return -1;
  }
  else {
    return 1 + maximo(altura(arvore->esq), altura(arvore->dir));
  }
}

int maximo(int x, int y) {
  if (x > y) {
    return x;
  }
  else {
    return y;
  }
}

//// exercicos lista 1

arvore_bin* copia(arvore_bin* arvore) {
  if (arvore != NULL) {
    arvore_bin* cop = criar_noh(arvore->info, copia(arvore->esq), copia(arvore->dir));
    return cop;
  }
  return NULL;
}

arvore_bin* espelho(arvore_bin* arvore) {
  if (arvore != NULL) {
    arvore_bin* cop = criar_noh(arvore->info, espelho(arvore->dir), espelho(arvore->esq));
    return cop;
  }
  return NULL;
}

int maior(arvore_bin* arvore) {
    int maior_inf, inf_atual, inf_esquerda, inf_direita;
    inf_atual = arvore->info;
    maior_inf = inf_atual; 
    if (arvore->esq != NULL) {
        inf_esquerda = maior(arvore->esq);

        if (inf_esquerda > maior_inf) {
            maior_inf = inf_esquerda;
        }
    }
    if (arvore->dir != NULL) {
        inf_direita = maior(arvore->dir);

        if (inf_direita > maior_inf) {
            maior_inf = inf_direita;
        }
    }
    return maior_inf;
}

int menor(arvore_bin* arvore) {
    int menor_inf, inf_atual, inf_esquerda, inf_direita;
    inf_atual = arvore->info;
    menor_inf = inf_atual; 
    if (arvore->esq != NULL) {
        inf_esquerda = maior(arvore->esq);

        if (inf_esquerda < menor_inf) {
            menor_inf = inf_esquerda;
        }
    }
    if (arvore->dir != NULL) {
        inf_direita = maior(arvore->dir);

        if (inf_direita < menor_inf) {
            menor_inf = inf_direita;
        }
    }
    return menor_inf;
}

int iguais(arvore_bin* arvore1, arvore_bin* arvore2) {
  if (arvore1 == NULL && arvore2 == NULL) {
    return 1;
  }
  if (arvore1->info != arvore2->info) {
    return 0;
  }
  int esq = iguais(arvore1->esq, arvore2->esq);
  if (esq == 0) {
    return 0;
  }
  int dir = iguais(arvore1->dir, arvore2->dir);
  if (dir == 0) {
    return 0;
  }
  return 1;

}

arvore_bin* remove_arvore(arvore_bin* arvore, int i) {
  if (arvore == NULL) {
    return arvore;
  }
  else {
    if (arvore->info != i) {
      arvore->esq = remove_arvore(arvore->esq, i);
      arvore->dir = remove_arvore(arvore->dir, i);
    }
    else {
      if ((arvore->esq == NULL) && (arvore->dir == NULL)) {
        arvore = NULL;
      }
      else if ((arvore->esq == NULL) || (arvore->dir == NULL)) {
        if (arvore->esq == NULL) {
          arvore = arvore->dir;
        }
        else {
          arvore = arvore->esq;
        }
      }
      else {
        arvore_bin* filho = arvore->esq;
        while (filho->esq != NULL && filho->dir != NULL) {
          filho = filho->esq;
        }
        if (filho->esq == NULL) {
          filho->esq = arvore->dir;
          arvore = arvore->esq;
        }
        else {
          filho->dir = arvore->dir;
          arvore = arvore->esq;
        }
      }
    }
    return arvore;
  }
}

arvore_bin* remove_impares_arvore(arvore_bin* arvore) {
  if(arvore == NULL) {
    return arvore;
  }
  if (arvore->info % 2 != 0) {
    return remove_impares_arvore(remove_arvore(arvore, arvore->info));
  }
  if (arvore->esq != NULL) {
    arvore->esq = remove_impares_arvore(arvore->esq);
  }
  if (arvore->dir != NULL) {
    arvore->dir = remove_impares_arvore(arvore->dir);
  }
  return arvore;
}

arvore_bin* remove_pares_arvore(arvore_bin* arvore) {
  if(arvore == NULL) {
    return arvore;
  }
  if (arvore->info % 2 == 0) {
    return remove_pares_arvore(remove_arvore(arvore, arvore->info));
  }
  if (arvore->esq != NULL) {
    arvore->esq = remove_pares_arvore(arvore->esq);
  }
  if (arvore->dir != NULL) {
    arvore->dir = remove_pares_arvore(arvore->dir);
  }
  return arvore;
}

int contar_folhas(arvore_bin* arvore) {
  if (arvore == NULL) {
    return 0;
  }
  if ((arvore->esq != NULL) || (arvore->dir != NULL)) {
    return 0 + contar_folhas(arvore->esq) + contar_folhas(arvore->dir);
  }
  else {
    return 1;
  }
}

int contar_internos(arvore_bin* arvore) {
  if (arvore == NULL) {
    return 0;
  }
  if ((arvore->esq != NULL) || (arvore->dir != NULL)) {
    return 1 + contar_internos(arvore->esq) + contar_internos(arvore->dir);
  }
  else {
    return 0;
  }
}

void pinta(arvore_bin* arvore, int i) {
  if (arvore != NULL) {
    arvore->info = i;
  }
}

void colore(arvore_bin* arvore) {
  if (arvore == NULL) {
    return;
  }
  if (arvore->info > -1) {
    pinta(arvore, -1);
    pinta(arvore->esq, -2);
    pinta(arvore->dir, -2);
    colore(arvore->esq);
    colore(arvore->dir);
  }
  else if (arvore->info == -1) {
    pinta(arvore->esq, -2);
    pinta(arvore->dir, -2);
    colore(arvore->esq);
    colore(arvore->dir);

  }
  else {
    pinta(arvore->esq, -1);
    pinta(arvore->dir, -1);
    colore(arvore->esq);
    colore(arvore->dir);
  }
  

  
}













/////////////////// FUNÇOES INSERE BUSCA E REMOVE PARA ARVORES BINARIAS DE BUSCA // 

arvore_bin* busca_arv__bin_busca(int i, arvore_bin* arvore) {
  if((arvore == NULL) || (arvore->info == i)) {
    return arvore;
  }
  if (arvore->info > i) {
    return busca_arv__bin_busca(i, arvore->esq);
  }
  else {
    return busca_arv__bin_busca(i, arvore->dir);
  }

}

arvore_bin* insere_arv_bin_busca(arvore_bin* arvore, int i) {
  if (arvore == NULL) {
    return criar_noh(i, NULL, NULL);
  }
  else {
    if (arvore->info > i) {
      arvore->esq = insere_arv_bin_busca(arvore->esq, i);
    }
    else if (arvore->info < i) {
      arvore->dir = insere_arv_bin_busca(arvore->dir, i);
    }
    return arvore;
  }
  if (arvore == NULL) {
    return arvore;
  }
}

arvore_bin* retira_arv_bin_busca(arvore_bin* arvore, int i) {
    if (arvore->info > i) {
      arvore->esq = retira_arv_bin_busca(arvore->esq, i);
    }
    else if (arvore->info < i) {
      arvore->dir = retira_arv_bin_busca(arvore->dir, i);
    }
    else {
      if ((arvore->esq == NULL) && (arvore->dir == NULL)) {
        arvore = NULL;
      }
      else if ((arvore->esq == NULL) || (arvore->dir == NULL)) {
        if (arvore->esq == NULL) {
          arvore = arvore->dir;
        }
        else {
          arvore = arvore->esq;
        }
      }
      else {
        arvore_bin* filho = arvore->esq;
        while (filho->dir != NULL) {
          filho = filho->dir;
        }
        arvore->info = filho->info;
        filho->info = i;
        arvore->esq = retira_arv_bin_busca(arvore->esq, i);
      }
    }
    return arvore;
  }



//////////// ESSAS FUNÇOES DE ABB SAO DESBALANCEADAS POIS ALGUMAS VEZES NAO INSEREM OS ELEMENTOS NA ORDEM CORRETA /// FICANDO MAIS CUSTOSO

arvore_bin* maior_arv__bin_busca(arvore_bin* arvore) {
  if(arvore == NULL) {
    return arvore;
  }
  if (arvore->dir != NULL) {
    return maior_arv__bin_busca(arvore->dir);
  }
  else {
    return arvore;
  }
}

arvore_bin* menor_arv__bin_busca(arvore_bin* arvore) {
  if(arvore == NULL) {
    return arvore;
  }
  if (arvore->esq != NULL) {
    return menor_arv__bin_busca(arvore->esq);
  }
  else {
    return arvore;
  }
}

arvore_bin* retira_impares_arv__bin_busca(arvore_bin* arvore) {
  if(arvore == NULL) {
    return arvore;
  }
  if (arvore->info % 2 != 0) {
    return retira_impares_arv__bin_busca(retira_arv_bin_busca(arvore, arvore->info));
  }
  if (arvore->esq != NULL) {
    arvore->esq = retira_impares_arv__bin_busca(arvore->esq);
  }
  if (arvore->dir != NULL) {
    arvore->dir = retira_impares_arv__bin_busca(arvore->dir);
  }
  return arvore;
}

void vetor_menores_arv_bin_busca(int* vetor, arvore_bin* arvore, int i) {
  if (arvore == NULL) {
    return;
  }
  if (arvore->info > i) {
    return vetor_menores_arv_bin_busca(vetor, arvore->esq, i);
  }
  else {
    *vetor = arvore->info;
    if (arvore->esq != NULL) {
      vetor_menores_arv_bin_busca(vetor+1, arvore->esq, i);
      if (arvore->dir != NULL) {
        vetor_menores_arv_bin_busca(vetor+2, arvore->dir, i);
      }
    }
    else {
      if (arvore->dir != NULL) {
        vetor_menores_arv_bin_busca(vetor+1, arvore->dir, i);
      }
    }
  }
}

/////////////////// EXERCICIOS DE ABB ^ //////

//// ABB_AVL
void libera_avl(arvore_bin_avl* arvore) {
  if (arvore != NULL) {
    libera_avl(arvore->esq);
    libera_avl(arvore->dir);
    free(arvore);
  }
}
int fator_balanceamento(arvore_bin_avl* arvore) {
  return rtrn_altura_avl(arvore->esq) - rtrn_altura_avl(arvore->dir);
}

int rtrn_altura_avl(arvore_bin_avl* arvore) {
  if (arvore == NULL) {
    return -1;
  }
  return arvore->altura;
}

arvore_bin_avl* rsd_avl(arvore_bin_avl * arvore) {
  arvore_bin_avl* novo = arvore->esq;
  arvore->esq = novo->dir;
  novo->dir = arvore;
  arvore->altura = 1 + maximo(rtrn_altura_avl(arvore->esq), rtrn_altura_avl(arvore->dir));
  novo->altura = 1 + maximo(rtrn_altura_avl(novo->esq), rtrn_altura_avl(novo->esq));
  return novo;
}

arvore_bin_avl* rse_avl(arvore_bin_avl * arvore) {
  arvore_bin_avl* novo = arvore->dir;
  arvore->dir = novo->esq;
  novo->esq = arvore;
  arvore->altura = 1 + maximo(rtrn_altura_avl(arvore->esq), rtrn_altura_avl(arvore->dir));
  novo->altura = 1 + maximo (rtrn_altura_avl(novo->esq), rtrn_altura_avl(novo->esq));
  return novo;
}

arvore_bin_avl* red_avl(arvore_bin_avl * arvore) {
  arvore->esq = rse_avl(arvore->esq);
  arvore = rsd_avl(arvore);
  return arvore;
}

arvore_bin_avl* rde_avl(arvore_bin_avl * arvore) {
  arvore->dir = rsd_avl(arvore->dir);
  arvore = rse_avl(arvore);
  return arvore;
}

arvore_bin_avl* insere_avl(arvore_bin_avl* arvore, int i) {
  if(arvore == NULL) {
    arvore = (arvore_bin_avl*) malloc(sizeof(arvore_bin_avl));
    arvore->info = i;
    arvore->altura = 0;
    arvore->esq = arvore->dir = NULL;
    return arvore;
  }
  if (arvore->info > i) {
    arvore->esq = insere_avl(arvore->esq, i);
    if (fator_balanceamento(arvore) == 2) {
      if(arvore->esq->info > i) {
        printf("rsd em %i\n", arvore->info);
        arvore = rsd_avl(arvore);
      }
      else {
        printf("red em %i\n", arvore->info);
        arvore = red_avl(arvore);
      }
    }
  }
  else if(i > arvore->info){
    arvore->dir = insere_avl(arvore->dir, i);
    if(fator_balanceamento(arvore) == -2) {
      if(i > arvore->dir->info) {
        printf("rse em %i\n", arvore->info);
        arvore = rse_avl(arvore);
      }
      else {
        printf("rde em %i\n", arvore->info);
        arvore = rde_avl(arvore);
      }
    }
  }
  arvore->altura = 1 + maximo(rtrn_altura_avl(arvore->dir), rtrn_altura_avl(arvore->esq));
  return arvore;
}

//

fila_arvore_bin_avl* init_fila_avl() {
  fila_arvore_bin_avl* fila = (fila_arvore_bin_avl*) malloc (sizeof(fila_arvore_bin_avl));
  return fila;
}

fila_arvore_bin_avl* push_fila_avl(fila_arvore_bin_avl* fila, arvore_bin_avl* arv) {
    if(fila->arvore == NULL) {
      fila->arvore = arv;
      return fila;
    }
    else {
      fila_arvore_bin_avl* aux = init_fila_avl();
      aux->arvore = arv;
      fila_arvore_bin_avl* aux2 = fila;
      while(aux2->prox != NULL) {
        aux2 = aux2->prox;
      }
      aux2->prox = aux;
      return fila;
    }
}

arvore_bin_avl* pop_fila_avl(fila_arvore_bin_avl* fila) {
  if (fila->prox == NULL) {
    if (fila->arvore == NULL) {
      return NULL;
    }
    else {
      arvore_bin_avl* aux = fila->arvore;
      fila->arvore = NULL;
      return aux;
    }
  }
  else {
    arvore_bin_avl* aux = fila->arvore;
    fila->arvore = fila->prox->arvore;
    fila->prox = fila->prox->prox;
    return aux;
  }
}

int fila_vazia_avl(fila_arvore_bin_avl* fila) {
  if (fila->arvore == NULL) {
    return 1;
  }
  else {
    return 0;
  }
}

void imprime_larg_fila_avl(arvore_bin_avl* arvore) {
  if (!arvore) {
    return;
  }
  else {
    fila_arvore_bin_avl* f = init_fila_avl();
    push_fila_avl(f, arvore);
    while (fila_vazia_avl(f) == 0) {
      arvore_bin_avl* aux = pop_fila_avl(f);
      printf("%i ", aux->info);
      if(aux->esq) {
        f = push_fila_avl(f, aux->esq);
      }
      if(aux->dir) {
        f = push_fila_avl(f, aux->dir);
      }
    }
    free(f);
  }
}

arvore_bin_avl* arv_busca_avl(int i, arvore_bin_avl* arvore) {
  if((arvore == NULL) || (arvore->info == i)) {
    return arvore;
  }
  arvore_bin_avl* resp = arv_busca_avl(i, arvore->esq);
  if(resp) {
    return resp;
  }
  return arv_busca_avl(i, arvore->dir);

  
}

void imprime_avl_aux(arvore_bin_avl* arvore, int andar) {
  if(arvore != NULL) {
    int j;
    imprime_avl_aux(arvore->esq, andar + 1);
    for(j = 0; j <= andar; j++) {
      printf("\t");
    } 
    printf("%d\n", arvore->info);
    imprime_avl_aux(arvore->dir, andar + 1);
  }
}


void imprime_avl(arvore_bin_avl* arvore) {
  imprime_avl_aux(arvore, 1);
}

int calc_alt_retira_avl(arvore_bin_avl* arvore) {
  if(arvore == NULL) {
    return 0;
  }
  int lh, rh;
  lh = 1 + rtrn_altura_avl(arvore->esq);
  lh = 1 + rtrn_altura_avl(arvore->dir);
  if(lh > rh) {
    return lh;
  }
  else {
    return rh;
  }
}

arvore_bin_avl* remove_avl(arvore_bin_avl* arvore, int i) {     
  if(arvore == NULL) {
    return arvore;
  }
  else if(i > arvore->info) {
    arvore->dir = remove_avl(arvore->dir, i);
    if (fator_balanceamento(arvore) == 2) {
      if (fator_balanceamento(arvore->esq) >= 0) {
        printf("rsd em %i\n", arvore->info);
        arvore = rsd_avl(arvore);
      }
      else {
        printf("red em %i\n", arvore->info);
        arvore = red_avl(arvore);
      }
    }
  }
  else if(i < arvore->info) {
    arvore->esq = remove_avl(arvore->esq, i);
    if(fator_balanceamento(arvore) == -2) {
      if(fator_balanceamento(arvore->dir) <= 0) {
        printf("rse em %i\n", arvore->info);
        arvore = rse_avl(arvore);
      }
      else {
        printf("rde em %i\n", arvore->info);
        arvore = rde_avl(arvore);
      }
    }
  }
  else {
    if(arvore->esq) {
      arvore_bin_avl* aux = arvore->esq;
      while(aux->dir) {
        aux = aux->dir;
      } 
      arvore->info = aux->info;
      arvore->esq = remove_avl(arvore->esq, aux->info);
      if(fator_balanceamento(arvore) == -2) {
        if(fator_balanceamento(arvore->dir) <= 0) {
        printf("rse em %i\n", arvore->info);
          arvore = rse_avl(arvore);
        }
        else {
        printf("rde em %i\n", arvore->info);
          arvore = rde_avl(arvore);
        }
      }
    }
    else {
       arvore_bin_avl* aux = arvore;
       arvore = arvore->dir;
       return(arvore);
    }
  }
  arvore->altura = calc_alt_retira_avl(arvore);
  return arvore;
}