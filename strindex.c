#include <stdio.h>
#include <string.h>
#define MAX 1000
int strindex(char s[], char t[]);
int main(void){
    char s[MAX] = "To Love! could you and I with Fate conspire";
    char t[MAX] = "To grasp this sorry Scheme of Thin conspire";
    int coincidence;
    if ((coincidence = strindex(s, t)) > 0){
        printf("\033[1;32m");
        printf("Index coincidence's position: %i\nSuccess!\n", coincidence);
        printf("\033[0m");
        while (t[coincidence] != ' ' && t[coincidence] != '\0'){
            printf("%c", t[coincidence++]);
            }
        printf("\n");
        return 0;
    }
    printf("\033[1;31m");
    printf("NO COINCIDENCE!\n");
    printf("\033[0m");
    return 1;
}

int strindex(char s[], char t[]){
    for (int i = strlen(t) - 1; i >= 0; i--){
        while (t[i] != ' '){
            if (t[i] == s[i]){
                return i;
            }
            i--;
        }
    }
    return -1;
}