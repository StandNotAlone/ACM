#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

int n,m;
int l,r;
ll num[maxn];

int32_t main()
{
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {cin>>num[i];num[i]+=num[i-1];}
    while(m--)
    {
        cin>>l>>r;
        cout<<num[r]-num[l-1]<<endl;
    }
}
