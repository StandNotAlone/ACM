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

pair<ll,ll> cal(ll t,ll n)
{
    if(n==0) return {0,0};
    ll len=(ll)1<<(n-1);
    ll a=t/((ll)1<<(2*n-2));
    pair<ll,ll>P=cal(t%((ll)1<<(2*n-2)),n-1);
    if(a==0)
    {
        ll x=P.first;
        P.first=P.second;
        P.second=x;
    }
    else if(a==1)
    {
        P.second+=len;
    }
    else if(a==2)
    {
        P.first+=len;
        P.second+=len;
    }
    else
    {
        ll x=P.first;
        P.first=2*len-P.second-1;
        P.second=len-x-1;
    }
    return P;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,t1,t2;
        cin>>n>>t1>>t2;
        pair<ll,ll>a1,a2;
        a1=cal(t1-1,n);
        a2=cal(t2-1,n);
        a1.first-=a2.first;
        a1.second-=a2.second;
        cout<<(sqrt(a1.first*a1.first+a1.second*a1.second)*10)<<endl;
    }
}


