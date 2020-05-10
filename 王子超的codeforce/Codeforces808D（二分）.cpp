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

#define local
#ifdef local
#endif

#define maxn

using namespace std;

//这道题要求我们移动（不是交换）一个数字后可以分成两个相等的部分，那么我们按照（0，n)（1，n-1)(2,n-2)...的顺序把原序列分成两个部分，比较两个部分的差值，从大的那里找差值一半的数是否存在就可以了

ll n,len=0;//len记录arr1数组存了几个数

struct Cell
{
    ll num,min,max;
};

struct Mynum
{
    ll num;
    ll dis;
};

vector<Cell>arr1;       //记录整个排序后的arr中出现了哪些数，min记录最小下标max记录最大下标
vector<Mynum>arr;       //arr存储初始的数值，.dis存储原本的下标位置
vector<ll>sum;          //前缀和数组，sum[i]记录前i个数的和

bool cmp(Mynum x,Mynum y)
{
    return x.num<y.num;
}

bool judge1(ll x,ll target)
{
    ll l=1,r=len,mid;
    while(l<r-1)
    {
        if(arr1[r].num==target) //特判右侧即可，下方的判断语句用的是<target赋给l因此l不会是边界
        {
            if(arr1[r].max>x) return 1;
            else return 0;
        }
        mid=l+(r-l)/2;
        if(arr1[mid].num<target) l=mid;
        else r=mid;
    }
    if(arr1[l].num==target&&arr1[l].max>x) return 1;//跳出循环的话要特判左右两侧
    if(arr1[r].num==target&&arr1[r].max>x) return 1;//后序列和大的时候要求找到的那个数的最大下标要比当前分割的下标要大
    return 0;
}

bool judge2(ll x,ll target)
{
    ll l=1,r=len,mid;
    while(l<r-1)
    {
        if(arr1[r].num==target)
        {
            if(arr1[r].min<=x) return 1;
            else return 0;
        }
        mid=l+(r-l)/2;
        if(arr1[mid].num<target) l=mid;
        else r=mid;
    }
    if(arr1[l].num==target&&arr1[l].min<=x) return 1;//前序列和小的时候找到的那个数的最小下标要不大于
    if(arr1[r].num==target&&arr1[r].min<=x) return 1;
    return 0;
}

int main()
{
    scanf("%lld",&n);
    arr.resize(n+1);
    sum.resize(n+1);
    arr1.resize(n+1);
    sum[0]=0;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i].num);
        sum[i]=sum[i-1]+arr[i].num;
        arr[i].dis=i;
    }
    sort(&arr[1],&arr[n+1],cmp);//将arr数组从小到大排序以用于二分查找
    arr1[0].num=-1;
    for(ll i=1;i<=n;i++)//对arr1数组初始化
    {
        arr1[i].min=llINF;
        arr1[i].max=0;
    }
    for(ll i=1;i<=n;i++)        //对排序后的arr数组数据处理后放入arr1中
    {
        if(arr[i].num==arr1[len].num)
        {
            if(arr[i].dis>arr1[len].max) arr1[len].max=arr[i].dis;
            if(arr[i].dis<arr1[len].min) arr1[len].min=arr[i].dis;
        }
        else
        {
            len++;
            arr1[len].num=arr[i].num;
            arr1[len].max=arr[i].dis;
            arr1[len].min=arr[i].dis;
        }
    }
    if(sum[n]%2||n==1) printf("NO\n");//特判总和是奇数还有只有一个数的情况
    else
    {
        bool flag=0;
        for(ll i=0;i<n;i++)     //注意i要从0开始取
        {
            ll target=sum[n]/2-sum[i];      //总和的一半减去当前序列的总和即为（后序列和-前序列和）/2
            if(target==0)                   //如果相等直接判定正确
            {
                flag=1;
                break;
            }
            else if(target>0)               //如果后面的大用judge1
            {
                if(judge1(i,target))
                {
                    flag=1;
                    break;
                }
            }
            else if(judge2(i,-target))      //前面的大用judge2
            {
                flag=1;
                break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}


