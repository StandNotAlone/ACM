#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    IOS
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int num[107];
        int ans=0;
        int cas=0;//cas保存到当前位置位置，当前这个数出现了几次
        for(int i=0;i<n;i++)
        {
            cin>>num[i];
            if(i&&num[i]==num[i-1]) cas++;
            else cas=1;
            ans=max(ans,cas);
        }
        cout<<ans<<endl;
    }
}
