#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e5+7;

ll a[maxn];

bool cmp(ll a,ll b)
{
    return a>b;
}

int main()
{
    IOS
    int t;cin>>t;
    while(t--)
    {
        ll n,m;cin>>n>>m;
        ll sum=0;//sum为所有任务占用的内存综合
        deque<ll>x,y;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        for(int i=1;i<=n;i++)
        {
            int f;
            cin>>f;
            if(f==1) x.push_back(a[i]);//x保存普通app的内存占用值
            else y.push_back(a[i]);//y保存重要app的内存占用值
        }
        sort(x.begin(),x.end(),cmp);
        sort(y.begin(),y.end(),cmp);
        x.push_front(0);
        y.push_front(0);
        for(int i=1;i<x.size();i++) x[i]+=x[i-1];//前缀和后，x[i]代表清理i个普通app，最多可以清理出的内存
        for(int i=1;i<y.size();i++) y[i]+=y[i-1];
        if(sum<m) cout<<-1<<endl;
        else
        {
            int ans=INF;
            int tar=0;//标记重要app最少要释放几个
            for(int i=x.size()-1;i>=0;i--)//i代表普通app选几个
            {
                while(tar<y.size()&&y[tar]+x[i]<m) tar++;//普通app选的越少，重要app对应要选的越多
                if(tar<y.size()) ans=min(ans,tar*2+i);
            }
            cout<<ans<<endl;
        }
    }
}
