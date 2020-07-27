#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ll road[21][21];

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        memset(road,0,sizeof(road));
        bool f=1;
        for(ll i=0;i<n;i++)
        {
            if(a[i]>b[i]) f=0;
            else road[a[i]-'a'][b[i]-'a']=1;
        }
        if(f)
        {
            ll ans=0;
            for(ll i=0;i<20;i++)
            {
                for(ll j=i+1;j<20;j++)
                {
                    if(road[i][j])
                    {
                        ans++;
                        for(ll k=j+1;k<20;k++)
                            if(road[i][k]) road[j][k]=1;
                        break;
                    }
                }
            }
            cout<<ans<<endl;
        }
        else cout<<-1<<endl;
    }
}
