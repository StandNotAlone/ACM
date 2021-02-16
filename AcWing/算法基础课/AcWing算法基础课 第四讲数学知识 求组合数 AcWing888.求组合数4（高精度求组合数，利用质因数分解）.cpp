#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=5e3+7;

vector<int>prime;
bool v[maxn];

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

vector<int>ans;

void mul_big(vector<int>&a,int b)
{
    int rest=0;
    for(int i=0;i<a.size();i++)
    {
        rest=rest+b*a[i];
        a[i]=rest%10;
        rest/=10;
    }
    while(rest)
    {
        a.push_back(rest%10);
        rest/=10;
    }
}

int get(int n,int p)
{
    int ret=0;
    while(n)
    {
        ret+=n/p;
        n/=p;
    }
    return ret;
}

int32_t main()
{
    IOS;
    primes(5000);
    int a,b;
    cin>>a>>b;
    ans.push_back(1);
    for(int i=0;i<prime.size();i++)
    {
        int num=get(a,prime[i])-get(b,prime[i])-get(a-b,prime[i]);
        for(int j=0;j<num;j++)
            mul_big(ans,prime[i]);
    }
    for(int i=(int)ans.size()-1;i>=0;i--) cout<<ans[i];
    cout<<endl;
}
