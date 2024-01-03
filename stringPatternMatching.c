#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char r_text[30] = "abcdefghijklmnopqrstuvwxyz";
    char pattern[4] = "wxyz";
    int text_len = strlen(r_text);
    printf(text_len);
    int p_len = 4;
    for (int i = 0; i < text_len - p_len; i++){
        int j = 0;
        while (j < p_len && r_text[i + j] == pattern[j])
            j++;
        if (j == p_len){
            printf("Pattern found");
            return 0;
        }

    }
}