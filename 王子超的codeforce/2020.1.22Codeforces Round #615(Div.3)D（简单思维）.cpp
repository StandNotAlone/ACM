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

//题意为一开始你的手上有一个空的数组，并给你一个数字x
//之后给你q个数，每次你要将这个数放入你的数组中，然后你可以对这个数组的任意数作任意次+x或者-x的操作
//最终要保证该数组的MEX最大，并输出MEX
//MEX为没有在该数组中出现的最小的自然数

//实际上我们可以对所有数作任意次+-x的操作的话，1和1+x还有1+2*x都是等价的，因此我们用每个数对x取模来表示这个数
//使用flag[i]存储余数为i的数出现了几次,我们的想法就是从0开始从小到大，用已有的数字来尽可能表示连续的数列

int main()
{
    ios::sync_with_stdio(false);
    int q,x,flag[400010];
    cin>>q>>x;
    int cas=0,num=0,t;//t为添加的数，cas为当前已经表示出几遍从0到x-1的余数，num为当前待表示余数
    memset(flag,0,sizeof(flag));
    for(int i=0;i<q;i++)
    {
        cin>>t;
        flag[t%x]++;
        while(flag[num]>cas)//出现次数大于等于当前需要个数（即cas+1)时，当前余数num被表示，待表示num变为num+1
        {
            num++;
            if(num==x)
            {
                num=0;
                cas++;
            }
        }
        cout<<cas*x+num<<endl;
    }
}

