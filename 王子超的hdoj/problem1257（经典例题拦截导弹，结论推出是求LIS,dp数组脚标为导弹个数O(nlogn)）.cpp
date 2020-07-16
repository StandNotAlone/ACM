#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<functional>
//#include<bits/stdc++.h>
#define INF 0x3f3f3f3f //1061109567
#define llINF 9223372036854775807
#define pi 3.141592653589793
#define ll long long
using namespace std;
const ll maxn=1e6+10;
const double eps=1e-10;
const ll mod=3e9;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int num[maxn];
int dp[maxn];

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            dp[i]=INF;
        }
        for(int i=0;i<n;i++)
            *lower_bound(dp,dp+n,num[i])=num[i];
        printf("%lld\n",(ll)(lower_bound(dp,dp+n,30001)-dp));
    }
}

