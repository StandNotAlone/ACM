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
        vector<ll>num(n);
        ll Max=-1;
        for(auto &x:num)
        {
            cin>>x;
            Max=max(Max,x);
        }
        ll ans=0;
        ll x1=-1,y1=-1,x2=-1,y2=-1;
        if(Max*2<n) cout<<0<<endl;
        else
        {
            vector<int>flag(n+1,0);
            ll sum1=0,sum2=0;
            for(ll i=0;i<Max;i++)
            {
                if(!flag[num[i]])
                {
                    sum1++;
                    flag[num[i]]=1;
                }
                else break;
            }
            if(sum1==Max)
            {
                for(auto &x:flag) x=0;
                for(ll i=Max;i<n;i++)
                {
                    if(!flag[num[i]]&&num[i]<=n-Max)
                    {
                        sum2++;
                        flag[num[i]]=1;
                    }
                    else break;
                }
            }
            if(sum1==Max&&sum2==n-Max)
            {
                ans++;
                x1=Max;
                y1=n-Max;
            }

            for(auto &x:flag) x=0;
            sum1=0;sum2=0;
            for(ll i=0;i<n-Max;i++)
            {
                if(!flag[num[i]]&&num[i]<=n-Max)
                {
                    sum1++;
                    flag[num[i]]=1;
                }
                else break;
            }
            if(sum1==n-Max)
            {
                for(auto &x:flag) x=0;
                for(ll i=n-Max;i<n;i++)
                {
                    if(!flag[num[i]])
                    {
                        sum2++;
                        flag[num[i]]=1;
                    }
                    else break;
                }
            }
            if(sum1==n-Max&&sum2==Max)
            {
                ans++;
                x2=n-Max;
                y2=Max;
            }
            if(x1==x2&&y1==y2&&ans) ans--;
            cout<<ans<<endl;
            if(x1!=-1) cout<<x1<<' '<<y1<<endl;
            if(x1==x2&&y1==y2);
            else if(x2!=-1) cout<<x2<<' '<<y2<<endl;
        }
    }
}

 