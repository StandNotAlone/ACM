#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n,m;
int a[100007],b[100007];

int32_t main()
{
    IOS
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    int tar=1;
    for(int i=1;i<=m;i++)
    {
        if(a[tar]==b[i]) tar++;
        if(tar>n) break;
    }
    if(tar>n) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
