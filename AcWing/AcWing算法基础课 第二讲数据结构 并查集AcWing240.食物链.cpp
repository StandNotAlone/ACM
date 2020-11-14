#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=5e4+7;

int n,k,fa[maxn*3];

void init()
{
    for(int i=1;i<=3*n;i++) fa[i]=i;
}

int get(int x)
{
    return fa[x]==x?x:fa[x]=get(fa[x]);
}

void merge(int x,int y)
{
    fa[get(x)]=get(y);
}

int32_t main()
{
    IOS
    int ans=0;
    cin>>n>>k;
    init();
    while(k--)
    {
        int d,x,y;
        cin>>d>>x>>y;
        if(x>n||y>n) {ans++;continue;}
        if(d==2&&x==y) {ans++;continue;}
        if(d==1)
        {
            if(get(x+n)==get(y)||get(x+2*n)==get(y)) ans++;
            else
            {
                merge(x,y);
                merge(x+n,y+n);
                merge(x+2*n,y+2*n);
            }
        }
        else
        {
            if(get(x)==get(y)||get(x+2*n)==get(y)) ans++;
            else
            {
                merge(x+n,y);
                merge(x+2*n,y+n);
                merge(x,y+2*n);
            }
        }
    }
    cout<<ans<<endl;
}
