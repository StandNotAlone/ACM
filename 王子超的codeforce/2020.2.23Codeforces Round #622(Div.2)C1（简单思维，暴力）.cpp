#include<algorithm>
#include<iostream>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#include<set>
//#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
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
const int maxn=INF;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<ll>m(n);
    for(auto &x:m)
    {
        cin>>x;
    }
    vector<ll>num[n];
    for(auto &x:num)
        x.resize(n);
    ll ans=-INF,flag;
    for(ll i=0;i<n;i++)
    {
        num[i][i]=m[i];
        ll sum=m[i];
        ll now=m[i];
        for(ll j=i-1;j>=0;j--)
        {
            now=min(now,m[j]);
            num[i][j]=now;
            sum+=now;
        }
        now=m[i];
        for(ll j=i+1;j<n;j++)
        {
            now=min(now,m[j]);
            num[i][j]=now;
            sum+=now;
        }
        if(sum>ans)
        {
            ans=sum;
            flag=i;
        }
    }
    for(ll i=0;i<n;i++)
    {
        if(i) cout<<' ';
        cout<<num[flag][i];
    }
    cout<<endl;
}



