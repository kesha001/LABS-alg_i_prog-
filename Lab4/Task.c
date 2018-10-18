#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define max_size 100

int main(void)
{
    int mass[max_size];
    int n = 10;
    int i;
    int temp;
    srand(time(NULL));

    for (i=0;i<n;i++)
    {
        mass[i]=rand()%10;
        printf("%d ",mass[i]);
    }
    printf("\n");
    i = 0;
    for (i=0;i<n;i++)
    {
        mass[i] = mass[i+1];
    }
    n--;
    for(i=0;i<n;i++)
    {
        printf("%d ",mass[i]);
    }
    printf("\n");
    int mass2[max_size];
    i=0;
    int l;
    l = n*1.5;
    int j =0;

    for(i=l;i>0; i--)
    {

        if((i)%3 == 0 && i!=0)
        {
            mass[i] = 0;

        }
        else
        {
            mass[i] = mass[n-j];
            j++;
        }



    }
    for(i=0;i<l;i++)
    {
        printf("%d ",mass[i]);
    }
    printf("\n");
    return 0;
}