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

//题意为你和n个人对抗，每轮场上剩下s个人，你可以将其中t个人打败，然后得到t/s的钱，要求你求出将所有人都打败后的最大获得金钱
//这里用数学归纳法证明一下.反证的方法，证明对于每一轮我们都只打败一个人，获得1/s的钱是最优策略即可

int main()
{
    //ios::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    double ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=1/(double)(n-i);
    }
    printf("%.10lf\n",ans);
}

