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

int read()      //ÕûÊý¶ÁÈë¹Ò
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
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;

vec num;

int32_t main()
{
    IOS;
    ll numz=0,numf=0,num0=0;
    ll tarz=-1,tarf=-1,tar0=-1;
    ll n;
    cin>>n;
    num.resize(n+1);
    vec cas0,casf,casz;
    vec flag(n+1,1);
    REP(i,n)
    {
        cin>>num[i];
        if(num[i]>0)
        {
            casz.pb(i);
            if(numz==0)
            {
                numz++;
                tarz=i;
            }
            else
            {
                numz++;
                if(num[i]<num[tarz]) tarz=i;
            }
        }
        else if(num[i]==0)
        {
            cas0.pb(i);
            num0++;
            tar0=i;
        }
        else
        {
            casf.pb(i);
            if(numf==0)
            {
                numf++;
                tarf=i;
            }
            else
            {
                numf++;
                if(num[i]>num[tarf]) tarf=i;
            }
        }
    }
    if(num0==0)
    {
        if(numf%2==0)
        {
            for(ll i=1;i<n;i++)
            {
                cout<<1<<' '<<i<<' '<<i+1<<endl;
            }
        }
        else
        {
            cout<<2<<' '<<tarf<<endl;
            flag[tarf]=0;
            vec ans;
            REP(i,n) if(flag[i]) ans.pb(i);
            for(ll i=0;i+1<ans.size();i++)
            {
                cout<<1<<' '<<ans[i]<<' '<<ans[i+1]<<endl;
            }
        }
    }
    else
    {
        for(ll i=0;i+1<cas0.size();i++)
        {
            cout<<1<<' '<<cas0[i]<<' '<<cas0[i+1]<<endl;
            flag[cas0[i]]=0;
        }
        if(numf%2)
        {
            cout<<1<<' '<<cas0[cas0.size()-1]<<' '<<tarf<<endl;
            flag[cas0[cas0.size()-1]]=0;
            if(numf==1&&numz==0);
            else
            {
                cout<<2<<' '<<tarf<<endl;
                flag[tarf]=0;
            }
        }
        else
        {
            if(numf+numz)
            {
                cout<<2<<' '<<cas0[cas0.size()-1]<<endl;
                flag[cas0[cas0.size()-1]]=0;
            }
        }
        vec ans;
        REP(i,n) if(flag[i]) ans.pb(i);
        for(ll i=0;i+1<ans.size();i++)
        {
            cout<<1<<' '<<ans[i]<<' '<<ans[i+1]<<endl;
        }
    }
}
