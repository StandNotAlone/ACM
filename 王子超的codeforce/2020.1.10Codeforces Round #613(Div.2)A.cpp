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

//水题.读懂题意就非常简单。t个朝左或者朝右的操作有任意个可能失效，t个操作能走到的左边界和右边界的距离就是t，所以有t+1个能走到的位置

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int i=0;i<t;i++) getchar();
    printf("%d\n",t+1);
}
