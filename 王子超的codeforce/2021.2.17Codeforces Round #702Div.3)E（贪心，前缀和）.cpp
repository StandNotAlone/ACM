#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e5+7;
const double eps=1e-6;
const int mod=1e9+7;

ll num[maxn],chuli[maxn],sum[maxn];

int main()
{
    IOS
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>num[i];
            chuli[i]=num[i];
        }
        sort(chuli+1,chuli+n+1);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+chuli[i];//sum为前缀和数组
        ll bas=chuli[n];//bas记录有可能获胜的人的初始代币最少为多少
        for(int i=n-1;i>=1;i--)
        {
            if(sum[i]<chuli[i+1]) break;//如果当前这个人把不比他大的所有人都赢了，此时他已经是剩下的人当中最少的人了
            //但是他如果赢不了其他人当中最小的那个，那他就没有获胜的希望
            bas=chuli[i];
        }
        vector<int>out;
        for(int i=1;i<=n;i++)
            if(num[i]>=bas) out.push_back(i);
        cout<<out.size()<<endl;
        for(int i=0;i<out.size();i++) cout<<out[i]<<' ';
        cout<<endl;
    }
}
