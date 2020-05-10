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

//此题的题意为一个机器人在二维坐标轴的原点，他每次只能向上或者向右移动
//而在这个二维平面内的第一象限中有n个包裹，要求我们拾取所有的包裹
//如果能拾取所有包裹则输出最短（这是个烟雾弹）路径，不能输出NO
//其实我们可以观察到这个机器人只能向上或者向右，也就是说他从一个点到另一个点，不管用什么样的走法...最后的步数都会是一样的...
//步数都是x和y坐标差的和，因此实际上我们任意的路径都是最短的（大家都一样长）
//因此这里方便代码，先规定机器人的行走路径，当当前纵坐标没有包裹时向右走，有包裹时向上走吃完该纵坐标所有包裹，再向右走...
//再然后就是无法拾取所有包裹的判断了，我们当前位置的下一个目标包裹的纵坐标比当前会大，而我们只能向右或者向上走
//因此下一个目标包裹的纵坐标不能小于当前的纵坐标
//这是先向右走再向上走的思路，实际先向上再向右的判断方式也是类似可证

struct Cell     //定义了一个cell存储坐标
{
    int x,y;
}cell[1010];

bool cmp(Cell a,Cell b) //sort函数的比较部分，让所有包裹的位置按照我们拾取的先后顺序排序好
{
    if(a.x<b.x||a.x==b.x&&a.y<b.y) return 1;//横坐标小的在前，横坐标相同的纵坐标小的在前，符合我们先向右再向上走的策略
    else return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>cell[i].x>>cell[i].y;
        sort(cell,cell+n,cmp);
        int flag=1,y=-INF,x=0;
        for(int i=0;i<n;i++)    //先进行一遍路径模拟判断是否可以取完所有包裹
        {
            if(x==cell[i].x)
            {
                y=cell[i].y;
            }
            else
            {
                if(y>cell[i].y)
                {
                    flag=0;
                    break;
                }
                else
                {
                    x=cell[i].x;
                    y=cell[i].y;
                }
            }
        }
        if(flag)
        {
            cout<<"YES"<<endl;
            x=0;
            y=0;
            for(int i=0;i<n;i++)
            {
                if(x==cell[i].x)        //横坐标与下一个目标包裹相等时向上走
                {
                    while(y<cell[i].y)
                    {
                        cout<<"U";
                        y++;
                    }
                }
                else
                {
                    while(x<cell[i].x)//横坐标比下一个目标包裹小的时候先向右走到相等再向上走
                    {
                        cout<<"R";
                        x++;
                    }
                    while(y<cell[i].y)
                    {
                        cout<<"U";
                        y++;
                    }
                }
            }
            cout<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}

