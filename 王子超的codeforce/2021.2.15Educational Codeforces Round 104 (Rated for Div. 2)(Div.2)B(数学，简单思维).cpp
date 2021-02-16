#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int main()
{
    IOS
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;
        int ans=0;
        if(n&1) ans=(k+(k-1)/(n/2))%n;
        else ans=k%n;
        if(ans==0) ans=n;//注意最后位置是n的时候取余运算会变成0，要变回来
        cout<<ans<<endl;
    }
}
