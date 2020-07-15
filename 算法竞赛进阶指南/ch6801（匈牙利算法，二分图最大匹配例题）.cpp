#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<functional>
//#include<bits/stdc++.h>
#define INF 0x3f3f3f3f //1061109567
#define llINF 9223372036854775807
#define pi 3.141592653589793
#define ll long long
using namespace std;
const ll maxn=1e2+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,m;

struct Node
{
    int x,y;
    Node(int x,int y):x(x),y(y){}
};

vector<Node>boy,girl;

bool vis[maxn*maxn];
int love[maxn*maxn];

int dir[4][2]=
{
    -1,0,
    1,0,
    0,-1,
    0,1
};

bool ntr(Node now)
{
    for(int i=0;i<4;i++)
    {
        int tempx=now.x+dir[i][0];
        int tempy=now.y+dir[i][1];
        int temp=tempx*n+tempy;
        if(tempx>0&&tempx<=n&&tempy>0&&tempy<=n&&!vis[temp])
        {
            vis[temp]=1;
            int tox=love[temp]/n;
            int toy=love[temp]%n;
            if(toy==0)
            {
                tox--;
                toy=n;
            }
            if(!love[temp]||ntr(Node(tox,toy)))
            {
                love[temp]=now.x*n+now.y;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        vis[x*n+y]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(!vis[i*n+j])
            {
                if((i+j)&1) boy.push_back(Node(i,j));
                else girl.push_back(Node(i,j));
            }
        }
    }
    int ans=0;
    for(int i=0;i<boy.size();i++)
    {
        for(auto temp:girl)
        {
            vis[temp.x*n+temp.y]=0;
        }
        if(ntr(boy[i])) ans++;
    }
    printf("%d\n",ans);
}


