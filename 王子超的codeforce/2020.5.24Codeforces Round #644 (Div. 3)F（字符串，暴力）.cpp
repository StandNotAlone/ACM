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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<string>field(n);
        at(x,field) cin>>x;
        bool Flag=0;
        rep(i,m)
        {
            bool flag=1,f=0;
            char c='0';
            for(ll j=1;j<n;j++)
            {
                ll sum=0;
                for(ll k=0;k<m;k++)
                {
                    if(k!=i)
                    {
                        if(field[j][k]!=field[0][k])
                        {
                            sum++;
                        }
                    }
                }
                if(sum==1)
                {
                    if(f)
                    {
                        if(field[j][i]!=c)
                        {
                            flag=0;
                            break;
                        }
                    }
                    else
                    {
                        f=1;
                        if(field[j][i]!=field[0][i])
                        {
                            c=field[j][i];
                        }
                        else c=field[0][i];
                    }
                }
                else if(sum>1)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                Flag=1;
                if(f) field[0][i]=c;
                cout<<field[0]<<endl;
                break;
            }
        }
        if(!Flag) cout<<-1<<endl;
    }
}

 