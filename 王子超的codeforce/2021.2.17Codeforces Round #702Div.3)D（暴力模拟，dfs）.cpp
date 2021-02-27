#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

map<ll,int>M;
vector<ll>num;

int main()
{
    IOS
    int t;cin>>t;
    for(int i=1;i<=10000;i++)
    {
        ll x=i;
        x=x*x*x;
        M[x]=1;
        num.push_back(x);
    }
    while(t--)
    {
        bool flag=0;
        ll x;cin>>x;
        for(int i=0;i<num.size();i++)
        {
            if(M.find(x-num[i])!=M.end()) {flag=1;break;}
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}