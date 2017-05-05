#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Jakub Czaja


void czytaj_zmienna(char *, int *, char *);
void zamiana(char *, int);
int irandom(int , int);

void czytaj_zmienna(char *prompt, int *p, char *format)
{
    int i;
    do
    {
        printf("podaj %s ", prompt);
        i = scanf(format,p);
        fflush(stdin);
        if (i == 0)
            printf("zla zmienna\n\n");
    }while(!i);
}

void zamiana(char *tab, int n)
{
    char samog[] = {'a', 'e', 'i', 'o', 'u', 'y'};
    int a = sizeof(samog)/sizeof(samog[0]);
    int p = 0;
    int i;
    for(i = 0; i < n; ++i)
    {
        int j;
        p = 0;
        for(j = 0; j < a; ++j)
        {
            if(*(tab + i) == *(samog + j))
            {
                p = 1;
                break;
            }
        }
        if(p)
            *(tab + i) -=32;
    }
}

int irandom(int a, int b)
{
    return rand()%(b+1-a)+a;
}

int main()
{
	srand(time(0));
    int n;
    czytaj_zmienna("rozmiar", &n, "%d");

    char *tab = calloc(n, sizeof(char));
    int i;
    for(i = 0; i < n; ++i)
    {
        *(tab + i) = irandom('a', 'z');
        printf("%c", *(tab + i));
    }
    printf("\n\n");

    zamiana(tab, n);


    for(i = 0; i < n; ++i)
    {
        printf("%c", *(tab + i));
    }
    return 0;
}
