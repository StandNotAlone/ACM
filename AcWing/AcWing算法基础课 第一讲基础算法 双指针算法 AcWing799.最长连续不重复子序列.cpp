#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

int num[maxn],tar[maxn];

int32_t main()
{
    IOS
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];
    int ans=0,l=0,r=0;
    while(r<n)
    {
        while(r<=n&&tar[num[r+1]]<=l) {tar[num[r+1]]=r+1;r++;}
        ans=max(r-l,ans);
        if(r<=n) l=tar[num[r+1]];
    }
    cout<<ans<<endl;
}
