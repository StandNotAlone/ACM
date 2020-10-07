#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    stack<ll>S;
    while(n--)
    {
        ll x;
        cin>>x;
        while(S.size()&&S.top()>=x) S.pop();
        if(S.size()) cout<<S.top();
        else cout<<-1;
        S.push(x);
        if(n) cout<<' ';
        else cout<<endl;
    }
}
