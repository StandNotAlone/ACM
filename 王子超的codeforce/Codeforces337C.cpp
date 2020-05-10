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
using namespace std;
int main()
{
    long long n,m,k,ans=1,t,xx=1e9+9,tmp=2;
    scanf("%lld%lld%lld",&n,&m,&k);
    if(n/k*(k-1)+n%k>=m) printf("%lld\n",m);   //首先我们尝试着一次也不达成连续对k题，那么我们每对k-1就错一题，一个部分就是k题，n/k*(k-1）即可以答对的题数，再加上n%k的余数就是一次也不达成连续对k题最多能对的题数。如果这个值大于m那么直接输出m
    else
    {
        t=m-n/k*(k-1)-n%k;//t是我们一次也不达成连续对k题情况下，仍然还要答对的题数
        int t1=t+1;       //我们其实可以注意到，在原本一次也不达成的情况下，再多答对的那道题越前面最后的值越小，对公式整理后会发现是k*(2^(t+1)-2)再加上剩余的题数
        while(t1)           //运用快速幂运算，直接暴力算会超时
        {
            if(t1%2) ans=ans*tmp%xx;
            tmp=tmp*tmp%xx;
            t1/=2;
        }
        ans-=2;
        if(ans<0) ans+=xx;      //注意这里ans-2后可能为负数，这时要多加一个xx让他变回正数
        ans=ans*k%xx;
        ans=(ans+m-k*t)%xx;
        printf("%lld\n",ans);       //幂运算的时间里加减乘法是等价的，但是除法是不等价的（另外要特别注意减法的时候可能会变成负数要手动加一个被除数
    }
}
