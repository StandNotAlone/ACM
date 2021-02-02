#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;
const int mod=998244353;

ll num[maxn];

int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        ll sum=0;
        int n;
        ll k;
        scanf("%d%lld",&n,&k);
        ll M=0;
        int tar=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&num[i]);
            if(num[i]>M)
            {
                tar=i;
                M=num[i];
            }
            num[i]+=num[i-1];
        }
        ll yici=M+n-1;
        if(k<tar-1) printf("NO\n");
        else
        {
            ll rest=(k-tar+1)%(yici);
            ll cas=(k-tar+1)/yici;
            cas*=(num[n]-M);
            cas+=num[tar-1]-tar+1;
            if(cas>=rest) printf("YES\n");
            else printf("NO\n");
        }
    }
}
