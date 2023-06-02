#include <stdlib.h>
#include <stdio.h>
void swap(long long int *xp,long long int *yp) {
    long long int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(long long int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(&arr[min_idx], &arr[i]);
    }
}
void bubbleSort(long long int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void insertionSort(long long int array[], int tam) {
    for (int i = 1; i < tam; i++) {
        long long int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}
void merge(long long int array[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    // Cria arrays temporários
    long long int *Array_esquerda = (long long int *)malloc(n1 * sizeof(long long int));
    long long int *Array_direita = (long long int *)malloc(n2 * sizeof(long long int));

    // Copia os dados para os arrays temporários
    for (i = 0; i < n1; i++)
        Array_esquerda[i] = array[esquerda + i];
    for (j = 0; j < n2; j++)
        Array_direita[j] = array[meio + 1 + j];

    // Faz o merge dos arrays temporários de volta para o array original
    i = 0; // Índice inicial do primeiro subarray
    j = 0; // Índice inicial do segundo subarray
    k = esquerda; // Índice inicial do array mesclado

    while (i < n1 && j < n2) {
        if (Array_esquerda[i] <= Array_direita[j]) {
            array[k] = Array_esquerda[i];
            i++;
        } else {
            array[k] = Array_direita[j];
            j++;
        }
        k++;
    }

    // Copia os elementos  do subarray esquerdo
    while (i < n1) {
        array[k] = Array_esquerda[i];
        i++;
        k++;
    }

    // Copia os elementos  do subarray direito
    while (j < n2) {
        array[k] = Array_direita[j];
        j++;
        k++;
    }

    free(Array_esquerda);
    free(Array_direita);
}

void mergeSort(long long int array[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        // Ordena a metade esquerda
        mergeSort(array, inicio, meio);

        // Ordena a metade direita
        mergeSort(array, meio + 1, fim);

        // Faz o merge das duas metades ordenadas
        merge(array, inicio, meio, fim);
    }
}
int partition(long long int array[], int low, int high) {
    long long int pivo = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivo) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(long long int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}