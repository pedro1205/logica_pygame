#include <stdio.h>

int main() {
    int n, lapiz, rand_pen, counter = 0;
    scanf("%d %d", &n, &lapiz);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &rand_pen);
        if (rand_pen == lapiz){
            counter++;
        }
    }
    printf("%d\n", counter);
}
