#include <stdio.h>
#include <math.h>
#define E 0.0001
int factorial(int n);
int main()
{
    float a = 0.1 , b = 1, changes = ((b-a)/10),y;
    double x , dodanok = 0, sum = 1, sume =1;
    int n;
    for (x = 0.1; x<= b; x += changes)
    {
        for (n = 1; n<= 10;n++)
        {
            dodanok = (pow(log(3),n)/factorial(n))*(pow(x,n));
            sum += dodanok;

        }
        n =1;
        while(1)
        {

            dodanok = (pow(log(3),n)/factorial(n))*(pow(x,n));
            sume += dodanok;
            if (dodanok < E)
            {
                break;
            }
            n++;
        }
    y = pow(3,x);
    printf("X=%f ; SN= %f ; SE= %f ; Y= %f\n", x,sum,sume,y);
    }

}


int factorial(int n)
{
    if (n==0 || n ==1)
    {
        return 1;
    }
    else
    {
        return n*factorial(n-1);
    }
}