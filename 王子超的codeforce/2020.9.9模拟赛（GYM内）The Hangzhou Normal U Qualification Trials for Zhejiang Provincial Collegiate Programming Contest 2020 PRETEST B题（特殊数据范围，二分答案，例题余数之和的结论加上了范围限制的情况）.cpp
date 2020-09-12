#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll n,m,k;

ll cal(ll x)
{
    ll ret=0;
    ll lim=x/m;
    ret+=lim*m;
    for(ll now=lim+1,next;now<=n;now=next+1)
    {
        next=x/now?min(x/(x/now),n):n;
        ret+=(x/now)*(next-now+1);
    }
    return ret;
}

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        k=n*m-k+1;
        if(n*m>=1e10&&cal(9999999999)<k) cout<<"Oops"<<endl;
        else
        {
            ll l=1,r=min(9999999999ll,n*m);
            while(l<r)
            {
                ll mid=(l+r)>>1;
                if(cal(mid)<k) l=mid+1;
                else r=mid;
            }
            cout<<l<<endl;
        }
    }
}
