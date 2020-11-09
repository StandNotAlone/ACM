#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

vector<ll>origin;

ll find(ll x)
{
    return lower_bound(origin.begin(),origin.end(),x)-origin.begin();
}

int n,m;
ll add[maxn],num[maxn],l[maxn],r[maxn];
ll sum[maxn*3];

int32_t main()
{
    IOS
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>add[i]>>num[i];
        origin.push_back(add[i]);
    }
    for(int i=0;i<m;i++)
    {
        cin>>l[i]>>r[i];
        origin.push_back(l[i]);
        origin.push_back(r[i]);
    }
    sort(origin.begin(),origin.end());
    origin.erase(unique(origin.begin(),origin.end()),origin.end());
    ll lim=origin.size()+1;
    for(int i=0;i<n;i++) sum[find(add[i])]+=num[i];
    for(int i=1;i<=lim;i++) sum[i]+=sum[i-1];
    for(int i=0;i<m;i++) cout<<sum[find(r[i])]-sum[find(l[i])-1]<<endl;
}
