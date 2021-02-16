#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

bool field[107][107];
int n,m;
int dir[4][2]=
{
    1,0,
    -1,0,
    0,1,
    0,-1
};

struct Node
{
    int x,y,num;
};

int bfs()
{
    queue<Node>Q;
    Q.push({1,1,0});field[1][1]=1;
    while(1)
    {
        Node now=Q.front();
        Q.pop();
        if(now.x==n&&now.y==m) return now.num;
        for(int i=0;i<4;i++)
        {
            int tempx=now.x+dir[i][0],tempy=now.y+dir[i][1];
            if(tempx>=1&&tempx<=n&&tempy>=1&&tempy<=m&&!field[tempx][tempy])
            {
                field[tempx][tempy]=1;
                Q.push({tempx,tempy,now.num+1});
            }
        }
    }
    return -1;
}

int32_t main()
{
    IOS
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>field[i][j];
    cout<<bfs()<<endl;
}
