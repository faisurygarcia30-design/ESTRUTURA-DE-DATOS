#include <stdio.h>

// entradas de datos (llenar array)
void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ---------------- Bubble Sort ----------------
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Intercambio
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ---------------- Selection Sort ----------------
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Intercambio
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// ---------------- Insertion Sort ----------------
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        // Mueve los elementos que son mayores que key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// ---------------- Programa Principal ----------------
int main() {
    int numeros[10] = {34, 12, 25, 9, 67, 45, 3, 89, 21, 50};
    int n = 10;

    printf("Arreglo original:\n");
    imprimirArreglo(numeros, n);

    // Bubble Sort
    int bubbleArr[10];
    for (int i = 0; i < n; i++) bubbleArr[i] = numeros[i];
    bubbleSort(bubbleArr, n);
    printf("\nOrdenado con Bubble Sort:\n");
    imprimirArreglo(bubbleArr, n);

    // Selection Sort
    int selectionArr[10];
    for (int i = 0; i < n; i++) selectionArr[i] = numeros[i];
    selectionSort(selectionArr, n);
    printf("\nOrdenado con Selection Sort:\n");
    imprimirArreglo(selectionArr, n);

    // Insertion Sort
    int insertionArr[10];
    for (int i = 0; i < n; i++) insertionArr[i] = numeros[i];
    insertionSort(insertionArr, n);
    printf("\nOrdenado con Insertion Sort:\n");
    imprimirArreglo(insertionArr, n);

    return 0;
}
