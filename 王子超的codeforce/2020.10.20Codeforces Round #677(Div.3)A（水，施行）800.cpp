#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        int ans=10*(x%10-1);
        int cas=0;
        while(x)
        {
            cas++;
            ans+=cas;
            x/=10;
        }
        printf("%d\n",ans);
    }
}