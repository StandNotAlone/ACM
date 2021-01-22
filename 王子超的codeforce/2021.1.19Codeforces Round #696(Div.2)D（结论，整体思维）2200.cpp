#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int num[200007];//记录每个位置初始值
int rest[200007];//rest[i]代表从左往右清空i位置前的所有值后，i位置剩下的值，也就是需要与i+1位置一起删除的值
int n;

int main()
{
    IOS
    int t;cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>num[i];
        int tar=0;//记录rest第一次出现非法的位置
        for(int i=1;i<=n;i++)//从左往右依次清空
        {
            if(rest[i-1]>num[i]&&!tar) tar=i;
            rest[i]=num[i]-rest[i-1];
        }
        if(!tar&&rest[n]>0) tar=n+1;//如果最后一个位置仍然有值待处理，仍然是无法不更改顺序清空的情况
        //注意这里要加个tar不为0，否则tar记录的第一次非法位置可能被改变
        if(tar)//如果存在非法位置
        {
            if(rest[n]%2) cout<<"NO"<<endl;//如果最后剩下的是奇数，由于每次操作减去的值为2是个偶数，最后都不可能被清零
            else
            {
                int flow=rest[n]/2;//记录需要交换位置的相邻两个数的差值
                bool f=0;
                for(int i=n;i>1;i--)
                {
                    rest[i]-=flow*2;//当前位置的rest减去两倍flow
                    if(rest[i]<0) break;//rest不能为负数
                    if(rest[i-1]+flow>=0&&num[i]-num[i-1]==flow&&tar>=i-1) {f=1;break;}
                    //找到了相邻两个位置差值为flow，并且位置在第一个(也就是最左边)非法位置的左边
                    //代表之前的非法flow位置也已经在上述过程中合法了，整体满足要求
                    flow=-flow;//移动一个位置后flow变为负数，很好理解，当前位置剩下的值变多了x，那么下个位置剩下的值就会减少x
                }
                if(f) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
        else cout<<"YES"<<endl;//不存在非法位置且最后被清零，直接输出
    }
}
