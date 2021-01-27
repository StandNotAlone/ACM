#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    IOS
    int t;cin>>t;
    while(t--)
    {
        vector<int>ans;
        int n;cin>>n;
        ans.push_back(0);
        int now=n;
        while(now)
        {
            ans.push_back(n/now);
            now=n/(n/now+1);
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
        {
            if(i) cout<<' ';
            cout<<ans[i];
        }
        cout<<endl;
    }
}
