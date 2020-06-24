#include<algorithm>
#include<iostream>
#include<cstring>
#include<fstream>
#include<iomanip>
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
//ifstream f1(".txt");
//ofstream f2(".txt");
//ios::sync_with_stdio(false);
//cin.tie(0);
using namespace std;
#define local
#ifdef local
#endif
const int maxn=INF;

//由于我们在两个班级当中，取得都是排名在中间的那个人
//针对2n个人，我们先对num[2n]这个数组从小到大排序
//我们可以总结出一个结论，所有的分配方案的差值一定是大于等于num[n+1]-num[n](下标从1开始）
//如果我们

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,a[200010];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(ll i=0;i<2*n;i++)
            cin>>a[i];
        sort(a,a+2*n);
        cout<<a[n]-a[n-1]<<endl;
    }
}



