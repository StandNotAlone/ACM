#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define llINF 9223372036854775807
using namespace std;

ll n;
vector<ll>num;

ll dfs(vector<ll>now)
{
    ll temp=0,len=now.size();
    ll Min=llINF;
    for(ll i=0;i<len;i++)
        Min=min(Min,now[i]);
    vector<ll>next;
    for(ll i=0;i<len;i++)
    {
        if(now[i]==Min)
        {
            if(next.size())
            {
                temp+=dfs(next);
                next.clear();
            }
        }
        else next.push_back(now[i]-Min);
    }
    if(next.size()) temp+=dfs(next);
    return min(len,Min+temp);
}

int32_t main()
{
    IOS;
    cin>>n;
    num.resize(n);
    for(auto &x:num) cin>>x;
    cout<<min(n,dfs(num))<<endl;
}