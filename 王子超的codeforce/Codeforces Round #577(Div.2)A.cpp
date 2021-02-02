#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n,m;
int num[1007][5];//num[i][j]代表第i题选'A'+j的有几个人

int32_t main()
{
    IOS;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        for(int j=0;j<m;j++)
            num[j][s[j]-'A']++;
    }
    int ans=0;
    for(int i=0;i<m;i++)
    {
        int x;cin>>x;
        int y=0;
        for(int j=0;j<5;j++) y=max(y,num[i][j]);
        ans+=x*y;
    }
    cout<<ans<<endl;
}
