#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll n;
ll prime[11]={0,2,3,5,7,11,13,17,19,23,29};
ll Max,ans;
ll num[11]={10000000};
ll now=1;

void dfs(int deep)
{
    if(deep==11)
    {
        ll temp=1;
        for(int i=1;i<11;i++) temp*=(num[i]+1);
        if(temp>Max||temp==Max&&now<ans)
        {
            Max=temp;
            ans=now;
        }
    }
    else
    {
        while(now<=n&&num[deep]<=num[deep-1])
        {
            dfs(deep+1);
            now*=prime[deep];
            num[deep]++;
        }
        while(num[deep])
        {
            num[deep]--;
            now/=prime[deep];
        }
    }
}

int32_t main()
{
    IOS;
    cin>>n;
    dfs(1);
    cout<<ans<<endl;
}
