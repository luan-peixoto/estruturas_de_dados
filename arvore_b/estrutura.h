typedef struct arvore_b {
  int nchaves, folha;
  int* chave;
  struct arvore_b** filho;
} arvore_b;

arvore_b* inicializa();

arvore_b* cria_no(int t);

void imprime(arvore_b* a);

void imp_aux(arvore_b* a, int andar);

arvore_b *Busca(arvore_b* a, int ch);

arvore_b *divisao(arvore_b* x, int ind, arvore_b* y, int t);

arvore_b* insere_nao_completo(arvore_b* x, int k, int t);

arvore_b* insere(arvore_b* T, int k, int t);

void Limpa_Remocao(arvore_b *a);

arvore_b* remover(arvore_b* arv, int ch, int t);

arvore_b* TARVB_Retira(arvore_b* arv, int k, int t);

//

arvore_b* copia(arvore_b* arv, int t);

int sucessor(arvore_b* arv, int t, int ch);

arvore_b* maior(arvore_b* arv);

arvore_b* menor(arvore_b* arv);

int igual(arvore_b* arv, arvore_b* arv2);

arvore_b* retira_pares(arvore_b* arv, int t);

int no_internos(arvore_b* arv);

int no_folhas(arvore_b* arv);