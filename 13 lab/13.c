#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
 
int i,temp,a[21],b[21],c[21],y[21],temp1,z,x,j;
 
int main () {
 
    srand(time(0));
 
    //генерация положительных чисел
    for(i=1; i<=5; i++)
    {
        temp=rand()%10;
        a[i]=temp;
    }
 
    //генерация отрицательных чисел
    for(i=1; i<=5; i++)
    {
        temp=(rand()%10)*(-1);
        a[5+i]=temp;
    }
 
    temp=0;
 
    //ищу положительные числа из массива
    for(i=1; i<=10; i++)
    {
        if(a[i]>=1)
        {
            temp++;
            b[temp]=a[i];
        }
    }
 
    //сортирую мои положительные чиселки
    for(i=1; i<=temp; i++)
    {
        for(j=i+1; j<=temp; j++)
        {
            if(b[i]>b[j])
            {
                z=b[i];
                x=b[j];
                b[j]=z;
                b[i]=x;
            }
        }
    }
 
    //записываю эти чиселки в мой конечный массивчик
    for(i=1; i<=temp; i++) y[i]=b[i];
 
    //ищу отрицательные чиселки
    for(i=1; i<=10; i++)
    {
        if(a[i]<0)
        {
            temp1++;
            c[temp1]=a[i];
        }
    }
 
    //сортирую их
    for(i=1; i<=temp1; i++)
    {
        for(j=i+1; j<=temp1; j++)
        {
            if(c[i]<c[j])
            {
                z=c[i];
                x=c[j];
                c[i]=x;
                c[j]=z;
            }
        }
    }
 
    //также записываю в окончательный массивчик
    for(i=temp+1; i<=10; i++) y[i]=c[i-temp];
 
    //вывожу свой окончательный массивчик
    for(i=1; i<=10; i++) printf("%d ", y[i]);
 
    return 0;
 
}