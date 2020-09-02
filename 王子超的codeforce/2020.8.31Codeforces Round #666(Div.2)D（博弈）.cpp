#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<ll>num;

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        num.clear();
        num.resize(n);
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>num[i];
            sum+=num[i];
        }
        sort(num.begin(),num.end());
        if(n==1) cout<<"T"<<endl;
        else if(n==2)
        {
            if(num[1]>num[0]) cout<<"T"<<endl;
            else cout<<"HL"<<endl;
        }
        else
        {
            if(num[n-1]*2>sum) cout<<"T"<<endl;
            else
            {
                if(sum&1) cout<<"T"<<endl;
                else cout<<"HL"<<endl;
            }
        }
    }
}
