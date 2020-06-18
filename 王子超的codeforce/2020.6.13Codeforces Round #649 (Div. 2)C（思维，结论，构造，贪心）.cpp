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
#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
#define ll long long
#define vec vector<ll>
#define mat vector<vector<ll>>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define _rep(i,n) for(ll i=n-1;i>=0;i--)
#define REP(i,n) for(ll i=1;i<=(ll)(n);i++)
#define _REP(i,n) for(ll i=n;i>0;i--)
#define at(x,n) for(auto &x:n)
//cout<<fixed<<setprecision(6)<<
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//ifstream f1("/Users/wangzichao/Documents/wzc.in");
//ofstream f2("/Users/wangzichao/Documents/wzc.out");
//ios::sync_with_stdio(false);
//cin.tie(0);cout.tie(0);
using namespace std;
#define local
#ifdef local
#endif
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    vec num(n);
    bool flag=1;
    rep(i,n)
    {
        cin>>num[i];
        if(num[i]>i+1) flag=0;
    }
    if(flag)
    {
        vec ans(n);
        ll now=n-1;
        stack<ll>S;
        while(now>=0)
        {
            if(num[now]==num[now-1])
            {
                if(S.size())
                {
                    ans[now]=S.top();
                    S.pop();
                }
                else ans[now]=1e6;
            }
            else
            {
                ans[now]=num[now-1];
                for(ll i=num[now]-1;i>num[now-1];i--)
                {
                    S.push(i);
                }
            }
            now--;
        }
        if(S.size())
        {
            ans[0]=S.top();
            S.pop();
        }
        else
        {
            if(num[0]) ans[0]=0;
            else ans[0]=1e6;
        }
        if(S.size()) cout<<-1<<endl;
        else
        {
            rep(i,n)
            {
                if(i) cout<<' ';
                cout<<ans[i];
            }
            cout<<endl;
        }
    }
    else cout<<-1<<endl;
}

 