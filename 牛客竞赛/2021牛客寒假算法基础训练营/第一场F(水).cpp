#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int sum[107][4];
int n;

int main()
{
    IOS
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char c;cin>>c;
        sum[i][c-'A']++;
    }
    for(int i=0;i<n;i++)
    {
        char c;cin>>c;
        sum[i][c-'A']++;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int temp=0;
        for(int j=0;j<4;j++)
         temp=max(temp,sum[i][j]);
        ans+=temp;
    }
    cout<<ans<<' '<<0<<endl;
}
