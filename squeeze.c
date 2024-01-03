#include <stdio.h>
int main(void){
    char string1[100], string2[100];
    printf("TEXT 1: ");
    scanf("%s", string1);
    printf("TEXT 2: ");
    scanf("%s", string2);
    int i, j;
    for (i = j = 0; string1[i] != '\0'; i++)
    {
        if (string1[i] != string2[i])
        {
            string1[j++] = string1[i];
        }
    }
    string1[j] = '\0';
    printf("%s\n", string1);
    return 0;
}
