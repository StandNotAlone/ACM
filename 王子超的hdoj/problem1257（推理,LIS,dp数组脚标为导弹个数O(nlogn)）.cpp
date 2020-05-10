#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define sup 2147483647
using namespace std;
int main()
{
    int i,j,n,h,dp[100001];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            dp[i]=sup;
        for(i=0;i<n;i++)
        {
            scanf("%d",&h);
            *lower_bound(dp,dp+n,h)=h;// 该函数求取从dp头指针到dp+n指针位置间大于等于h的第一个指针
        }
        printf("%d\n",lower_bound(dp,dp+n,sup)-dp);
    }
}
