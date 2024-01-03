#include <stdio.h>
#include <string.h>
int main(void){
    char s[10];
    int x;
    int i = 10, k = 1;
    int n = 0, n2 = 0;
    int tmp, width;
    printf("ENTER A NUMBER: ");
    scanf("%i", &x);
    printf("ENTER A WIDTH: ");
    scanf("%i", &width);
    for (int j = 0; (x -= n) > 0; i *= 10, k *= 10){
        n = x % i;
        n2 = n / k;
        s[j] = n2 + 48;
        printf("%c ", s[j++]); 
    }
    printf("\n");
    for (int y = 0, len = strlen(s) - 1; y < strlen(s) / 2; y++, len--){
        tmp = s[y];
        s[y] = s[len];
        s[len] = tmp;
    }
    int m = 0;
    do {
        for (int b = 0; b <= width; b++){
            printf(" ");
        }
        printf("%c", s[m++]);
    } while(s[m] != 0);
    printf("\n");
    return 0;
}
