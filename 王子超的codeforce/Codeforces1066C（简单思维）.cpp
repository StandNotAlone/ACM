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
const ll maxn=2e5+7;
const double eps=1e-10;
const ll mod=1e9+7;
/*
列车想要出来，必然是把它左侧的列车全部出站，或者右侧的列车全部出站。不可能两侧都有出站，那样就会出现无用操作，一定不是最优解

我们可以把这个火车站看成一个队列，我们只要知道当前队列的左右下标，以及目标列车的位置，就可以通过下标相减得到目标列车左侧或者右侧的列车数量，取更小的那一个就行了

注意到此题中的列车编号范围是1-2e5，比较小，因此我们完全可以类似桶排序的思想，用一个数组a[num]记录编号num的列车所在的位置

大一的上学期刚上了数据结构，这里使用的思想就类似于栈队列那章知识的用两个变量记录队列左右下标
*/


ll target[maxn];

int32_t main()
{
    IOS;
    ll t;
    cin>>t;
    ll l=llINF,r;    //l为队列左侧下标，r为队列右侧下标,初始化l为llINF代表为空
    while(t--)
    {
        char ope;
        ll num;
        cin>>ope>>num;
        if(ope=='?') cout<<min(abs(target[num]-l),abs(target[num]-r))<<endl;
        else if(l==llINF)   //第一本书放在位置0
        {
            l=r=0;  //放入第一本书后将l和r下标均置为0
            target[num]=0;  //记录列车位置
        }
        else if(ope=='L') target[num]=--l;  //左侧进站，左下标-1，并记录
        else if(ope=='R') target[num]=++r;  //右侧进站，右下标+1，并记录
    }
}


