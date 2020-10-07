#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

ll num[maxn];
int tar=0,ed=0;
string s[4]=
{
    "push",
    "pop",
    "empty",
    "query"
};

int32_t main()
{
    IOS;
    int m;
    cin>>m;
    while(m--)
    {
        string temp;
        cin>>temp;
        if(temp==s[0]) cin>>num[ed++];
        else if(temp==s[1]) tar++;
        else if(temp==s[2])
        {
            if(tar!=ed) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        else cout<<num[tar]<<endl;
    }
}
