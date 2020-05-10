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
//cin.tie(0);
using namespace std;
#define local
#ifdef local
#endif
const ll maxn=6e5+7;
const double eps=1e-10;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>prince(n+1);
        for(auto &x:prince) x=0;
        vector<ll>D,P;
        for(ll i=0;i<n;i++)
        {
            ll k;
            bool f=1;
            cin>>k;
            for(ll j=0;j<k;j++)
            {
                ll x;
                cin>>x;
                if(f&&!prince[x])
                {
                    f=0;
                    prince[x]=1;
                }
            }
            if(f) D.pb(i+1);
        }
        for(ll i=1;i<=n;i++)
        {
            if(!prince[i]) P.pb(i);
        }
        if(P.size())
        {
            cout<<"IMPROVE"<<endl<<D[0]<<' '<<P[0]<<endl;
        }
        else cout<<"OPTIMAL"<<endl;
    }
}


