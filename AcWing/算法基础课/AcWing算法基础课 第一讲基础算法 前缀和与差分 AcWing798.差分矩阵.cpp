#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n,m,q;
ll num[1007][1007];

int32_t main()
{
    IOS;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int x;
            cin>>x;
            num[i][j]+=x;
            num[i][j+1]-=x;
            num[i+1][j]-=x;
            num[i+1][j+1]+=x;
        }
    while(q--)
    {
        int xx1,xx2,yy1,yy2,c;
        cin>>xx1>>yy1>>xx2>>yy2>>c;
        num[xx1][yy1]+=c;
        num[xx1][yy2+1]-=c;
        num[xx2+1][yy1]-=c;
        num[xx2+1][yy2+1]+=c;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j>1) cout<<' ';
            num[i][j]+=num[i-1][j]+num[i][j-1]-num[i-1][j-1];
            cout<<num[i][j];
        }
        cout<<endl;
    }
}
