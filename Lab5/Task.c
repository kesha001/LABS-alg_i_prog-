#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define n 2
#define m 60

void dobuvannya(int mass[n][m])  // Функція яка  генерує випадкові числа (60) і розділяє їх на "слова"
{
    for(int i = 0; i<n; i++)
    {
        printf("(");
        char last_symb;
        for (int j = 0; j<m;j++)
            {

                mass[i][j] = rand()%10; // Заповнює двовимірний масив псевдовипадковими числами
                if (mass[i][j] == 0 && last_symb != ',' && j != 0 && j!= m-1) // розділяє числа, якщо між ними стоїть 0
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
int main()          //головна функція, в якій застосовується функція яка  генерує випадкові числа (60) і розділяє їх на "слова"
{
    srand(time(NULL));
    int mass[n][m];
    dobuvannya(mass);


}
