#include <stdio.h>

int main(void){
    char string1[100], string2[100];
    printf("TEXT 1: ");
    scanf("%s", string1);
    printf("TEXT 2: ");
    scanf("%s", string2);
    int position = -1, i = 0;
    while (position == - 1)
    {
        if (string1[++i] == string2[i])
        {
            position = i;
        }
    }
    printf("FIRST CHAR COINCIDENCE: %i\n", position);
    return 0;
}