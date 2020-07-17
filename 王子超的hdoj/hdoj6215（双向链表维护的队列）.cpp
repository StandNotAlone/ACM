#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<queue>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define longlongINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
using namespace std;

int a[100010],pre[100010],nxt[100010],que[100010];      //a数组存储输入m个数据的值，pre为当前数的前一个，nxt为下一个，que为当前需要排序的队列范围

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m;
        scanf("%d",&m);
        int nowr=m;             //nowr存储当前待排序队列的尾下标
        for(int i=0;i<m;)           //初始化
        {
            que[i]=i+1;
            pre[i+1]=i;
            nxt[i]=i+1;
            scanf("%d",&a[++i]);
        }
        nxt[m]=m+1;                 //让末尾指向m+1，已到达后面程序体跳出循环的条件
        int ans=m;
        while(1)
        {
            int flag=1,nowl=0,sum=0;        //！flag代表当前是否已经被排序好，nowl表示当前排序的头下标，sum表示本次排序后的待排序队列长度
            while(nowl<nowr)
            {
                int x=que[nowl],num=0;              //num存储多少个数不符合排序的条件
                while(nxt[x]<=m&&a[x]>a[nxt[x]])
                {
                    flag=0;
                    num++;
                    x=nxt[x];
                }
                if(num)
                {
                    ans-=num+1;
                    nxt[pre[que[nowl]]]=nxt[x];         //当前待排序的前一个数（当前排序的数被清除了）的后指针指向x的后指针
                    pre[nxt[x]]=pre[que[nowl]];         //x的后一个数的前指针指向当前排序的前一个数
                    que[sum++]=pre[que[nowl]];          //排序后的队列存储待排序的前一个数，并且sum+1
                }
                while(que[nowl]<=x&&nowl<nowr) nowl++;    //x代表的是已经被排序的右侧下标，因此让nowl一直右移直到超过他
            }
            nowr=sum;
            if(flag) break;
        }
        printf("%d\n",ans);
        int num=0;
        for(int nowl=0;nowl<=m;nowl=nxt[nowl],num++)
            if(nowl)printf("%d ",a[nowl]);                  //这里最后一个数后面也要带个空格不然它给你PE..
        printf("\n");
    }
}