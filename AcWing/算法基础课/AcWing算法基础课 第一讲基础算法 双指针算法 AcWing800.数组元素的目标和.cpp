#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

int a[maxn],b[maxn];
int n,m,x;

int32_t main()
{
    IOS
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    int l=1,r=m;
    while(a[l]+b[m]<x) l++;
    while(1)
    {
        while(r>1&&b[r-1]+a[l]>=x) r--;
        if(a[l]+b[r]==x) {cout<<l-1<<' '<<r-1<<endl;break;}
        l++;
    }
}
