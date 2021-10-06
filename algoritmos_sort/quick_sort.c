#include <stdio.h>

void troca(int* vetorz, int esquerda, int direita) {
  int x = *(vetorz+esquerda);
  *(vetorz+esquerda) = *(vetorz+direita);
  *(vetorz+direita) = x;
}

int particao(int vetor[], int inicio, int fim) {
  int pivo = vetor[inicio];
  int esquerda = inicio;
  int direita = fim;
  while (esquerda < direita) {
    while(vetor[esquerda] <= pivo) {
      esquerda = esquerda + 1;
      if (esquerda > fim) {
        break;
      }
    }
    while(vetor[direita] > pivo) {
      direita = direita - 1;
    }
    if (esquerda < direita) {
      troca(&vetor[0],esquerda, direita);
    }
  }
  troca(&vetor[0], inicio, direita);
  return direita;
}

void quick_sort(int vetor[],int inicio, int fim) {
  if (fim > inicio) {
    int posPivo = particao(vetor, inicio, fim);
    quick_sort(vetor, inicio, posPivo - 1);
    quick_sort(vetor, posPivo + 1, fim);
  }
}

int main(void) {
  int nums[4] = {1,2,3,1};
  quick_sort(nums, 0, 3);
  printf("%i", nums[3]);
}