#include <stdio.h>
#include <math.h>
int main(void){
    int low, high, mid, tmp, n = 100000, x = 255550, j = 0;
    int list[n];
    for (int i = 0, j = 0; i < n; i++, j += 10)
    {
        list[i] = j;
    }
    low = 0;
    high = n - 1;
    mid = round((low + high) / 2) + 1;
    while (x != list[mid] && mid != low && mid != high)
    {
        if (x < list[mid])
        {
            high = mid;
        }
        else 
        {
            low = mid;
        }
        printf("MID: %i\n", mid);
        mid = (low + high) / 2;
    }
    if (mid == n - 2 && list[mid] == x);
    else if (mid == n - 2 && list[mid + 1] == x)
    {
        mid = mid + 1;
    }
    if (list[mid] == x){
        printf("ITEM'S POSITION AT: %i\n", mid);
        printf("ITEM: %i\n", list[mid]);
        return 0;
    }
    else{
        printf("WARNING: NO OBJECT FOUND, NEAREST POSITION IN LIST: %i\n", mid);
        return 1;
    }
}