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

ll ASK(ll l,ll r)
{
    cout<<"?"<<' '<<r-l+1;
    for(ll i=l;i<=r;i++) cout<<' '<<i;
    cout<<endl;
    ll ret;
    cin>>ret;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        mat num(k);
        at(x,num)
        {
            ll temp1;
            cin>>temp1;
            rep(i,temp1)
            {
                ll temp2;
                cin>>temp2;
                x.pb(temp2);
            }
        }
        ll MAX=ASK(1,n);
        ll l=1,r=n;
        while(l<r)
        {
            ll mid=(l+r)>>1;
            ll now=ASK(l,mid);
            if(now==MAX) r=mid;
            else l=mid+1;
        }
        ll ans=-1,tar=-1;
        vec F(n+1,1);
        rep(i,k)
        {
            bool flag=0;
            at(x,num[i]) if(x==l)
            {
                tar=i;
                flag=1;
            }
            if(flag)
            {
                at(x,num[i]) F[x]=0;
                break;
            }
        }
        if(tar!=-1)
        {
            cout<<'?'<<' '<<n-(ll)num[tar].size();
            REP(i,n) if(F[i]) cout<<' '<<i;
            cout<<endl;
            cin>>ans;
        }
        cout<<'!';
        rep(i,k)
            if(i==tar) cout<<' '<<ans;
            else cout<<' '<<MAX;
        cout<<endl;
        num.clear();
        string s;
        cin>>s;
    }
}


