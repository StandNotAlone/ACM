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

一开始的班级人数就会存在一个最大值Max

求最小的所有班级人数的最大值x，分配的时候要让他尽可能小
我们的策略必然是让其他还没到达Max这个值的班级优先分配学生进去，直到等于Max，都不会改变x
因此我们用一个sum记录所有班级都打到Max人数需要安排多少人，如果m<=sum就代表最小的x就是Max
如果max>sum
也就是所有班级都放到Max人后，还剩下temp=m-sum个人代放
我们采取平均放的方式，一个一个依次分配到班级里
如果temp恰好被n整除，那么每个班级是平均的，增加的人数为temp/n
如果temp无法被n整除，那么temp%n个班级会比其他班级多一个人，增加的人数为temp/n+1

求最小的所有班级人数的最大值x,我们只需要把所有的m个新学生全部分配到一开始的最大班级人数Max的那个班去就行了

int32_t main()
{
    IOS;
    ll n,m;
    cin>>n>>m;
    vec num(n);
    ll Min=llINF,Max=-llINF;        //Min为这些班级一开始人数最小的值，Max为最大值的值
    at(x,num)
    {
        cin>>x;
        Min=min(Min,x);
        Max=max(Max,x);
    }
    ll sum=0;
    at(x,num) sum+=Max-x;
    if(m<=sum) cout<<Max<<' ';
    else
    {
        ll temp;
        if((m-sum)%n) temp=(m-sum)/n+1;
        else temp=(m-sum)/n;
        cout<<temp+Max<<' ';
    }
    cout<<Max+m<<endl;
}


