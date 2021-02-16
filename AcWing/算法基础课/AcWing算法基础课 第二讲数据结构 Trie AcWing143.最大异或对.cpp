#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=3e6+7;

int n;
int num;

//可以改用结构体指针来实现，用时间来换取空间
int trie[maxn][2],ed[maxn];
int tot=0;

void insert(string s)
{
    int len=s.size(),tar=0;
    for(int i=0;i<len;i++)
    {
        int net=s[i]-'0';
        if(trie[tar][net]==0) trie[tar][net]=++tot;
        tar=trie[tar][net];
    }
    ed[tar]++;
}

int cal(string s)
{
    int tar=0,ret=0;
    for(int i=0;i<31;i++)
    {
        bool flag=s[i]-'0';
        if(trie[tar][!flag])
        {
            ret+=(1ll<<(30-i));
            tar=trie[tar][!flag];
        }
        else
        {
            if(!trie[tar][flag]) return 0;
            tar=trie[tar][flag];
        }
    }
    return ret;
}

int32_t main()
{
    IOS;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        string s;
        for(int i=30;i>=0;i--)
        {
            if(x&(1ll<<i)) s.push_back('1');
            else s.push_back('0');
        }
        ans=max(ans,cal(s));
        insert(s);
    }
    cout<<ans<<endl;
}
