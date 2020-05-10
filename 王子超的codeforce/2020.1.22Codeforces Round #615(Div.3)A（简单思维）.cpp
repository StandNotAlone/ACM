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

//算是非常水的一道题，姐姐有三个妹妹，她们四个人各有一定数量的硬币
//现询问姐姐能否将她的所有硬币任意分配给三个妹妹使得她们手上的硬币数量相等
//显而易见的我们先计算四个人硬币总和能否被3整除，无法被整除直接输出NO
//当能被3整除时，我们计算出分配后三个妹妹手上的硬币数，和她们原本拥有的硬币作比较
//能够分配的充要条件是她们原本拥有的硬币都小于等于最后的硬币数

int main()
{
    ios::sync_with_stdio(false);
    ll t,a,b,c,n,m,sum;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>n;
        m=max(a,b);
        m=max(m,c);         //m存储a,b,c中最大的数直接和最后的硬币数比较即可
        sum=a+b+c+n;
        if(sum%3) cout<<"NO"<<endl;
        else
        {
            if(sum/3>=m) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}

