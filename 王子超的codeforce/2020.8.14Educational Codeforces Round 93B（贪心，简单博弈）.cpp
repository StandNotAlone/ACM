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
        string s;
        cin>>s;
        vector<ll>num;//记录字符串中各段连续的1的长度
        ll len=s.size();
        for(ll i=0;i<len;i++)
        {
            if(s[i]=='1')
            {
                ll now=0;//当前扫到的连续1的长度
                while(i<len&&s[i]=='1') now++,i++;
                num.push_back(now);
            }
        }
        sort(num.begin(),num.end());
        ll ans=0;
        for(ll i=(ll)num.size()-1;i>=0;i-=2) ans+=num[i];//先手从大到小取依次取第1,3,5,7...个
        cout<<ans<<endl;
    }
}
