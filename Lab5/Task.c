#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define n 2
#define m 60

void dobuvannya(int mass[n][m])
{
    for(int i = 0; i<n; i++)
    {
        printf("(");
        char last_symb;
        for (int j = 0; j<m;j++)
            {

                mass[i][j] = rand()%10;
                if (mass[i][j] == 0 && last_symb != ',' && j != 0 && j!= m-1)
                {
                    printf(",");
                    last_symb = ',';
                }

                else
                {
                    last_symb = mass[i][j];
                    printf("%i", mass[i][j]);
                }

            }
        printf(")");
        printf("\n");
    }
}
int main()
{
    srand(time(NULL));
    int mass[n][m];
    dobuvannya(mass);


}
