#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=30+7;

ll ans,n,k;
ll num[100007];
ll cas[100007];

int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        ans=-1;
        for(int i=1;i<100007;i++) cas[i]=-1;
        scanf("%lld%lld",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&num[i]);
            num[i]=(num[i]+num[i-1])%k;
            if(cas[num[i]]==-1) cas[num[i]]=i;
            else ans=max(ans,i-cas[num[i]]);
        }
        printf("%lld\n",ans);
    }
}