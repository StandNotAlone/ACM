#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

int n,m,fa[maxn],sum[maxn];

void init()
{
    for(int i=1;i<=n;i++) {fa[i]=i;sum[i]=1;}
}

int get(int x)
{
    return fa[x]==x?x:fa[x]=get(fa[x]);
}

void merge(int x,int y)
{
    int X=get(x),Y=get(y);
    if(X==Y) return ;
    sum[Y]+=sum[X];
    fa[X]=Y;
}

int32_t main()
{
    IOS
    cin>>n>>m;
    init();
    while(m--)
    {
        string s;
        cin>>s;
        if(s[0]=='C')
        {
            int a,b;
            cin>>a>>b;
            merge(a,b);
        }
        else
        {
            if(s[1]=='1')
            {
                int a,b;
                cin>>a>>b;
                if(get(a)==get(b)) cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
            else
            {
                int a;
                cin>>a;
                cout<<sum[get(a)]<<endl;
            }
        }
    }
}
