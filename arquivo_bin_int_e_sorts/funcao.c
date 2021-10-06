#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funcao.h"

void cria_arq_binario_vetor(char *nome_arq, int* v, int tam) {
  FILE *fp = fopen(nome_arq, "wb");
  if (fp != NULL) {
    fwrite(v, sizeof(int), tam, fp);
    fclose(fp);
  } 
  else {
    exit(1);
  }
}

void ler_arq_binario(char *nome_arq, int* v) {
  FILE *fp = fopen(nome_arq, "rb");
  if (fp != NULL) {
    int i = 0;
    while (fread(&v[i], sizeof(int), 1, fp) >= 1) {
      i ++;
    }
    fclose(fp);
  } 
  else {
    exit(1);
  }
}

void cria_arq_ord_cresc_bin(char *nome_arq) {
  FILE *fp = fopen(nome_arq, "wb");
  if(fp == NULL) {
    exit(1);
  }
  int ant, atual;
  printf("Digite um numero... ");
  scanf("%d", &ant);
  fwrite(&ant, sizeof(int), 1, fp);
  printf("Digite um numero maior que o anterior... ");
  scanf("%d", &atual);
  while(atual > ant){
    fwrite(&atual, sizeof(int), 1, fp);
    ant = atual;
    printf("Digite um numero maior que o anterior... ");
    scanf("%d", &atual);
  }
  printf("Finalizei o arquivo %s\n", nome_arq);
  fclose(fp);
}

void arquivo_juntar_bin(char* nome_arq_1, char* nome_arq_2, char *nome_arq_dest) {
  FILE *fp1 = fopen(nome_arq_1, "rb");
  FILE *fp2 = fopen(nome_arq_2, "rb");
  FILE *fpo = fopen(nome_arq_dest, "wb");
  if((fp1 == NULL)||(fp2 == NULL)||(fpo == NULL)) {
    exit(1);
  }
  int r1, n1, r2, n2;
  r1 = fread(&n1, sizeof(int), 1, fp1);
  r2 = fread(&n2, sizeof(int), 1, fp2);
  while((r1 >= 1) || (r2 >= 1)) {
    if((r2 < 1) || (n1 < n2)) {
      fwrite(&n1, sizeof(int), 1, fpo);
      r1 = fread(&n1, sizeof(int), 1, fp1);
      if(r1 < 1) n1 = INT_MAX;
    }
    else if((r1 < 1) || (n2 < n1)) {
      fwrite(&n2, sizeof(int), 1, fpo);
      r2 = fread(&n2, sizeof(int), 1, fp2);
      if(r2 < 1) n2 = INT_MAX;
    }
    //se quiser retirar repetições entre arquivos...
    else if(n1 == n2) {
      fwrite(&n1, sizeof(int), 1, fpo);
      r1 = fread(&n1, sizeof(int), 1, fp1);
      if(r1 < 1) n1 = INT_MAX;
      r2 = fread(&n2, sizeof(int), 1, fp2);
      if(r2 < 1) n2 = INT_MAX;
    }
  }
  fclose(fp1); 
  fclose(fp2);
  fclose(fpo);
}

void arquivo_insere_ord_bin(char* nome_arq, int i) {
  FILE* fp = fopen(nome_arq, "r+b");
  int n, aux;
  while (fread(&n, sizeof(int), 1, fp) == 1) {
    if (n == i) {
      fclose(fp);
      break;
    }
    else if (n > i) {
      aux = n;
      fseek(fp, -sizeof(int), SEEK_CUR);
      fwrite(&i, sizeof(int), 1, fp);
      i = aux;
    }
  }
  fwrite(&i, sizeof(int), 1, fp);
}


// bb

int prox_mult(int elem, int tipo) {
  int resp = 0;
  while(resp <= elem) {
    resp += tipo;
  }
  return resp;
}

int busca_binaria_arquivo_binario_aberto(FILE *fp, int elem, int tipo) {
  int ini, fim, meio, elem_meio;
  ini = ftell(fp);
  fseek(fp, 0L, SEEK_END);
  fim = ftell(fp) - tipo;
  while(ini <= fim){
    meio = (fim + ini) / 2;
    if((meio % tipo) != 0) meio = prox_mult(meio, tipo);
    fseek(fp, meio, SEEK_SET);
    fread(&elem_meio, tipo, 1, fp);
    printf("ini = %d\tfim = %d\tmeio = %d\telem = %d\n", ini, fim, meio, elem_meio);
    if(elem_meio == elem) {
      return meio;
    }
    if(elem_meio < elem) {
      ini = meio + tipo;
    } 
    if(elem_meio > elem) {
      fim = meio - tipo;
    } 
  }
  return -1;
}

int busca_binaria_arquivo_binario(char* nome_arq, int i, int tipo) {
  FILE* fp = fopen(nome_arq, "r");
  int r = busca_binaria_arquivo_binario_aberto(fp, i, tipo);
  fclose(fp);
  return r;
}

int retorna_elemento_arquivo_binario(char* nome_arq, int pos) {
  int i;
  FILE* fp = fopen(nome_arq, "r");
  fseek(fp, pos, SEEK_SET);
  fread(&i, sizeof(int), 1, fp);
  fclose(fp);
  return i;
}

// selection sort 

void selection_sort_arquivo_bin_aberto(FILE *fp) {
  int i, j, r, s, elem_menor, menor, elem, aux;

  i = ftell(fp);
  r = fread(&elem_menor, sizeof(int), 1, fp);
  while(r == 1){
    menor = i;
    aux = elem_menor;
    j = ftell(fp);
    s = fread(&elem, sizeof(int), 1, fp);
    while(s == 1){
      if(elem < elem_menor){
        menor = j;
        elem_menor = elem;
      }
      j = ftell(fp);
      s = fread(&elem, sizeof(int), 1, fp); 
    }
    if(menor != i){
      printf("Trocar %d(%d) por %d(%d)\n", aux, i, elem_menor, menor);
      fseek(fp, menor, SEEK_SET);
      fwrite(&aux, sizeof(int), 1, fp);
      fseek(fp, i, SEEK_SET);
      fwrite(&elem_menor, sizeof(int), 1, fp);
    }
    else
      fseek(fp, (i + sizeof(int)), SEEK_SET);

    i = ftell(fp);
    r = fread(&elem_menor, sizeof(int), 1, fp);
  } 
}

void selection_sort_arquivo_bin(char* nome_arq) {
  FILE* fp = fopen(nome_arq, "r+b");
  selection_sort_arquivo_bin_aberto(fp);
  fclose(fp);
}

// quicksort

void qs_aux(char *nome, int tipo, int ini, int fim) {
  if((fim - ini) <= tipo) return;

  FILE *fp = fopen(nome, "rb+");
  if(!fp) exit(1);

  int a, b, r, x, elem, aux_a, aux_b;
  a = ini;
  fseek(fp, a, SEEK_SET);
  fread(&x, tipo, 1, fp);
  a = ftell(fp);
  b = fim - tipo;

  //printf("x = %d\ta = %d\tb = %d\n", x, a, b);
  int i, aux, aux_pos;
  do{
    fseek(fp, a, SEEK_SET);
    while(a < fim){
      r = fread(&elem, tipo, 1, fp);
      a = ftell(fp);
      if((elem > x) || (r != 1)) break;
    }
    if(elem > x){
      aux_a = elem; //armazeno o valor que esta no endereco a
      a = a - tipo;
      //printf("aux_a = %d ", aux_a);
    }
    else a = fim + tipo;
    //printf("a = %d\n", a);

    int acc = -tipo;
    rewind(fp);
    fseek(fp, fim, SEEK_SET);
    fseek(fp, acc, SEEK_CUR);
    while(1){
      r = fread(&elem, tipo, 1, fp);
      //printf("%d %d %d\n", b, elem, r);
      if((elem <= x) || (r != 1)) break;
      b = b - tipo;
      acc = acc - tipo;
      fseek(fp, fim, SEEK_SET);
      fseek(fp, acc, SEEK_CUR);
    }
    if(elem < x){
      aux_b = elem; //armazeno o valor que esta no endereco a
    }
    else{
      aux_b = x;
      b = ini;
    }
    //printf("aux_b = %d\tb = %d\n", aux_b, b);

    if(a < b){
      printf("Trocar %d(%d) por %d(%d)\n", aux_a, a, aux_b, b);
      fseek(fp, b, SEEK_SET);      //posiciono o arquivo na posicao a
      fwrite(&aux_a, tipo, 1, fp); //escrevo o valor de a na posicao b
      fseek(fp, a, SEEK_SET);      //posiciono o arquivo na posicao a
      fwrite(&aux_b, tipo, 1, fp); //escrevo o valor de b na posicao a
      a = ftell(fp);
      b = fim - tipo;
      //printf("a = %d\tb = %d\n", a, b);
    }

  }while (a <= b);

  printf("Trocar pivo = %d(%d) por %d(%d)\n", x, ini, aux_b, b);
  rewind(fp);
  a = ini;
  fseek(fp, a, SEEK_SET);
  fwrite(&aux_b, tipo, 1, fp);
  rewind(fp);
  fseek(fp, b, SEEK_SET);
  fwrite(&x, tipo, 1, fp);
  fclose(fp);
  //printf("(%d,%d)\t(%d,%d)\n", ini, b, (b + tipo), fim);
  qs_aux(nome, tipo, ini, b);
  qs_aux(nome, tipo, (b + tipo), fim);
}

void quick_sort_arquivo_bin(char* nome_arq, int tipo) {
  FILE *fp = fopen(nome_arq, "rb");
  if(!fp) exit(1);
  int ini, fim;
  ini = ftell(fp);
  fseek(fp, 0L, SEEK_END);
  fim = ftell(fp);
  fclose(fp);
  qs_aux(nome_arq, tipo, ini, fim);
}

void bubble_sort_arquivo_bin_aberto(FILE* fp, int tipo) {
  int f = 1, aux;
  while (f == 1) {
    f = 0;
    while (fread(&aux, tipo, 1, fp) == 1) {
      int cur;
      if (fread(&cur, tipo, 1, fp) == 0) {
        break;
      }
      printf("\nl peguei %i e %i z", aux, cur);
      if (cur < aux) {
        fseek(fp, -2*tipo, SEEK_CUR);
        fwrite(&cur, tipo, 1, fp);
        fwrite(&aux, tipo, 1, fp);
        f = 1;
      }
      fseek(fp, -tipo, SEEK_CUR);
    }
    fseek(fp, 0L, SEEK_SET);
  }
}

void bubble_sort_arquivo_bin(char* nome_arq, int tipo) {
  FILE* fp = fopen(nome_arq, "r+b");
  bubble_sort_arquivo_bin_aberto(fp, tipo);
  fclose(fp);
}

void insertion_sort_arquivo_bin(char* nome_arq, int tipo) {
  FILE* fp = fopen(nome_arq, "r+b");
  int aux;
  int auxPos;
  int inic = 0;
  int atual;
  while(fread(&aux, tipo, 1, fp) == 1) {
    atual = ftell(fp);
    auxPos = ftell(fp);
    fseek(fp, -tipo, SEEK_CUR);
    int cur;
    int curPos;
    while(ftell(fp) > inic) {
      fread(&cur, tipo, 1, fp);
      curPos = ftell(fp);
      printf("\n\naux %i cur %i\n\n", aux,cur);
      if(aux < cur) { // troca posicoes
        fseek(fp, -tipo, SEEK_CUR);
        fwrite(&aux, tipo, 1, fp);
        while (ftell(fp) != auxPos) {
          fseek(fp, tipo, SEEK_CUR);
        }
        fseek(fp, -tipo, SEEK_CUR);
        fwrite(&cur, tipo, 1, fp);
        auxPos = curPos;
        while (ftell(fp) != curPos) {
          fseek(fp, -tipo, SEEK_CUR);
        }
      }
      fseek(fp, -2*tipo, SEEK_CUR); // andar cursor um pra trás
    }
    fread(&cur, tipo, 1, fp); // le o 1 val
    curPos = ftell(fp);
    if(aux < cur) {
      fseek(fp, -tipo, SEEK_CUR);
      fwrite(&aux, tipo, 1, fp);
      while (ftell(fp) != auxPos) {
        fseek(fp, tipo, SEEK_CUR);
      }
      fseek(fp, -tipo, SEEK_CUR);
      fwrite(&cur, tipo, 1, fp);
      auxPos = curPos;
      while (ftell(fp) != curPos) {
        fseek(fp, -tipo, SEEK_CUR);
      }
    }
    fseek(fp, -tipo, SEEK_CUR);
    printf("\n\naux %i cur %i\n\n", aux,cur);
    while (ftell(fp) < atual) {
      fseek(fp, tipo, SEEK_CUR);
    }
  }
  fclose(fp);
}

/* outro jeito

void insertion_sort_arquivo_bin(char* nome_arq, int tipo) {
  FILE* fp = fopen(nome_arq, "r+b");
  int aux;
  int auxPos;
  int inic = 0;
  int atual;
  while(fread(&aux, tipo, 1, fp) == 1) {
    atual = ftell(fp);
    auxPos = ftell(fp);
    fseek(fp, -tipo, SEEK_CUR);
    int cur;
    int curPos;
    while(ftell(fp) >= inic) {
      fread(&cur, tipo, 1, fp);
      curPos = ftell(fp);
      printf("\n\naux %i cur %i\n\n", aux,cur);
      if(aux < cur) { // troca posicoes
        fseek(fp, -tipo, SEEK_CUR);
        fwrite(&aux, tipo, 1, fp);
        while (ftell(fp) != auxPos) {
          fseek(fp, tipo, SEEK_CUR);
        }
        fseek(fp, -tipo, SEEK_CUR);
        fwrite(&cur, tipo, 1, fp);
        auxPos = curPos;
        while (ftell(fp) != curPos) {
          fseek(fp, -tipo, SEEK_CUR);
        }
      }
      if (ftell(fp) == tipo) {
        fseek(fp, -tipo, SEEK_CUR);
        break;
      }
      fseek(fp, -2*tipo, SEEK_CUR); // andar cursor um pra trás
    }
    fseek(fp, -tipo, SEEK_CUR);
    printf("\n\naux %i cur %i\n\n", aux,cur);
    while (ftell(fp) < atual) {
      fseek(fp, tipo, SEEK_CUR);
    }
  }
  fclose(fp);
}

*/