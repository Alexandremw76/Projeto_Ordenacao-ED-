#include "test.h"
int main() {

    long long int * array;
    int tam; // numero de numeros no arquivo 
    char nome_arquivo [] = "num.100000.4.in"; // arquivo a ser aberto
    tam = abrir_arquivo(&array,nome_arquivo); // le o arquivo ate o final e retorna o tamanho dele para tam
    pegar_valores(&array,nome_arquivo);// escreve os valores do arquivo no array
    test_algoritmos(array,tam,1);// testa os algoritimos (1 = SelectionSort) (2 = BubbleSort) (3 = InsertionSort) (4 = MergeSort) (5 = QuickSort)
    free(array);
}