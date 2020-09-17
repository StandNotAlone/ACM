#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=2e5+7;

ll num[maxn];
ll n;

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(ll i=0;i<n;i++) cin>>num[i];
        ll ans=0;
        if(num[0]) ans++;//由于朋友是先手，因此第一个boss如果就是困难的那就必须要使用一次道具
        ll temp=0;
        for(ll i=1;i<n;i++)
        {
            while(i<n&&num[i]==1)//统计连续的困难boss有多少个
            {
                temp++;
                i++;
            }
            ans+=temp/3;//除3加到答案上并置零
            temp=0;
        }
        cout<<ans<<endl;
    }
}
