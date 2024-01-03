#include <stdio.h>
#include <ctype.h>
#define MAX 100
double atoi(char s[]);
double atof(char s[]);
int main(void){
    char s[MAX];
    int i, exponent = 0, after_digits, sign;
    printf("ENTER A NUMBER IN SCIENTIFIC NOTATION: ");
    scanf("%s", s);
    double s_notation = atoi(s);
    printf("%f\n", s_notation);
    return 0;
}

double atoi(char s[]){
    return atof(s);
}

double atof(char s[]){
    double number = 0, result;
    int sign, i = 0, power, prev_digits = 0, power2 = 0, power3, j = 0;
    power3 = power = sign = 1;
    for (; isspace(s[i]); i++);
    if (s[i] == '-'){
        sign = -1;
    }
    while (isdigit(s[i])){
        number = 10.00 * number + (s[i++] - 48);
        prev_digits++;
    }
    i = (s[i] == '.') ? i++ : i;
    while (isdigit(s[i])){
        number = 10.00 * number + (s[i++] - 48);
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E'){
        i++;
        while (isdigit(s[i])){
            power2 = 10.00 * power2 + (s[i++] - '0');
        }
        while (j++ <= power2){
            power3 *= 10;
        }
        result = (sign * number / power) / (power3 + prev_digits);
    } 
    else {
        result = sign * number / power;
    }
    return result;
}