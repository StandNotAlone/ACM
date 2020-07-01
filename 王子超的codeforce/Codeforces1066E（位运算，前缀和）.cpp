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
const ll mod=998244353;

//这道题目我们要抛弃计算每次单次操作的累加值，而去关注对于二进制数s1中的每一个1对应总共会被计算几次

//因为是位与运算，并且二进制数s1在整个计算过程中是不变的，因此二进制数s1的每一位的1代表的值是不变的，并且每次操作累加值所能包含的1只能是s1对应位上的1

//如果s1的右侧第一个数字是1，那么对与长度为L2的二进制数s2，s2的第1-L2位置上出现的每个1都会和s1右侧第一个数字1进行一次与运算得到1
//如果s2的右侧第二个数字是2，那么对于长度为L2的二进制数s2，s2的第1-(L2-1)位置上出现的每个1都会和s1右侧第二个数字1进行一次与运算得到1
//.......

//因此我们借助一个前缀和数组cal[i]记录s2当中第1到第i个位置总共出现了几个1就可以计算s1中每一位1对应的系数了

int32_t main()
{
    IOS;
    ll L1,L2;
    cin>>L1>>L2;
    vec origin(L1+1);
    origin[1]=1;
    for(ll i=2;i<=L1;i++)
    {
        origin[i]=origin[i-1]*2%mod;        //预处理，orgin[i]代表2^(i-1)，也就是二进制数从最低位到最高位
    }
    string s1,s2;
    cin>>s1>>s2;
    ll ans=0;
    vec cal(L2+1,0);
    REP(i,L2)
    {
        cal[i]=cal[i-1]+s2[i-1]-'0'; //cal前缀和数组，记录s2当中下标1到下标i总共出现了几个1
    }
    REP(i,min(L1,L2))                 //注意这里循环上限是两个二进制数长度较小的那个
    {
        if(s1[L1-i]=='1')
        {
            ans=(origin[i]*cal[L2-i+1]%mod+ans)%mod;
        }
    }
    cout<<ans<<endl;
}


