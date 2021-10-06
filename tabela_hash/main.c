#include "TH.h"

int main(void){
  int n, m;
  printf("Digite m (tamanho da tabela hash)... ");
  scanf("%d", &m);
  printf("Digite n (quantidade de matriculas)... ");
  scanf("%d", &n);

  if((n <= 1) || (m <= 1)) return 0;

  TH tab;
  TH_inicializa(tab, m);

  int i, mat;
  float cr;
  for(i = 0; i < n; i++){
    printf("Digite a matricula e o cr...\n");
    scanf("%d", &mat);
    scanf("%f", &cr);
    TH_insere(tab, m, mat, cr);
  }
  TH_imprime(tab, m);

  char resp;
  do{
    printf("Digite a matricula a ser removida... ");
    scanf("%d", &mat);
    cr = TH_retira(tab, m, mat);
    if(cr != -1) printf("%d\t%f saiu\n", mat, cr);
    printf("Quer continuar? ");
    scanf(" %c", &resp);
  }while((resp != 'N') && (resp != 'n'));
  TH_imprime(tab, m);

  do{
    printf("Digite a matricula a ser procurada... ");
    scanf("%d", &mat);
    TA *p = TH_busca(tab, m, mat);
    if(!p) printf("Elemento nao encontrado!\n");
    else printf("%d\t%f\n", p->mat, p->cr);
    printf("Quer continuar? ");
    scanf(" %c", &resp);
  }while((resp != 'N') && (resp != 'n'));
  TH_imprime(tab, m);

  for(i = 0; i < n/2; i++){
    printf("Digite a matricula e o cr...\n");
    scanf("%d", &mat);
    scanf("%f", &cr);
    TH_insere(tab, m, mat, cr);
  }
  TH_imprime(tab, m);

  TH_libera(tab, m);

  return 0;
}
