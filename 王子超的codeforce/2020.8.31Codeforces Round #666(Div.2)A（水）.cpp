#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int num[26];

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<s.size();j++)
                num[s[j]-'a']++;
        }
        bool flag=1;
        for(int i=0;i<26;i++)
            if(num[i]%n) flag=0;
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
