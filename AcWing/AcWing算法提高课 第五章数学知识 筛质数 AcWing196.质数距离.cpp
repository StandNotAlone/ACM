#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<int>prime;
bool v[100007];
void primes(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!v[i])
        {
            v[i]=1;
            prime.push_back(i);
        }
        for(int j=0;prime[j]<=n/i;j++)
        {
            v[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}

bool flag[1000007];

int32_t main()
{
    IOS;
    primes(100000);
    ll l,r;
    while(cin>>l>>r)
    {
        ll lim=r-l;
        for(int i=0;i<=lim;i++) flag[i]=1;
        for(int i=0;prime[i]<=r/prime[i];i++)
        {
            ll now=l/prime[i];
            if(l%prime[i]) now++;
            if(now==1) now++;
            while(now*prime[i]<=r)
            {
                flag[prime[i]*now-l]=0;
                now++;
            }
        }
        if(l==1) flag[0]=0;
        vector<int>ans;
        for(int i=0;i<=lim;i++)
            if(flag[i]) ans.push_back(i);
        if(ans.size()<2) cout<<"There are no adjacent primes."<<endl;
        else
        {
            int tar1=0,tar2=0;
            for(int i=1;i+1<ans.size();i++)
            {
                if(ans[i+1]-ans[i]<ans[tar1+1]-ans[tar1]) tar1=i;
                if(ans[i+1]-ans[i]>ans[tar2+1]-ans[tar2]) tar2=i;
            }
            cout<<l+ans[tar1]<<','<<l+ans[tar1+1]<<" are closest, ";
            cout<<l+ans[tar2]<<','<<l+ans[tar2+1]<<" are most distant."<<endl;
        }
    }
}
