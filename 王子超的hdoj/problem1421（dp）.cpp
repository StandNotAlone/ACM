#include<stdio.h>
#include<string.h>
int w[2001],dp[2001][1001];

void qsort(int q,int p)
{
    int l=q,r=p,mid=w[(q+p)/2],t;
    while(l<=r)
    {
        while(w[l]<mid)l++;
        while(w[r]>mid)r--;
        if(l<=r)
        {
            t=w[l];
            w[l]=w[r];
            w[r]=t;
            l++;
            r--;
        }
    }
    if(l<p) qsort(l,p);
    if(r>q) qsort(q,r);
}

int main()
{
    int n,k,i,j;
    memset(dp,0,sizeof(dp));
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&w[i]);
        qsort(1,n);
        for(i=2;i<=n;i++)
            for(j=1;j<=k&&j*2<=i;j++)
            {
                int x=dp[i-2][j-1]+(w[i]-w[i-1])*(w[i]-w[i-1]);
                if(i==j*2) dp[i][j]=x;
                else if(x<dp[i-1][j]) dp[i][j]=x;
                     else dp[i][j]=dp[i-1][j];
            }
        printf("%d\n",dp[n][k]);
    }
}

