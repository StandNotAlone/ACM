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

//这道题目的思考过程是这样的，a和b的最小公倍数是x，那么a和b分解质因数，相同的质因数出现的次数取最大，相乘就是x。
//而a和b的最大值要最小，也就是代表在满足a和b最小公倍数是x的情况下，要除去a和b不需要的质因数，而a,b相同的质因数出现次数最大的那一个和x里该质因数出现的次数一样就可以了
//也就是代表比如b里面2出现了3次，x里2也出现了3次，a里2出现了2次，那么a可以把这两个2除去
//经过这样的操作之后我们会发现a和b是一个互质的关系，gcd(a,b)=1，并且a*b=x
//因此对x直接开平方后就从1e12变成1e6，再向下（脑残一开始向上枚举然后tle了...)枚举就可以了

long long gcd(long long a,long long b)
{
    if(b) return gcd(b,a%b);
    else return a;
}

int main()
{
    long long x;
    scanf("%lld",&x);
    long long y,z;
    y=sqrt(x);
    for(;y;y--)
    {
        if(x%y==0)
        {
            z=x/y;
            if(gcd(z,y)==1) break;
        }
    }
    printf("%lld %lld\n",y,z);
}

