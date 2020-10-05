#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int num[107][2][2];

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        bool flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    cin>>num[i][j][k];
            if(num[i][0][1]==num[i][1][0]) flag=1;
        }
        if(m%2==0&&flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
