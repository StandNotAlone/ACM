#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<functional>
#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define ft first
#define sd second
#define endl "\n"
#define mp make_pair
#define pb push_back
#define ll long long
#define int long long
#define vec vector<ll>
#define mat vector<vector<ll>>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define _rep(i,n) for(ll i=n-1;i>=0;i--)
#define REP(i,n) for(ll i=1;i<=(ll)(n);i++)
#define _REP(i,n) for(ll i=n;i>0;i--)
#define at(x,n) for(auto &x:n)
//cout<<fixed<<setprecision(6)<<
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//ifstream f1("/Users/wangzichao/Documents/wzc.in");
//ofstream f2("/Users/wangzichao/Documents/wzc.out");
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int read()      //整数读入挂
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}

using namespace std;
#define local
#ifdef local
#endif
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;



int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        bool f=0;
        int tar=-1;
        int num=0;
        for(int i=3;i+3<n;i++)
        {
            if(s[i-3]=='a'&&s[i-2]=='b'&&s[i-1]=='a'&&s[i]=='c'&&s[i+1]=='a'&&s[i+2]=='b'&&s[i+3]=='a') num++;
        }
        for(int i=3;i+3<n;i++)
        {
            if(s[i]=='c'||s[i]=='?')
            {
                bool flag=1;
                if(i-7>=0)
                {
                    bool F=1;
                    if(s[i-7]=='a'&&s[i-6]=='b'&&s[i-5]=='a'&&s[i-4]=='c');
                    else F=0;
                    if(F) flag=0;
                }
                if(i+7<n)
                {
                    bool F=1;
                    if(s[i+7]=='a'&&s[i+6]=='b'&&s[i+5]=='a'&&s[i+4]=='c');
                    else F=0;
                    if(F) flag=0;
                }
                if(s[i-3]=='a'||s[i-3]=='?');
                else flag=0;
                if(s[i-2]=='b'||s[i-2]=='?');
                else flag=0;
                if(s[i-1]=='a'||s[i-1]=='?');
                else flag=0;
                if(s[i+1]=='a'||s[i+1]=='?');
                else flag=0;
                if(s[i+2]=='b'||s[i+2]=='?');
                else flag=0;
                if(s[i+3]=='a'||s[i+3]=='?');
                else flag=0;
                if(flag)
                {
                    tar=i;
                    f=1;
                }
            }
        }
        if(num>1) cout<<"No"<<endl;
        else if(num==1)
        {
            cout<<"Yes"<<endl;
            for(ll i=0;i<n;i++)
            {
                if(s[i]=='?') cout<<'z';
                else cout<<s[i];
            }
            cout<<endl;
        }
        else if(f)
        {
            s[tar]='c';
            s[tar-3]='a';
            s[tar-2]='b';
            s[tar-1]='a';
            s[tar+1]='a';
            s[tar+2]='b';
            s[tar+3]='a';
            cout<<"Yes"<<endl;
            for(ll i=0;i<n;i++)
            {
                if(s[i]=='?') cout<<'z';
                else cout<<s[i];
            }
            cout<<endl;
        }
        else cout<<"No"<<endl;
    }
}


