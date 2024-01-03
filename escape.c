#include <stdio.h>

int main(void){
    char string1[100], string2[100];
    int i = 0, c = 0, j = 0;
    while ((c = getchar()) != EOF)
    {
        string1[i] = c;
        switch (c) {
            case '\n': 
            {
                string2[j++] = '\\';
                string2[j++] = 'n';
                string2[j] = '\0';
                break;
            }
            case '\t':
            {
                string2[++j] = '\\';
                string2[++j] = 't';
                string2[j] = '\0';
                break;
            }
            case ' ':
            {
                string2[j++] = 'b';
                string2[j] = '\0';
                break;
            }
            default:
            {
                string2[j++] = c;
            }
        }
        i++;
    }
    string1[i] = '\0';
    printf("%s\n", string1);
    printf("%s\n", string2);
    return 0;
}