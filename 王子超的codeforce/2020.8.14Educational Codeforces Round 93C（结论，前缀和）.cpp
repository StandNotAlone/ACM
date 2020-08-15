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
        ll n;
        string s;
        cin>>n>>s;
        unordered_map<ll,ll>M;//M[x]=y代表,满足前i个数字的前缀和减去个数i等于x的有多少个i
        M[0]=1;
        ll now=0,ans=0;
        for(int i=0;i<n;i++)
        {
            now+=s[i]-'0';
            if(M.find(now-i-1)==M.end()) M[now-i-1]=1;
            else
            {
                ans+=M[now-i-1];//最终答案加上前面已经出现过的对数
                M[now-i-1]++;
            }
        }
        cout<<ans<<endl;
    }
}
