#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
 
int temp,hkey,b[21],a[10][21],i,ans;
 
int main () {
 
    srand(time(0));
 
    for(i=1; i<=20; i++)
    {
        temp=rand()%100;  // генерируем значения
        printf("%d ", temp);
        hkey=temp%10; // хеш-функция
        b[hkey]++;   //счётчик коллизий
        a[hkey][b[hkey]]=temp; //запись в хеш функцию
    }
    printf("\n");
 
    for(i=5; i<=9; i++) ans+=b[i]; // подсчёт ответа
 
    printf("%d\n",ans);
 
    return 0;
 
}