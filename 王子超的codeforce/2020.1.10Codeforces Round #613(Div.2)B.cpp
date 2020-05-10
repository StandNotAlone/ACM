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
//这道题目的话只要从头和尾分别往后和往前加，出现非正数（因为要严格比第二个人大所以不能是0）就代表是NO
//推理过程的话可以这么去思考，如果第二个人取到的部分比第一个人大，那么就代表他没取到的左侧部分和右侧部分累加会是<=0，其实也就是至少有一侧<=0
int main()
{
    long long t,n,sum[100010];
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(int i=0;i<n;i++)
            scanf("%lld",&sum[i]);
        int flag=1;
        long long sum1=0,sum2=0;        //cf的第一次上分机会就被这两个变量没开long long整没了...不能怪比赛时评测机数据不行只能怪自己菜
        for(int i=0;i<n;i++)
        {
            sum1+=sum[i];
            sum2+=sum[n-i-1];
            if(sum1<=0||sum2<=0)
            {
                flag=0;
                break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}

