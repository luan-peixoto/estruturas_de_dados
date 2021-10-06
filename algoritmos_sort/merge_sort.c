#include <stdio.h>

void merge(int inicio, int meio, int fim, int vetor[]) {
  int aux[fim];
  int i = inicio;
  int j = meio + 1; 
  int k = 0;
  while (i <= meio && j <= fim) {
    if (vetor[i] <= vetor[j]) {
      aux[k] = vetor[i];
      i = i + 1;
    }
    else {
      aux[k] = vetor[j];
      i = i + 1;
    }
    k = k + 1;
  }
  while (i <= meio) {
    aux[k] = vetor[i];
    i = i + 1;
    k = k + 1;
  }
  while (j <= fim) {
    aux[k] = vetor[j];
    j = j + 1;
    k = k + 1;
  }
  for (k = 0; k < fim+1; k++) {
    *&vetor[k] = aux[k-inicio];
  }
}

void merge_sort(int inicio, int fim, int vetor[]) {
  if (inicio < fim) {
    int meio = inicio + (fim - inicio) / 2;
    merge_sort(inicio, meio, vetor);
    merge_sort(meio+1, fim, vetor);
    merge(inicio, meio, fim, vetor);

  }
}

int main(void) {
  int vetor[7] = {1,6,4,5,7,3,2};
  merge_sort(0, 6, vetor);
  for (int i = 0; i < 7; i++) {
    printf("%i ", vetor[i]);
  }
  return 0;
}