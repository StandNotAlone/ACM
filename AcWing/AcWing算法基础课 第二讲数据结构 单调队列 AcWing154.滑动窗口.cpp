#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
struct Node
{
    ll data;
    int tar;
};

int32_t main()
{
    IOS;
    int n,k;
    cin>>n>>k;
    deque<Node>low,high;
    vector<ll>ans1,ans2;
    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        while(low.size()&&i-low.front().tar+1>k) low.pop_front();
        while(high.size()&&i-high.front().tar+1>k) high.pop_front();
        while(low.size()&&low[low.size()-1].data>=x) low.pop_back();
        while(high.size()&&high[high.size()-1].data<=x) high.pop_back();
        low.push_back({x,i});
        high.push_back({x,i});
        if(i>=k) ans1.push_back(low.front().data);
        if(i>=k) ans2.push_back(high.front().data);
    }
    for(int i=0;i<ans1.size();i++)
    {
        if(i) cout<<' ';
        cout<<ans1[i];
    }
    cout<<endl;
    for(int i=0;i<ans2.size();i++)
    {
        if(i) cout<<' ';
        cout<<ans2[i];
    }
    cout<<endl;
}
