#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=2e5+7;


ll n;
ll a[maxn],b[maxn];
ll ru[maxn];//ru[i]保存结点i的入度

int32_t main()
{
    IOS;
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>a[i];
    for(ll i=1;i<=n;i++)
    {
        cin>>b[i];
        if(b[i]!=-1) ru[b[i]]++;
    }
    ll ans=0;
    queue<ll>Q;
    vector<ll>ans1,ans2;
    for(ll i=1;i<=n;i++)
        if(!ru[i]) Q.push(i);
    while(Q.size())///拓扑排序过程
    {
        ll now=Q.front();
        Q.pop();
        ll to=b[now];
        if(to!=-1)
        {
            ru[to]--;
            if(!ru[to]) Q.push(to);
            if(a[now]>0) a[to]+=a[now];//如果当前结点的值是正数，那么加到下一个对应结点的值上
        }
        ans+=a[now];//入度为0的结点的值加到ans上
        if(a[now]>=0) ans1.push_back(now);
        else ans2.push_back(now);
    }
    cout<<ans<<endl;
    for(ll i=0;i<ans1.size();i++) cout<<ans1[i]<<' ';//正数结点的下标按照拓扑序输出
    ll len=ans2.size();
    for(ll i=0;i<ans2.size();i++) cout<<ans2[len-i-1]<<' ';//负数结点的下标按照拓扑序的逆序输出
    cout<<endl;
}


