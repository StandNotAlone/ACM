#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#include<set>
//#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define longlongINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define pb push_back
using namespace std;

void pri(int field[][10])           //�����ú���
{
    for(int i=0;i<11;i++)
    {
        for(int j=0;j<10;j++)
            printf("%3d ",field[i][j]);
        printf("\n");
    }
}

int yd[4][2]=                       //�ƶ�����
{
    1,0,
    0,1,
    -1,0,
    0,-1
};

struct Qizi
{
    char name[10];
    int r,c;
} qizi[10];

int main()
{
    int n,redr,redc,field[11][10],flag[11][10];     //field�洢�����ϸ�λ����û�к�ɫ���ӣ�flag�洢�õ��ܷ��ں췽��һ�����ߵ�
    while(scanf("%d%d%d",&n,&redr,&redc),n||redr||redc) //����Ӧ����black���ӣ�д���˲ŷ������ø���
    {
        memset(field,0,sizeof(field));
        memset(flag,0,sizeof(flag));
        for(int i=0;i<n;i++)
        {
            getchar();
            scanf("%s%d%d",qizi[i].name,&qizi[i].r,&qizi[i].c);//�ӵ�Ҫ��uva����%c����wa��
            field[qizi[i].r][qizi[i].c]=1;
        }
        for(int i=0;i<n;i++)
        {
            if(qizi[i].name[0]=='G')
            {
                int nowr=qizi[i].r-1;
                while(nowr)
                {
                    flag[nowr][qizi[i].c]++;                               //�췽�ɽ�����������Ϳ����ˣ�ֻ��Ҫ�������ϵķ���
                    if(nowr==redr&&qizi[i].c==redc) flag[redr][redc]=-INF; //�ڷ�����ֱ�ӷɽ����������
                    if(field[nowr][qizi[i].c]) break;
                    nowr--;
                }
            }
            else if(qizi[i].name[0]=='R')               //�������ĸ�����ע���һ��ײ�����Ǹ�������Ȼ�����ܳԵ��ģ���Ϊ������������ȥ
            {
                int nowr=qizi[i].r-1;
                while(nowr)
                {
                    flag[nowr][qizi[i].c]++;
                    if(field[nowr][qizi[i].c]) break;
                    nowr--;
                }
                nowr=qizi[i].r+1;
                while(nowr<11)
                {
                    flag[nowr][qizi[i].c]++;
                    if(field[nowr][qizi[i].c]) break;
                    nowr++;
                }
                int nowc=qizi[i].c-1;
                while(nowc)
                {
                    flag[qizi[i].r][nowc]++;
                    if(field[qizi[i].r][nowc]) break;
                    nowc--;
                }
                nowc=qizi[i].c+1;
                while(nowc<10)
                {
                    flag[qizi[i].r][nowc]++;
                    if(field[qizi[i].r][nowc]) break;
                    nowc++;
                }
            }
            else if(qizi[i].name[0]=='H')           //�����ĸ����������źͷ�Χ
            {
                if(qizi[i].r>2&&!field[qizi[i].r-1][qizi[i].c])
                {
                    if(qizi[i].c>1)flag[qizi[i].r-2][qizi[i].c-1]++;
                    if(qizi[i].c<9)flag[qizi[i].r-2][qizi[i].c+1]++;
                }
                if(qizi[i].r<9&&!field[qizi[i].r+1][qizi[i].c])
                {
                    if(qizi[i].c>1)flag[qizi[i].r+2][qizi[i].c-1]++;
                    if(qizi[i].c<9)flag[qizi[i].r+2][qizi[i].c+1]++;
                }
                if(qizi[i].c>2&&!field[qizi[i].r][qizi[i].c-1])
                {
                    if(qizi[i].r<10)flag[qizi[i].r+1][qizi[i].c-2]++;
                    if(qizi[i].r>1)flag[qizi[i].r-1][qizi[i].c-2]++;
                }
                if(qizi[i].c<8&&!field[qizi[i].r][qizi[i].c+1])
                {
                    if(qizi[i].r<10)flag[qizi[i].r+1][qizi[i].c+2]++;
                    if(qizi[i].r>1)flag[qizi[i].r-1][qizi[i].c+2]++;
                }
            }
            else if(qizi[i].name[0]=='C')  //��Ҫ��һ�����ӣ��ȳ����һ��flg�洢·���ϳ����˼������ӣ�2��ʱ�����
            {
                int nowr=qizi[i].r-1;
                int flg=0;
                while(nowr)
                {
                    if(flg) flag[nowr][qizi[i].c]++;
                    if(field[nowr][qizi[i].c])
                    {
                        flg++;
                        if(flg==2) break;
                    }
                    nowr--;
                }
                nowr=qizi[i].r+1;
                flg=0;
                while(nowr<11)
                {
                    if(flg) flag[nowr][qizi[i].c]++;
                    if(field[nowr][qizi[i].c])
                    {
                        flg++;
                        if(flg==2) break;
                    }
                    nowr++;
                }
                int nowc=qizi[i].c-1;
                flg=0;
                while(nowc)
                {
                    if(flg) flag[qizi[i].r][nowc]++;
                    if(field[qizi[i].r][nowc])
                    {
                        flg++;
                        if(flg==2) break;
                    }
                    nowc--;
                }
                nowc=qizi[i].c+1;
                flg=0;
                while(nowc<10)
                {
                    if(flg) flag[qizi[i].r][nowc]++;
                    if(field[qizi[i].r][nowc])
                    {
                        flg++;
                        if(flg==2) break;
                    }
                    nowc++;
                }
            }
        }
        //pri(flag);
        int flg=1;
        if(flag[redr][redc]<0) flg=0;
        for(int i=0;i<4;i++)
        {
            int newr=redr+yd[i][0],newc=redc+yd[i][1];
            if(newr<4&&newr&&newc>3&&newc<7&&!flag[newr][newc]) flg=0;
        }
        if(flg) printf("YES\n");
        else printf("NO\n");
    }
}
