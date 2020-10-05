#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e4+7;

ll num[maxn];
ll n,sum;

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>n;
        for(ll i=1;i<=n;i++) {cin>>num[i];sum+=num[i];}
        if(sum%n) cout<<-1<<endl;
        else
        {
            sum/=n;
            cout<<3*(n-1)<<endl;
            for(ll i=2;i<=n;i++)
            {
                ll temp=i-num[i]%i;
                if(temp==i) temp=0;
                cout<<1<<' '<<i<<' '<<temp<<endl;
                num[1]-=temp;
                num[i]+=temp;
                cout<<i<<' '<<1<<' '<<num[i]/i<<endl;
                num[1]+=num[i];
            }
            for(ll i=2;i<=n;i++) cout<<1<<' '<<i<<' '<<sum<<endl;
        }
    }
}
