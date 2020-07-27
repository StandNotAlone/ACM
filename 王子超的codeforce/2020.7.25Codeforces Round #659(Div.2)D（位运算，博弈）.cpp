#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll num[30];

int32_t main()
{
    IOS;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        for(ll i=0;i<n;i++)
        {
            ll a;
            scanf("%lld",&a);
            ll temp=1;
            for(ll j=0;j<30;j++)
            {
                if(temp&a) num[j]++;
                temp<<=1;
            }
        }
        int f=0;
        for(ll i=29;i>=0;i--)
            if(num[i]&1)
            {
                if(num[i]/2&1)
                {
                    if((n-num[i])&1) f=1;
                    else f=-1;
                }
                else f=1;
                break;
            }
        if(f==1) printf("WIN\n");
        else if(f==0) printf("DRAW\n");
        else printf("LOSE\n");
    }
}
