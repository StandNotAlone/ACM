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

int field[2][100][100],nowr,nowc;           //����bool��gd������������field�������Ӳ���ʱ���ܴ�������ǰ����Ϊ���õ�ԭֵ��nowr��nowc���ڼ�¼��ǰ�ľ����r��c
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
    int newr=0,flag=0;              //newr������¼�¾����r��flag������һ��Ҫɾ������С���к�
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
            else                //���Ӻͼ��ٵĲ��������
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
        memset(field,0,sizeof(field));          //ע��ÿ�γ�ʼ������Ϊ0
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                field[gd][i][j]=i*100+j;        //��һ����λ������ʾ����ԭ�����ڵ��к��У�ǧλ��λ��ʾ�У�ʮλ��λ��ʾ��
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
