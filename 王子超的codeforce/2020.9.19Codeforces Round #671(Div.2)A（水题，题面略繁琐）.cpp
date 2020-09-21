#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
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
        string s;
        cin>>s;
        bool flag;
        if(n&1)
        {
            flag=0;
            for(int i=0;i<n;i+=2)
                if(s[i]%2) flag=1;
        }
        else
        {
            flag=1;
            for(int i=1;i<n;i+=2)
                if(s[i]%2==0) flag=0;
        }
        if(flag) cout<<1<<endl;
        else cout<<2<<endl;
    }
}
