#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int num[107];//记录每个数字出现了几次

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        memset(num,0,sizeof(num));
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            num[x]++;
        }
        int ans=0;
        for(int j=0;j<2;j++)//执行两次，分为两个部分
        {
            for(int i=0;1;i++)
            {
                if(i==101) {ans+=101;break;}//循环到101就可以结束了，输入数据最大也只有100
                if(num[i]==0) {ans+=i;break;}//当前数字不存在，则就为当前部分的最小未出现自然数，累加到答案并结束循环
                else num[i]--;//代表使用一个数字到当前部分里
            }
        }
        cout<<ans<<endl;
    }
}

