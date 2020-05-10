#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
using namespace std;

void qsort(int q,int p,int sweet[])
{
    int l=q,r=p,mid=sweet[(q+p)/2],t;
    while(l<=r)
    {
        while(sweet[l]<mid)l++;
        while(sweet[r]>mid)r--;
        if(l<=r)
        {
            t=sweet[l];
            sweet[l]=sweet[r];
            sweet[r]=t;
            l++;
            r--;
        }
    }
    if(l<p) qsort(l,p,sweet);
    if(r>q) qsort(q,r,sweet);
}

int sweet[200010];
int main()
{
    int n,m,i,x,suger=0,sum=0;
    scanf("%d%d",&n,&m);
    sweet[0]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&sweet[i]);
    }
    qsort(1,n,sweet);
    for(i=1;i<=n;i++)
        sweet[i]+=sweet[i-1];
    for(i=1;i<n;i++)
    {
        sum++;
        if(sum>m)
        {
            sum-=m;
            suger+=sweet[i-1];
        }
        suger=suger+sweet[i]-sweet[i-1];
        printf("%d ",suger);
    }
    sum++;
    if(sum>m)
    {
        sum-=m;
        suger+=sweet[i-1];
    }
    suger=suger+sweet[n]-sweet[n-1];
    printf("%d\n",suger);
}
