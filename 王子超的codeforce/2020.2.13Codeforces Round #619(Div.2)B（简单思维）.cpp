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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll Max=-1,Min=1e9+7,ans=0;
        vec num(n);
        for(auto &x:num)
            cin>>x;
        for(ll i=0;i<n;i++)
        {
            if(num[i]>=0)
            {
                if(i==0)
                {
                    if(num[i+1]>=0)
                    {
                        ans=max(ans,abs(num[i]-num[i+1]));
                    }
                    else
                    {
                        Min=min(Min,num[i]);
                        Max=max(Max,num[i]);
                    }
                }
                else if(i==n-1)
                {
                    if(num[i-1]>=0)
                    {
                        ans=max(ans,abs(num[i]-num[i-1]));
                    }
                    else
                    {
                        Min=min(Min,num[i]);
                        Max=max(Max,num[i]);
                    }
                }
                else
                {
                    if(num[i+1]>=0)
                    {
                        ans=max(ans,abs(num[i]-num[i+1]));
                    }
                    else
                    {
                        Min=min(Min,num[i]);
                        Max=max(Max,num[i]);
                    }
                    if(num[i-1]>=0)
                    {
                        ans=max(ans,abs(num[i]-num[i-1]));
                    }
                    else
                    {
                        Min=min(Min,num[i]);
                        Max=max(Max,num[i]);
                    }
                }
            }
        }
        if(Max==-1) cout<<0<<' '<<0<<endl;
        else
        {
            ll t=(Min+Max)/2;
            ans=max(ans,max(abs(Min-t),abs(Max-t)));
            cout<<ans<<' '<<t<<endl;
        }
    }
}



