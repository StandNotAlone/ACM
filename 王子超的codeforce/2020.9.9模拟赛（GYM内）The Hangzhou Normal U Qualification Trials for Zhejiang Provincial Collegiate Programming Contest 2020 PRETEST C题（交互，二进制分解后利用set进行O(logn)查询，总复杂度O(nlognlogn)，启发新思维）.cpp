#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

ll n,lim;
string origin[maxn];
string changed[maxn];
ll num[maxn];
string ans[maxn];
set<string>ST;

void solve(ll x)
{
    vector<ll>ask;
    for(ll i=1;i<=n;i++) if(i&(1ll<<x)) ask.push_back(i);
    cout<<"? "<<ask.size();
    for(ll i=0;i<ask.size();i++)
    {
        cout<<' '<<origin[ask[i]];
    }
    cout<<endl;
    cout.flush();
    string temp;
    for(ll i=0;i<ask.size();i++)
    {
        cin>>temp;
        ST.insert(temp);
    }
    for(ll i=1;i<=n;i++)
    {
        if(ST.find(changed[i])==ST.end()) num[i]=num[i]*2;
        else num[i]=num[i]*2+1;
    }
    ST.clear();
}

int32_t main()
{
    IOS;
    cin>>n;
    for(ll i=1;i<20;i++) if(n&(1ll<<i)) lim=i;
    for(ll i=1;i<=n;i++) cin>>origin[i];
    cout<<"? "<<n;
    for(ll i=1;i<=n;i++) cout<<' '<<origin[i];
    cout<<endl;
    cout.flush();
    for(ll i=1;i<=n;i++) cin>>changed[i];
    for(ll x=lim;x>=0;x--) solve(x);
    for(ll i=1;i<=n;i++) ans[num[i]]=changed[i];
    cout<<"!";
    for(ll i=1;i<=n;i++) cout<<' '<<ans[i];
    cout<<endl;
}
