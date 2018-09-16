#include <stdio.h>


int main(void)
{   
    int y = 0 ;
    for (int x = 3; x<200; x+=3)
    {
        
        y += x;

    }
    printf("The sum of numbers that are aliquot 3 is %i\n", y);
}

