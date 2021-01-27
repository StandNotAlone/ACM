#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

string field[57];//存图
int flag[57][57];//每个位置的标记，0代表未被搜索过，非0值代表其在第几次搜索被搜索过
bool f=0;//记录是否存在圈
int n,m,cas=0;//cas记录当前是第几次搜索

int dir[4][2]=//存储上下左右四个方向
{
    1,0,
    -1,0,
    0,1,
    0,-1
};

void dfs(int x,int y,int prex,int prey)//x,y为当前的行标列标，prex和prey为上一步的行标和列标
{
    flag[x][y]=cas;
    for(int i=0;i<4;i++)//朝四个方向走
    {
        int nextx=x+dir[i][0];//下一步的位置
        int nexty=y+dir[i][1];
        if((nextx!=prex||nexty!=prey)&&nextx>=0&&nextx<n&&nexty>=0&&nexty<m)
            //不能走回头路，且不可以走出地图外
        {
            if(field[nextx][nexty]==field[x][y])//字符要相同
            {
                if(!flag[nextx][nexty]) dfs(nextx,nexty,x,y);//如果是未被搜索过的点，继续执行搜索
                else if(flag[nextx][nexty]==flag[x][y]) f=1;//如果是已经被搜索过的点，且是当前这次搜索搜到的点，代表出现了圈
            }
        }
    }
}

int main()
{
    IOS
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>field[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!flag[i][j])//如果发现未被搜索过的点，执行新的一次搜索
            {
                cas++;
                dfs(i,j,-1,-1);
            }
    if(f) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
