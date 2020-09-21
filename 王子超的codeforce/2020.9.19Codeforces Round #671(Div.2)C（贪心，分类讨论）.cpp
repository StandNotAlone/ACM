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
        int n,x;
        cin>>n>>x;
        int sum=0,cas=0;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            if(temp!=x) sum+=temp;
            else cas++;
        }
        if(cas==n) cout<<0<<endl;
        else if(cas) cout<<1<<endl;
        else
        {
            if(sum%n==0&&sum/n==x) cout<<1<<endl;
            else cout<<2<<endl;
        }
    }
}