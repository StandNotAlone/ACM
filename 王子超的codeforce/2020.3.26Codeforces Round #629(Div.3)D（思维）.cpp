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
    ll q;
    cin>>q;
    while(q--)
    {
        ll n;
        cin>>n;
        vector<ll>num(n);
        for(auto &x:num) cin>>x;
        ll flag=-1,f=1;
        for(ll i=1;i<n;i++)
        {
            if(num[i]==num[i-1]) flag=i;
            else f=0;
        }
        if(num[n-1]==num[0]) flag=0;
        if(f)
        {
            cout<<1<<endl;
            for(ll i=0;i<n;i++)
            {
                if(i) cout<<' ';
                cout<<1;
            }
            cout<<endl;
        }
        else if(n%2==0)
        {
            cout<<2<<endl;
            for(ll i=0;i<n;i++)
            {
                if(i) cout<<' ';
                cout<<i%2+1;
            }
            cout<<endl;
        }
        else
        {
            if(flag==-1)
            {
                cout<<3<<endl;
                for(ll i=0;i<n-1;i++)
                {
                    if(i) cout<<' ';
                    cout<<i%2+1;
                }
                cout<<' '<<3<<endl;
            }
            else
            {
                num[0]=0;
                cout<<2<<endl<<1;
                for(ll i=1;i<n;i++)
                {
                    if(flag==0&&i==n-1) num[i]=num[0];
                    else if(i!=flag) num[i]=!num[i-1];
                    else num[i]=num[i-1];
                    cout<<' '<<num[i]+1;
                }
                cout<<endl;
            }
        }
    }
}


