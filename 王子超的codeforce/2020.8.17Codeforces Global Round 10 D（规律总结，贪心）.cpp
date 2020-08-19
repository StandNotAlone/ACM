#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<char>S(n);
        for(auto &x:S) cin>>x;
        bool f=1;
        for(int i=1;i<n;i++) if(S[i]!=S[i-1]) f=0;
        if(f) cout<<1+(n-1)/3<<endl;
        else
        {
            ll ans=0,cas=1;//cas代表当前扫到的连续的相同字符个数
            while(S[0]==S[n-1]){cas++;n--;}
            for(ll i=1;i<n;i++)
            {
                if(S[i]!=S[i-1])
                {
                    ans+=cas/3;
                    cas=1;
                }
                else cas++;
            }
            cout<<ans+cas/3<<endl;
        }
    }
}
