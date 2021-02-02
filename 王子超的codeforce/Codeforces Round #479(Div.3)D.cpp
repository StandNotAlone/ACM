#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<int>field[107];//保存图的边信息i点与field[i]中的元素存在有向边
ll num[107];
int n;
bool visit[107];//记录各个点被访问的情况
vector<int>road;//保存路径，用数组实现而不是使用vector的push和pop操作会更快,这里出于方便理解的考虑写成vector形式

void dfs(int now)
{
    visit[now]=1;//当前位置置为访问过
    road.push_back(now);//压入路径中

    if(road.size()==n)
    {
        for(int i=0;i<n;i++) cout<<num[road[i]]<<' ';
        exit(0);//找到满足的路径后直接结束程序
    }

    for(int i=0;i<field[now].size();i++)//遍历当前结点出发可以走到的其他点
        if(!visit[field[now][i]]) dfs(field[now][i]);//如果下个位置未被访问过，即未被走过的路径，继续递归搜索

    road.pop_back();//还原
    visit[now]=0;//还原
}

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(num[j]*3==num[i]||num[i]*2==num[j])//暴力for一遍建图
                field[i].push_back(j);
    for(int i=1;i<=n;i++) dfs(i);//以这n个数字分别作为第一个数字进行搜索
}
