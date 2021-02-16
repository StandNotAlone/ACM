#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=3e6;

int trie[maxn][2],ed[maxn],tot=0;

void insert(int x,int y)
{
    int tar=0,now=1<<20;
    while(now)
    {
        bool net=x&now;
        if(trie[tar][net]==0) trie[tar][net]=++tot;
        tar=trie[tar][net];
        now>>=1;
    }
    ed[tar]=y;
}

pair<int,int> cal(int x)
{
    int ret=0;
    int tar=0,now=1<<20;
    while(now)
    {
        bool to=x&now;
        if(trie[tar][!to])
        {
            ret+=now;
            tar=trie[tar][!to];
        }
        else tar=trie[tar][to];
        now>>=1;
    }
    return {ret,ed[tar]};
}

int main()
{
    IOS
    int n;cin>>n;
    int ans=-1,tar=0,len=0,sum=0;
    insert(0,0);//前缀和一个不取的初始情况
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        sum^=x;
        pair<int,int>temp=cal(sum);
        if(temp.first>ans) {ans=temp.first;len=i-temp.second;tar=i;}
        insert(sum,i);
    }
    cout<<ans<<' '<<tar-len+1<<' '<<tar<<endl;
}
