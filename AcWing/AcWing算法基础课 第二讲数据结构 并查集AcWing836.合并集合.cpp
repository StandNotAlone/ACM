#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

int fa[maxn];
int n,m;

void init()
{
    for(int i=1;i<=n;i++) fa[i]=i;
}

int get(int a)
{
    return fa[a]=a?a:fa[a]=get(fa[a]);
}

void merge(int a,int b)
{
    fa[a]=get(b);
}

int32_t main()
{
    IOS
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        //getchar();
        char c;
        cin>>c;
        int a,b;
        cin>>a>>b;
        if(c=='M') merge(a,b);
        else
        {
            if(fa[a]==fa[b]) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
}