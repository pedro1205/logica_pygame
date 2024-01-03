#include <stdio.h>
#define n 10
void shellsort(int v[]);
int main(void){
    int v[n] = {2, 3, 8, 4, 1, 5, 9, 0, 6, 7};
    for (int i = 0; i < n; i++){
        printf("%i ", v[i]);
    }
    printf("\n\n");
    shellsort(v);
    return 0;

}

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[]){
    int gap, i, j, temp, counter;
    for (gap = n / 2; gap > 0; gap /= 2){
        for (i = gap; i < n; i++){
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap){
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
                for (counter = 0; counter < n;){
                    printf("%i ", v[counter++]);
                }
                printf("\n");
            }
        }
    }
    printf("\n");
    for (int k = 0; k < n; k++){
        printf("%i ", v[k]);
    }
    return;
}