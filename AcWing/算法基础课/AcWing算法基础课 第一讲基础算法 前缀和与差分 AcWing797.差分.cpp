#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

int n,m,l,r,c;
ll num[maxn];

int32_t main()
{
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=n;i>1;i--) num[i]-=num[i-1];
    while(m--)
    {
        cin>>l>>r>>c;
        num[l]+=c;
        num[r+1]-=c;
    }
    for(int i=1;i<=n;i++)
    {
        if(i>1) cout<<' ';
        num[i]+=num[i-1];
        cout<<num[i];
    }
    cout<<endl;
}
