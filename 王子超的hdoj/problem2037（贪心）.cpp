#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
using namespace std;                    //一开始想着用dp来写，发现这道题排序后就可以直接贪心了.

void qsort(int q,int p,int s[],int e[])
{
    int l=q,r=p,mid1=s[(q+p)/2],mid2=e[(q+p)/2],t;
    while(l<=r)
    {
        while(e[l]<mid2||e[l]==mid2&&s[l]<mid1)l++;
        while(e[r]>mid2||e[r]==mid2&&s[r]>mid1)r--;
        if(l<=r)
        {
            t=s[l];
            s[l]=s[r];
            s[r]=t;
            t=e[l];
            e[l]=e[r];
            e[r]=t;
            l++;
            r--;
        }
    }
    if(l<p) qsort(l,p,s,e);
    if(r>q) qsort(q,r,s,e);
}

int main()
{
    int n,i,j,s[110],e[110],sum,time,t;
    while(scanf("%d",&n),n)
    {
        for(i=1;i<=n;i++)
            scanf("%d%d",&s[i],&e[i]);
        qsort(1,n,s,e);
        sum=0;
        for(i=1;1;)
        {
            sum++;
            t=e[i];
            i++;
            while(s[i]<t) i++;
            if(i>n) break;
        }
        printf("%d\n",sum);
    }
}
