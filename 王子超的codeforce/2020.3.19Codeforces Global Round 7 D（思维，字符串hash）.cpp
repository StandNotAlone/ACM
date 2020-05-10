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
//ifstream f1(".txt");
//ofstream f2(".txt");
//ios::sync_with_stdio(false);
//cin.tie(0);
using namespace std;
#define local
#ifdef local
#endif
const ll maxn=6e5+7;
const double eps=1e-10;
const unsigned ll mod=1e9+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    cin.get();
    while(t--)
    {
        string s;
        getline(cin,s);
        ll pre=0;
        ll len=s.length();
        while(pre*2+2<=len&&s[pre]==s[len-pre-1])
        {
            pre++;
        }
        ll newlen=len-2*pre;
        if(newlen>0)
        {
            vector<pair<unsigned ll,unsigned ll>>hash1(newlen),hash2(newlen),hash3(newlen),hash4(newlen);
            unsigned ll x1=1,x2=1,HS1=0,HS2=0;      //hash1和3为正向子串，ft为pre部分的hash，sd为suf部分的hash
                                                    //hash2和4为反向子串，ft为pre部分的hash，sd为suf部分的hash
            for(ll i=0;i<newlen;i++)
            {
                HS1=HS1*26+s[i+pre]-'a';
                hash1[i].ft=HS1;
                HS2=(HS2*26+s[i+pre]-'a')%mod;
                hash3[i].ft=HS2;
            }
            HS1=0;HS2=0;
            for(ll i=newlen-1;i>=0;i--)
            {
                HS1+=x1*(s[i+pre]-'a');
                x1*=26;
                hash1[i].sd=HS1;
                HS2=(HS2+x2*(s[i+pre]-'a')%mod)%mod;
                x2=x2*26%mod;
                hash3[i].sd=HS2;
            }
            HS1=0;HS2=0;
            for(ll i=0;i<newlen;i++)
            {
                HS1=HS1*26+s[len-pre-1-i]-'a';
                hash2[i].ft=HS1;
                HS2=(HS2*26+s[len-pre-1-i]-'a')%mod;
                hash4[i].ft=HS2;
            }
            HS1=0;x1=1;
            HS2=0;x2=1;
            for(ll i=newlen-1;i>=0;i--)
            {
                HS1+=x1*(s[len-pre-1-i]-'a');
                x1*=26;
                hash2[i].sd=HS1;
                HS2=(HS2+x2*(s[len-pre-1-i]-'a')%mod)%mod;
                x2=x2*26%mod;
                hash4[i].sd=HS2;
            }
            ll tar1=-1,tar2=-1;
            for(ll i=newlen-1;i>=0;i--)
            {
                if(hash1[i].ft==hash2[newlen-i-1].sd&&hash3[i].ft==hash4[newlen-i-1].sd)
                {
                    tar1=i;
                    break;
                }
            }
            for(ll i=newlen-1;i>=0;i--)
            {
                if(hash2[i].ft==hash1[newlen-i-1].sd&&hash4[i].ft==hash3[newlen-i-1].sd)
                {
                    tar2=i;
                    break;
                }
            }
            for(ll i=0;i<pre;i++) cout<<s[i];
            if(tar1>=tar2)
            {
                for(ll i=0;i<=tar1;i++) 
                    cout<<s[i+pre];
            }
            else
            {
                for(ll i=tar2;i>=0;i--)
                    cout<<s[len-pre-i-1];
            }
            for(ll i=pre;i;i--) cout<<s[len-i];
            cout<<endl;
        }
        else 
        {
            for(ll i=0;i<pre;i++) cout<<s[i];
            for(ll i=pre;i;i--) cout<<s[len-i];
            cout<<endl;
        }
    }
}


