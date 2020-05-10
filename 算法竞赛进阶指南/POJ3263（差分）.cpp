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
    ll n,i,h,r;
    cin>>n>>i>>h>>r;
    vector<ll>cas(n,0);
    map<pair<ll,ll>,bool>M;
    while(r--)
    {
        ll a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        if(M.find({a,b})==M.end())
        {
            M[{a,b}]=1;
            cas[a]--;
            cas[b-1]++;
        }
    }
    for(ll i=1;i<n;i++) cas[i]+=cas[i-1];
    for(auto &x:cas)
    {
        cout<<x+h<<endl;
    }
}


