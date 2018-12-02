#include <stdio.h>
#include <stdlib.h>
//СТВОРЮЄТЬСЯ СТРУКТУРА АБІТУРІЄНТ
typedef struct
{
    char nm_lnm_pbtk[111];
    int birth_year;
    char grades_entering_exams[111];
    int aver_grad;
}Abiturient;
void printAbik (FILE *f, int number);
int main()
{
    //ВІДКРИВАЄМО ФАЙЛ В РЕЖИМІ БІНАРНОГО ЗАПИСУ/ПЕРЕЗАПИСУ
    FILE *f = fopen("abiturienty.dat", "rb");
    int na;
    char* filename = "abiturienty.dat";
    //ПЕРЕВІРКА НА ТЕ ЧИ ВИДАЄТЬСЯ ПОМИЛКА ПРИ ВІДКРИТТІ ФАЙЛУ, ЯКЩО ТАК, ТО ПРОГРАММА ЗАВЕРШУЄТЬСЯ
    if(fopen(filename , "rb") == NULL)
    {
        exit(0);
    }
    //ПРОГРАМА ПИТАЄ КОРИСТУВАЧА КІЛЬКІСТЬ АБІТУРІЄНТІВ
    printf("Number of abiturients : ");
    scanf("%d", &na);

    //ВИДАЄ СПИСОК АБІТУРІЄНТІВ З ФАЙЛА В КОНСОЛЬ
    printAbik(f, na);
    //ЗАКРИТТЯ ФАЙЛУ
    fclose(f);
    return 0;
}
void printAbik (FILE *f,int number)
{
    Abiturient abiki[number];
    int i = 0;

    //ПОКИ НЕМА КІНЦЯ ФАЙЛУ ЦИКЛ ЗЧИТУЄ З ФАЙЛА ДАНІ І ВИДАЄ ЇХ В КОНСОЛЬ
    while(!feof(f) && i<number)
    {
        fread(&abiki[i],sizeof(Abiturient), 1, f );
        printf("Student: %s\nBirth year: %d \nEntering grades: %s \nAverage grade: %d \n",
        abiki[i].nm_lnm_pbtk, abiki[i].birth_year,abiki[i].grades_entering_exams,abiki[i].aver_grad);
        i++;
    }
}