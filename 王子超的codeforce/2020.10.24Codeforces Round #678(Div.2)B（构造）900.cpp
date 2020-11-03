#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

bool field[107][107];

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        memset(field,0,sizeof(field));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) field[i][i]=field[i][n-i+1]=1;//两条对角线上放置1
        if(n&1) field[n/2+1][1]=field[1][n/2+1]=1;//特判n为奇数的情况，此时中间排和中间列只有一个1，在左侧中间和上测中间各加一个1即可
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) cout<<field[i][j]<<' ';
            cout<<endl;
        }
    }
}
