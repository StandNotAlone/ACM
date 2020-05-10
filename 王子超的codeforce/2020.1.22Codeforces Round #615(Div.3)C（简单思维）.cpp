#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<fstream>
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
//ifstream f1(".txt");
//ofstream f2(".txt");
//ios::sync_with_stdio(false);
using namespace std;
#define local
#ifdef local
#endif

//题意为给你一个数n，要求你找出三个大于等于2且互不相同的数a,b,c满足a*b*c=n，输出任意情况
//既然是输出任意情况那我们从最小的2开始找，规定a<b<c，我们只要找到a和b再判断一下c是否满足不等于a和b就行了

int main()
{
    ios::sync_with_stdio(false);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<24) cout<<"NO"<<endl;//存在满足条件a,b,c最小的数是2*3*4=24
        else
        {
            int a=0,b=0,c=0;           //a,b,c的初值都赋为0方便后续判断
            for(int i=2;i<=sqrt(n);i++)//先找到n大于等于2的最小的一个因数
                if(n%i==0)
                {
                    a=i;
                    break;
                }
            if(a&&a*a*a<n)                //如果找到了a并且a*a*a<n，即我们还可以从n的剩余部分中找到两个比a大的数
            {
                for(int i=a+1;i<=sqrt(n/a);i++)//从a+1开始找b，注意这里的上限不再是sqrt(n)而是sqrt(n/a)
                    if(n/a%i==0)
                    {
                        b=i;
                        break;
                    }
                if(b&&n/a/b>b)          //a和b都找到的情况下计算c，c如果比b要大则满足
                {
                    c=n/a/b;
                }
            }
            if(a&&b&&c) cout<<"YES"<<endl<<a<<' '<<b<<' '<<c<<endl;//a,b,c均找到的情况下输出该情况
            else cout<<"NO"<<endl;
        }
    }
}

