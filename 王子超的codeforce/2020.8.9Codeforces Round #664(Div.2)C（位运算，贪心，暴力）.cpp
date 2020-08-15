#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<int>ans;

int32_t main()
{
    IOS;
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;
    for(int i=8;i>=0;i--)
    {
        int flag=1;
        for(int j=0;j<n;j++)
        {
            if(a[j]&(1<<i))
            {
                bool F=0;
                for(int k=0;k<m;k++)
                {
                    int temp=a[j]&b[k];
                    bool f=1;
                    for(auto x:ans) if(temp&(1<<x)) f=0;
                    if(temp&(1<<i)) f=0;
                    if(f) F=1;
                }
                if(!F)
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag) ans.push_back(i);
    }
    int out=(1<<9)-1;
    for(auto x:ans) out-=(1<<x);
    cout<<out<<endl;
}
