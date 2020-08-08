#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

ll num[maxn];

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        num[x]++;
    }
    ll cas2=0,cas4=0;
    for(ll i=1;i<=100000;i++)
    {
        cas2+=num[i]/2;
        if(num[i]>3) cas4++;
    }
    ll q;
    cin>>q;
    while(q--)
    {
        char c;
        ll x;
        cin>>c>>x;
        if(c=='-')
        {
            if(num[x]==4) cas4--;
            if(num[x]%2==0) cas2--;
            num[x]--;
        }
        else
        {
            if(num[x]==3) cas4++;
            if(num[x]%2) cas2++;
            num[x]++;
        }
        if(cas4&&cas2>3) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
