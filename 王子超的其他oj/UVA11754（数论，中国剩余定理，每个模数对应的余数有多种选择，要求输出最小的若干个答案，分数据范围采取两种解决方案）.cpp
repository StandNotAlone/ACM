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
#include<unordered_map>
//#include<bits/stdc++.h>
#define INF 0x3f3f3f3f //1061109567
#define llINF 9223372036854775807
#define pi 3.141592653589793
#define ll long long
using namespace std;
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int c,s;
int bestc;
ll x[10],k[10];
vector<ll>num[10];
ll product,m;
vector<ll>ans;

void solve_violence()
{
    unordered_map<ll,bool>M[10];
    for(int i=1;i<=c;i++)
    {
        if(i!=bestc)
        {
            for(int j=0;j<k[i];j++)
                M[i][num[i][j]]=1;
        }
    }
    for(ll i=0;s;i++)
    {
        for(ll j=0;j<k[bestc];j++)
        {
            if(!s) break;
            ll now=i*x[bestc]+num[bestc][j];
            if(now==0) continue;
            bool flag=1;
            for(int l=1;l<=c;l++)
            {
                if(l!=bestc&&M[l].find(now%x[l])==M[l].end()) flag=0;
            }
            if(flag)
            {
                printf("%lld\n",now);
                s--;
            }
        }
    }
}

ll a[10];

ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!a&&!b) return -1;
    if(!b)
    {
        x=1;y=0;
        return a;
    }
    ll ret=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return ret;
}

ll china()
{
    ll ret=0;
    ll k1,k2;
    for(int i=1;i<=c;i++)
    {
        ll w=m/x[i];
        exgcd(w,x[i],k1,k2);
        ret=(ret+w*a[i]*k1)%m;
    }
    return (ret+m)%m;
}

void dfs(int deep)
{
    for(int i=0;i<k[deep];i++)
    {
        a[deep]=num[deep][i];
        if(deep==c) ans.push_back(china());
        else dfs(deep+1);
    }
}

void solve_china()
{
    ans.clear();
    dfs(1);
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    ll len=ans.size();
    for(ll i=0;s;i++)
    {
        for(ll j=0;j<len;j++)
        {
            if(!s) break;
            if(i*m+ans[j])
            {
                printf("%lld\n",i*m+ans[j]);
                s--;
            }
        }
    }
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    while(1)
    {
        scanf("%d%d",&c,&s);
        if(!c&&!s) break;
        product=m=bestc=1;
        for(int i=1;i<=c;i++)
        {
            scanf("%lld%lld",&x[i],&k[i]);
            num[i].clear();
            for(int j=0;j<k[i];j++)
            {
                ll temp;
                scanf("%lld",&temp);
                num[i].push_back(temp);
            }
            if(k[bestc]*x[i]>k[i]*x[bestc]) bestc=i;
            sort(num[i].begin(),num[i].end());
            product*=k[i];
            m*=x[i];
        }
        if(product<=10000) solve_china();
        else solve_violence();
        printf("\n");
    }
}

