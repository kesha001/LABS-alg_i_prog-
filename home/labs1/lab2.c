#include <stdio.h>

int main() {
    double n , m, d, e, l;
    n = 1000;
    m = 1;
    d = n + ++m;
    e = m-- >n;
    l = n-- > m;
    printf("%f %f %f\n", d, e, l);

}
