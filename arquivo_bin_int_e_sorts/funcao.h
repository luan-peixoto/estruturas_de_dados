void cria_arq_binario_vetor(char *nome_arq, int* vetor, int tam);

void ler_arq_binario(char *nome_arq, int* v);

void cria_arq_ord_cresc_bin(char *nome_arq);

void arquivo_juntar_bin(char *nome_arq_1, char *nome_arq_2, char *nome_arq_dest);

void arquivo_insere_ord_bin(char* nome_arq, int i);


// bb

int prox_mult(int elem, int pot);

int busca_binaria_arquivo_binario_aberto(FILE *fp, int elem, int tipo);

int busca_binaria_arquivo_binario(char* nome_arq, int i, int tipo);

int retorna_elemento_arquivo_binario(char* nome_arq, int pos);

//sel sort

void selection_sort_arquivo_bin_aberto(FILE *fp);

void selection_sort_arquivo_bin(char* nome_arq);

// quicksort

void qs_aux(char *nome, int tipo, int ini, int fim);

void quick_sort_arquivo_bin(char* nome_arq, int tipo);

//bubble sort

void bubble_sort_arquivo_bin_aberto(FILE* fp, int tipo);

void bubble_sort_arquivo_bin(char* nome_arq, int tipo);

//insert sort

void insertion_sort_arquivo_bin(char* nome_arq, int tipo);