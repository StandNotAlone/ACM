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

//做了i次操作(i≤n-i+1)每次操作把第i个到第n-i+1个骰盅倒序
//你会发现第一次操作是把第1个到第n个倒序，第二次操作把第2个到第n-1个倒序
//第三次操作把第3个到第n-2个倒序........
//不难发现，每个骰盅在每次操作后都是和对称位置的骰盅交换位置
//而每个骰盅交换的次数和它的位置有关，距离左边界距离（或者右边界，看它在中心线的左侧还是右侧）
//如果骰盅下标从1到n，那么下标1的骰盅就是进行了1次交换，下标2的骰盅就是进行了2次交换...
//进行奇数次交换后，前后位置互换；进行偶数次交换后，位置不变
//因此直接for一遍1到n/2，奇数的时候前后交换位置放置，偶数的时候前后原位置放置

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int num[200010];    //存放初始骰盅的价值和位置
    for(int i=1;i<=n;i++)
        cin>>num[i];
    int flag[200010];   //存放操作后各个骰盅所在位置
    for(int i=1;i<=n/2;i++)
    {
        if(i%2)
        {
            flag[i]=n+1-i;  //奇数情况前后位置交换放置
            flag[n+1-i]=i;
        }
        else
        {
            flag[i]=i;      //偶数情况前后位置不变直接放置
            flag[n+1-i]=n+1-i;
        }
    }
    if(n%2) flag[n/2+1]=n/2+1;//n是奇数的时候，让中间位置放置它的原位置（上面代码flag数组没有进行赋初值）
    cout<<num[flag[1]];
    for(int i=2;i<=n;i++)   //根据flag数组存放的位置下标依次输出值即可
        cout<<' '<<num[flag[i]];
    cout<<endl;
}
