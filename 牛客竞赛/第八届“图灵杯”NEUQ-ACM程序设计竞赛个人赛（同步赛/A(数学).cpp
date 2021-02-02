#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=30+7;
const int mod=998244353;

int k;
int ans=1023;

int main()
{
    scanf("%d",&k);
    printf("%d\n",ans+k);
    int now=1;
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<now;j++)
            printf("1 %d\n",i);
        now*=2;
    }
    int num=1024;
    int a=num/k,b=num%k;
    for(int i=1;i<=k;i++)
    {
        printf("2");
        if(i<=b)
        {
            printf(" %d",a+1);
            for(int i=0;i<=a;i++) printf(" 10");
            printf("\n");
        }
        else
        {
            printf(" %d",a);
            for(int i=0;i<a;i++) printf(" 10");
            printf("\n");
        }
    }
}
