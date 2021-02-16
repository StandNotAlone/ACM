#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

int n,ans=0;

struct Node
{
    int l,r;
}node[maxn];

bool cmp(Node a,Node b)
{
    return a.l<b.l;
}

int32_t main()
{
    IOS
    cin>>n;
    for(int i=0;i<n;i++) cin>>node[i].l>>node[i].r;
    sort(node,node+n,cmp);
    int now=0;
    while(now<n)
    {
        ans++;
        int tar=node[now].r;
        while(now<n)
        {
            now++;
            if(node[now].l>tar) break;
            tar=max(tar,node[now].r);
        }
    }
    cout<<ans<<endl;
}