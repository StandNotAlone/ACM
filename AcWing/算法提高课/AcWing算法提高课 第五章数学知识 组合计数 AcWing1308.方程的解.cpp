#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int k,x;

vector<int>prime;
bool v[1007];
int num[1007];

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

int qpow(int a,int p)
{
    int ret=1;
    while(p)
    {
        if(p&1) ret=ret*a%1000;
        a=a*a%1000;
        p>>=1;
    }
    return ret;
}

vector<int> mul_big(vector<int>a,int b)
{
    int rest=0;
    for(int i=0;i<a.size();i++)
    {
        a[i]=a[i]*b+rest;
        rest=a[i]/10;
        a[i]%=10;
    }
    while(rest) a.push_back(rest%10),rest/=10;
    return a;
}

int32_t main()
{
    IOS;
    primes(1000);
    cin>>k>>x;
    x=qpow(x%1000,x);
    if(k>x) cout<<0<<endl;
    else
    {
        vector<int>a;
        a.push_back(1);
        for(int i=1;i<k;i++)
        {
            int temp=i;
            for(int j=0;j<prime.size();j++)
                while(temp%prime[j]==0) temp/=prime[j],num[j]--;
            temp=x-i;
            for(int j=0;j<prime.size();j++)
                while(temp%prime[j]==0) temp/=prime[j],num[j]++;
        }
        for(int i=0;i<prime.size();i++)
            for(int j=0;j<num[i];j++)
                a=mul_big(a,prime[i]);
        for(int i=(int)a.size()-1;i>=0;i--)
            cout<<a[i];
        cout<<endl;
    }
}
