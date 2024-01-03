#include <stdio.h>
// JUST A LOTTERY GAME 
int main(void){
    // We are back again 
    int x;
    printf("ENTER A NUMBER BETWEEN 1 AND 5: ");
    scanf("%i", &x);
    if (x >= 0 && x <= 10){
        switch (x) {
        case 5:
        printf("THIS NUMBER IS TOO HIGH!\n");
        break;
        case 4:
        printf("THIS IS A LITTLE HIGH\n");
        break;
        case 3:
        printf("YEP THIS IS THE CORRECT NUMBER!!!!\n");
        break;
        case 2:
        printf("THIS IS A BIT LOW\n");
        break;
        case 1:
        printf("THIS IS TOO LOW\n");
        break;
        default:
        printf("DEFINITELY THIS IS NOT THE CORRECT!\n");
        }
        return 0;
    }
    else{
        return 1;
    }
}