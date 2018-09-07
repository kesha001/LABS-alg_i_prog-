# include <stdio.h>
#include <math.h>

int main() {
    float a = 1000, b = 0.0001, c , d, fin, e;
    c = pow(a+b, 2);
    d = ((pow(a, 2)) - 2*a*b);
    e = (c - d);
    fin = (e/(pow(b, 2)));
    printf("%f\n", fin);
}

