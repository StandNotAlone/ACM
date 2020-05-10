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

//我们会发现移项后的式子为x=(b-y)*m，不难发现对于每个整数y，对应的x都是一个整数，并且-1/m的斜率不难发现y的取值范围更小，只有[0,b]
//因此直接for一遍y的取值范围，计算[0,y][0,x]这个矩阵范围内所有点的横纵坐标和就可以了
//而计算公式其实并不难推，x的部分是(1+x)*x*(1+y)/2，y的部分是(1+y)*y*(1+x)/2

int main()
{
    ios::sync_with_stdio(false);
    ll m,b;
    cin>>m>>b;
    ll ans=0,t;
    for(ll y=0;y<=b;y++)    //这里其实应该有一个纰漏，y=0的时候如果想要把最右侧的点取到的话，这个矩形是没有高的，那么这还算不算矩形呢，这个应该算出题人一个不严谨的地方
    {
        ll x=(b-y)*m;
        t=(1+x)*(1+y)*(x+y)/2;
        if(t>ans) ans=t;
    }
    cout<<ans<<endl;
}
