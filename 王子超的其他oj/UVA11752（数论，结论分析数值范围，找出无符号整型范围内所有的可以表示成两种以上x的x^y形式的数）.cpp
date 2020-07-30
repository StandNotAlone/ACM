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
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f //1061109567
#define llINF 9223372036854775807
#define pi 3.141592653589793
#define ll unsigned long long
using namespace std;
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool flag[64];

int main()
{
    //IOS;//使用之后不要混用cin和scanf printf
    unordered_map<ll,bool>M;
    for(int i=4;i<64;i++)
    {
        int j=2;
        for(;j*j<=i;j++)
            if(i%j==0) break;
        if(j*j<=i) flag[i]=1;
    }
    ll lim=((ll)1<<63)-1+((ll)1<<63);
    ll r=sqrt(sqrt(lim));
    vector<ll>ans;
    ans.push_back((ll)1);
    for(ll i=2;i<=r;i++)
    {
        ll temp=i*i;
        for(ll now=3;now<64;now++)
        {
            if(temp<=lim/i)
            {
                temp*=i;
                if(flag[now])
                {
                    if(M.find(temp)==M.end())
                    {
                        ans.push_back(temp);
                        M[temp]=1;
                    }
                }
            }
            else break;
        }
    }
    sort(ans.begin(),ans.end());
    for(ll i=0;i<ans.size();i++)
        printf("%llu\n",ans[i]);
}


