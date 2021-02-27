#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e5+7;
const double eps=1e-6;
const int mod=1e9+7;

map<int,int>M;

ll cishu[maxn];//cishu[i]记录出现了i次的数字有多少种
ll sumcishu[maxn];//sumcishu为cishu数组的前缀和，记录出现了不超过i次的数字有多少种
ll num[maxn];//num[i]记录出现了i次数字，他们总共出现了几次
ll sumnum[maxn];//sunnum为num数组的前缀和，记录出现了不超过i次的数字，他们总共出现了几次

int main()
{
    IOS
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        ll ans=llINF;

        for(int i=0;i<n;i++)
        {
            int x;cin>>x;
            if(M.find(x)==M.end()) M[x]=1;
            else M[x]++;
        }
        for(auto &x:M)
        {
            cishu[x.second]++;
            num[x.second]+=x.second;
        }

        for(int i=1;i<=n;i++)
        {
            sumcishu[i]=sumcishu[i-1]+cishu[i];
            sumnum[i]=sumnum[i-1]+num[i];
        }

        for(int i=1;i<=n;i++)//i为我们最后希望数组中剩下的数字，每个数字出现多少次
        {
            ll temp=0;
            temp+=n-sumnum[i]-(sumcishu[n]-sumcishu[i])*i;//对于一开始出现次数大于i次的，我们要把他们减少到i次
            //sumcishu[n]-sumcishu[i]即为有多少种数字一开始出现次数是大于i次的，他们最后都要变为出现i次，总次数就乘以i
            //用n-sumnum[i]即为一开始出现次数大于i次的总共出现了几次，减去目标的总次数即为需要删掉的个数
            temp+=sumnum[i-1];//出现次数小于i的所有数字都要被删掉
            ans=min(ans,temp);
        }

        cout<<ans<<endl;

        for(int i=1;i<=n;i++) cishu[i]=sumcishu[i]=num[i]=sumnum[i]=0;
        M.clear();
    }
}
