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
        int num0=0,num1=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(x) num1++;
            else num0++;
        }
        if(num0>=num1)
        {
            cout<<num0<<endl;
            for(ll i=0;i<num0;i++)
            {
                if(i) cout<<' ';
                cout<<0;
            }
        }
        else
        {
            if(num1&1) num1--;
            cout<<num1<<endl;
            for(ll i=0;i<num1;i++)
            {
                if(i) cout<<' ';
                cout<<1;
            }
        }
        cout<<endl;
    }
}
