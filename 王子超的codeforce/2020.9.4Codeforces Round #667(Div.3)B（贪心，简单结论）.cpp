#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll solve(ll a,ll b,ll x,ll y,ll n)
{
    ll temp=min(a-x,n);//优先考虑减a的值,temp为a能减少的最大值
    a-=temp;n-=temp;
    temp=min(b-y,n);//再考虑剩下的次数全部减到b上
    b-=temp;
    return a*b;
}

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,x,y,n;
        cin>>a>>b>>x>>y>>n;
        ll ans1=solve(a,b,x,y,n);//ans1为优先减a的值的结果
        ll ans2=solve(b,a,y,x,n);//ans2为优先减b的值的结果
        cout<<min(ans1,ans2)<<endl;
    }
}
