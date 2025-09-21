#include <stdio.h>


typedef struct {
    int codigo;   
    float nota;   
} Estudiante;

int cantidad = 6;

Estudiante estudiantes[6] = {
    {2024101, 4.5},
    {2024102, 3.2},
    {2024103, 2.9},
    {2024104, 5.0},
    {2024105, 3.8},
    {2024106, 4.0}
};

float notaMaxima(Estudiante arr[], int n, int i, float max) {
    if (i == n) return max;
    if (arr[i].nota > max) max = arr[i].nota;
    return notaMaxima(arr, n, i + 1, max);
}

float promedio(Estudiante arr[], int n, int i, float suma) {
    if (i == n) return suma / n;
    return promedio(arr, n, i + 1, suma + arr[i].nota);
}

void swap (Estudiante *a, Estudiante *b) {
    Estudiante temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(Estudiante arr[], int n, int i) {
    if (i == n - 1) return;

    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
        if (arr[j].codigo < arr[minIndex].codigo) {
            minIndex = j;
        }
    }

    if (minIndex != i) swap(&arr[i], &arr[minIndex]);

    selectionSort(arr, n, i + 1);
}

void mostrarEstudiantes(Estudiante arr[], int n) {
    printf("\nLista de estudiantes:\n");
    for (int i = 0; i < n; i++) {
        printf("Codigo: %d - Nota: %.2f\n", arr[i].codigo, arr[i].nota);
    }
}

int main() {
    int opcion;
    int n = 6;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Buscar la Nota Maxima del Curso\n");
        printf("2. Calcular el Promedio del Curso\n");
        printf("3. Ordenar Codigos de Estudiantes (Selection Sort Recursivo)\n");
        printf("4. Mostrar lista de estudiantes\n");
        printf("5. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("\nLa nota maxima es: %.2f\n", notaMaxima(estudiantes, n, 0, estudiantes[0].nota));
                break;
            case 2:
                printf("\nEl promedio del curso es: %.2f\n", promedio(estudiantes, n, 0, 0));
                break;
            case 3:
                selectionSort(estudiantes, n, 0);
                printf("\nLista ordenada por codigo:\n");
                mostrarEstudiantes(estudiantes, n);
                break;
            case 4:
                mostrarEstudiantes(estudiantes, n);
                break;
            case 5:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("\n Opcion invalida. Intenta de nuevo.\n");
        }
    } while(opcion != 5);

    return 0;
}



