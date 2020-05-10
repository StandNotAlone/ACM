#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 2147483647
using namespace std;

void qsort(int q,int p,int w[][3])
{
    int l=q,r=p,mid=w[(q+p)/2][0],t;
    while(l<=r)
    {
        while(w[l][0]>mid)l++;
        while(w[r][0]<mid)r--;
        if(l<=r)
        {
            t=w[l][0];
            w[l][0]=w[r][0];
            w[r][0]=t;
            t=w[l][1];
            w[l][1]=w[r][1];
            w[r][1]=t;
            t=w[l][2];
            w[l][2]=w[r][2];
            w[r][2]=t;
            l++;
            r--;
        }
    }
    if(l<p) qsort(l,p,w);
    if(r>q) qsort(q,r,w);
}

void swap(int *a,int*b)
{
    if(*a<*b)
    {
        int t;
        t=*a;
        *a=*b;
        *b=t;
    }
}

int main()
{
    int n,stone[1000][3],dp[1000],flag[1000],height,cas=0,i,I,j,x,y,z;
    while(scanf("%d",&n),n)
    {
        cas++;
        printf("Case %d: maximum height = ",cas);
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            swap(&x,&y);
            swap(&y,&z);
            swap(&x,&y);
            I=3*i;
            stone[I][0]=x;
            stone[I][1]=y;
            stone[I][2]=z;
            stone[I+1][0]=y;
            stone[I+1][1]=z;
            stone[I+1][2]=x;
            stone[I+2][0]=x;
            stone[I+2][1]=z;
            stone[I+2][2]=y;
        }
        n*=3;
        qsort(0,n-1,stone);
        height=0;
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        {
            for(j=0;j<i;j++)
                if(stone[j][0]>stone[i][0]&&stone[j][1]>stone[i][1]&&dp[j]>dp[i])
                    dp[i]=dp[j];
            dp[i]+=stone[i][2];
            if(dp[i]>height) height=dp[i];
        }
        printf("%d\n",height);
    }
}
