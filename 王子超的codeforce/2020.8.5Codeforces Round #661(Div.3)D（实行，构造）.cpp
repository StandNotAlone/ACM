#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=2e5+7;

ll cas[maxn];
ll n;
string s;

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        ll now=0;
        stack<ll>odd,even;
        for(ll i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                if(even.size())
                {
                    ll temp=even.top();
                    even.pop();
                    odd.push(temp);
                    cas[i]=temp;
                }
                else
                {
                    cas[i]=++now;
                    odd.push(now);
                }
            }
            else
            {
                if(odd.size())
                {
                    ll temp=odd.top();
                    odd.pop();
                    even.push(temp);
                    cas[i]=temp;
                }
                else
                {
                    cas[i]=++now;
                    even.push(now);
                }
            }
        }
        cout<<now<<endl;
        for(ll i=0;i<n;i++)

        {
            if(i) cout<<' ';
            cout<<cas[i];
        }
        cout<<endl;
    }
}
