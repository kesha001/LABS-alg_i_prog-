#include <stdlib.h>
#include <stdio.h>

int main()
{
    char k,m;
    FILE *fp1 = fopen("F1", "r");
    FILE *fp2 = fopen("F2", "r");
    while(!feof(fp1))
    {
        fread(&k, sizeof(char),1,fp1);
        printf("%c", k);
    }
    fclose(fp1);
    while(!feof(fp2))
    {
        fread(&m, sizeof(char),1,fp2);
        printf("%c", m);
    }
    fclose(fp2);
    return 0;
}