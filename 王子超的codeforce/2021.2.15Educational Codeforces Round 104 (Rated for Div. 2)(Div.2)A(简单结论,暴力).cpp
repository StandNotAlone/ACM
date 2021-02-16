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
        vector<int>num(n);
        for(int i=0;i<n;i++) cin>>num[i];
        sort(num.begin(),num.end());
        int ans=n;
        for(int i=0;i<n;i++) if(num[i]==num[0]) ans--;
        cout<<ans<<endl;
    }
}
