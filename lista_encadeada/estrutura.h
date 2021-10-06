typedef struct ponto {
  float x;
  float y;
} ponto;

typedef struct circulo {
  ponto centro;
  float raio;
} circulo;

void printar_algo();

ponto* criar_ponto(float x, float y);

void liberar_ponto(ponto* p);

float dist_ponto(ponto* p1, ponto* p2);

void acessa_ponto(ponto* p, float* x, float* y);

void atribui_ponto(ponto* p, float x, float y);

circulo* criar_circulo(int raio, float x, float y);

void liberar_circulo(circulo* c);

float area_circulo(circulo* c);

int contido_em_circulo(circulo* c, ponto* p);

// LISTA ENCADEADA COM ALOCAÇAO DINAMICA

typedef struct lista_encadeada {
  int i;
  struct lista_encadeada* prox;
} lista_encadeada;

lista_encadeada* lista_cria();

lista_encadeada* lista_insere(lista_encadeada* l, int i);

void lista_exclui(lista_encadeada* l);

void lista_imprime(lista_encadeada* l);

lista_encadeada* lista_busca(lista_encadeada* l, int i);

lista_encadeada* lista_remove_i(lista_encadeada* l, int i);

lista_encadeada* lista_insere_ord(lista_encadeada* l, int i);

lista_encadeada* lista_divide(lista_encadeada* l2, int i);

lista_encadeada* lista_concatena(lista_encadeada* l, lista_encadeada* l2);

lista_encadeada* lista_criar_de_vetor(lista_encadeada* l, int* v, int len);

lista_encadeada* lista_criar_de_vetor_reverso(lista_encadeada* l, int* v, int len);

lista_encadeada* lista_insere_no_fim(lista_encadeada* l, int i);

int lista_len(lista_encadeada* l);

lista_encadeada* lista_insere_em_pos(lista_encadeada* l, int i, int pos);

lista_encadeada* lista_remove_todos(lista_encadeada* l, int i);

void lista_ordena(lista_encadeada* l);

lista_encadeada* lista_ordena1(lista_encadeada* l);