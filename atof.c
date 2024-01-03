#include <ctype.h>
#include <stdio.h>
#define MAX 100
double atof(char s[]);
int main(void){
    char s[MAX] = "CHOCOBO";
    double convertion = atof(s);
    printf("%f\n", convertion);
    return 0;
}
double atof(char s[]){
    double val, power; // Valor y potencia
    int i, sign; // Signo?
    for (i = 0; isspace(s[i]); i++); // Saltar espacios
    sign = (s[i] == '-') ? -1 : 1; // Servira como multiplicador
    if (s[i] == '+' || s[i] == '-'){ // Moverme al siguiente caracter
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++){ // 
        val = (10.0 * val) + (s[i] - '0');
    }
    if (s[i] == '.'){
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power;
}
