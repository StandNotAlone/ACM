#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int num[1007],cas[1007];

int32_t main()
{
    IOS
    int n;cin>>n;
    int ans=1;

    for(int i=0;i<n;i++)
    {
        cin>>num[i];
        for(int j=0;j<i;j++)
            if(num[j]<num[i]) cas[i]=max(cas[i],cas[j]+1);
        ans=max(ans,cas[i]);
    }
    cout<<ans+1<<endl;
}
