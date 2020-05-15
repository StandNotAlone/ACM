#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define ft first
#define sd second
#define pb push_back
#define ll long long
#define vec vector<ll>
#define mat vector<vector<ll>>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define REP(i,n) for(ll i=1;i<=(ll)(n);i++)
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
const ll maxn=2e5+1;
const double eps=1e-10;
const ll mod=1e9+7;

struct Node
{
    ll len;
    ll l,r;
};

vec ans(maxn+1);

vector<Node>node[maxn];

bool cmp(Node a,Node b)
{
    return a.l<b.l;
}

void solve(Node N,ll now)
{
    ll mid=(N.l+N.r)>>1;
    ans[mid]=now;
    if(mid!=N.l)
    {
        Node NEW;
        NEW.l=N.l;
        NEW.r=mid-1;
        NEW.len=NEW.r-NEW.l+1;
        node[NEW.len].pb(NEW);
    }
    if(mid!=N.r)
    {
        Node NEW;
        NEW.l=mid+1;
        NEW.r=N.r;
        NEW.len=NEW.r-NEW.l+1;
        node[NEW.len].pb(NEW);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll now=1,Mlen=n;
        Node start;
        start.l=1;start.r=n;
        start.len=n;
        node[n].pb(start);
        while(Mlen)
        {
            sort(node[Mlen].begin(),node[Mlen].end(),cmp);
            at(x,node[Mlen])
            {
                solve(x,now++);
            }
            node[Mlen].clear();
            Mlen--;
        }
        REP(i,n)
        {
            if(i>1) cout<<' ';
            cout<<ans[i];
        }
        cout<<endl;
    }
}

 