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
    ll n,m;
    scanf("%lld%lld",&n,&m);
    string s;
    cin>>s;
    mat ans;
    ll max=0;
    while(1)
    {
        vec now;
        for(ll i=0;i+1<n;i++)
        {
            if(s[i]=='R'&&s[i+1]=='L')
            {
                s[i]='L';
                s[i+1]='R';
                now.pb((i++)+1);
            }
        }
        if(now.size())
        {
            max+=now.size();
            ans.pb(now);
            now.clear();
        }
        else break;
    }
    if(m<ans.size()||m>max) printf("-1\n");
    else
    {
        ll r=0,c=0;
        for(ll i=0;i<m-(ll)ans.size();i++)
        {
            while(c+1>=ans[r].size())
            {
                printf("1 %lld\n",ans[r][c]);
                r++;
                c=0;
            }
            printf("1 %lld\n",ans[r][c++]);
        }
        for(;r<(ll)ans.size();r++)
        {
            cout<<(ll)ans[r].size()-c;
            for(;c<ans[r].size();c++) printf(" %lld",ans[r][c]);
            printf("\n");
            c=0;
        }
    }
}


