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
    ll u,v;
    cin>>u>>v;
    if(u>v) cout<<-1<<endl;
    else if(u==v)
    {
        if(!u) cout<<0<<endl;
        else cout<<1<<endl<<u<<endl;
    }
    else 
    {
        v-=u;
        if(v&1) 
        {
            cout<<-1<<endl;
            return 0;
        }
        v/=2;
        if(v&u) cout<<3<<endl<<u<<' '<<v<<' '<<v<<endl;
        else cout<<2<<endl<<u+v<<' '<<v<<endl;
    }
}


