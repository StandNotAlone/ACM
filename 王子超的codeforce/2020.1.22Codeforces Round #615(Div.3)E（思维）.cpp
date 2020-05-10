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
const int maxn=2e5+10;

//比赛的时候还是思维过于死板
//好吧思路确实挺难想的..
//题意为给定一个n*m的数字矩阵，要求你通过多少次操作后使得这个矩阵按照从1到n*m的自然顺序，从左到右，从上到下在矩阵内排列好
//你能进行的操作一是将某一列整体上移一位，操作二是将任意一个数改变成为你希望变成的任意一个数

//每一列是独立的，对每一列计算最少需要进行的操作数，累加便是ans
//而针对每一列怎么计算最少需要的操作数呢
//当时想到的就是很朴素的做法，对该列作0到n-1次的整体上移操作，分别计算每次上移操作后位置符合的数的个数x，再进行n-x次变换数字操作即可
//但是这种朴素做法的时间复杂度是O(n*n*m)明显是超时的，当时怎么都跳不出对整列进行上移操作后再计算的惯性思维

//这里其实一个思考的关键点在于要认识到对于某一列，进行相同次数操作一的方案，操作一和操作二的先后执行顺序对最后的效果是没有影响的，也就是最后操作次数是相等的
//认识到了这一点之后，我们就可以先通过找寻这一列的n个数字，它们如果经过一定次数的操作一后可以到达一个它符合排列条件的位置的话，我们记录下这个数字需要经过几次操作一可以达到这个位置
//这样的话经过O(n)的复杂度我们便计算出了对于这一列，进行0--n-1次(i)操作一后有多少个（x)数字是已经满足要求练度，那么还要对这一列的n-x个数字进行操作二
//这一列的总操作次数便是n-x+i次
//然后这个方案的最后一个关键点就是如何确定某个数字能否在经过一定次数操作一后能到达符合的位置，并且进行操作一的次数又是多少
//可以观察到，对于第j列来说，每一个数字减去j后都可以被m整除，并且商+1便是这个数应该在的位置，通过这一点我们就可以进行判断和计算了

vector<int>field[maxn];//这里要用vector不然开maxn^2爆内存，题目说了n*m不会超过2*10^5
int sum[maxn];         //sum[i]存储对于这一列，进行i次上移操作后有几个数字已经符合条件

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        field[i].pb(0);
        for(int j=1;j<=m;j++)
        {
            int x;
            cin>>x;
            field[i].pb(x);
        }
    }
    int ans=0;
    for(int j=1;j<=m;j++)
    {
        int now=INF;            //now存储当前列所需最小操作数
        for(int i=0;i<n;i++)    //对sum数组清零操作，注意这里不可以用memset
            sum[i]=0;           //sum数组大小是maxn，而m的最大情况也是maxn，最糟糕的情况会变成10^10级
        for(int i=1;i<=n;i++)
        {
            if((field[i][j]-j)%m==0&&field[i][j]<=n*m)//前半部分判断fidld[i][j]能否在一定次数上移操作后达到一个满足的位置，后半部分判断它的值是否满足在n*m内这个条件
            {
                sum[(i-(field[i][j]-j)/m-1+n)%n]++;//(field[i][j]-j)/m+1为field[i][j]应该在的位置的行数，与原来的行数相减便是需要进行的上移次数
            }                                      //由于可能会计算出负数，所以加一个n后再对n取模
        }
        for(int i=0;i<n;i++)
            now=min(now,i+n-sum[i]);                //得到从0次到n-1次上移操作所需次数中最小的次数，加到最后的ans上
        ans+=now;
    }
    cout<<ans<<endl;
}


