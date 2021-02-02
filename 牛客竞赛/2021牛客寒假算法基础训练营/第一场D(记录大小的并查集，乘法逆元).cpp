#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=25e4+7;
const int mod=1e9+7;

ll qpow(ll a,ll p)
{
    ll ret=1;
    while(p)
    {
        if(p&1) ret=ret*a%mod;
        a=a*a%mod;
        p>>=1;
    }
    return ret;
}

int n;
char field[507][507];
int dir[4][2]=
{
    0,-1,
    -1,0,
    1,0,
    0,1
};
ll ans=1,cas=0;


int fa[maxn],siz[maxn];

int get(int x)
{
    return x==fa[x]?x:fa[x]=get(fa[x]);
}

void merge(int x,int y)
{
    siz[get(y)]+=siz[get(x)];
    fa[get(x)]=get(y);
}

void work(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int tempx=x+dir[i][0],tempy=y+dir[i][1];
        if(tempx>=0&&tempx<n&&tempy>=0&&tempy<n&&field[tempx][tempy]=='1'&&get(x*n+y)!=get(tempx*n+tempy))
        {
            ans=ans*qpow(cas,mod-2)%mod;
            cas--;
            ans=ans*qpow(siz[get(x*n+y)],mod-2)%mod;
            ans=ans*qpow(siz[get(tempx*n+tempy)],mod-2)%mod;
            merge(x*n+y,tempx*n+tempy);
            ans=ans*siz[get(x*n+y)]%mod;
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s",field[i]);
    for(int i=0;i<n*n;i++) {fa[i]=i;siz[i]=1;}

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(field[i][j]=='1')
            {
                cas++;
                ans=ans*cas%mod;
            }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(field[i][j]=='1')
                work(i,j);

    int k;scanf("%d",&k);
    while(k--)
    {
        int x,y;scanf("%d%d",&x,&y);
        if(field[x][y]=='0')
        {
            field[x][y]='1';
            cas++;ans=ans*cas%mod;
            work(x,y);
        }
        printf("%lld\n",ans);
    }
}
