#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int now=-1,cas=0;//cas记录整个数列中有几个不同的数
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(x!=now) cas++;
            now=x;
        }
        if(k==1)
        {
            if(cas>1) cout<<-1<<endl;
            else cout<<1<<endl;
        }
        else
        {
            int ans=1;//第一次可以消除k个不同的数字为0
            if(cas>k) ans+=(cas/*-k+k*/-2)/(k-1);//之后每次消除k-1个不同的数字为0了，此时计算(ans-k)/(k-1)向上取整的结果
            cout<<ans<<endl;
        }
    }
}
