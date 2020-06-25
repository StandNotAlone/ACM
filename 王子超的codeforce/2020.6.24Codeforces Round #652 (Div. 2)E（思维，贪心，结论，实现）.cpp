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
#define endl "\n"
#define mp make_pair
#define pb push_back
#define ll long long
#define int long long
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
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int read()      //整数读入挂
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}

using namespace std;
#define local
#ifdef local
#endif
const ll maxn=2e5+7;
const double eps=1e-10;
const ll mod=1e9+7;

int32_t main()
{
    IOS;
    ll n,m;
    cin>>n>>m;
    vec base(maxn,0);
    REP(i,n)
    {
        cin>>base[i];
    }
    vector<int>Flag(maxn,0),flag(m+1,0);
    vec cas(maxn,0);
    vector<pair<ll,ll>>node(m+1);
    mat field(maxn);
    REP(i,m)
    {
        cin>>node[i].ft>>node[i].sd;
        field[node[i].ft].pb(i);
        field[node[i].sd].pb(i);
        cas[node[i].ft]++;
        cas[node[i].sd]++;
    }
    queue<ll>Q;
    stack<ll>S;
    REP(i,n)
    {
        if(base[i]>=cas[i])
        {
            Q.push(i);
            Flag[i]=1;
        }
    }
    while(Q.size())
    {
        ll temp=Q.front();
        Q.pop();
        at(x,field[temp])
        {
            if(!flag[x])
            {
                S.push(x);
                flag[x]=1;
                cas[node[x].ft]--;
                cas[node[x].sd]--;
                if(!Flag[node[x].ft]&&base[node[x].ft]>=cas[node[x].ft])
                {
                    Q.push(node[x].ft);
                    Flag[node[x].ft]=1;
                }
                if(!Flag[node[x].sd]&&base[node[x].sd]>=cas[node[x].sd])
                {
                    Q.push(node[x].sd);
                    Flag[node[x].sd]=1;
                }
            }
        }
    }
    if(S.size()==m)
    {
        cout<<"ALIVE"<<endl;
        bool f=0;
        while(S.size())
        {
            if(f) cout<<' ';
            else f=1;
            ll temp=S.top();
            cout<<temp;
            S.pop();
        }
        cout<<endl;
    }
    else cout<<"DEAD"<<endl;
}


