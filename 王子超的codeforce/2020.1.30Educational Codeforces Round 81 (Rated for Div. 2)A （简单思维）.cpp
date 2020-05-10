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

//题意为你要按照类似红绿灯和电子手表上显示数字的方法来用n条实线来表示出尽可能大的数字
//首先我们把0-9这几个数字每个数字需要多少个实线来表示计算出来
//0(6) 1(2) 2(5) 3(5) 4(4) 5(5) 6(6) 7(3) 8(7) 9(6)
//我们要用n条实线表示出尽可能大的数字，那么自然我们要让这个数字的位数更大，也就是说我们优先要找表示所需实线数目少的数字
//可以发现这里1所需的实线数目是最少的只要条，但是注意如果输入的n是奇数的话会多出来一条
//而我们可以注意到7的话只需要3条实线，比其他的数字都要少，而且3是奇数正好解决了n是奇数的问题
//因此如果输入的n条实线是偶数的话，直接不停输出1即可，如果是奇数则先输出一个7

int main()
{
    ios::sync_with_stdio(false);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%2) //n是奇数的情况输出一个7，减去消耗的实线数3
        {
            cout<<7;
            n-=3;
        }
        while(n)//循环输出1即可
        {
            cout<<1;
            n-=2;
        }
        cout<<endl;
    }
}
