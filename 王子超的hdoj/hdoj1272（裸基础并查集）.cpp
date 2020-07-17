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
const ll maxn=1e5+7;
const double eps=1e-10;
const ll mod=1e9+7;

vector<ll>fa(maxn);
vector<ll>F(maxn);

void fainit()
{
    for(ll i=0;i<fa.size();i++)
    {
        fa[i]=i;
        F[i]=0;
    }
}

ll get(ll x)
{
    return x==fa[x]?x:fa[x]=get(fa[x]);
}

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);使用之后不要混用cin和scanf printf
    ll x,y;
    while(scanf("%lld%lld",&x,&y),x!=-1||y!=-1)
    {
        fainit();
        bool flag=1;
        ll Nsum=0,Lsum=1;
        while(x||y)
        {
            if(!F[x])
            {
                F[x]=1;
                Nsum++;
            }
            if(!F[y])
            {
                F[y]=1;
                Nsum++;
            }
            if(get(x)==get(y)) flag=0;
            else
            {
                fa[get(x)]=get(y);
                Lsum++;
            }
            scanf("%lld%lld",&x,&y);
        }
        if(flag&&Lsum==Nsum||!Nsum) printf("Yes\n");//注意此处一个坑点，空树也是满足的
        else printf("No\n");
    }
}


