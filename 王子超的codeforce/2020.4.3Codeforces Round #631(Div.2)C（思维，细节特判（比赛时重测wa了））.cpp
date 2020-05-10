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
    ll n,m;
    cin>>n>>m;
    ll sum=0;
    vector<ll>num(m);
    for(auto &x:num)
    {
        cin>>x;
        sum+=x;
    }
    if(sum<n) cout<<-1<<endl;
    else
    {
        ll now=0;
        bool flag=1;
        vector<ll>ans;
        for(ll i=0;i<m;i++)
        {
            if(now+sum-num[i]+1>=n)
            {
                if(now+num[i]>n)
                {
                    flag=0;
                    break;
                }
                ans.pb(++now);
                sum-=num[i];
            }
            else
            {
                if(now+num[i]>n)
                {
                    flag=0;
                    break;
                }
                if(n-sum+1<=now)
                {
                    ans.pb(++now);
                }
                else
                {
                    ans.pb(n-sum+1);
                    now=n-sum+1;
                }
                sum-=num[i];
            }
        }
        if(flag)
        {
            for(ll i=0;i<ans.size();i++)
            {
                if(i) cout<<' ';
                cout<<ans[i];
            }
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
}

 