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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t;
    scanf("%lld",&t);
    ll cas=1;
    while(t--)
    {
        ll ans=0;
        ll n,m;
        scanf("%lld%lld",&n,&m);
        vector<ll>A(n);
        for(auto &x:A) scanf("%lld",&x);
        vector<ll>B(m);
        for(auto &x:B) scanf("%lld",&x);
        vector<ll>B1,B2;
        for(ll i=0;i<m;i++)
        {
            ll temp;
            scanf("%lld",&temp);
            if(temp) B2.push_back(B[i]);    //B2为防守状态的怪
            else B1.push_back(B[i]);        //B1位正常状态的怪
        }
        sort(B1.begin(),B1.end());
        sort(B2.begin(),B2.end());
        sort(A.begin(),A.end());
        ll tans=0;
        for(ll i=0;i<B1.size()&&i<n;i++)
        {
            if(B1[i]>A[n-1-i]) break;
            tans+=A[n-1-i]-B1[i];
        }
        ans=max(ans,tans);
        if(n>m)
        {
            vector<int>flag(n,0);
            ll i=0,j=0;
            while(i<n&&j<B2.size())
            {
                while(i<n&&A[i]<B2[j]) i++;
                if(i<n)
                {
                    flag[i++]=1;
                    j++;
                }
            }
            if(j==B2.size())
            {
                tans=0;
                i=0;j=0;
                while(i<n&&j<B1.size())
                {
                    while(i<n&&(A[i]<B1[j]||flag[i])) i++;
                    if(i<n)
                    {
                        tans+=A[i]-B1[j];
                        flag[i++]=1;
                        j++;
                    }
                }
                if(j==B1.size())
                {
                    for(ll i=0;i<n;i++)
                        if(!flag[i]) tans+=A[i];
                    ans=max(ans,tans);
                }
            }
        }
        printf("Case %lld: %lld\n",cas++,ans);
    }
}


