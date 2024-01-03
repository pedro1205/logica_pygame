#include <stdio.h>
#include <math.h>
#define N 20

double f1(double init_v, int i){
    if (i == 0){
        return init_v;
    }
    init_v = cos(init_v / 2.0);
    i--;
    f1(init_v, i); 
}

int main(){
    int flag, i = N;
    double init_value;
    do{
        printf("Ingresa un valor inicial entero: ");
        flag = scanf("%lf", &init_value);
    } while (!flag && getchar() != ' ');
    printf("%.2f", f1(init_value, i));
}