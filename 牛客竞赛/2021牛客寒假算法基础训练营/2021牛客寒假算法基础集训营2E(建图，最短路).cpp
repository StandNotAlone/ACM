#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

int n;
struct Line
{
    int l,r,num;
};

vector<Line>y[maxn];
vector<int>field[maxn];
int dis[maxn];

bool cmp(Line a,Line b)
{
    return a.l<b.l;
}

struct Node
{
    int pos;int val;
    Node(int pos,int val):pos(pos),val(val){}
    friend bool operator < (Node a,Node b)
    {
        return a.val>b.val;
    }
};

int Dijkstra(int start,int target)
{
    for(int i=1;i<=n;i++) dis[i]=maxn*10;
    dis[start]=0;
    priority_queue<Node>Q;
    Q.push(Node(start,0));
    while(Q.size())
    {
        Node now=Q.top();
        Q.pop();
        if(now.val>dis[now.pos]) continue;
        for(int i=0;i<field[now.pos].size();i++)
        {
            int to=field[now.pos][i];
            if(dis[to]>now.val+1)
            {
                dis[to]=now.val+1;
                Q.push(Node(to,dis[to]));
            }
        }
    }
    return dis[target];
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int tar;
        Line temp;
        scanf("%d%d%d",&tar,&temp.l,&temp.r);
        temp.num=i;
        y[tar].push_back(temp);
    }
    for(int i=0;i<=100000;i++)
    {
        sort(y[i].begin(),y[i].end(),cmp);
        for(int j=0;j+1<y[i].size();j++)
            if(y[i][j].r==y[i][j+1].l)
            {
                field[y[i][j].num].push_back(y[i][j+1].num);
                field[y[i][j+1].num].push_back(y[i][j].num);
            }
    }
    for(int i=1;i<=100000;i++)
    {
        int tar1=0,tar2=0;
        while(tar1<y[i-1].size()&&tar2<y[i].size())
        {
            if(y[i-1][tar1].r>=y[i][tar2].r)
            {
                if(y[i][tar2].r>y[i-1][tar1].l)
                {
                    field[y[i-1][tar1].num].push_back(y[i][tar2].num);
                    field[y[i][tar2].num].push_back(y[i-1][tar1].num);
                }
                tar2++;
            }
            else
            {
                if(y[i-1][tar1].r>y[i][tar2].l)
                {
                    field[y[i-1][tar1].num].push_back(y[i][tar2].num);
                    field[y[i][tar2].num].push_back(y[i-1][tar1].num);
                }
                tar1++;
            }
        }
    }
    printf("%d\n",Dijkstra(1,n));
}
