#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int i,j;
float max,a[11][11],c[11][11],b[11],d[11],eps,currentVariableValues[11],previousVariableValues[11],error;
 
int main () {
 
    // Обычный ввод массивчика a
    for(i=1; i<=3; i++)
    {
        for(j=1; j<=3; j++)
        {
            printf("Vvedite a[%d][%d]", i, j);
            scanf("%f", &a[i][j]);
        }
    }
 
    // такой же ввод массива b
 
    for(i=1; i<=3; i++)
    {
        printf("Vvedite b[%d]", i);
        scanf("%f", &b[i]);
    }
 
    // точность решения 
 
    printf("Vvedite eps");
    scanf("%f", &eps);
 
    // заполнение значений неизвестных на предыдущей итерации
 
    for(i=1; i<=3; i++) previousVariableValues[i]=0;
 
    while(1)
    {
        // рассчёты в соответствии с формулками
        for(i=1; i<=3; i++)
        {
            currentVariableValues[i]=b[i];
            for(j=1; j<=3; j++)
            {
                if(j!=i) currentVariableValues[i]-=a[i][j]*currentVariableValues[j];
            }
            currentVariableValues[i]/=a[i][i];
        }
 
        error=0;
 
        // считаем текущую погрешность относительно предыдущей итерации
 
        for(i=1; i<=3; i++) error+=fabs(currentVariableValues[i]-previousVariableValues[i]);
        // если точность достигнута, выходим
        if(error<eps) break;
        // заполняем предыдущую итерацию текущей
        for(i=1; i<=3; i++) previousVariableValues[i]=currentVariableValues[i];
    }
 
    //вывод ответа
 
    for(i=1; i<=3; i++)
    {
        printf("%.5f ", previousVariableValues[i]);
    }
 
}
