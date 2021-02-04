#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=4e6+7;
const ll mod=1e9+7;

int n;
ll ans[maxn];
bool v[maxn];

int main()
{
    scanf("%d",&n);
    ll out=0;
    for(int i=2;i<=n;i++)
    {
        if(!v[i])
        {
            ll cas=1;ll I=i;
            while(I)
            {
                I/=10;
                cas=cas*10%mod;
            }
            for(int j=i;j<maxn;j+=i)
            {
                v[j]=1;
                ll temp=j;
                while(temp%i==0)
                {
                    ans[j]=(ans[j]*cas+i)%mod;
                    temp/=i;
                }
            }
        }
        out=(out+ans[i])%mod;
    }
    printf("%lld\n",out);
}
