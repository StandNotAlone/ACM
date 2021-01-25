#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#include<set>
//#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define longlongINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define pb push_back
#define ll long long

#define local
#ifdef local
#endif

#define maxn
using namespace std;

ll n,s,ans=0;

//可以推理得到结论：真大数和非大数的范围是完全分开的，也就是从最小的真大数开始，比它大的数都是真大数，因此二分查找最小的真大数在哪里就可以了

int judge(ll x)             //检测x是不是really big number
{
    ll sum=0,x1=x;
    while(x1)
    {
        sum+=x1%10;
        x1/=10;
    }
    if(x-sum>=s) return 1;
    else return 0;
}

ll bs()
{
    ll l=s,r=n;
    ll mid;
    while(l<r-1)        //由于最小的那个真大数减去它各位数字的和后可能大于也可能等于s，不方便l=r直接跳出循环，所以让l=r-1时就跳出去
    {
        mid=l+(r-l)/2;
        if(judge(mid)) r=mid;
        else l=mid;
    }
    if(judge(l)) return l;  //从左侧开始检测是不是真大数
    if(judge(r)) return r;
    return -1;              //都不是的话返回一个负数
}

int main()
{
    scanf("%lld%lld",&n,&s);
    if(n>s)
    {
        ll num=bs();
        if(num>0)
        {
            ans=n-num+1;
        }
    }
    printf("%lld\n",ans);
}


