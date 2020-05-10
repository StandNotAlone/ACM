#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define longlongINF 9223372036854775807
#define pi 3.14159265358979323846264338327950254
using namespace std;
long long dp[2][1000001];
int sx[1000001]={0};
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) scanf("%d",&sx[i]);
        bool cas=0;         //这里用到了一个滚动数组的知识，通过bool型不断取反来交替反复使用两个数组达到节省内存空间的作用
        long long ans=-longlongINF;
        for(int i=1;i<=m;i++)                   //循环i次后的dp数组中存储的是前j个元素划分成i个子段的最大值
        {
            cas=!cas;
            dp[cas][i-1]=-longlongINF;
            long long maxs=dp[!cas][i-1];
            for(int j=i;j<=n;j++)
            {
                dp[cas][j]=max(maxs,dp[cas][j-1])+sx[j];        //状态转移方程，这里用maxs来存储划分i-1个子段时候（i-j-1）个元素能构成的最大值
                maxs=max(maxs,dp[!cas][j]);
            }
        }
        for(int i=m;i<=n;i++) ans=max(ans,dp[cas][i]);
        printf("%lld\n",ans);
    }
}
//这里直接贴来源自网上的题解，题目中的实现部分并没有完全按照题解来
//首先，dp[i][j]用来表示由前 j项得到的含i个字段的最大值，且最后一个字段以num[j]项结尾。（避免产生不相连的情况）递推式为:(同时缩小段落数和序列数)
//dp[i][j]=max(dp[i][j-1]+num[j],dp(i-1,t)+num[j]) 其中i-1<=t<=j-1.
//(因为必须是以 num[j] 结尾的，所以num[j]一定属于最后一个子段，即要么自己独立成一个子段，要么与前边以num[j-1]结尾的子段联合)
//
//所求的最后结果为 max( dp[m][j] ) 其中1<=j<=n.
//但是，我们会发现，当n非常大时，这个算法的时间复杂度和空间复杂度是非常高的,时间复杂度近似为O(mn^2)，空间复杂度近似为O(mn)。因此，我们需要优化算法来降低时间复杂度和空间复杂度.
//
//算法优化：dp[i][j]=max(dp[i][j-1]+num[j],dp(i-1,t)+num[j])，其中i-1<=t<=j-1.我们只要找到dp[i][j-1]和dp[i-1][t]的最大值加上num[j]即为dp[i][j].所以，定义一个数组pre_max[n]，用pre_max[j-1]来表示求解dp[i][j]时dp[i-1][t]的最大值,则
//dp[i][j]=max(pre_max[j-1],dp[i][j-1])+num[j].
//
//在求解dp[i][j]的同时，我们可以计算出dp[i][t];i<=t<=j的最大值，这个最大值在计算dp[i+1][j+1]的时候需要作为pre_max[j]的形式被使用，我们先把它存在pre_max[0]中。
//
//你可能会问：为什么不把它直接放在pre_max[j]中呢？因为你接下来需要计算dp[i][j+1]的值，需要用到pre_max[j]中原来的值， 如果你把它存在这里，就会覆盖掉计算dp[i][j+1]所需要的那个值。所以，先把它放在pre_max[n]中。
//当我们计算完dp[i][j+1]之后，就会发现pre_max[j]中的值已经没有用处了，我们可以把它更新为计算dp[i+1][j+1]所需要的那个值，即之前放在pre_max[n]中的那个值，即执行pre_max[j]=pre_max[0].
//这样，最后的时间复杂度为O(mn)。
//
//通过时间的节省，我们突然间发现程序执行结束后pre_max[n]的值即为最后的结果，pre_max[n]数组才是我们希望求解的，dp[m][n]这个庞大的数组已经不是那么重要了，因此，我们现在用整型数tmp来代替dp[m][n]，用来临时存储dp[i][j]的值，作为求解pre_max[n]的中介。（这里，可以先用dp数组实现一遍，再用tmp）
//这样，最后的时间复杂度为O(n)。//这里说错了，时间复杂度是O（mn）
