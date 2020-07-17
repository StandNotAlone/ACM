#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 2147483647
using namespace std;

void qsort(int q,int p,int sum[],int w[],int s[])
{
    int l=q,r=p,mid1=s[(q+p)/2],mid2=w[(q+p)/2],t;
    while(l<=r)
    {
        while(s[l]>mid1||s[l]==mid1&&w[l]>mid2)l++;
        while(s[r]<mid1||s[r]==mid1&&w[r]<mid2)r--;
        if(l<=r)
        {
            t=w[l];
            w[l]=w[r];
            w[r]=t;
            t=s[l];
            s[l]=s[r];
            s[r]=t;
            t=sum[l];
            sum[l]=sum[r];
            sum[r]=t;
            l++;
            r--;
        }
    }
    if(l<p) qsort(l,p,sum,w,s);
    if(r>q) qsort(q,r,sum,w,s);
}


int main()
{
    int dp[1002],flag[1002],sum[1002],w[1002],s[1002],num=1,i,j,max;
    while(scanf("%d%d",&w[num],&s[num])!=EOF)
    {
        sum[num]=num;
        num++;
    }
    num--;
    qsort(1,num,sum,w,s);
    dp[1]=1;
    max=1;
    for(i=2;i<=num;i++)
    {
        dp[i]=1;
        for(j=1;j<i;j++)
            if(w[j]<w[i]&&s[j]>s[i]&&dp[j]+1>dp[i]) dp[i]=dp[j]+1;
        if(dp[i]>max) max=dp[i];
    }
    printf("%d\n",max);
    for(i=1;i<=num;i++)
        flag[i]=0;
    for(i=num;i&&max;i--)
    {
        if(dp[i]==max)
        {
            flag[i]=1;
            max--;
        }
    }
    for(i=1;i<=num;i++)
        if(flag[i])printf("%d\n",sum[i]);
}
