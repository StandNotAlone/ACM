#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=30+7;

ll cas[20];

int main()
{
    cas[1]=1;
    for(int i=2;i<=15;i++) cas[i]=cas[i-1]*2;
    for(int i=2;i<=15;i++) cas[i]+=cas[i-1];
    int t;scanf("%d",&t);
    while(t--)
    {
        ll n;scanf("%lld",&n);
        bool flag=0;
        for(int i=2;i<=15;i++) if(n%cas[i]==0) flag=1;
        if(flag) printf("YE5\n");
        else printf("N0\n");
    }
}
