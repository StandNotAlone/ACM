#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main()
{
    //IOS;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        ll n;
        scanf("%lld",&n);
        vector<ll>num;
        for(ll i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                num.push_back(i);
                if(i*i!=n) num.push_back(n/i);
            }
        }
        sort(num.begin(),num.end());
        for(ll i=0;i<num.size();i++)
        {
            if(i) printf(" ");
            printf("%lld",num[i]);
        }
        printf("\n");
    }
}
