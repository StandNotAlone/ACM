#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e5+10;

//题意为给你一个有n个节点n-1条边的树(没有闭环的图）
//要求你在这棵树里找到三个节点，使得它们之间的三条路径走过的边数最多（多次经过同一条边只算一次）
//首先要知道树的直径这个概念.树的直径是整棵树中两点距离最长的那一条路径

//先用反证的方法证明三条路径必定至少有一条会是树的直径
//如果三条路径中没有任何一条是树的直径
//我们可以将其中的两个点更换为树的直径两端的端点，会发现长度变得更大了
//因此三条路径中没有任何一条是直径的情况必然不是总长度最长的

//因而首先我们可以确定这三条路径中必定至少存在一条直径，这样就确定了两个点，再就是第三个点如何确定
//第三个点和第一还有第二个点的路径合起来的新路径，必定包含了这条直径
//那么在原来已经找到的这条直径基础上加上这个第三个点，规定第三和第一个点的距离为d1，第三和第二个点的距离为d2，树的直径为x
//那么加入第三个点后增加的边数就应该是(d1+d2-x)/2，而x是我们计算出的一个定值
//所以实际上第三个点需要满足的条件是和第一个点还有第二个点的距离和最大

//到此思路已经全部完成，首先是求取树的直径的两个端点，这个方法和证明过程自己见算法书或者博客
//dfs第一次从1点开始，dst[i][0]记录i点到1点的距离，距离最大的点为直径的第一个端点a
//dfs第二次从a点开始，dst[i][1]记录i点到a点的距离，距离最大的点为直径的第二个端点b
//dfs第三次从b点开始，dst[i][2]记录i点到b点的距离，由此我们便计算出了整棵树各个点到点a还有点b的距离，由此去寻找c点

vector<int>road[maxn];//记录路径
int dis[maxn][3];

void dfs(int now,int before,int sum,int cas)//now为当前所在节点位置，before为上一个节点位置，sum为当前到起点的距离，cas为dst第二个下标
{
    for(int i=0;i<road[now].size();i++)
    {
        if(road[now][i]!=before)         //这是个无闭环的图，因此我们任意的搜索路径也都是无闭环的，只要满足不往回走就可以了
        {
            dis[road[now][i]][cas]=sum+1;
            dfs(road[now][i],now,sum+1,cas);
        }
    }
}

int main()
{
    IOS
    memset(dis,0x7f,sizeof(dis));
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        road[x].push_back(y);
        road[y].push_back(x);
    }
    dis[1][0]=0;
    dfs(1,1,0,0);
    int a,b,c,Max=-INF;
    for(int i=2;i<=n;i++)
        if(dis[i][0]>Max)
        {
            Max=dis[i][0];
            a=i;
        }
    dis[a][1]=0;
    dfs(a,a,0,1);
    Max=-INF;
    for(int i=1;i<=n;i++)   //这个循环结束后Max记录的便是直径的长度
    {
        if(dis[i][1]>Max)
        {
            Max=dis[i][1];
            b=i;
        }
    }
    dis[b][2]=0;
    dfs(b,b,0,2);
    int ans=-INF;
    for(int i=1;i<=n;i++)       //ans记录的是c点到a点和b点的距离和
    {
        int x=dis[i][1]+dis[i][2];
        if(x>ans&&i!=a&&i!=b)  //注意这里如果整棵树只有一条路径的话寻找c点的时候可能会和a或者b点重复
        {
            ans=x;
            c=i;
        }
    }
    ans=(ans+Max)/2;            //原本应该是(ans-Max)/2+Max，化简了一下
    cout<<ans<<endl;
    if(a>b) swap(a,b);
    if(b>c) swap(b,c);
    if(a>b) swap(a,b);
    cout<<a<<' '<<b<<' '<<c<<endl;
}
