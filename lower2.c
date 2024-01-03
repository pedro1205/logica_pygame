#include <stdio.h>
#include <string.h>
int main(void){
    char string1[100];
    printf("ENTER UPPER TEXT TO CONVERT TO LOWER: ");
    scanf("%s", string1);
    for (int i = 0, j = strlen(string1); i < j; i++)
    {
        string1[i] = (string1[i] > 59 && string1[i] < 91) ? string1[i] + 32 : string1[i]; 
    }
    printf("%s\n", string1);
    return 0;
}