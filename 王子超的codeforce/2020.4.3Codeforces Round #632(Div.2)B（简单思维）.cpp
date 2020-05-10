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
        vector<ll>a(n),b(n);
        for(auto &x:a) cin>>x;
        for(auto &x:b) cin>>x;
        bool f1=0,f2=0,f=1;
        for(ll i=0;i<n;i++)
        {
            if(a[i]<b[i]&&!f1)
            {
                f=0;
                break;
            }
            if(a[i]>b[i]&&!f2)
            {
                f=0;
                break;
            }
            if(a[i]==1) f1=1;
            if(a[i]==-1) f2=1;
        }
        if(f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}


