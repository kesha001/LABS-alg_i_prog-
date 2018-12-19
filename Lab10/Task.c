#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
void deleteElement(int *mass, int k, int n);
void addElement(int *mass, int n, int k);
int main()
{
    srand(time(NULL));
    int *mass;
    int n;
    printf("Number of elements in massive: ");
    scanf("%i", &n);
    mass = malloc(n * sizeof(int));
    printf("Massive:\n");
    for (int i = 0; i<n; i++)
    {
        mass[i] = rand()%10;
        printf("%i ", mass[i]);
    }
    printf("\n");
    printf("Elemetn u want to delete: ");
    int d;
    scanf("%i",&d);
    deleteElement(mass, d, n);
    n--;
    for (int i = 0; i<n; i++)
    {
            printf("%i ", mass[i]);
    }
    printf("\n");
    printf("Element u want to add: ");
    scanf("%i",&d);
    n++;
    addElement(mass,n,d);
    for (int i = 0; i<n; i++)
    {
            printf("%i ", mass[i]);
    }
    printf("\n");
    free(mass);
}
void deleteElement(int *mass, int k, int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(i>=k-1)
        {
            *(mass+i)=*(mass+(i+1));
        }
        else;
    }
}
void addElement(int *mass, int n, int k)
{
    mass[n-1] = k;
}