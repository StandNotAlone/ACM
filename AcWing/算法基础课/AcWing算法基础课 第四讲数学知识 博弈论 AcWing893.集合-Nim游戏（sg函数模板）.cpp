#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e4+7;

int n,k;
int num[107];
int sg[maxn];

int getsg(int x)
{
    if(sg[x]!=-1) return sg[x];
    unordered_set<int>S;
    for(int i=0;i<k;i++)
        if(x>=num[i]) S.insert(getsg(x-num[i]));
    for(int i=0;;i++)
        if(!S.count(i))
            return sg[x]=i;
}

int32_t main()
{
    IOS;
    memset(sg,-1,sizeof(sg));
    cin>>k;
    for(int i=0;i<k;i++) cin>>num[i];
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
