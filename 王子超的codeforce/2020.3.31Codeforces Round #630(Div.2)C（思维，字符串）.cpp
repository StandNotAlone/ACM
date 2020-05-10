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

int flag[11]={2,3,5,7,11,13,17,19,23,29,31};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        string s;
        cin.get();
        getline(cin,s);
        ll ans=0;
        ll m=n/k;
        for(ll i=0;i*2+2<=k;i++)
        {
            ll num[26];
            memset(num,0,sizeof(num));
            for(ll j=0;j<m;j++)
            {
                num[s[i+k*j]-'a']++;
                num[s[k-i-1+k*j]-'a']++;
            }
            ll max=-1;
            for(ll i=0;i<26;i++)
                if(num[i]>max) max=num[i];
            ans+=2*m-max;
        }
        if(k&1)
        {
            ll num[26];
            memset(num,0,sizeof(num));
            ll i=k/2;
            for(ll j=0;j<m;j++)
            {
                num[s[j*k+i]-'a']++;
            }
            ll max=-1;
            for(ll i=0;i<26;i++)
                if(num[i]>max) max=num[i];
            ans+=m-max;
        }
        cout<<ans<<endl;
    }
}