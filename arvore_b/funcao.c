#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "estrutura.h"
#define MAX_INT 99999;

arvore_b* inicializa() {
  return NULL;
}

arvore_b* cria_no(int t) {
  arvore_b* novo = NULL;
  novo = (arvore_b*) malloc(sizeof(arvore_b));
  novo->nchaves = 0;
  novo->chave = (int*) malloc(sizeof(int) * (2*t-1));
  novo->folha = 1;
  novo->filho = (arvore_b**) malloc(sizeof(arvore_b*) * (2 *t));
  int i;
  for (i = 0; i< 2*t ; i++) {
    novo->filho[i] = NULL;
  }
  return novo;
}

void imp_aux(arvore_b *a, int andar){
  if(a) {
    int i,j;
    for(i=0; i<=a->nchaves-1; i++){
      imp_aux(a->filho[i],andar+1);
      for(j=0; j<=andar; j++) printf("    ");
      printf("%d\n", a->chave[i]);
    }
    imp_aux(a->filho[i], andar + 1);
  }
}

void imprime(arvore_b* a) {
  imp_aux(a, 0);
}

void libera(arvore_b * a) {
  if (a) {
    if (!a->folha) {
      int i;
      for (int i = 0; i <= a->nchaves; i++) {
        libera(a->filho[i]);
      }
    }
    free(a->filho);
    free(a->chave);
    free(a);
  }
}

arvore_b *Busca(arvore_b* a, int ch) {
  if(!a) return NULL;
  int i = 0;
  while(i < a->nchaves && ch > a->chave[i]) i++;
  if(i < a->nchaves && ch == a->chave[i]) return a;
  if(a->folha) return NULL;
  return Busca(a->filho[i], ch);
}

//

arvore_b *divisao(arvore_b* x, int ind, arvore_b* y, int t) {
  arvore_b* z = cria_no(t);
  z->nchaves = t-1;
  z->folha = y->folha;
  int j;

  for (j = 0; j < t - 1; j++) {
    z->chave[j] = y->chave[j+t];
  }

  if(!y->folha){
    for(j=0;j<t;j++){
      z->filho[j] = y->filho[j+t];
      y->filho[j+t] = NULL;
    }
  }

  y->nchaves = t-1;
  
  for(j=x->nchaves; j>=ind; j--) 
    x->filho[j+1] = x->filho[j];
  x->filho[ind] = z;

  for(j=x->nchaves; j>=ind; j--) 
    x->chave[j] = x->chave[j-1];
  x->chave[ind-1] = y->chave[t-1];

  x->nchaves++;
  return x;
}


arvore_b* insere_nao_completo(arvore_b* x, int k, int t) {

  int i = x->nchaves-1;

  if(x->folha) {
    
    while((i>=0) && (k<x->chave[i])) {
      x->chave[i+1] = x->chave[i];
      i--;
    }


    x->chave[i+1] = k;
    x->nchaves++;
    return x;
  }

  while((i>=0) && (k<x->chave[i])) i--;

  i++;

  if(x->filho[i]->nchaves == ((2*t)-1)) {
    x = divisao(x, (i+1), x->filho[i], t);
    if(k>x->chave[i]) i++;
  }

  x->filho[i] = insere_nao_completo(x->filho[i], k, t);
  return x;
}

arvore_b* insere(arvore_b* T, int k, int t) {
  if(Busca(T,k)) return T;
  if(!T) {
    T = cria_no(t);
    T->chave[0] = k;
    T->nchaves = 1;
    return T;
  }

  if (T->nchaves == (2*t)-1) {
    arvore_b* S = cria_no(t);

    S->nchaves = 0;
    S->folha = 0;
    S->filho[0] = T;
    S = divisao(S,1,T,t);
    S = insere_nao_completo(S,k,t);
    return S;
  }
  T = insere_nao_completo(T,k,t);
  return T;
}
  
void Limpa_Remocao(arvore_b *a){ //ultima revisao: 04/2020
  if(!a) return;
  int i;
  for(i = 0; i <= a->nchaves; i++) a->filho[i] = NULL;
}


arvore_b* remover(arvore_b* arv, int ch, int t){
  if(!arv) return arv;
  int i;
  printf("Removendo %d\n", ch);
  printf("\nno: ");
  for (int j = 0; j < arv->nchaves; j++) printf("%d ", arv->chave[j]);
  for(i = 0; i<arv->nchaves && arv->chave[i] < ch; i++);
  if(i < arv->nchaves && ch == arv->chave[i]){ //CASOS 1, 2A, 2B e 2C
    if(arv->folha){ //CASO 1
      printf("\nCASO 1: n está na folha e tem t ou mais chaves\n\n");
      int j;
      for(j=i; j<arv->nchaves-1;j++) arv->chave[j] = arv->chave[j+1];
      arv->nchaves--;
      if(!arv->nchaves){ //ultima revisao: 04/2020
        libera(arv);
        arv = NULL;
      }
      return arv;      
    }
    if(!arv->folha && arv->filho[i]->nchaves >= t){ //CASO 2A
      printf("\nCASO 2A: filho à esq de n tem t ou mais chaves\ndesce até o maior elemento a esq de n\ncoloca esse elemento em n\naplica as transformacoes necessarias para remover esse elemento da posicao antiga\n\n");
      arvore_b *y = arv->filho[i];  //Encontrar o predecessor k' de k na árvore com raiz em y
      while(!y->folha) y = y->filho[y->nchaves];
      int temp = y->chave[y->nchaves-1];
      arv->filho[i] = remover(arv->filho[i], temp, t); 
      //Eliminar recursivamente K e substitua K por K' em x
      arv->chave[i] = temp;
      return arv;
    }
    if(!arv->folha && arv->filho[i+1]->nchaves >= t){ //CASO 2B
      printf("\nCASO 2B: filho à dir de n tem t ou mais chaves\ndesce até o menor elemento a dir de n\ncoloca esse elemento em n\naplica as transformacoes necessarias para remover esse elemento da posicao antiga\n\n");
      arvore_b*y = arv->filho[i+1];  //Encontrar o sucessor k' de k na árvore com raiz em y
      while(!y->folha) y = y->filho[0];
      int temp = y->chave[0];
      y = remover(arv->filho[i+1], temp, t); //Eliminar recursivamente K e substitua K por K' em x
      arv->chave[i] = temp;
      return arv;
    }
    if(!arv->folha && arv->filho[i+1]->nchaves == t-1 && arv->filho[i]->nchaves == t-1){ //CASO 2C
      printf("\nCASO 2C: ambos filhos de n tem t-1 chaves\nse n nao tinha irmao filho da esq e dir sobem e viram irmao de nN\nse n tinha irmao junta filho da esq com n com filho da dir e eles viram filho do ex irmao imediato\ndps apaga n\n\n");
      arvore_b*y = arv->filho[i];
      arvore_b*z = arv->filho[i+1];
      y->chave[y->nchaves] = ch;          //colocar ch ao final de filho[i]
      int j;
      for(j=0; j<t-1; j++)                //juntar chave[i+1] com chave[i]
        y->chave[t+j] = z->chave[j];
      for(j=0; j<=t; j++){                 //juntar filho[i+1] com filho[i]
        y->filho[t+j] = z->filho[j];
        z->filho[j] = NULL; //ultima revisao: 04/2020
      }
      //TARVB_Libera(z);
      y->nchaves = 2*t-1;
      for(j=i; j < arv->nchaves-1; j++)   //remover ch de arv
        arv->chave[j] = arv->chave[j+1];
      for(j=i+1; j < arv->nchaves; j++)  
        arv->filho[j] = arv->filho[j+1]; //remover ponteiro para filho[i+1]
      //Limpa_Remocao(arv->filho[j]);
      //TARVB_Libera(arv->filho[j]);
      arv->filho[j] = NULL;
      arv->nchaves--;
      if(!arv->nchaves){ //ultima revisao: 04/2020
        arvore_b *temp = arv;
        arv = arv->filho[0];
        temp->filho[0] = NULL;
        libera(temp);
        arv = remover(arv, ch, t);
      }
      else arv->filho[i] = remover(arv->filho[i], ch, t);
      return arv;   
    }   
  }

  arvore_b *y = arv->filho[i], *z = NULL;
  if (y->nchaves == t-1){ //CASOS 3A e 3B
    if((i < arv->nchaves) && (arv->filho[i+1]->nchaves >=t)){ //CASO 3A
      printf("\nCASO 3A EM NOH %d: no tem t - 1 chaves e irmao imediato tem t ou mais chaves\ndesce o elemento do pai do no e do irmao para o no\ncoloca o menor do irmao pro pai do elemento removido de pai\ncaso 3a pode acontecer em no que nao contem n, porem eh caminho ate n\n\n", arv->chave[0]);
      z = arv->filho[i+1];
      y->chave[t-1] = arv->chave[i];   //dar a y a chave i da arv
      y->nchaves++;
      arv->chave[i] = z->chave[0];     //dar a arv uma chave de z
      int j;
      for(j=0; j < z->nchaves-1; j++)  //ajustar chaves de z
        z->chave[j] = z->chave[j+1];
      y->filho[y->nchaves] = z->filho[0]; //enviar ponteiro menor de z para o novo elemento em y
      for(j=0; j < z->nchaves; j++)       //ajustar filhos de z
        z->filho[j] = z->filho[j+1];
      z->nchaves--;
      arv->filho[i] = remover(arv->filho[i], ch, t);
      return arv;
    }
    if((i > 0) && (!z) && (arv->filho[i-1]->nchaves >=t)){ //CASO 3A
      printf("\nCASO 3A EM NOH %d: no tem t - 1 chaves e irmao imediato tem t ou mais chaves\ndesce o elemento do pai do no e do irmao para o no\ncoloca o menor do irmao pro pai do elemento removido de pai\ncaso 3a pode acontecer em no que nao contem n, porem eh caminho ate n\n\n", arv->chave[0]);
      z = arv->filho[i-1];
      int j;
      for(j = y->nchaves; j>0; j--)               //encaixar lugar da nova chave
        y->chave[j] = y->chave[j-1];
      for(j = y->nchaves+1; j>0; j--)             //encaixar lugar dos filhos da nova chave
        y->filho[j] = y->filho[j-1];
      y->chave[0] = arv->chave[i-1];              //dar a y a chave i da arv
      y->nchaves++;
      arv->chave[i-1] = z->chave[z->nchaves-1];   //dar a arv uma chave de z
      y->filho[0] = z->filho[z->nchaves];         //enviar ponteiro de z para o novo elemento em y
      z->nchaves--;
      arv->filho[i] = remover(y, ch, t);
      return arv;
    }
    if(!z){ //CASO 3B
      if(i < arv->nchaves && arv->filho[i+1]->nchaves == t-1){
        printf("\nCASO 3B EM NOH %d: no de n tem t - 1 chaves e irmaos imediatos tem t - 1 tambem\njunta pai dos dois irmaos com irmaos e remove n (parecido com c)\ncaso 3b pode acontecer em no que nao contem n, porem eh caminho ate n\n\n", arv->chave[0]);
        z = arv->filho[i+1];
        y->chave[t-1] = arv->chave[i];     //pegar chave [i] e coloca ao final de filho[i]
        y->nchaves++;
        int j;
        for(j=0; j < t-1; j++){
          y->chave[t+j] = z->chave[j];     //passar filho[i+1] para filho[i]
          y->nchaves++;
        }
        if(!y->folha){
          for(j=0; j<t; j++){
            y->filho[t+j] = z->filho[j];
            z->filho[j] = NULL; //ultima revisao: 04/2020
          }
          libera(z);
        }
        for(j=i; j < arv->nchaves-1; j++){ //limpar referências de i
          arv->chave[j] = arv->chave[j+1];
          arv->filho[j+1] = arv->filho[j+2];
        }
        arv->filho[arv->nchaves] = NULL;
        arv->nchaves--;
        if(!arv->nchaves){ //ultima revisao: 04/2020
          arvore_b *temp = arv;
          arv = arv->filho[0];
          temp->filho[0] = NULL;
          libera(temp);
        }
        arv = remover(arv, ch, t);
        return arv;
      }
      if((i > 0) && (arv->filho[i-1]->nchaves == t-1)){ 
        printf("\nCASO 3B EM NOH %d: no de n tem t - 1 chaves e irmaos imediatos tem t - 1 tambem\njunta pai dos dois irmaos com irmaos e remove n (parecido com c)\ncaso 3b pode acontecer em no que nao contem n, porem eh caminho ate n\n\n", arv->chave[0]);
        z = arv->filho[i-1];
        if(i == arv->nchaves)
          z->chave[t-1] = arv->chave[i-1]; //pegar chave[i] e poe ao final de filho[i-1]
        else
          z->chave[t-1] = arv->chave[i];   //pegar chave [i] e poe ao final de filho[i-1]
        z->nchaves++;
        int j;
        for(j=0; j < t-1; j++){
          z->chave[t+j] = y->chave[j];     //passar filho[i+1] para filho[i]
          z->nchaves++;
        }
        if(!z->folha){
          for(j=0; j<t; j++){
            z->filho[t+j] = y->filho[j];
            y->filho[j] = NULL; //ultima revisao: 04/2020
          }
          libera(y);
        }
        arv->filho[arv->nchaves] = NULL;
        arv->nchaves--;
        if(!arv->nchaves){ //ultima revisao: 04/2020
          arvore_b *temp = arv;
          arv = arv->filho[0];
          temp->filho[0] = NULL;
          libera(temp);
        }
        else arv->filho[i-1] = z;
        arv = remover(arv, ch, t);
        return arv;
      }
    }
  }  
  arv->filho[i] = remover(arv->filho[i], ch, t);
  return arv;
}


arvore_b* TARVB_Retira(arvore_b* arv, int k, int t) {
  if(!arv || !Busca(arv, k)) return arv;
  return remover(arv, k, t);
}

// exerc

arvore_b* copia(arvore_b* arv, int t) {
  if (!arv) {
    return NULL;
  }
  arvore_b* novo = NULL;
  novo = (arvore_b*) malloc(sizeof(arvore_b));
  novo->nchaves = arv->nchaves;
  novo->folha = arv->folha;
  novo->chave = (int*) malloc(sizeof(int) * (2*t-1));
  novo->filho = (arvore_b**) malloc(sizeof(arvore_b*) * (2 *t));
  for (int i = 0; i < arv->nchaves; i++) {
    novo->chave[i] = arv->chave[i];
    novo->filho[i] = copia(arv->filho[i], t);
  }
  novo->filho[novo->nchaves] = copia(arv->filho[novo->nchaves], t);
  return novo;
}

int sucessor(arvore_b* arv, int t, int ch) {
  arvore_b* aux = inicializa();
  arvore_b* aux2 = inicializa();
  aux = Busca(arv, ch);
  if (!aux) {
    return -1;
  }
  if (arv->chave[0] != aux->chave[0]) {
    aux2 = Busca(arv, aux->chave[0] - 1);
  }
  for (int i = 0; i < aux->nchaves; i++) {
    if (ch == aux->chave[i]) {
      if(aux->filho[i+1]) {
        return aux->filho[i+1]->chave[0];
      }
      else {
        if (i < aux->nchaves-1) {
          return aux->chave[i+1];
        }
        else {
          if (aux2) {
            for (int j = 0; j < aux2->nchaves; j++) if (aux2->chave[j] > ch) return aux2->chave[j];
          }
          return MAX_INT;
        }
      }
    }
  }
  return-1;
}

arvore_b* maior(arvore_b* arv) {
  if (!arv) {
    return NULL;
  }
  arvore_b* aux = inicializa();
  aux = arv;
  while (aux->filho[aux->nchaves]) aux = aux->filho[aux->nchaves];
  return aux;
}

arvore_b* menor(arvore_b* arv) {
  if (!arv) {
    return NULL;
  }
  arvore_b* aux = inicializa();
  aux = arv;
  while (aux->filho[0]) aux = aux->filho[0];
  return aux;
}

int igual(arvore_b* arv, arvore_b* arv2) {
  if ((!arv && !arv2)) {
    return 1;
  }
  else if ((!arv && arv2) || (arv && !arv2)) {
    return 0;
  }
  if (arv->nchaves != arv2->nchaves) {
    return 0;
  }
  for (int i = 0; i < arv->nchaves; i++) {
    if (arv->chave[i] != arv2->chave[i]) {
      return 0;
    }
    if (!igual(arv->filho[i],arv2->filho[i])) {
      return 0;
    }
  }
  if (!igual(arv->filho[arv->nchaves],arv2->filho[arv2->nchaves])) {
    return 0;
  }
  return 1;

}

int retira_pares_aux(arvore_b* arv) {
  if (!arv) {
    return -1;
  }
  arvore_b* aux = NULL;
  aux = arv;
  for (int i = 0; i < aux->nchaves; i++) {
    if (retira_pares_aux(arv->filho[i]) != -1) {
      return retira_pares_aux(arv->filho[i]);
    }
    if(aux->chave[i] % 2 == 0) return aux->chave[i];
  }
  if (retira_pares_aux(arv->filho[aux->nchaves]) != -1) {
      return retira_pares_aux(arv->filho[aux->nchaves]);
    }
  return -1;
}

arvore_b* retira_pares(arvore_b* arv, int t) {
  if (!arv) {
    return NULL;
  }
  arvore_b* aux = NULL;
  aux = arv;
  int c = retira_pares_aux(arv);
  while(c != -1) {
    retira_pares(TARVB_Retira(arv, c, t), t);
    c = retira_pares_aux(arv);
  } 
}

int no_internos(arvore_b* arv) {
  if (!arv || (arv->folha == 1)) {
    return 0;
  }
  int c = 1;
  for (int i = 0; i < arv->nchaves; i++) {
    c += no_internos(arv->filho[i]);
  }
  c += no_internos(arv->filho[arv->nchaves]);
  return c;
}

int no_folhas(arvore_b* arv) {
  if (!arv) {
    return 0;
  }
  if (arv->folha == 1) return 1; 
  int c = 0;
  for (int i = 0; i < arv->nchaves; i++) {
    c += no_folhas(arv->filho[i]);
  }
  c += no_folhas(arv->filho[arv->nchaves]);
  return c;
}