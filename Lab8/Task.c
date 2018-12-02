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

//ІНІЦІАЛІЗУЮТЬСЯ МАЙБУТНІ ФУНКЦІЇ
void newAbik (FILE *f, int number);
void printAbik (FILE *f, int number);
void delete_abik(FILE *f, int numberA, int numberD);
void print_in_buffer(FILE *f, int numberA ,int numberD);
void add_abik(FILE *f, int number);
//ГОЛОВНА Ф-Я
int main()
{
    //ВІДКРИВАЄМО ФАЙЛ В РЕЖИМІ БІНАРНОГО ЗАПИСУ/ПЕРЕЗАПИСУ
    FILE *f = fopen("abiturienty.dat", "wb");
    int na;
    char* filename = "abiturienty.dat";
    //ПЕРЕВІРКА НА ТЕ ЧИ ВИДАЄТЬСЯ ПОМИЛКА ПРИ ВІДКРИТТІ ФАЙЛУ, ЯКЩО ТАК, ТО ПРОГРАММА ЗАВЕРШУЄТЬСЯ
    if(fopen(filename , "wb") == NULL)
    {
        exit(0);
    }
    //ПРОГРАМА ПИТАЄ КОРИСТУВАЧА КІЛЬКІСТЬ АБІТУРІЄНТІВ
    printf("Number of abiturients : ");
    scanf("%d", &na);
    //ФУКНЦІЯ ЯКА ДОДАЄ СПИСОК АБІТУРІЄНТІВ В ФАЙЛ
    newAbik (f, na);
    //ФАЙЛ ЗАКРИВАЄТЬСЯ, ЦЕ ПОТРІБНО РОБИТИ ЗАВЖДИ ДЛЯ КОРРЕКТНОЇ РОБОТИ ПРОГРАМИ
    fclose(f);
    //ВІДКРИВАЄТЬСЯ ФАЙЛ У РЕЖИМІ БІНАРНОГО ЧИТАННЯ
    f = fopen("abiturienty.dat", "rb");
    //ПЕРЕВІРКА НА ПОМИЛКУ
    if(fopen(filename , "rb") == NULL)
    {
        exit(0);
    }
    //ВИДАЄ СПИСОК АБІТУРІЄНТІВ З ФАЙЛА В КОНСОЛЬ
    printAbik(f, na);
    //ЗАКРИТТЯ ФАЙЛУ
    fclose(f);
    //ПРОГРАМА ПИТАЄ КОРИСТУВАЧА ЯКИЙ ПО СПИСКУ АБІТУРІЄН МАЄ БУТИ ВИДАЛЕНИЙ
    //printf("Element u want to delete: ");
    int k;
    scanf("%d",&k);
    //ВІДКРИВАЄТЬСЯ ФАЙЛ У РЕЖИМІ БІНАРНОГО ЗАПИСУ/ПЕРЕЗАПИСУ
    /*f = fopen("abiturienty.dat", "wb");
    //ЗАПИСУЄ В БУФЕР АБІТУРІЄНТІВ ЯКІ НЕ МАЮТЬ БУТИ ВИДАЛЕНІ
    print_in_buffer(f, na, k);
    fclose(f);
    f = fopen("abiturienty.dat", "wb");
    //ВИДАЛЯЄ З ФАЙЛУ АБІТУРІЄНА ЗА ВКАЗАНИМ НОМЕРОМ
    delete_abik(f, na, k);
    fclose(f);
    f = fopen("abiturienty.dat", "ab");
    //ДОДАЄ НОВОГО АБІТУРІЄНТА В ФАЙЛ
    add_abik(f, na);
    fclose(f);
    f = fopen("abiturienty.dat", "rb");
    //ПЕРЕВІРКА НА ПОМИЛКУ
    if(fopen(filename , "rb") == NULL)
    {
        exit(0);
    }
    //ВИДАЄ СПИСОК АБІТУРІЄНТІВ З ФАЙЛА В КОНСОЛЬ
    printAbik(f, na);*/
    return 0;
}
//ФУКНЦІЯ ЯКА ДОДАЄ СПИСОК АБІТУРІЄНТІВ В ФАЙЛ
void newAbik(FILE *f , int number)
{
    //СТВОРЮЄТЬСЯ МАСИВ СТРУКТУР, ЯКИЙ ПОТІМ БУДЕ ПЕРЕДАНО В ФАЙЛ
    Abiturient abik[number];
    //ДАНІ ЯКІ БУДЕ ПЕРЕДАНО В ФАЙЛ
    for (int i = 0; i<number; i++)
    {
        printf("Name, Last name, Po batkovi: ");
        scanf("%[^.]%*c", abik[i].nm_lnm_pbtk);
        printf("\nBirth year: ");
        scanf("%d", &abik[i].birth_year);
        printf("Entering grades: ");
        scanf("%[^.]%*c",abik[i].grades_entering_exams);
        printf("Average grade: ");
        scanf("%d",&abik[i].aver_grad);
        //ЗАПИСУЄМО В ФАЙЛ ОТРИМАНІ ДАНІ ПРО 1 СТРУКТУРУ
        fwrite(&abik[i], sizeof(Abiturient), 1, f);
    }

}
//ВИДАЄ СПИСОК АБІТУРІЄНТІВ З ФАЙЛА В КОНСОЛЬ
void printAbik (FILE *f, int number)
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
//ЗАПИСУЄ В ПРОМІЖНИЙ ФАЙЛ ЕЛЕМЕНТИ ЯКІ НЕ МАЮТЬ БУТИ ВИДАЛЕНІ
void print_in_buffer(FILE *f, int numberA ,int numberD)
{
    //ВІДКРИВАЄТЬСЯ ПРОМІЖНИЙ ФАЙЛ В РЕЖИМІ БІНАРНОГО ЗАПИСУ І ПЕРЕЗАПИСУ
    FILE *buffer = fopen("buffer.txt","wb");
    Abiturient abituriki[numberA];
    //ЗАПИС В БУФЕР БЕЗ ВИДАЛЕНОГО ЕЛЕМЕНТА
    for (int i = 0; i<numberA; i++)
    {
        fread(&abituriki[i],sizeof(Abiturient),1,f);
        if (i != numberD)
        {
            fwrite(&abituriki[i],sizeof(Abiturient),1,buffer);
        }
    }
    //ЗАКРИТТЯ БУФЕРУ
    fclose(buffer);
}
//ПЕРЕЗАПИСУЄ ФАЙЛИ НАНОВО В ФАЙЛ З БУФЕРУ, ЯКИЙ НЕ МІСТИТЬ ВИДАЛЕНОГО ЕЛЕМЕНТА
void delete_abik(FILE *f, int numberA, int numberD)
{
    Abiturient abikl[numberD];
    int i = 0;
    //ВІДКРИВАЄТЬСЯ БУФЕР У РЕЖИМІ ЧИТАННЯ
    FILE *buffer = fopen("abiturienty.dat", "rb");
    //ЗЧИТУЄ З БУФЕРУ І ЗАПИСУЄ ЗЧИТАНЕ В ФАЙЛ
    while(!feof(f) && i<numberD)
    {
        fread(&abikl[i], sizeof(Abiturient), 1, buffer);
        fwrite(&abikl[i], sizeof(Abiturient), 1, f);
        i++;
    }
    printf("The element has been deleted!\n\n");
    fclose(buffer);
}
//ДОДАЄ НОВОГО АБІТУРІЄНТА В ФАЙЛ
void add_abik(FILE *f, int number)
{
    //ТА САМА ПРОЦЕДУРА ЩО І В ФУНКЦІЇ newAbik ТІЛЬКИ З ОДНИМ ЕЛЕМЕНТОМ
    Abiturient abik2;
    printf("NEW ABITURIENT: \n");
        printf("Name, Last name, Po batkovi: ");
        scanf("%[^.]%*c", abik2.nm_lnm_pbtk);
        printf("\nBirth year: ");
        scanf("%d", &abik2.birth_year);
        printf("Entering grades: ");
        scanf("%[^.]%*c",abik2.grades_entering_exams);
        printf("Average grade: ");
        scanf("%d",&abik2.aver_grad);
        fwrite(&abik2, sizeof(Abiturient), 1, f);
}