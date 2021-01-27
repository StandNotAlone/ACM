#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    IOS
    int n,t;cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        t-=86400-x;
        if(t<=0) {cout<<i<<endl;break;}
    }
}
