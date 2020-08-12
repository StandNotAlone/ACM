#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e4+7;

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

void sub_big(vector<int>&a,vector<int>b)
{
    int now=0;
    for(;now<b.size();now++)
    {
        a[now]-=b[now];
        if(a[now]<0)
        {
            a[now]+=10;
            a[now+1]--;
        }
    }
    if(a[now]<0)
    {
        a[now]+=10;
        a[now+1]--;
    }
    while(a.size()>1&&a[a.size()-1]==0) a.pop_back();
}

int32_t main()
{
    IOS;
    primes(10000);
    int n,m;
    cin>>n>>m;
    n+=m;
    vector<int>ans1,ans2;
    ans1.push_back(1);
    ans2.push_back(1);
    for(int i=0;i<prime.size();i++)
    {
        int num1=get(n,prime[i])-get(m,prime[i])-get(n-m,prime[i]);
        int num2=get(n,prime[i])-get(m-1,prime[i])-get(n-m+1,prime[i]);
        for(int j=0;j<num1;j++)
            mul_big(ans1,prime[i]);
        for(int j=0;j<num2;j++)
            mul_big(ans2,prime[i]);
    }
    sub_big(ans1,ans2);
    for(int i=(int)ans1.size()-1;i>=0;i--) cout<<ans1[i];
    cout<<endl;
}
