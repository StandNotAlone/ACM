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
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define REP(i,n) for(ll i=1;i<=(ll)(n);i++)
#define at(x,n) for(auto &x:n)
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
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vec num(3,-1);
        ll ans=llINF;
        rep(i,s.size())
        {
            num[s[i]-'1']=i;
            ll temp=min(num[0],min(num[1],num[2]));
            if(temp==-1) continue;
            ans=min(ans,i-temp+1);
        }
        if(ans==llINF) cout<<0<<endl;
        else cout<<ans<<endl;
    }
}


//笨比写法
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);
//    ll t;
//    cin>>t;
//    while(t--)
//    {
//        bool flag1=0,flag2=0,flag3=0;
//        string s;
//        cin>>s;
//        vec num[(ll)s.size()];
//        at(x,num) x.resize(4);
//        ll temp1=-1,temp2=-1;
//        ll len=(ll)s.size();
//        rep(i,len)
//        {
//            if(s[i]=='1')
//            {
//                temp1=i;
//                flag1=1;
//            }
//            else if(s[i]=='2')
//            {
//                temp2=i;
//                flag2=1;
//            }
//            else flag3=1;
//            num[i][0]=temp1;
//            num[i][1]=temp2;
//        }
//        temp1=-1;
//        temp2=-1;
//        for(ll i=len-1;i>=0;i--)
//        {
//            if(s[i]=='1') temp1=i;
//            else if(s[i]=='2') temp2=i;
//            num[i][2]=temp1;
//            num[i][3]=temp2;
//        }
//        if(flag1&&flag2&&flag3)
//        {
//            ll ans=llINF;
//            rep(i,len)
//            {
//                if(s[i]=='3')
//                {
//                    if(num[i][0]!=-1&&num[i][1]!=-1)
//                    {
//                        ans=min(ans,i-min(num[i][0],num[i][1])+1);
//                    }
//                    if(num[i][0]!=-1&&num[i][3]!=-1)
//                    {
//                        ans=min(ans,num[i][3]-num[i][0]+1);
//                    }
//                    if(num[i][1]!=-1&&num[i][2]!=-1)
//                    {
//                        ans=min(ans,num[i][2]-num[i][1]+1);
//                    }
//                    if(num[i][2]!=-1&&num[i][3]!=-1)
//                    {
//                        ans=min(ans,max(num[i][2],num[i][3])-i+1);
//                    }
//                }
//            }
//            cout<<ans<<endl;
//        }
//        else cout<<0<<endl;
//    }
//}
