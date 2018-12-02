#include <stdio.h>
#define MAXLINE 100
#include <stdlib.h>
void filesize(FILE *fp, char* filename);
int main()
{

    FILE *fout = fopen("F1","w");
    FILE *fin = fopen("F2","w");
    if(fopen("F1","w") == NULL ||fopen("F2","w") == NULL )
    {
        printf("Oops! Something went wrong! ");
        exit(0);
    }
    char s[MAXLINE];
    int numb_of_lines;
    printf("Enter number of lines: ");
    scanf("%d",&numb_of_lines);
    for (int i = 0; i<numb_of_lines; i++)
    {
        printf("%d line: ",i+1);
        scanf("%[^.]%*c", s);
        printf("%s",s);
        printf(" noted in F1\n");
        fputs(s, fout);
        if(i%2 == 0)
        {
            printf(" and noted in F2\n");
            fputs(s, fin);
        }
    }

    fclose(fout);
    fclose(fin);
    filesize(fout, "F1");
    filesize(fin, "F2");

}
void filesize(FILE *fp, char* filename)
{
    fp = fopen(filename, "rb");
    fseek(fp, 0, SEEK_END);
    printf("%ld\n", ftell(fp));
    fclose(fp);
}