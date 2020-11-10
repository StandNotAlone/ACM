#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}

int32_t main()
{
    IOS
    int t;
    cin>>t;
    while(t--)
    {
        int n,sum=0;
        cin>>n;
        vector<int>num(n);
        for(auto &x:num) {cin>>x;sum+=x;}
        if(sum==0) cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            if(sum<0) sort(num.begin(),num.end());
            else sort(num.begin(),num.end(),cmp);
            for(int i=0;i<n;i++) cout<<num[i]<<' ';
            cout<<endl;
        }
    }
}
