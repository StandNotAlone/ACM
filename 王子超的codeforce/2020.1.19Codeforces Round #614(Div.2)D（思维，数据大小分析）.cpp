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
//2251799813685248 2251799813685248 10000000000000000
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
const int maxn=INF;

//事实证明许多比赛时认为的不可写题都是因为自己心里已经有了这个成绩已经够了的心态
//多次比赛里后劲乏力侧面说明了自己的坚持还不够

//题意为在一个二维的平面上，你在起始位置s(s.x,s.y)上，你可以在这个平面上停留t秒，每秒你可以选择上下左右四个方向移动一格
//在这个平面上有无数个箱子等着你去拾取，第一个箱子的位置在（x0,y0)，题目给你值ax,ay,bx,by,下一个箱子的横坐标是 上一个箱子横坐标*ax+bx,纵坐标是上一格箱子纵坐标*ay+by
//要求你求出t秒钟内你最多可以拾取多少个箱子

//当时想这道题目的时候被庞大的输入数据震到了，1e16级别，但是实际上冷静想一想根本没有这么可怕
//我们注意到ax和ay都是大于等于2的，也就是说节点的个数最多也只会有log2(1e16)级别，是可以接受的
//接下来是推导我们行走路径的过程

//可以在稿纸上模拟我们的拾取过程，由于ax,ay的数据都是大于等于2的，而bx,by的数据都是非负数，那么下一个节点的位置一定在上一个节点位置的右上角
//实际我们可以将所有的节点当做在一条路径上，也就是说假设我们在节点4和5之间，如果我们要拾取节点3，我们就一定可以经过节点4
//假设我们拾取的所有节点的左节点为l，右节点为r
//由这个拾取过程我们可以发现我们的路径是先到达左节点l再向右到右节点r，或者是先到右节点r再到左节点l
//因此拾取从节点l到节点r之间所有节点耗费的时间就是节点l和节点r的距离+min(distance(l,s),distance(r,s))
//直接暴力枚举所有可能走到的节点，第一层循环枚举左节点，第二层节点枚举右节点，计算耗费时间是否在t内即可，时间复杂度O(lg(t)^2)

struct Node //定义了一个坐标结构体
{
    ll x,y;
};

vector<Node>node;//存储和起始位置距离在t内的节点（实际左侧的点会可能超过t距离，但是由于计算和代码方便需要也将其压入数组

int main()
{
    ios::sync_with_stdio(false);
    Node a,b,s,newnode;
    ll t;
    cin>>newnode.x>>newnode.y>>a.x>>a.y>>b.x>>b.y>>s.x>>s.y>>t;
    while(1)
    {
        node.pb(newnode);
        newnode.x=newnode.x*a.x+b.x;
        newnode.y=newnode.y*a.y+b.y;
        if(newnode.x-s.x+newnode.y-s.y>t)//距离超出t时跳出循环
                                         //注意这里没有abs
            break;
    }
    ll ans=0;
    for(ll i=0;i<node.size();i++)//i为左节点
    {
        ll m=abs(node[i].x-s.x)+abs(node[i].y-s.y);//m存储左节点到起始s点的距离
        for(ll j=i;j<node.size();j++)       //j为右节点
        {
            ll M=abs(node[j].x-s.x)+abs(node[j].y-s.y);//M存储右节点到起始s点的距离
            ll d=abs(node[j].x-node[i].x)+abs(node[j].y-node[i].y);//d为左右节点距离
            if(d+min(m,M)<=t)//同上分析的表达式
            {
                ans=max(ans,j-i+1);
            }
        }
    }
    cout<<ans<<endl;
}


