#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define longlongINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
using namespace std;

int field[2][100][100],nowr,nowc;           //利用bool型gd滚动利用数组field避免增加操作时可能带来的提前覆盖为利用的原值，nowr和nowc用于记录当前的矩阵的r和c
bool gd=0;

void dr()
{
    gd=!gd;
    int n,x[51];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    sort(x,x+n);
    int newr=0,flag=0;              //newr用来记录新矩阵的r，flag则是下一个要删除的最小的行号
    for(int i=1;i<=nowr;i++)
    {
        if(flag<n)
        {
            if(i!=x[flag])
            {
                newr++;
                for(int j=1;j<=nowc;j++)
                    field[gd][newr][j]=field[!gd][i][j];
            }
            else flag++;
        }
        else
        {
            newr++;
            for(int j=1;j<=nowc;j++)
                field[gd][newr][j]=field[!gd][i][j];
        }
    }
    nowr=newr;
}

void dc()
{
    gd=!gd;
    int n,x[51];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    sort(x,x+n);
    int newc=0,flag=0;
    for(int i=1;i<=nowc;i++)
    {
        if(flag<n)
        {
            if(i!=x[flag])
            {
                newc++;
                for(int j=1;j<=nowr;j++)
                    field[gd][j][newc]=field[!gd][j][i];
            }
            else flag++;
        }
        else
        {
            newc++;
            for(int j=1;j<=nowr;j++)
                field[gd][j][newc]=field[!gd][j][i];
        }
    }
    nowc=newc;
}

void ir()
{
    gd=!gd;
    int n,x[51];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    sort(x,x+n);
    int newr=0,flag=0;
    for(int i=1;i<=nowr;i++)
    {
        if(flag<n)
        {
            if(i!=x[flag])
            {
                newr++;
                for(int j=1;j<=nowc;j++)
                    field[gd][newr][j]=field[!gd][i][j];
            }
            else                //增加和减少的差别在这里
            {
                flag++;
                newr++;
                for(int j=1;j<=nowc;j++)
                    field[gd][newr][j]=0;
                newr++;
                for(int j=1;j<=nowc;j++)
                    field[gd][newr][j]=field[!gd][i][j];
            }
        }
        else
        {
            newr++;
            for(int j=1;j<=nowc;j++)
                field[gd][newr][j]=field[!gd][i][j];
        }
    }
    nowr=newr;
}

void ic()
{
    gd=!gd;
    int n,x[51];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    sort(x,x+n);
    int newc=0,flag=0;
    for(int i=1;i<=nowc;i++)
    {
        if(flag<n)
        {
            if(i!=x[flag])
            {
                newc++;
                for(int j=1;j<=nowr;j++)
                    field[gd][j][newc]=field[!gd][j][i];
            }
            else
            {
                flag++;
                newc++;
                for(int j=1;j<=nowr;j++)
                    field[gd][j][newc]=0;
                newc++;
                for(int j=1;j<=nowr;j++)
                    field[gd][j][newc]=field[!gd][j][i];
            }
        }
        else
        {
            newc++;
            for(int j=1;j<=nowr;j++)
                field[gd][j][newc]=field[!gd][j][i];
        }
    }
    nowc=newc;
}

void ex()
{
    int i1,j1,i2,j2;
    scanf("%d%d%d%d",&i1,&j1,&i2,&j2);
    int t=field[gd][i1][j1];
    field[gd][i1][j1]=field[gd][i2][j2];
    field[gd][i2][j2]=t;
}

int main()
{
    int r,c,n,cas=0;
    char opera[10];
    while(scanf("%d%d",&r,&c),r!=0||c!=0)
    {
        cas++;
        if(cas!=1) printf("\n");
        nowr=r;
        nowc=c;
        memset(field,0,sizeof(field));          //注意每次初始化数组为0
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                field[gd][i][j]=i*100+j;        //用一个四位整数表示该数原本所在的行和列，千位百位表示行，十位个位表示列
        scanf("%d",&n);
        getchar();
        for(int i=0;i<n;i++)
        {
            scanf("%s",opera);
            if(opera[0]=='D')
            {
                if(opera[1]=='R') dr();
                else dc();
            }
            else if(opera[0]=='I')
            {
                if(opera[1]=='R') ir();
                else ic();
            }
            else ex();
            getchar();
        }
        printf("Spreadsheet #%d\n",cas);
        scanf("%d",&n);
        int x,y;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            int x1=0,y1=0,sum=x*100+y;
            printf("Cell data in (%d,%d) ",x,y);
            for(int j=1;j<=nowr;j++)
                for(int k=1;k<=nowc;k++)
                    if(field[gd][j][k]==sum)
                    {
                        x1=j;
                        y1=k;
                    }
            if(x1) printf("moved to (%d,%d)\n",x1,y1);
            else printf("GONE\n");
        }
    }
}
