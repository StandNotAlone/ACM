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
    ll t,n;
    ll a[110];
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll sum=0,ans=0;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==0)
            {
                a[i]++;
                ans++;
            }
            sum+=a[i];
        }
        if(sum==0) ans++;
        cout<<ans<<endl;
    }
}



