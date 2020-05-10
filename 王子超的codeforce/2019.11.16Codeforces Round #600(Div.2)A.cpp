#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
using namespace std;

int main()
{
    int t,n,x,i,flag,a[100010],sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        flag=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&x);
        sum=x-a[0];
        if(sum<0) flag+=100;
        if(sum>0) flag+=1;
        for(i=1;i<n;i++)
        {
            scanf("%d",&x);
            if(x-a[i]<0) flag+=100;
            else if(x-a[i]!=sum)
                 {
                     sum=x-a[i];
                     if(sum) flag++;
                 }
        }
        if(flag<=1) printf("YES\n");
        else printf("NO\n");
    }
}
