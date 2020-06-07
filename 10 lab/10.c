#include <stdio.h>
#include <stdbool.h>

float a[11][11],mx=-1e9,savee,savee1;
int i,j,save;

int main() {

    for(i=1; i<=3; i++)
    {
        for(j=1; j<=4; j++) scanf("%f",&a[i][j]);
    }

    for(i=1; i<=3; i++)
    {
        if(a[i][1]>mx){save=i; mx=a[i][1];}
    }

    for(i=1; i<=4; i++)
    {
        savee=a[1][i];
        savee1=a[save][i];
        a[1][i]=savee1;
        a[save][i]=savee;
    }

    for(i=1; i<=3; i++)
    {
        for(j=1; j<=4; j++)
        {
            if(j==1) savee=a[i][j];
            a[i][j]/=savee;
        }
    }

    for(i=2; i<=3; i++)
    {
        for(j=1; j<=4; j++)
        {
            a[i][j]-=a[1][j];
        }
    }

    mx=0;

    for(i=2; i<=3; i++)
    {
        if(a[i][2]>mx){mx=a[i][2],save=i;}
    }

    if(save==3)
    {
        for(i=1; i<=4; i++)
        {
            savee=a[3][i];
            savee1=a[2][i];
            a[2][i]=savee;
            a[3][i]=savee1;
        }
    }

    for(i=2; i<=3; i++)
    {
        for(j=2; j<=4; j++)
        {
            if(j==2) savee=a[i][j];
            a[i][j]/=savee;
        }
    }

    for(i=2; i<=4; i++) a[3][i]-=a[2][i];

    a[3][4]/=a[3][3];
    a[3][3]=1;

    float x1,x2,x3;

    x3=a[3][4];
    x2=a[2][4]-x3*a[2][3];
    x1=a[1][4]-x2*a[1][2]-x3*a[1][3];

    printf("x1=%.2f\nx2=%.2f\nx3=%.2f\n", x1,x2,x3);

    return 0;
}