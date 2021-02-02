#include<stdio.h>
#include<string.h>
int sum,a[7],b[107],len;//sum为所有任务的天数综合，a[i]代表需要i天的任务有几件
bool dp[60001];
//b[]保存二进制优化的01背包
//dp[i]代表花费i天的分配方案是否存在

void get()
{
    sum=0;
    for(int i=1;i<=6;i++)
    {
        scanf("%d",&a[i]);
        sum=sum+i*a[i];
    }
}

void change()//二进制优化
{
    len=0;
    for(int i=1;i<=6;i++)//i代表当前优化的是需要i天的任务
    {
        int x=1;//对任务数量进行二进制分解,x从2进制最低位的1开始
        while(x<=a[i])
        {
            b[++len]=i*x;//x件任务合并为一个统一的任务
            a[i]-=x;
            x*=2;//二进制更高一位
        }
        if(a[i]) b[++len]=i*a[i];//剩余的部分合并为一个统一的任务
    }
}

int main()
{
    int flag,t=0;
    dp[0]=1;
    while(get(),sum)//逗号表达式，返回值为sum，当sum=0时推出循环；get函数负责读入
    {
        t++;//t记录当前是第几组数据
        flag=1;//标记是否存在平均分配的方案
        if(sum%2) flag=0;
        else
        {
            sum/=2;
            change();//将多重背包利用二进制优化为01背包
            for(int i=1;i<=len;i++)
                for(int j=sum;j>=b[i];j--)
                    if(dp[j-b[i]]) dp[j]=1;//01背包dp过程
            if(dp[sum]==0) flag=0;
            for(int i=1;i<=sum;i++) dp[i]=0;
        }
        printf("Collection #%d:\n",t);
        if(flag) printf("Can be divided.\n\n");
        else printf("Can't be divided.\n\n");
    }
}
