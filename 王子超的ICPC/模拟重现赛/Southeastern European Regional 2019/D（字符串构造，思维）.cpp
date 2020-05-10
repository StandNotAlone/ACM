#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define ft first
#define sd second
#define pb push_back
#define ll long long
#define vec vector<ll>
#define mat vector<vector<ll>>
//cout<<fixed<<setprecision(6)<<
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//ifstream f1("/Users/wangzichao/Documents/wzc.in");
//ofstream f2("/Users/wangzichao/Documents/wzc.out");
//ios::sync_with_stdio(false);
//cin.tie(0);cout.tie(0);
using namespace std;
#define local
#ifdef local
#endif
const ll maxn=6e5+7;
const double eps=1e-10;
const ll mod=1e9+7;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    ll len=s.length(),Max=-1,tar=-1,Min=llINF,tar1=-1;
    vector<ll>num(26,0);
    for(auto &x:s)
    {
        num[x-'a']++;
    }
    ll flag=0;
    for(ll i=0;i<26;i++)
    {
        if(num[i]) flag++;
        if(num[i]>Max)
        {
            Max=num[i];
            tar=i;
        }
        if(num[i]&&num[i]<Min)
        {
            Min=num[i];
            tar1=i;
        }
    }
    if(flag>1)
    {
        if(Max*2>len)
        {
            if(Max==len-1||flag==2&&Max==len-2)
            {
                cout<<"NO"<<endl;
                return 0;
            }
            cout<<"YES"<<endl;
            for(ll i=0;i<len/2;i++)
                cout<<(char)('a'+tar);
            cout<<(char)('a'+tar1);
            num[tar1]--;
            for(ll i=0;i<Max-len/2;i++)
                cout<<(char)('a'+tar);
            num[tar]=0;
            for(ll i=0;i<26;i++)
            {
                for(ll j=0;j<num[i];j++)
                    cout<<(char)('a'+i);
            }
            cout<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            for(ll i=0;i<26;i++)
            {
                if(num[i])
                {
                    for(ll j=0;j<num[i];j++)
                        cout<<(char)('a'+i);
                }
            }
        }
        cout<<endl;
    }
    else cout<<"NO"<<endl;
}

