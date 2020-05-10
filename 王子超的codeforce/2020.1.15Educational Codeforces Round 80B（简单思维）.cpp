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
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define pb push_back
#define ll long long
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//ios::sync_with_stdio(false);
using namespace std;
#define local
#ifdef local
#endif

//想到了这道题就是个超级简单的题目，果然cf前几题都是思维训练题
//a*b+a+b其实不就是a*(b+1)+b，然后要等于a和b拼接起来，我们注意到末尾的b已经相同了，所以实际上可以推出b只要是全部由9组成的数就可以了

int main()
{
    ios::sync_with_stdio(false);
    ll t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        ll flag=1,t=b,len=0;
        while(t)        //计算b有len位，flag表示b是不是全部都是9，如果是那么全部都是9的b就有len个满足的数，否则就是len-1个
        {
            len++;
            if(t%10!=9)
            {
                flag=0;
            }
            t/=10;
        }
        if(flag) cout<<a*len<<endl; //乘以a的情况个数就是答案
        else cout<<a*(len-1)<<endl;
    }
}
