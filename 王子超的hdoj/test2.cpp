#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#include<set>
//#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define longlongINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define pb push_back
#define ll long long

#define local
#ifdef local
#endif

#define maxn
using namespace std;
int main()
{
    long long t,n,sum[100010];
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(int i=0;i<n;i++)
            scanf("%lld",&sum[i]);
        int flag=1,sum1=sum[0],sum2=sum[n-1];
        for(int i=1;i<n;i++)
        {
            if(sum1<=0||sum2<=0)
            {
                flag=0;
                break;
            }
            sum1+=sum[i];
            sum2+=sum[n-i-1];
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}

