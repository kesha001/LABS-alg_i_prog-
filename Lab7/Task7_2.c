#include <stdio.h>

int sum(int n, ...)
{

    int s = 0;

    for(int *ptr = &n;n>0; n--)
    {
        ptr++;
        s+= *(ptr);
    }
    return s;
}

int main(void)
{
    printf("%d \n", sum(4, 1, 2, 3, 4));
    printf("%d \n", sum(5, 12, 21, 13, 4, 5));
    return 0;
}
