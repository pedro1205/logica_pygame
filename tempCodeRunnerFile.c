#include <stdio.h>

int main(){
    int *arr;
    getInput(&arr);
}

void getInput(int **arr){
    printf("Ingresa 5 numeros");
    for (int i = 0; i < 5; i++){
        scanf("%d", &((*arr)[i]));
    }
}

