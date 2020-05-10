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
    int n,m,sum[100],ans=INF;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d",&sum[i]);
    sort(sum,sum+m);                //从小到大排个序
    for(int i=n-1;i<m;i++)          //对整个序列中下标差n-1的两个数（即取这两个数和这两个数之间总计n个数）计算差值取最小
    {
        if(sum[i]-sum[i-n+1]<ans) ans=sum[i]-sum[i-n+1];
    }
    printf("%d\n",ans);
}
