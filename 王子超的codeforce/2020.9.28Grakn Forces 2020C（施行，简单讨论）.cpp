#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

double timea[maxn],timeb[maxn];//timea记录左边的汽车开到每个点要用的时间，timeb记录右边汽车的
int dis[maxn];

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n>>dis[n+1];
        for(int i=1;i<=n;i++) cin>>dis[i];
        timea[0]=timeb[n+1]=0;
        for(int i=1;i<=n+1;i++)
        {
            timea[i]=timea[i-1]+(dis[i]-dis[i-1])/(double)i;
        }
        int tar;
        for(tar=n;1;tar--)//tar记录在dis[tar]到dis[tar+1]之间辆车相遇，时间点满足timea[tar]<=timeb[tar]
        {
            timeb[tar]=timeb[tar+1]+(dis[tar+1]-dis[tar])/(double)(n+1-tar);
            if(timeb[tar]>=timea[tar]) break;
        }
        if(timea[tar]>timeb[tar+1])//分两种情况分类讨论计算，步骤分开写了方便理解
        {
            double ans=timea[tar];
            double d=dis[tar+1]-dis[tar]-(timea[tar]-timeb[tar+1])*(n+1-tar);
            ans+=d/(tar+1+n+1-tar);
            cout<<fixed<<setprecision(10)<<ans<<endl;
        }
        else
        {
            double ans=timeb[tar+1];
            double d=dis[tar+1]-dis[tar]-(timeb[tar+1]-timea[tar])*(tar+1);
            ans+=d/(tar+1+n+1-tar);
            cout<<fixed<<setprecision(10)<<ans<<endl;
        }
    }
}
