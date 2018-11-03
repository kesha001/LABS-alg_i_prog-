#include <stdio.h>
#include <string.h>
#define symb 255
int main()
{
    int k = 0;
    char vyraz[symb];
    char zaryv[symb];
    fgets(vyraz,symb,stdin);

    for (int i = 0; i<symb; i++)
    {
        if (vyraz[i] == '\0')
        {
            break;
        }
        else
        k++;
    }
    k--;
    for (int i = 0; i<k; i++)
    {
        if (vyraz[i] == '\0')
        {
            break;
        }
        else
        printf("%c ", vyraz[i]);
    }
    printf("\n");
    for (int i = k-1, j = 0; i>=0; i--, j++)
    {
        if (vyraz[j] == '\0')
        {
            break;
        }
        else
        zaryv[i] = vyraz[j];
    }
    for (int i = 0; i<k; i++)
    {
        if (zaryv[i] == '\0')
        {
            break;
        }
        else
        printf("%c ", zaryv[i]);
    }
    printf("\n");
    int k2 = 0;
    for (int i = 0; i<k; i++)
    {
        if (vyraz[i] == zaryv[i])
        {
            k2++;
        }
    }
    if (k == k2)
    {
        printf("Your vyraz is palindrome\n");
    }
    else
    {
        printf("Ne palindrome\n");
    }
}