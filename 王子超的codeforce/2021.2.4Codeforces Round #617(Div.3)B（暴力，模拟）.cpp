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
        int n;cin>>n;
        int ans=0;
        while(n>9)//当还可以得到返利时就不断重复把除了个位的钱都花掉，贪心去拿返利
        {
            ans+=n/10*10;
            n=n%10+n/10;
        }
        cout<<ans+n<<endl;
    }
}
