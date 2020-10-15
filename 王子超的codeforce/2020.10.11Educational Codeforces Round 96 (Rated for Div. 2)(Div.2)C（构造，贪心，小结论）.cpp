#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const double eps=1e-5;

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<2<<endl;
        cout<<n<<' '<<n-1<<endl;
        int now=n;
        while(now>2)
        {
            cout<<now<<' '<<now-2<<endl;
            now--;
        }
    }
}
