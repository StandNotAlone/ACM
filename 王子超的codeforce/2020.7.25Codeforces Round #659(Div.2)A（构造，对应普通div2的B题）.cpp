#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

char next(char in)
{
    return 'a'+(in-'a'+1)%26;
}

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>num(n);//num[i]表示字符串i和字符串i+1的最长公共前缀的长度
        for(auto &x:num) cin>>x;
        vector<string>s(n+1);
        for(ll i=0;i<=num[0];i++) s[0]+='a';
        for(ll i=1;i<n;i++)
        {
            ll len=max(num[i-1],num[i])+1;
            //字符串s[i]的长度，需要满足不小于num[i-1]和num[i-2]这两个长度，且长度不能为0因此+1
            for(ll j=0;j<num[i-1];j++)  
            //num[i-1]为字符串s[i-1]和字符串s[i]前缀公共的部分，直接复制过来
                s[i]+=s[i-1][j];
            if(num[i-1]<s[i-1].size()) s[i]+=next(s[i-1][num[i-1]]);
            //检验下一个与字符串s[i-1]不匹配的位置字符串s[i-1]是否存在字符
            //如果存在就使用那个字符对应字母表里的下一个字母替换
            while(s[i].size()<len) s[i]+='a';//后面部分随意补
        }
        for(ll i=0;i<num[n-1];i++)
            s[n]+=s[n-1][i];
        s[n]+=next(s[n-1][num[n-1]]);
        for(ll i=0;i<=n;i++) cout<<s[i]<<endl;
    }
}