#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n,q;
set<ll>S;
priority_queue<ll>length_now,length_delete;

void insert(ll x)
{
    if(S.size())
    {
        auto now=S.lower_bound(x);
        if(now==S.begin()) length_now.push(*now-x);
        else
        {
            if(now==S.end())
            {
                now--;
                length_now.push(x-*now);
            }
            else
            {
                ll temp=*now;
                now--;
                length_now.push(temp-x);
                length_now.push(x-*now);
                length_delete.push(temp-*now);
            }
        }
    }
    S.insert(x);
}

void erase(ll x)
{
    S.erase(x);
    if(S.size())
    {
        auto now=S.lower_bound(x);
        if(now==S.begin()) length_delete.push(*now-x);
        else
        {
            if(now!=S.end())
            {
                ll temp=*now;
                now--;
                length_now.push(temp-*now);
                length_delete.push(temp-x);
                length_delete.push(x-*now);
            }
            else
            {
                now--;
                length_delete.push(x-*now);
            }
        }
    }
}

void out()
{
    if(S.size()==0) cout<<0<<endl;
    else
    {
        while(length_delete.size()&&length_delete.top()==length_now.top())
        {
            length_delete.pop();
            length_now.pop();
        }
        ll ans=*S.rbegin()-*S.begin();
        if(length_now.size()) cout<<ans-length_now.top()<<endl;
        else cout<<0<<endl;
    }
}

int32_t main()
{
    IOS;
    cin>>n>>q;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        insert(x);
    }
    out();
    for(ll i=0;i<q;i++)
    {
        ll ope,x;
        cin>>ope>>x;
        if(ope) insert(x);
        else erase(x);
        out();
    }
}
