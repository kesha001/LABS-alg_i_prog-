#include <stdio.h>
//бібліотека з va_list, va_arg, va_...
#include <stdarg.h>

int sum(int n, ...)
{
    int s = 0;
    va_list ptr;
    va_start(ptr, n);
    for(int i=0;i<n; i++)
    {
        s += va_arg(ptr, int);
    }
    va_end(ptr);
    return s;
}

int main(void)
{
    printf("%d \n", sum(3, 1,3, 4));
    printf("%d \n", sum(7, 1,1, 2, 2, 3, 3, 4));
    printf("%d \n", sum(11, 10,10,10,10,10,10,10,10,10,10,10));
    return 0;
}