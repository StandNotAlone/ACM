#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e6+7;

int cas[maxn];
int ans[maxn];
bool flag[maxn];

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    vector<int>num(n);
    for(auto &x:num)
    {
        cin>>x;
        cas[x]++;
    }
    for(auto &x:num)
    {
        if(!flag[x])
        {
            flag[x]=1;
            int temp=0;
            while(temp+x<=1e6)
            {
                temp+=x;
                ans[temp]+=cas[x];
            }
        }
    }
    for(auto &x:num) cout<<ans[x]-1<<endl;
}
