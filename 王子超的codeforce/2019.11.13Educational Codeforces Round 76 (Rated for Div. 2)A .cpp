#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 2147483647
using namespace std;
int main()
{
    int t,n,x,a,b,dis;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&x,&a,&b);
        dis=fabs(a-b)+x;
        if(dis>=n) printf("%d\n",n-1);
        else printf("%d\n",dis);
    }
}
