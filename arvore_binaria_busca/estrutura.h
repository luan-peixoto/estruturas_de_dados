typedef struct arvore_bin {
  int info;
  struct arvore_bin *esq;
  struct arvore_bin *dir;
} arvore_bin;

typedef struct pilha_arvore_bin {
  struct pilha_arvore_bin *anterior;
  struct arvore_bin *arvore;
} pilha_arvore_bin;

typedef struct fila_arvore_bin {
  struct fila_arvore_bin *prox;
  struct arvore_bin *arvore;
} fila_arvore_bin;

typedef struct arvore_bin_avl {
  int info;
  int altura;
  struct arvore_bin_avl *esq;
  struct arvore_bin_avl *dir;
} arvore_bin_avl;

typedef struct pilha_arvore_bin_avl {
  struct pilha_arvore_bin_avl *anterior;
  struct arvore_bin_avl* arvore;
} pilha_arvore_bin_avl;

typedef struct fila_arvore_bin_avl {
  struct fila_arvore_bin_avl *prox;
  struct arvore_bin_avl* arvore;
} fila_arvore_bin_avl;

fila_arvore_bin* init_fila();

fila_arvore_bin* push_fila(fila_arvore_bin* fila, arvore_bin* arv);

arvore_bin* pop_fila(fila_arvore_bin* fila);

int fila_vazia(fila_arvore_bin* fila);

void imprime_larg_fila(arvore_bin* arvore);


pilha_arvore_bin* init();

pilha_arvore_bin* push(pilha_arvore_bin* pilha, arvore_bin * arv);

arvore_bin* pop(pilha_arvore_bin* pilha);

int pilha_vazia(pilha_arvore_bin* pilha);

arvore_bin* inicializa();

arvore_bin* criar_noh(int i, arvore_bin* esq, arvore_bin* dir);

arvore_bin* criar_arv_vetor_simetrica(int* vetor, int len);

void libera_arv_bin(arvore_bin* arvore);

void imprime_pre_red(arvore_bin* arvore);

void imprime_pre_red_pilha(arvore_bin* arvore);

void imprime_sim_erd(arvore_bin* arvore);

void imprime_pos_edr(arvore_bin* arvore);

arvore_bin* arv_busca(int i, arvore_bin* arvore);

int altura(arvore_bin* arvore);

int maximo(int x, int y); 

///////// exerc lista 1

arvore_bin* copia(arvore_bin* arvore);

arvore_bin* espelho(arvore_bin* arvore);

int maior(arvore_bin* arvore);

int menor(arvore_bin* arvore);

int iguais(arvore_bin* arvore1, arvore_bin* arvore2);

arvore_bin* remove_arvore(arvore_bin* arvore, int i);

arvore_bin* remove_impares_arvore(arvore_bin* arvore);

arvore_bin* remove_pares_arvore(arvore_bin* arvore);

int contar_folhas(arvore_bin*arvore);

int contar_internos(arvore_bin* arvore);

void pinta(arvore_bin* arvore, int i);

void colore(arvore_bin* arvore);


/////////// abb e exerc lista 2

arvore_bin* busca_arv_bin_busca(int i, arvore_bin* arvore);

arvore_bin* insere_arv_bin_busca(arvore_bin* arvore, int i);

arvore_bin* retira_arv_bin_busca(arvore_bin* arvore, int i);

arvore_bin* maior_arv__bin_busca(arvore_bin* arvore);

arvore_bin* menor_arv__bin_busca(arvore_bin* arvore);

arvore_bin* retira_impares_arv__bin_busca(arvore_bin* arvore);

void vetor_menores_arv_bin_busca(int* vetor, arvore_bin* arvore, int i);

/// exerc 7 list 2

typedef struct figura {
  void* info;
  int tipo;
  struct figura *esq;
  struct figura *dir;
} figura;
typedef struct retangulo {
  int base;
  int altura;
  int area;
} retangulo;
typedef struct triangulo {
  int base;
  int altura;
  int area;
} triangulo;
typedef struct trapezio {
  int base;
  int altura;
  int area;
} trapezio;

void libera_avl(arvore_bin_avl* arvore);

int fator_balanceamento(arvore_bin_avl* arvore);

int rtrn_altura_avl(arvore_bin_avl* arvore);

arvore_bin_avl* rsd_avl(arvore_bin_avl * arvore);

arvore_bin_avl* rse_avl(arvore_bin_avl * arvore);

arvore_bin_avl* red_avl(arvore_bin_avl * arvore);

arvore_bin_avl* rde_avl(arvore_bin_avl * arvore);

arvore_bin_avl* insere_avl(arvore_bin_avl* arvore, int i);

//

fila_arvore_bin_avl* init_fila_avl();

fila_arvore_bin_avl* push_fila_avl(fila_arvore_bin_avl* fila, arvore_bin_avl* arv);

arvore_bin_avl* pop_fila_avl(fila_arvore_bin_avl* fila);

int fila_vazia_avl(fila_arvore_bin_avl* fila);

void imprime_larg_fila_avl(arvore_bin_avl* arvore);

arvore_bin_avl* arv_busca_avl(int i, arvore_bin_avl* arvore);

void imprime_avl_aux(arvore_bin_avl* arvore, int andar);


void imprime_avl(arvore_bin_avl* arvore);

int calc_alt_retira_avl(arvore_bin_avl* arvore);

arvore_bin_avl* remove_avl(arvore_bin_avl* arvore, int i);