#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){
    char s1[10];
    int x, left, right;
    printf("Enter the shorthand: ");
    scanf("%s", s1);
    x = strlen(s1);
    if (x >= 3 && x <= 5){
        if (x == 3 && (isdigit(s1[0]) || islower(s1[0]) || isupper(s1[0])) && 
        s1[1] == 45 && (isdigit(s1[2]) || islower(s1[2]) || isupper(s1[2])) && s1[0] < s1[2]){
            int m, n;
            if (isdigit(s1[0]) && isdigit(s1[2])){
                m = s1[0] + 49;
                n = s1[2] + 49;
            }
            else {
                m = s1[0];
                n = s1[2];
            }
            for (;m <= n;){
                printf("%c ", m++);
            }
            printf("\n");
            return 0;
        }
        else if (x == 4 && (isdigit(s1[0]) || islower(s1[0]) || isupper(s1[0])) && s1[1] == 45 && 
        ((s1[2] >= 49 && s1[2] <= 50) && (s1[3] >= 48 && s1[3] <= 53))){
            int j = (((s1[2] - 48) * 10) + s1[3] - 48) + 65;
            for (int i = s1[0] + 17; i <= j;){
                printf("%c ", i++);
            }
            printf("\n");
            return 0;
        }
        else if (x == 5 && (s1[0] >= 49 && s1[0] <= 50) && (s1[1] >= 48 && s1[1] <= 52) && s1[2] == 45 
        && (s1[3] >= 49 && s1[3] <= 50) && (s1[4] >= 48 && s1[4] <= 53)){
            left = ((s1[0] - 48) * 10) + (s1[1] - 48);
            right = ((s1[3] - 48) * 10) + (s1[4] - 48); 
            if (left < right){
                for (int i = left + 65, j = right + 65; i <= j;){
                    printf("%c ", i++);
                }
                printf("\n");
                return 0;
            }
        }
        else {
            printf("Error!\n");
            return 1;
        }
    }
    else {
        printf("STRING LENGTH: %i-%i\n", 3,5);
        return 1;
    }
}