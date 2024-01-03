#include <stdio.h>
#include <stdlib.h>

void getInput(int **arr){
    printf("Ingresa 5 numeros");
    *arr = malloc(sizeof(int));
    for (int i = 0; i < 5; i++){
        printf("\n");
        scanf("%d", &((*arr)[i]));
        
    }
}

int main(){
    int *arr;
    getInput(&arr);
    printf("\n");
    for (int i = 0; i < 5;i++){
        printf("%d | ", arr[i]);
    }
}


