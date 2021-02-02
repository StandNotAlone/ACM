#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=3e6+7;

ll cas[maxn];
ll dis=1;

int main()
{
    for(int i=1;i<maxn;i++)
    {
        if(cas[i]!=-1)
        {
            cas[i]=i+dis;
            if(i+dis<maxn) cas[i+dis]=-1;
            dis++;
        }
    }
    int t;scanf("%d",&t);
    while(t--)
    {
        ll n,x;scanf("%lld%lld",&n,&x);
        ll a=x-1,b=n-x;
        if(a>b) swap(a,b);
        if(cas[a]==-1||cas[a]!=b) printf("yo xi no forever!\n");
        else printf("ma la se mi no.1!\n");
    }
}
