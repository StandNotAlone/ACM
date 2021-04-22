#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e5+7;
const double eps=1e-6;
const int mod=1e9+7;

ll n;
ll num[maxn];

int main(){
    IOS
    int t;cin>>t;
    while(t--){
        cin>>n;
        ll cnt=0;//记录有几个最小值
        ll Min=llINF;
        ll temp;//计算n个数的位与结果
        for(int i=0;i<n;i++){
            cin>>num[i];
            if(i) temp&=num[i];
            else temp=num[i];
            if(num[i]<Min){Min=num[i];cnt=1;}
            else if(num[i]==Min) cnt++;
        }
        if(cnt<2||temp!=Min) cout<<0<<endl;
        else{
            ll ans=cnt*(cnt-1)%mod;//最小值里挑两个放在开头结尾
            for(int i=2;i<=n-2;i++) ans=ans*i%mod;//剩下的在中间任意排列，即(n-2)!
            cout<<ans<<endl;
        }
    }
}
