#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main()
{
    IOS;
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    cout<<x<<' '<<y<<endl;
    cout<<1<<' '<<y<<endl;
    for(int i=1;i<=n;i++)
    {
        if(i&1)
        {
            for(int j=1;j<=m;j++)
            {
                if(j==y&&(i==1||i==x)) continue;
                cout<<i<<' '<<j<<endl;
            }
        }
        else
        {
            for(int j=m;j>=1;j--)
            {
                if(j==y&&(i==1||i==x)) continue;
                cout<<i<<' '<<j<<endl;
            }
        }
    }
}
