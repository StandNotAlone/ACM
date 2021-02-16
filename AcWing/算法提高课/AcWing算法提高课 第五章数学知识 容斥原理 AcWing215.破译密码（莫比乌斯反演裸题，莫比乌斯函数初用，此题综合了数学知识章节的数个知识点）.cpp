#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=5e4+7;

int mbus[maxn];
bool v[maxn];

void getmbus()
{
    for(int i=1;i<=50000;i++) mbus[i]=1,v[i]=0;
    for(int i=2;i<=50000;i++)
    {
        if(v[i]) continue;
        mbus[i]=-1;
        for(int j=2*i;j<=50000;j+=i)
        {
            v[j]=1;
            if(j/i%i==0) mbus[j]=0;
            else mbus[j]*=-1;
        }
    }
}

int32_t main()
{
    IOS;
    getmbus();
    for(int i=2;i<=50000;i++) mbus[i]+=mbus[i-1];
    int n;
    cin>>n;
    while(n--)
    {
        int x,y,d;
        cin>>x>>y>>d;
        x/=d;y/=d;
        ll ans=0;
        for(int i=1;i<=x&&i<=y;i++)
        {
            int next=min(x/(x/i),y/(y/i));
            ans+=(ll)x/i*(y/i)*(mbus[next]-mbus[i-1]);
            i=next;
        }
        cout<<ans<<endl;
    }
}
