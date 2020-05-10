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
    ll n,a[100010];
    ll flag[50][2];
    memset(flag,0,sizeof(flag));
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        ll x=a[i],cas=0;
        while(x)
        {
            if(x&1)
            {
                flag[cas][0]++;
                flag[cas][1]=i;
            }
            x>>=1;
            cas++;
        }
    }
    //flag[0][0];
    ll cas;
    for(cas=49;cas>=0;cas--)
        if(flag[cas][0]==1) break;
    if(cas>=0)
    {
        cout<<a[flag[cas][1]];
        for(ll i=0;i<n;i++)
            if(i!=flag[cas][1]) cout<<' '<<a[i];
        cout<<endl;
    }
    else
    {
        for(ll i=0;i<n;i++)
        {
            if(i) cout<<' ';
            cout<<a[i];
        }
        cout<<endl;
    }
}



