#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    IOS
    int n;cin>>n;
    string s;cin>>s;
    int ans=0;
    for(int i=1;i<n;i+=2)
    {
        if(s[i]==s[i-1])
        {
            if(s[i]=='a') s[i-1]='b';
            else s[i-1]='a';
            ans++;
        }
    }
    cout<<ans<<endl;
    cout<<s<<endl;
}
