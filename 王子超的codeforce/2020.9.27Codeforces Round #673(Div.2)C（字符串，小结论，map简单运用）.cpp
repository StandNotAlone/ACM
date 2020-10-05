#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int,pair<int,int>>M;//M[i]=pair{j,k},代表值为i的数字最后出现在下标j的位置，值为i的数字之间的最大间隔为k
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            if(M.find(x)==M.end()) M[x]=make_pair(i,i);
            else
            {
                M[x].second=max(M[x].second,i-M[x].first);
                M[x].first=i;
            }
        }
        vector<int>ans(n+1,INF);
        for(auto &x:M)
        {
            x.second.second=max(x.second.second,n+1-x.second.first);
            ans[x.second.second]=min(ans[x.second.second],x.first);
        }
        int now=INF;
        for(int i=1;i<=n;i++)
        {
            now=min(now,ans[i]);
            if(now==INF) cout<<-1<<' ';
            else cout<<now<<' ';
        }
        cout<<endl;
    }
}
