#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=3e3+7;

int n;
int num[maxn];
int sum[maxn][maxn];

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<n;i++)
            for(int j=1;j<=n;j++) sum[i][j]=0;
        ll ans=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>num[i];
            if(i)
                for(int j=1;j<=n;j++)
                    sum[i][j]=sum[i-1][j];
            sum[i][num[i]]++;
        }
        for(int i=1;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                int sumleft=sum[i-1][num[j]];
                int sumright=sum[n-1][num[i]]-sum[j][num[i]];
                ans+=sumleft*sumright;
            }
        cout<<ans<<endl;
    }
}