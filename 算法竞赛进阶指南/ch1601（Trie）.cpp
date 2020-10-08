#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e6+7;

int n,m;
string s;

//可以改用结构体指针来实现，用时间来换取空间
int trie[maxn][26],ed[maxn];
int tot=0;

void insert(string s)
{
    int len=s.size(),tar=0;
    for(int i=0;i<len;i++)
    {
        int net=s[i]-'a';
        if(trie[tar][net]==0) trie[tar][net]=++tot;
        tar=trie[tar][net];
    }
    ed[tar]++;
}

int cal(string s)
{
    int len=s.size(),tar=0,ret=0;
    for(int i=0;i<len;i++)
    {
        tar=trie[tar][s[i]-'a'];
        ret+=ed[tar];
        if(tar==0) return ret;
    }
    return ret;
}

int32_t main()
{
    IOS;
    cin>>n>>m;
    while(n--)
    {
        cin>>s;
        insert(s);
    }
    while(m--)
    {
        cin>>s;
        cout<<cal(s)<<endl;
    }
}
