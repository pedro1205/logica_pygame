#include <stdio.h>

int main(){
    int *p;
    int num;
    p = &num;
    *p = 11;
    printf("Num: %p", p);
    printf("Num: %d", *p);



}

