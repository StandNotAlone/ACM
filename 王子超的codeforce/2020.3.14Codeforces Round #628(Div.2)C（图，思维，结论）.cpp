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
    ll n;
    cin>>n;
    ll flag[100010];
    memset(flag,0,sizeof(flag));
    ll num[100010][2];
    for(ll i=0;i<n-1;i++)
    {
        cin>>num[i][0]>>num[i][1];
        flag[num[i][0]]++;
        flag[num[i][1]]++;
    }
    map<ll,ll>M;
    for(ll i=1;i<=n;i++)
    {
        if(flag[i]==1) M[i]=1;
    }
    ll min=0,Min=(ll)M.size();
    for(ll i=0;i<n-1;i++)
    {
        if(M.find(num[i][0])!=M.end()||M.find(num[i][1])!=M.end())
        {
            cout<<min++<<endl;
        }
        else cout<<Min++<<endl;
    }
}

 