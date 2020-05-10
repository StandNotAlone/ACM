#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 2147483647
using namespace std;
int a[200002][3];
int main()
{
    int t,n,len,x,i,j,max;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            a[x][0]++;
            if(a[x][1]==0) a[x][1]=i+1;
            else if(a[x][2]==0)
                 {
                     a[x][2]=i+1-a[x][1];
                     a[x][1]=i+1;
                 }
                 else
                 {
                     if(i+1-a[x][1]<a[x][2]) a[x][2]=i+1-a[x][1];
                     a[x][1]=i+1;
                 }
        }
        max=0;
        len=INF;
        for(i=0;i<n+1;i++)
        {
            if(a[i][0]>max) max=a[i][0];
            if(a[i][0]>1&&a[i][2]<len) len=a[i][2];
        }
        if(max>1) printf("%d\n",len+1);
        else printf("-1\n");
    }
}
