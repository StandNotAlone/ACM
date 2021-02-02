#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=30+7;
const int mod=998244353;

int n,m;
int field[307][307];
bool flag[307];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b,w;scanf("%d%d%d",&a,&b,&w);
        if(field[a][b]==0) field[a][b]=field[b][a]=w;
        else field[a][b]=field[b][a]=min(field[a][b],w);
    }
    ll ans=llINF;
    int k;scanf("%d",&k);
    while(k--)
    {
        for(int i=1;i<=n;i++) flag[i]=0;
        int cnt=0;
        ll sum=0;
        bool f=1;
        int x;scanf("%d",&x);
        int now=0;
        while(x--)
        {
            int to;scanf("%d",&to);
            if(field[now][to]==0) f=0;
            sum+=field[now][to];
            now=to;
            if(flag[to]==0) {flag[to]=1;cnt++;}
        }
        if(field[now][0]==0||cnt!=n) f=0;
        sum+=field[now][0];
        if(f) ans=min(ans,sum);

    }
    if(ans==llINF) printf("-1\n");
    else printf("%lld\n",ans);
}
