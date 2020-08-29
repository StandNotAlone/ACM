#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1;
        int n=(int)s1.size();
        s2.resize(n,'!');
        int x;
        cin>>x;
        bool flag=1;
        for(int i=0;i<n;i++)
        {
            if(s1[i]=='0')
            {
                if(i-x>=0&&s2[i-x]=='1') flag=0;
                if(i-x>=0) s2[i-x]='0';
                if(i+x<n) s2[i+x]='0';
            }
            else
            {
                bool f=0;
                if(i-x>=0&&s2[i-x]=='1') f=1;
                if(!f)
                {
                    if(i-x>=0&&s2[i-x]=='!') s2[i-x]='1';
                    else if(i+x<n) s2[i+x]='1';
                    else flag=0;
                }
            }
        }
        for(int i=0;i<n;i++) if(s2[i]=='!') s2[i]='0';
        if(flag) cout<<s2<<endl;
        else cout<<-1<<endl;
    }
}