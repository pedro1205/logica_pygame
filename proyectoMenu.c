#include <stdio.h>


void selection_sort(int arr[], int n) {
    int i, j, menor, k;
    for (i = 0; i < n - 1; i++) {
        menor = arr[i];
        k = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < menor) {
                menor = arr[j];
                k = j;
            }
        }
        arr[k] = arr[i];
        arr[i] = menor;
    }
}

void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j+ 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void imprimir_vector(int arr[], int n) {
    printf("Vector ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main(){
    int arr_len, metodo;
    printf("Ingrese el tamano del vector: ");
    scanf("%d", &arr_len);

    int vector[arr_len];
    printf("Ingrese los numeros del vector:\n");
    for (int i = 0; i < arr_len; i++) {
        scanf("%d", &vector[i]);
    }

    do {
        printf("\nEscoge un metodo de ordenamiento:\n");
        printf("1. Burbuja\n2. Insercion\n3. Seleccion\n4. Salir\n\n");
        scanf("%d", &metodo);
        printf("\n");
        switch(metodo){
            case 1:
                bubble_sort(vector, arr_len);
                imprimir_vector(vector, arr_len);
                break;
            case 2:
                insertion_sort(vector, arr_len);
                imprimir_vector(vector, arr_len);
                break;
            case 3:
                selection_sort(vector, arr_len);
                imprimir_vector(vector, arr_len);
                break;
            case 4:
                printf("FIN\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    }while(metodo != 4);

    return;
}
