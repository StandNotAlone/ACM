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

//题意为有一块2*n的矩阵，你在(1,1)的位置，要到(2,n）位置去
//起始所有地块都是可走的
//总共有q秒钟，下方q行给你一个坐标（不包括起点和终点），代表该地块变成岩浆（不可走）或者重新从岩浆变为地面
//要求你对这q秒钟每秒能否从起点走到终点进行输出

//q的数据是1e5，n也是1e5，很明显我们不可能对每一秒都去搜索整个图寻找是否可以走到终点
//这里可以观察到这道题的矩阵是2*n的，行数只有2，那么在什么时候会让阻止我们走到终点呢？
//分析可以发现，假设第一行的第i块地块变成了岩浆，那么第二行的i-1,i,i+1块地块中任意一块如果也是岩浆就会阻止我们走到终点
//由此切入，我们记录每一秒钟是否存在这样的情况阻止我们到达终点即可

int flag[2][100010];//flag数组记录每一个地块的情况，0代表可走1代表不可走

int main()
{
    ios::sync_with_stdio(false);
    memset(flag,0,sizeof(flag));
    int n,q,ans=0;              //ans记录当前地块中存在几种阻止我们到达终点的情况，如果是0则可走
    int r,c;
    cin>>n>>q;
    for(int i=0;i<q;i++)
    {
        cin>>r>>c;
        if(flag[r-1][c])        //如果该地块已经变成了岩浆不可走
                                //注意这里第一个下标是0和1，方便后面用！操作取另一行，因此这里是r-1
        {
            flag[r-1][c]=0;
            for(int j=-1;j<2;j++)   //列标增加-1到1，寻找另一行中的对应三个地块
            {
                if(c+j>0&&c+j<=n&&flag[!(r-1)][c+j])
                    ans--;
            }
        }
        else
        {
            flag[r-1][c]=1;
            for(int j=-1;j<2;j++)
            {
                if(c+j>0&&c+j<=n&&flag[!(r-1)][c+j])
                    ans++;
            }
        }
        if(ans) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}

