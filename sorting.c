#include <stdio.h>
#include <stdlib.h>
#define arr_len 10
int main(){
    int random_numbers[arr_len];
    for (int i = 0; i < arr_len; i++){
        random_numbers[i] = rand() % 100;
        printf("%d, ", random_numbers[i]);
    }
    printf("\n");
    sort(random_numbers);
    for (int i = 0; i < arr_len; i++){
        printf("%d, ", random_numbers[i]);
    }
    return 0;
}

int sort(int set1[]){
    for (int i = 0; i < arr_len; i++){
        while (set1[i] < set1[i-1] && i > 0){
                int buffer = set1[i-1];
                set1[i-1] = set1[i]; 
                set1[i] = buffer;
                i--;
            }
        }
    
    }
