#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e2+7;

int n;
int sg[maxn];

int getsg(int x)
{
    if(sg[x]!=-1) return sg[x];
    unordered_set<int>S;//用于计算当前状态对应的mex值
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<x;j++)
            S.insert(getsg(i)^getsg(j));
    }
    for(int i=0;;i++)
        if(!S.count(i))
            return sg[x]=i;
}

int32_t main()
{
    IOS;
    memset(sg,-1,sizeof(sg));
    int ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        ans^=getsg(x);
    }
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
