#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=30+7;

ll ans=0,n;
ll num[100007];
ll cas=0;

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&num[i]);
        if(num[i]>=num[i-1]) cas++;
        else
        {
            ans+=cas*(cas+1)/2;
            cas=1;
        }
    }
    ans+=cas*(cas+1)/2;
    printf("%lld\n",ans);
}
