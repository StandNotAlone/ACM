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
const ll maxn=1e4+10;
const double eps=1e-10;
const ll mod=3e9;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const double C=0.5772156649015328606065;

double ans[maxn];

void init()
{
    ans[0]=0;
    for(int i=1;i<=10000;i++)
    {
        ans[i]=ans[i-1]+1.0/i;
    }
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    int t;
    init();
    scanf("%d",&t);
    for(int CASE=1;CASE<=t;CASE++)
    {
        ll n;
        scanf("%lld",&n);
        double out;
        if(n<=10000) out=ans[n];
        else out=log(n)+C+0.5/n;//该公式只对10000以上的级数成立
        printf("Case %d: %.10lf\n",CASE,out);
    }
}
