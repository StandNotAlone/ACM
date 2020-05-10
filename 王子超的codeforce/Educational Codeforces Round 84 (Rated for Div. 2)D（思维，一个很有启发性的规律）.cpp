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
//cout<<fixed<<setprecision(6)<<
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//ifstream f1(".txt");
//ofstream f2(".txt");
//ios::sync_with_stdio(false);
//cin.tie(0);cout.tie(0);
using namespace std;
#define local
#ifdef local
#endif
const ll maxn=6e5+7;
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
        ll n;
        cin>>n;
        vector<ll>p(n),c(n);
        for(auto &x:p)
        {
            cin>>x;
            x--;
        }
        for(auto &x:c) cin>>x;
        ll ans=llINF;
        vector<bool>flag(n,0);
        for(ll i=0;i<n;i++)
        {
            if(flag[i]) continue;
            vector<ll>circle;
            ll T=p[i];
            while(!flag[T])
            {
                flag[T]=1;
                circle.pb(T);
                T=p[T];
            }
            ll size=circle.size();
            for(ll j=1;j<=size;j++)
            {
                if(size%j) continue;
                bool F=0;
                for(ll k=0;k<j;k++)
                {
                    bool f=1;
                    for(ll l=k+j;l<size;l+=j)
                        if(c[circle[l]]!=c[circle[l-j]]) f=0;
                    if(f)
                    {
                        F=1;
                        break;
                    }
                }
                if(F)
                {
                    ans=min(ans,j);
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
}


