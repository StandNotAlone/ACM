#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 2147483647
using namespace std;
int main()
{
    int t,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&x,&y);
        if(x>=y) printf("YES\n");
        else
        {
            if(x>3) printf("YES\n");
            else if(x==2&&y==3) printf("YES\n");
                 else printf("NO\n");
        }
    }
}
