#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define llINF 9223372036854775807
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
        ll len=s.size();
        ll ans=llINF;
        for(ll i=0;i<10;i++)
            for(ll j=0;j<10;j++)
            {
                ll temp=0,tar=0;//tar为当前位置下标，tamp为删除了几个字符
                while(tar<len)
                {
                    while(tar<len&&s[tar]-'0'!=i) tar++,temp++;
                    tar++;
                    while(tar<len&&s[tar]-'0'!=j) tar++,temp++;
                    tar++;
                }
                if(i!=j&&((len-temp)&1)) temp++;//当奇数和偶数下标的字符不相同，且最后得到的字符串长度是奇数的时候，要再多删掉一个字符把字符串变成偶数长度
                ans=min(ans,temp);
            }
        cout<<ans<<endl;
    }
}

