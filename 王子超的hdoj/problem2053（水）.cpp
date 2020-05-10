#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define pi 3.141592653589793238462643383279502
using namespace std;
int main()
{
    int flag[100001];
    memset(flag,0,sizeof(flag));
    for(int i=1;i<100001;i++)
        for(int j=1;i*j<100001;j++)
        flag[i*j]++;
    int n;
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",flag[n]%2);
}
