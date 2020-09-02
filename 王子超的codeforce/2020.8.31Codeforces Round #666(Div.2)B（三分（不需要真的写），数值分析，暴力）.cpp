#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n;
vector<ll>num;

int32_t main()
{
    IOS;
    cin>>n;
    num.resize(n);
    for(auto &x:num) cin>>x;
    sort(num.begin(),num.end());
    ll ans=llINF;
    for(ll i=1;i<=1e5;i++)
    {
        ll temp=0,now=1;//temp记录比值为i时候所需的操作次数
        for(ll j=0;j<n;j++)
        {
            temp+=abs(now-num[j]);
            if(now>llINF/i) {temp=-1;break;}//如果等比数列当前项超过了longlong上限则结束循环
            now*=i;
        }
        if(temp==-1) break;//temp-1代表等比数列某一项已经超出longlong上限，结束循环
        if(temp<ans) ans=temp;
        else break;//temp>=ans代表我们已经到达凹函数的“谷底”
    }
    cout<<ans<<endl;
}