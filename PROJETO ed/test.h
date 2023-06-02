#include  "Al_ordenacao.h"
#include <time.h>
void escrever_array_ordenado(long long int * array,int tam){
    FILE *arquivo; 
    arquivo = fopen("array_ordenado.txt", "w");

    // Verificar se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }
    for(int i = 0;i<tam;i++){
        fprintf(arquivo,"[%lld]", array[i]);
    }
    printf("\nnumeros ordenados salvo em array_ordenado.txt");
    fclose(arquivo);
}

int abrir_arquivo(long long int ** array,char nome_arquivo[]){ // le o arquivo ate o final e aloca a memoria necessaria no array para colcoar os numeros, tambem ira retornar o tamanho do array
    FILE *arquivo;    // Nome do arquivo a ser lido
    long long int numero;
    int cont=0;

    // Abrir o arquivo no modo de leitura
    arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }

    while (fscanf(arquivo, "%lld", &numero) != EOF) {
        cont++;
    }
    (*array) = (long long int*) malloc(sizeof(long long int)*cont);
    if((*array)== NULL){
        printf("Erro ao alocar memoria\n");
    }
    fclose(arquivo);
    return cont;

}
void  pegar_valores(long long int ** array,char nome_arquivo[]){ // da os valores do arquivo ao array
    FILE *arquivo;   // Nome do arquivo a ser lido
    long long int numero;
    int cont = 0;
    long long int * prt = (*array);

    // Abrir o arquivo no modo de leitura
    arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }

    while (fscanf(arquivo, "%lld", &numero) != EOF) {
        prt[cont] = numero;
        cont++;
    }
    fclose(arquivo);

}
void test_algoritmos(long long int * array,int tam,int metodo){
    clock_t start;
    clock_t end;
    double tempo_total;
     switch ( metodo )
  {
    case 1 :
        printf ("Algoritmo SelectionSort selecionado. \nAguarde");
        start = clock();
        selectionSort(array,tam);
        end = clock();
        tempo_total = (double)(end - start) / CLOCKS_PER_SEC;
        escrever_array_ordenado(array,tam);
        printf("\nO algoritmo SelectionSort levou cerca de %lf segundos para ordenar %d numeros\n", tempo_total,tam);
    break;
    
    case 2 :
        printf ("Algoritmo BubbleSort selecionado. \nAguarde");
        start = clock();
        bubbleSort(array,tam);
        end = clock();
        tempo_total = (double)(end - start) / CLOCKS_PER_SEC;
        escrever_array_ordenado(array,tam);
        printf("\nO algoritmo BubbleSort levou cerca de %lf segundos para ordenar %d numeros\n", tempo_total,tam);
    break;
    
    case 3 :
        printf ("Algoritmo InsertionSort selecionado. \nAguarde ");
        start = clock();
        insertionSort(array,tam);
        end = clock();
        tempo_total = (double)(end - start) / CLOCKS_PER_SEC;
        escrever_array_ordenado(array,tam);
        printf("\nO algoritmo InsertionSort levou cerca de %lf segundos para ordenar %d numeros\n", tempo_total,tam);
    break;
    
    case 4 :
        printf ("Algoritmo MergeSort selecionado. \nAguarde ");
        start = clock();
        mergeSort(array,0,tam);
        end = clock();
        tempo_total = (double)(end - start) / CLOCKS_PER_SEC;
        escrever_array_ordenado(array,tam);
        printf("\nO algoritmo MergeSort levou cerca de %lf segundos para ordenar %d numeros\n", tempo_total,tam);
    break;
    
    case 5 :
        printf ("algoritmo QuickSort selecionado. \nAguarde ");
        start = clock();
        quickSort(array,0,tam);
        end = clock();
        tempo_total = (double)(end - start) / CLOCKS_PER_SEC;
        escrever_array_ordenado(array,tam);
        printf("\nO algoritmo QuickSort levou cerca de %lf segundos para ordenar %d numeros\n", tempo_total,tam);
    break;
    
    default :
        printf ("Valor invalido!\n");
        printf ("(1 = SelectionSort) (2 = BubbleSort) (3 = InsertionSort) (4 = MergeSort) (5 = QuickSort)\n");
  }
}
