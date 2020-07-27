#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<functional>
//#include<bits/stdc++.h>
#define INF 0x3f3f3f3f //1061109567
#define llINF 9223372036854775807
#define pi 3.141592653589793
#define ll long long
using namespace std;
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll flag[maxn];

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        memset(flag,0,sizeof(flag));
        cin>>n>>m;
        for(ll i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            flag[x]++;
        }
        ll tar=-1;
        for(ll i=0;i<m;i++)
        {
            ll x;
            cin>>x;
            if(flag[x]) tar=x;
        }
        if(tar==-1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl<<1<<' '<<tar<<endl;
    }
}


