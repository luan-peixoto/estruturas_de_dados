#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "estrutura.h"

void printar_algo() {
  puts("                     com mil mamacos.");
}

// CRIAR PONTO COM ALOCAÇÃO DINÂMICA //

ponto* criar_ponto(float x, float y) {
  ponto* p = (ponto*) malloc(sizeof(ponto));
  if (p == NULL) {
    puts("Memória insuficiente.");
  }
  p->x = x;
  p->y = y;
  return p;
}

void liberar_ponto(ponto* p) {
  free(p);
}

float dist_ponto(ponto* p1, ponto* p2) {
  float dx = p2->x - p1->x;
  float dy = p2->y - p1->y;
  return sqrt(dx*dx + dy*dy);
}

void acessa_ponto(ponto* p, float* x, float* y) {
  *x = p->x;
  *y = p->y;
}

void atribui_ponto(ponto* p, float x, float y) {
  p->x = x;
  p->y = y;
}

// PONTO COM ALOCAÇÃO DINÂMICA ^ //

// CIRCULO COM ALOCAÇÃO DINÂMICA //

circulo* criar_circulo(int raio, float x, float y) {
  circulo* c = (circulo*) malloc(sizeof(circulo));
  if (c == NULL) {
    puts("Memória insuficiente.");
  }
  c->centro.x = x;
  c->centro.y = y;
  c->raio = raio;
  return c;
}

void liberar_circulo(circulo* c) {
  free(c);
}

float area_circulo(circulo* c) {
  float r = c->raio;
  return 3.14 * r * r;
}

int contido_em_circulo(circulo* c, ponto* p) {
  float px = p->x;
  float py = p->y;
  float cx = c->centro.x;
  float cy = c->centro.y;
  float raio = c->raio;
  if (px <= cx+raio && px >= cx-raio && py <= cy+raio && px >= cy-raio) {
    return 1;
  }
  else {
    return 0;
  }
}

// CIRCULO COM ALOCAÇÃO DINÂMICA ^ //

// LISTA ENCADEADA //

lista_encadeada* lista_cria() {
  return NULL;
}

lista_encadeada* lista_insere(lista_encadeada* l, int i) {
  lista_encadeada* novo = (lista_encadeada*) malloc(sizeof(lista_encadeada));
  novo->i = i;
  novo->prox = l;
  return novo;
}

void lista_exclui (lista_encadeada* l) {
  lista_encadeada* p = l;
  while (p != NULL) {
    lista_encadeada* t = p->prox;
    free(p);
    p = t;
  }
}

void lista_imprime(lista_encadeada* l) {
  lista_encadeada* p;
  for (p = l; p != NULL; p = p->prox) {
    printf("N = %i\n", p->i);
  }
}

lista_encadeada* lista_busca(lista_encadeada* l, int i) {
  lista_encadeada* p;
  for (p = l; p != NULL; p = p->prox) {
    if (p->i == i) {
      return p;
    }
  }
  return NULL;
}

lista_encadeada* lista_remove_i(lista_encadeada* l, int i) {
  lista_encadeada* ant = NULL;
  lista_encadeada* p = l;
  while (p != NULL && p->i != i) {
    ant = p;
    p = p->prox;
  }
  if (p == NULL) {
    return l;
  }
  if (ant == NULL) {
    l = p->prox;
  }
  else {
    ant->prox = p->prox;
  }
  free(p);
  return l;
}

lista_encadeada* lista_insere_ord(lista_encadeada* l, int i) {
  lista_encadeada* ant = NULL;
  lista_encadeada* p = l;
  while (p != NULL && p->i < i) {
    ant = p;
    p = p->prox;
  }
  lista_encadeada* novo = (lista_encadeada*) malloc(sizeof(lista_encadeada));
  novo->i = i;
  if (ant == NULL) {
    novo->prox = l;
    l = novo;
  }
  else {
    novo->prox = ant->prox;
    ant->prox = novo;
  }
  return l;
}

lista_encadeada* lista_divide(lista_encadeada* l2, int i) {
  lista_encadeada* ant = NULL;
  lista_encadeada* p = l2;
  while(i > 0 && p->prox != NULL) {
    ant = p;
    p = p->prox;
    i -= 1;
  }
  ant->prox = NULL;
  return p;
}

lista_encadeada* lista_concatena(lista_encadeada* l, lista_encadeada* l2) {
  lista_encadeada * p = l;
  lista_encadeada * ant = NULL;
  while (p != NULL) {
    ant = p;
    p = p->prox;
  }
  ant->prox = l2;
  return l;
}

lista_encadeada* lista_criar_de_vetor(lista_encadeada* l, int* v, int len) {
  lista_encadeada* ant = l;
  while (len != 0) {
    lista_encadeada* novo = (lista_encadeada*) malloc(sizeof(lista_encadeada));
    novo->i = *v;
    novo->prox = ant;
    ant = novo;
    v += 1;
    len -= 1;
  }
  return ant;
}

lista_encadeada* lista_criar_de_vetor_reverso(lista_encadeada* l, int* v, int len) {
  v += len - 1;
  lista_encadeada* ant = l;
  while (len != 0) {
    lista_encadeada* novo = (lista_encadeada*) malloc(sizeof(lista_encadeada));
    novo->i = *v;
    novo->prox = ant;
    ant = novo;
    v -= 1;
    len -= 1;
  }
  return ant;
}

lista_encadeada* lista_insere_no_fim(lista_encadeada* l, int i) {
  lista_encadeada* ant = NULL;
  lista_encadeada* p = l;
  lista_encadeada* novo = (lista_encadeada*) malloc(sizeof(lista_encadeada));
  novo->i = i;
  novo->prox = NULL;
  while(p != NULL) {
    ant = p;
    p = p->prox;
  }
  if (l == NULL) {
    novo->prox = l;
    return novo;
  }
  else {
    ant->prox = novo;
    novo->prox = p;
  }
  return l;
}

int lista_len(lista_encadeada* l) {
  int len = 0;
  if (l == NULL) {
    return 0;
  }
  else {
    lista_encadeada* p = l;
    while (p != NULL) {
      len += 1;
      p= p->prox;
    }
  }
  return len;
}

lista_encadeada* lista_insere_em_pos(lista_encadeada* l, int i, int pos) {
  lista_encadeada* ant = NULL;
  lista_encadeada* p = l;
  lista_encadeada* novo = (lista_encadeada*) malloc(sizeof(lista_encadeada));
  novo->i = i;
  novo->prox = NULL;
  if (pos == 1 || p == NULL) {
    novo->prox = p;
    return novo;
  }
  while(pos != 1 && p != NULL) {
    pos -= 1;
    ant = p;
    p = p->prox;
  }
  ant->prox = novo;
  novo->prox = p;
  return l;
}

lista_encadeada* lista_remove_todos(lista_encadeada* l, int i) {
  lista_encadeada* ant = NULL;
  lista_encadeada* p = l;
  while (p != NULL) {
    if (p->i == i) {
      if (ant == NULL) {
        p = p->prox;
      }
      else {
        ant->prox = p->prox;
        free(p);
        p = p->prox;
      }
    }
    else {
      ant = p;
      p = p->prox;
    }

  }
  return l;
}

//////////////

void lista_ordena(lista_encadeada* l) {
  lista_encadeada* p;
  for (p = l; p != NULL; p = p->prox) {
    lista_encadeada* q;
    lista_encadeada* menor = p;
    for (q = p; p != NULL; q = q->prox) {
      if (q-> i < menor->i) {
        menor = q;
      }
    }
    if (menor != p) {
      int tempo = menor->i;
      menor->i = p->i;
      p->i = tempo;
    }
  }
}

// OU

lista_encadeada* lista_ordena1(lista_encadeada* l) {
  lista_encadeada* p;
  for (p = l; p != NULL; p = p->prox) {
    lista_encadeada* q;
    lista_encadeada* menor = p;
    for (q = p; p != NULL; q = q->prox) {
      if (q-> i < menor->i) {
        menor = q;
      }
    }
    if (menor != p) {
      int tempo = menor->i;
      menor->i = p->i;
      p->i = tempo;
    }
  }
  return l;
}

// DA NO MSM ^^