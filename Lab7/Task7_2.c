#include <stdio.h>

int sum(int n, ...)
{
    int *ptr = &n;
    int s = 0;
    printf("%d", &n);
    ptr++;
    printf("%i \n", *ptr);
    /*for( ;n>0; n--, ptr++)
    {

        printf("*ptr: %d \n s: %d \n" , *ptr, s);
        s+= *(ptr);
        printf("*ptr: %d \n s: %d \n", *ptr, s);
    }*/
    return s;
}

int main(void)
{
    printf("%d \n", sum(4, 1, 2, 3, 4));
    printf("%d \n", sum(5, 12, 21, 13, 4, 5));
    return 0;
}
