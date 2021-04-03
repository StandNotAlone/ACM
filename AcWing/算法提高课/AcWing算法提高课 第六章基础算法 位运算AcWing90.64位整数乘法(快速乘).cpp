#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

ll  a,b,p;

ll qmul(ll a,ll b,ll p){
    ll ret=0;
    while(b){
        if(b&1) ret=(ret+a)%p;
        a=a*2%p;
        b>>=1;
    }
    return ret;
}

int main(){
    IOS
    cin>>a>>b>>p;
    cout<<qmul(a,b,p)<<endl;
}
