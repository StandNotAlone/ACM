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

//这道题的思路是分解成二进制后从最高位开始看，如果只出现0或者1的话那么答案的这一位就是0
//如果又出现0又出现1点话，答案的这一位就是1，再根据0还是1分成两个部分去看下一位的情况，取这两个部分的最小值
//人生第一次写出cf的D题
//当时想到了这个思路但是没有能够在比赛时间内用递归来实现出来，或者说脑子里仍然是递推实现的死板思路，只能说水平还是有差距

vector<int>a;

int solve(vector<int>&b,int bit) //&重复利用数组a降低内存消耗，bit为当前正在判断的位数
{
    if(b.size()==0||bit<0) return 0;    //注意bit可以取0来对最后一位来进行判断
    vector<int>l,r;
    for(int i=0;i<b.size();i++)
    {
        if(b[i]>>bit&1) l.pb(b[i]); //和1进行与运算就能判断末尾是1还是0
        else r.pb(b[i]);
    }
    if(l.size()==0) return solve(r,bit-1);
    if(r.size()==0) return solve(l,bit-1);
    return min(solve(l,bit-1),solve(r,bit-1))+(1<<bit);
}

int main()
{
    int n;
    scanf("%d",&n);
    a.resize(n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("%d\n",solve(a,30));     //最大数据没超过2^30
}


